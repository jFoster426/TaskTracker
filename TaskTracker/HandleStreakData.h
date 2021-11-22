#ifndef HandleStreakData_h
#define HandleStreakData_h

/*
   EEPROM memory mapping:

   1950 - 1953   totalStreak
   1954 - 1967   timeLastTaskCompleted
 */

#include "Arduino.h"
#include <EEPROM.h>

extern int totalStreak;
extern uint64_t timeLastTaskCompleted;
extern const bool EEPROM_COMMIT;

void writeStreakDataToEEPROM();
void loadStreakDataFromEEPROM();

#endif
