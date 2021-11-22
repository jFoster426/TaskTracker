#include "WiFiMode.h"

// The current WiFi mode (access point mode or device mode).
const int WIFI_AP_MODE  = 0;
const int WIFI_DEV_MODE = 1;

// Enter the SSID and Password of the Wi-Fi network.
const char* ssid = "Judd";
const char* password = "juddiscool";

// This will be the SSID and Password of the access point
// created by the ESP.
const char* ssid_ap = "TaskTrackerAP";

void setWiFiMode(int newMode)
{
  if (newMode == WIFI_AP_MODE)
  {
    // In case we were in another mode before, make sure it is finished.
    WiFi.disconnect(true);
    // Set up the WiFi access point.
    WiFi.softAP(ssid_ap);
    IPAddress myIP = WiFi.softAPIP();
    // Show the Serial terminal what is happening.
    Serial.print("User set WiFi access point mode.");
    Serial.print("\nSetting up Wi-Fi Access Point.\n");
    Serial.print("Network name: ");
    Serial.print(ssid_ap);
    Serial.print("\nIP address: ");
    Serial.print(myIP);
    Serial.print("\n");
    // Show the parameters on the LCD.
    handleUpdateLCD(ssid_ap, myIP.toString().c_str());
  }
  if (newMode == WIFI_DEV_MODE)
  {
    // In case we were in another mode before, make sure it is finished.
    WiFi.disconnect(true);
    // Show the Serial terminal what is happening.
    Serial.print("User set WiFi device mode.");
    Serial.print("\nConnecting to Wi-Fi Network: ");
    Serial.print(ssid);
    Serial.print("\n");
    // Show the user that we are connecting to the Wi-Fi.
    handleUpdateLCD("Connecting...", "");
    // Connect to the Wi-Fi network.
    WiFi.begin(ssid, password);
    // Wait for the connection to be established.
    int i = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
      // Set a 30 seond timer, or if the user presses the button.
      // In this case recursively call the function again and set
      // access point mode.
      if (i == 60 ||
          digitalRead(BTN) == LOW)
      {
        delay(50);
        // Call this function recursively and set the device to AP mode.
        // Immediately return from this instance of the function.
        setWiFiMode(WIFI_AP_MODE);
        return;
      }
      // ESP Soft WDT reset.
      delay(1);
    }
    // If connection  was successful, show IP address in serial monitor.
    Serial.print("\n");
    Serial.print("Connected to ");
    Serial.print(ssid);
    Serial.print("\nIP address: ");
    // Print the IP address assigned to your ESP.
    Serial.print(WiFi.localIP());
    Serial.print("\n");
    handleUpdateLCD("Connected!", WiFi.localIP().toString().c_str());
  }
  // Wait in case user button is already pressed! This is needed in the case
  // above where the WiFi device mode times out and converts to AP mode.
  while (digitalRead(BTN) == LOW)
  {
    delay(1);
  }
  // Button debouncing.
  delay(50);
  // Wait for the user button press. The user needs to confirm that they have
  // read and copied down the IP address in order to connect to the ESP.
  while (digitalRead(BTN) == HIGH)
  {
    // Needed for ESP8266 WDT reset.
    delay(1);
  }
  // Wait for user to release button to avoid completing a task accidentally!
  while (digitalRead(BTN) == LOW)
  {
    delay(1);
  }
  // Button debouncing.
  delay(500);
  // Set up functions to be executed when the website does something.
  server.on("/", handleRoot);
  server.on("/resetListCounter", resetListCounter);
  server.on("/sendListItem", sendListItem);
  server.on("/addNewItem", handleAddNewItem);
  server.on("/reOrderItem", handleReOrderItem);
  server.on("/removeItem", handleRemoveItem);
  server.on("/finishedItem", handleFinishedItem);
  server.begin();
  Serial.print("HTTP server started.\n\n");
  // Update the user settings to match the current mode.
  int i = 0;
  while (strcmp(settingsMenuItems[i], "X") != 0)
  {
    if (strcmp(settingsMenuItems[i], "Set WiFi AP Mode") == 0)
    {
      if (newMode == WIFI_AP_MODE)
      {
        strcpy(currentSettings[i], "WiFi AP Mode");
        break;
      }
      if (newMode == WIFI_DEV_MODE)
      {
        strcpy(currentSettings[i], "WiFi Device Mode");
      }
    }
    i++;
  }
}
