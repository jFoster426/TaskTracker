#ifndef WiFiMode_h
#define WiFiMode_h

#include <ESP8266WebServer.h>

#include "HandleLCD.h"
#include "HandleServer.h"
#include "StateMachine.h"

extern ESP8266WebServer server;
extern const int WIFI_AP_MODE;
extern const int WIFI_DEV_MODE;
extern const int BTN;
extern const char settingsMenuItems[][17];
extern char currentSettings[][17];

void setWiFiMode(int newMode);

#endif
