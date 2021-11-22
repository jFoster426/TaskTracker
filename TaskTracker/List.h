#ifndef List_h
#define List_h

#define MAX_LIST_SIZE 13

#include "Arduino.h"
#include <EEPROM.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ListItem.h"

extern const bool EEPROM_COMMIT;

class List
{
  public:
    // Constructor.
    List();
    // Array of ListItem to store each item.
    ListItem listItems[MAX_LIST_SIZE];
    // Member functions for the list.
    void loadDataFromEEPROM();
    int addNewItem(char *itemName, uint64_t cTime, uint64_t dTime);
    int removeItem(uint8_t itemNumber);
    int renameItem(uint8_t itemNumber, char *newName);
    int swapItems(uint8_t itemNumber1, uint8_t itemNumber2);
    ListItem getListItemData(uint8_t itemNumber);
    void condenseItemNumbers();
    int findItemByItemName(char *itemName);
    int findItemByItemNumber(uint8_t itemNumber);
    // Commit the list to the emulated EEPROM memory
    // (this is actually just FLASH in ESP8266).
    // DON'T DO THIS OFTEN! Reduces FLASH lifespan!
    void commitList();
  private:
    void convertRawToTime64(uint8_t timeDataRaw[8], uint64_t *timeData);
    void convertTime64ToRaw(uint64_t *timeData, uint8_t timeDataRaw[8]);
};

#endif
