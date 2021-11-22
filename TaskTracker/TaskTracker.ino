// Include Arduino based libraries.
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <time.h>
#include <stdint.h>
// Include our own libraries.
#include "HandleLCD.h"
#include "HandleLED.h"
#include "HandleServer.h"
#include "HandleStreakData.h"
#include "List.h"
#include "ListItem.h"
#include "ShiftRegister.h"
#include "ShiftRegisterLCD.h"
#include "StateMachine.h"
#include "WiFiMode.h"
// Include the contents of the webpage.
#include "index.h"

// Constants which make the code easier to understand.
const int LCD_BKLT_BIT = 4;
const int LCD_RS_BIT   = 5;
const int LCD_RW_BIT   = 6;
const int LCD_E_BIT    = 7;
const int LCD_D0_BIT   = 8;
const int LCD_D1_BIT   = 9;
const int LCD_D2_BIT   = 10;
const int LCD_D3_BIT   = 11;
const int LCD_D4_BIT   = 12;
const int LCD_D5_BIT   = 13;
const int LCD_D6_BIT   = 14;
const int LCD_D7_BIT   = 15;
// Two buttons, main button (front) on IO15, alternate
// button (rear) on IO0. Also used for programming
// (hold down while powering on board).
const int PROG_BTN     = 0;
const int BTN          = 16;

// Initialize the listCounter variable. This variable is used when the webpage wants to get
// the contents of the task list stored in the EEPROM memory on the ESP8266. The webpage
// first sends a "resetListCounter" request, then spams "sendListItem" while the ESP sends
// the contents of the list. When we have reached the end of the list, the ESP responds
// to the sendListItem with "end" so the webpage knows there are no more items.
int listCounter = 0;

// Store the user's total streak. This variable is also stored in EEPROM and loaded on
// program reset to make sure that we can keep the streak even on power-off.
int totalStreak = 0;

// Store the variables that indicate the button press states for the state machine.
bool frontButtonPressed = false;
bool rearButtonPressed = false;

// Store the time since the last GET request. This should be called every
// 2.5 seconds from the webpage so if we go a long period of time without seeing it,
// then we know the user has disconnected the webpage.
unsigned long int timeAtLastRequest = 0;

// Is there a website currently linked to the ESP?
bool currentlyConnected = false;

// When running the state machine, the user may select to change the Wi-Fi mode.
// The main loop will check if this variable is true and if so then resets the
// WiFi module with the correct status (access point, or device mode).
bool restartWiFi = false;
// Stores the current WiFi mode (access point, or device mode). The default state
// tries to connect to the network.
int currentWiFiState = WIFI_DEV_MODE;

uint32_t millisAtTimeSync = 0;
uint64_t epochAtTimeSync = 0;

// Stores the time that the last task was completed (in epoch time).
uint64_t timeLastTaskCompleted = 0;

// Have we connected to the website within the last power cycle?
// If so, then we are able to increment the streak counter. Otherwise pause the streak.
bool timeSyncedSincePowerOn = false;

// Do we want to actually commit the data to the emulated EEPROM (FLASH)?
// Set to false for testing.
const bool EEPROM_COMMIT = true;

// Set up the web server on port 80.
ESP8266WebServer server(80);

// Set up our output shift registers (two connected to the ESP8266 in this project).
ShiftRegister sr(4, 5, 12, 13, 14);

// Set up the LCD connected to the shift registers.
ShiftRegisterLCD srLCD(&sr, LCD_RS_BIT, LCD_RW_BIT, LCD_E_BIT,
                       LCD_D0_BIT, LCD_D1_BIT, LCD_D2_BIT, LCD_D3_BIT,
                       LCD_D4_BIT, LCD_D5_BIT, LCD_D6_BIT, LCD_D7_BIT);

// Create a task list using the list class.
List myTaskList;

