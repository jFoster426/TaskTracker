#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "ShiftRegister.h"
#include "ShiftRegisterLCD.h"
#include "List.h"
#include "ListItem.h"

// Include the contents of the webpage.
#include "index.h"

// Enter the SSID and Password of the Wi-Fi network.
const char* ssid = "Judd";
const char* password = "juddiscool";

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

// Set up the web server on port 80.
ESP8266WebServer server(80);

// Define NTP Client to get the time.
WiFiUDP ntpUDP;
// Define the time client, using our local UTC offset in seconds.
NTPClient timeClient(ntpUDP, "pool.ntp.org", (-3600 * 8));

// Set up our output shift registers (two connected to the ESP8266 in this project).
ShiftRegister sr(4, 5, 12, 13, 14);

// Set up the LCD connected to the shift registers.
ShiftRegisterLCD srLCD(&sr, LCD_RS_BIT, LCD_RW_BIT, LCD_E_BIT,
                       LCD_D0_BIT, LCD_D1_BIT, LCD_D2_BIT, LCD_D3_BIT,
                       LCD_D4_BIT, LCD_D5_BIT, LCD_D6_BIT, LCD_D7_BIT);

// Create a task list using the list class.
List myTaskList;

void handleRoot()
{
  // Read the contents of the HTML webpage.
  String s = MAIN_page;
  // Send the webpage to the client.
  server.send(200, "text/html", s);
  // TODO: Send the list contents to the client
  // (it should be waiting for list items).
}

void handleAddNewItem()
{
  char itemName[128] = { '\0' };
  server.arg("itemName").toCharArray(itemName, 128);
  Serial.print("Got: ");
  Serial.println(itemName);
  // Sometimes the HTTP request goes through twice. Handle this by
  // sending the item number as an argument and checking if that item
  // number already exists. If so, we can safely ignore this request.
}

void setup(void)
{
  // Open the serial port at 115200 baud.
  Serial.begin(115200);
  // Make sure to start on a new line because the ESP8266 prints
  // garbage at 74800 baud when it starts up.
  Serial.println();
  // Connect to the Wi-Fi network.
  WiFi.begin(ssid, password);
  // Wait for the connection to be established.
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  // If connection  was successful, show IP address in serial monitor.
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  // The IP address assigned to your ESP.
  Serial.println(WiFi.localIP());
  // Set up functions to be executed when the website does something.
  server.on("/", handleRoot);
  server.on("/addNewItem", handleAddNewItem);
  //  server.on("/reorderItem", handleReorderItem);
  //  server.on("/deleteItem", handleDeleteItem);
  //  server.on("/finishItem", handleFinishItem);
  //  server.on("/unfinishItem", handleUnfinishItem);
  // TODO: How to make client close action --> handleEEPROMCommit()

  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient();
}
