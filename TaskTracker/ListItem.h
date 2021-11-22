#ifndef ListItem_h
#define ListItem_h

// Each list item is at 150 spacing in memory.
#define LIST_ITEM_SIZE 150

#include "Arduino.h"
#include <stdint.h>

/*
   EEPROM memory mapping:

   Byte Index Contents
   0         List Item Number (non-zero, zero indicates no list item)
   1   - 129 List Item Name (128-byte character array)
   130 - 138 List Item Creation Time (64-bit integer)
   139 - 146 List Item Due Time (64-bit integer)
   147 - 148 List Item Point Score (16-bit integer)

   EEPROM will be laid out as follows:
   Byte Index  Contents
   0    - 148  List Item 1
   150  - 298  List Item 2
   300  - 448  List Item 3
   450  - 598  List Item 4
   600  - 748  List Item 5
   750  - 898  List Item 6
   900  - 1048 List Item 7
   1050 - 1198 List Item 8
   1200 - 1348 List Item 9
   1350 - 1498 List Item 10
   1500 - 1648 List Item 11
   1650 - 1798 List Item 12
   1800 - 1948 List Item 13
   1949 - 2047 ...  Reserved for other use
*/

class ListItem
{
  public:
    // Constructor.
    ListItem();
    // Member variables for ListItem.
    uint8_t itemNumber;
    char itemName[128];
    uint8_t creationTimeRaw[8];
    uint64_t creationTime;
    uint8_t dueTimeRaw[8];
    uint64_t dueTime;
    uint8_t pointScoreRaw[2];
    bool completed;
};

#endif