void handleDebugInput()
{
  char inputStr[100] = { '\0' };
  int i = 0;
  int timeout = millis();
  // At least one character will be available for read
  // if this function is called.
  while ((inputStr[i++] = Serial.read()) != '\n')
  {
    while (!Serial.available())
    {
      // Implement 1 second timeou while waiting for "\n" character.
      if (millis() - timeout >= 1000)
      {
        Serial.print("Invalid Debug String!\n\n");
        return;
      }
    }
  }
  // We now have a properly formatted debug string, which we can parse.
  Serial.print("\nDebug String: ");
  // No need for newline (inputStr already has newline terminating)!
  Serial.print(inputStr);
  if (strcmp(inputStr, "help\n") == 0)
  {
    Serial.print("\nCurrent Commands Implemented:\n");
    Serial.print("\'printlist\' - Print the task list contents.\n");
  }
  if (strcmp(inputStr, "printlist\n") == 0)
  {
    // Print the list contents.
    Serial.print("\nContents of Task List:\n\n");
    for (int j = 0; j < MAX_LIST_SIZE; j++)
    {
      Serial.print("List Index: ");
      Serial.print(j);
      if (myTaskList.listItems[j].itemNumber == 255)
      {
        Serial.print("\n  Empty List Item.\n\n");
        continue;
      }
      Serial.print("\n  List Item Number: ");
      Serial.print(myTaskList.listItems[j].itemNumber);
      Serial.print("\n  List Item Name: ");
      Serial.print(myTaskList.listItems[j].itemName);
      Serial.print("\n  List Item Creation Time: ");
      Serial.print(myTaskList.listItems[j].creationTime);
      Serial.print("\n  List Item Due Time: ");
      Serial.print(myTaskList.listItems[j].dueTime);
      Serial.print("\n\n");
    }
    Serial.print("End List Contents.\n\n\n");
  }
}

void setup(void)
{
  // Set the front and rear buttons as inputs.
  pinMode(PROG_BTN, INPUT);
  pinMode(BTN,      INPUT);
  // Set LED 1 as an output.
  pinMode(LED1_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  // Set the correct time-zone (U.S. Pacific Time).
  setenv("TZ", "PST8PDT", 1);
  tzset();
  // Open the serial port.
  Serial.begin(74880);
  delay(100);
  // Set up the emulated EEPROM to load and store list items even after
  // the device is powered off.
  EEPROM.begin(2048);
  // Set up the LCD screen.
  srLCD.begin(16, 2);
  // Enable the LCD backlight.
  sr.setBit(LCD_BKLT_BIT);
  // Make sure to start on a new line because the ESP8266 prints
  // garbage at 74800 baud when it starts up.
  Serial.print("\n");
  // Set up the Wi-Fi on the device. Default to connect to a router.
  setWiFiMode(WIFI_DEV_MODE);
  // Load the streak data from EEPROM.
  loadStreakDataFromEEPROM();
  // Load the list data from EEPROM.
  myTaskList.loadDataFromEEPROM();
}

void loop()
{
  // Uncomment for testing.
//  digitalWrite(LED1_PIN, HIGH);
//  delay(10);
//  digitalWrite(LED1_PIN, LOW);
//  delay(10);
  // Handle all the HTML related stuff.
  server.handleClient();
  // Handle typing something into the Serial port.
  if (Serial.available() > 0)
  {
    handleDebugInput();
  }
  // Handle user changed WiFi settings. Make sure this doesn't get called
  // when the user is still in the settings mode.
  if (restartWiFi == true &&
      currentState == STATE_SHOW_TASK)
  {
    setWiFiMode(currentWiFiState);
    restartWiFi = false;
  }
  // If the website was disconnected, make sure to perform
  // a "save" operation, into the emulated EEPROM (FLASH) memory.
  if (millis() - timeAtLastRequest > 10000 &&
      currentlyConnected == true)
  {
    currentlyConnected = false;
    // Display the changed state on the Serial monitor.
    Serial.print("\nWebsite disconnected.\n");
    Serial.print("Saving current task list contents to memory.\n");
    // Show on the LCD as well in case Serial monitor not connected.
    handleUpdateLCD("Working offline!", "Saving list...");
    myTaskList.commitList();
    delay(1000);
  }
  // Make sure the button states are reset.
  frontButtonPressed = false;
  rearButtonPressed = false;
  // Update the button states to their most current value
  // based on the IO pin values.
  if (digitalRead(BTN) == LOW)
  {
    frontButtonPressed = true;
  }
  if (digitalRead(PROG_BTN) == LOW)
  {
    rearButtonPressed = true;
  }
  // Handle the state machine. This function is mainly in charge
  // of what is currently being displayed on the LCD.
  handleStateMachine();
  // Prevent button hold-down from re-triggering the state machine
  // on the next loop iteration.
  while (digitalRead(BTN) == LOW ||
         digitalRead(PROG_BTN) == LOW)
  {
    // Prevent ESP soft WDT reset.
    delay(1);
  }
  // Handle button debouncing.
  if (frontButtonPressed == true ||
      rearButtonPressed == true)
  {
    delay(50);
  }
}

// Need to finish:
// 1. Save to FLASH
// 3. Syncing times
