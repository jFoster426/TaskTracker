#include "HandleStreakData.h"

void writeStreakDataToEEPROM()
{
  EEPROM.write(1950, (totalStreak >> 24) & 0xFF);
  EEPROM.write(1951, (totalStreak >> 16) & 0xFF);
  EEPROM.write(1952, (totalStreak >> 8)  & 0xFF);
  EEPROM.write(1953,  totalStreak        & 0xFF);

  EEPROM.write(1960, (timeLastTaskCompleted >> 56) & 0xFF);
  EEPROM.write(1961, (timeLastTaskCompleted >> 48) & 0xFF);
  EEPROM.write(1962, (timeLastTaskCompleted >> 40) & 0xFF);
  EEPROM.write(1963, (timeLastTaskCompleted >> 32) & 0xFF);
  EEPROM.write(1964, (timeLastTaskCompleted >> 24) & 0xFF);
  EEPROM.write(1965, (timeLastTaskCompleted >> 16) & 0xFF);
  EEPROM.write(1966, (timeLastTaskCompleted >>  8) & 0xFF);
  EEPROM.write(1967,  timeLastTaskCompleted        & 0xFF);
  // Debug.
  Serial.print("\nCommitting data to EEPROM!\n");
  if (EEPROM_COMMIT == true)
  {
    Serial.print("Executing EEPROM.commit();\n");
    EEPROM.commit();
  }
}

void loadStreakDataFromEEPROM()
{
  // Read the 4 byte total streak variable from EEPROM.
  totalStreak = (EEPROM.read(1950) << 24) |
                (EEPROM.read(1951) << 16) |
                (EEPROM.read(1952) << 8)  |
                (EEPROM.read(1953));
  // Read the 8 byte time that the last task was completed
  // from EEPROM.
  timeLastTaskCompleted = (EEPROM.read(1960) << 56) |
                          (EEPROM.read(1961) << 48) |
                          (EEPROM.read(1962) << 40) |
                          (EEPROM.read(1963) << 32) |
                          (EEPROM.read(1964) << 24) |
                          (EEPROM.read(1965) << 16) |
                          (EEPROM.read(1966) <<  8) |
                          (EEPROM.read(1967));
  // Take care of empty streak data (all 1's when reading), this
  // means the program is running for the first time or not using
  // the actual EEPROM (RAM table for testing).
  if (~totalStreak == 0 ||
      ~timeLastTaskCompleted == 0)
  {
    totalStreak = 0;
    timeLastTaskCompleted = 0;
    writeStreakDataToEEPROM();
  }
}
