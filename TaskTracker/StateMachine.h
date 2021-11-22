#ifndef StateMachine_h
#define StateMachine_h

#include "Arduino.h"
#include <stdint.h>

#include "List.h"
#include "HandleLCD.h"
#include "HandleLED.h"
#include "HandleStreakData.h"
#include "ShiftRegister.h"
#include "WiFiMode.h"

#define STATE_SHOW_TASK      0
#define STATE_SHOW_SETTINGS  1

#define DUE_TIME_1PM         13
#define DUE_TIME_2PM         14
#define DUE_TIME_3PM         15
#define DUE_TIME_4PM         16
#define DUE_TIME_5PM         17

extern bool frontButtonPressed;
extern bool rearButtonPressed;
extern bool currentlyConnected;
extern int totalStreak;
extern List myTaskList;
extern bool restartWiFi;
extern int currentWiFiState;
extern int currentState;
extern int newListItemDueTime;
extern uint64_t timeLastTaskCompleted;
extern const int LCD_BKLT_BIT;

void animate();

void handleStateMachine();

#endif
