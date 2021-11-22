#ifndef HandleServer_h
#define HandleServer_h

#include "Arduino.h"
#include <string.h>
#include <ESP8266WebServer.h>

#include "HandleLCD.h"
#include "StateMachine.h"
#include "List.h"
#include "index.h"

extern ESP8266WebServer server;
extern int listCounter;
extern List myTaskList;
extern int totalStreak;
extern unsigned long int timeAtLastRequest;
extern bool currentlyConnected;
extern uint32_t millisAtTimeSync;
extern uint64_t epochAtTimeSync;
extern bool timeSyncedSincePowerOn;

void handleRoot();
void resetListCounter();
void sendListItem();
void handleAddNewItem();
void handleReOrderItem();
void handleRemoveItem();
void handleFinishedItem();

#endif
