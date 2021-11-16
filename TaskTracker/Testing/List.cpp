#include "List.h"

List::List()
{
  //EEPROM.begin(2048);
  // Store the offset for the current list item in the listItem array.
  int eeprom_offset = 0;
  // Load all the list items from memory.
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    //listItems[i].itemNumber = EEPROM.read(eeprom_offset + 0);
    for (int j = 0; j < 128; j++)
    {
      //listItems[i].itemName[j] = EEPROM.read(eeprom_offset + 1 + j);
    }
    for (int j = 0; j < 16; j++)
    {
      //listItems[i].creationTimeRaw[j] = EEPROM.read(eeprom_offset + 130 + j);
      //listItems[i].dueTimeRaw[j]      = EEPROM.read(eeprom_offset + 139 + j);
    }
    // Convert to user-readable form, all in one uint64_t.
    convertRawToTime64(listItems[i].creationTimeRaw, &listItems[i].creationTime);
    convertRawToTime64(listItems[i].dueTimeRaw, &listItems[i].dueTime);
    for (int j = 0; j < 2; j++)
    {
      //listItems[i].pointScoreRaw[j] = EEPROM.read(eeprom_offset + 147 + j);
    }
    eeprom_offset += LIST_ITEM_SIZE;
  }
}

// Return 0 on success, -1 on failure (no space for new list item).
int List::addNewItem(char *itemName, uint64_t cTime, uint64_t dTime)
{
  bool full = true;
  int i;
  for (i = 0; i < MAX_LIST_SIZE; i++)
  {
    // Break if we found an empty list item (we can put more information in it).
    if (listItems[i].itemNumber == 0)
    {
      full = false;
      break;
    }
  }
  // If the list is full indicate to the main program!
  if (full)
  {
    return -1;
  }
  // Put the new item at the end of the list (highest possible item number).
  listItems[i].itemNumber = 255;
  // Re-order the item numbers by condensing them (1,3,6,7,8 --> 1,2,3,4,5).
  List::condenseItemNumbers();
  // Pad rest of the item name with null termination character.
  char tmpName[128] = { '\0' };
  strcpy(tmpName, itemName);
  // Copy the new tmpName into the list item's itemName.
  strcpy(listItems[i].itemName, tmpName);
  // Add time information for time created.
  listItems[i].creationTime = cTime;
  List::convertTime64ToRaw(&cTime, listItems[i].creationTimeRaw);
  // Add time information for due time.
  listItems[i].dueTime = dTime;
  List::convertTime64ToRaw(&dTime, listItems[i].dueTimeRaw);
  // Store the converted times in proper format.
  convertRawToTime64(listItems[i].creationTimeRaw, &listItems[i].creationTime);
  convertRawToTime64(listItems[i].dueTimeRaw, &listItems[i].dueTime);
  return 0;
}

// Return 0 on success, -1 on failure (list item number could not be found).
int List::removeItem(uint8_t itemNumber)
{
  int index = List::itemNumberToIndex(itemNumber);
  // This item number does not exist, so we can't delete it.
  if (index == -1) return -1;
  // We only need to reset the item number (allows it to be over-written).
  listItems[index].itemNumber = 0;
  return 0;
}

// Return 0 on success, -1 on failure (list item number could not be found).
int List::renameItem(uint8_t itemNumber, char *newName)
{
  int index = List::itemNumberToIndex(itemNumber);
  // This item number does not exist, so we can't delete it.
  if (index == -1) return -1;
  char tmpName[128] = { '\0' };
  strcpy(tmpName, newName);
  // Copy the new tmpName into the list item's itemName.
  strcpy(listItems[index].itemName, tmpName);
  return 0;
}

// Return 0 on success, -1 on failure (list item number could not be found).
int List::swapItems(uint8_t itemNumber1, uint8_t itemNumber2)
{
  int index1 = List::itemNumberToIndex(itemNumber1);
  int index2 = List::itemNumberToIndex(itemNumber2);
  if (index1 == -1 || index2 == -1) return -1;
  // We don't need to swap the data, just swap the item numbers!
  int tmp = listItems[index1].itemNumber;
  listItems[index1].itemNumber = listItems[index2].itemNumber;
  listItems[index2].itemNumber = tmp;
  return 0;
}

// Return itemNumber = 0 on failure.
ListItem List::getListItemData(uint8_t itemNumber)
{
  // Default initialization of ListItem is everything = 0.
  ListItem retVal;
  int index = itemNumberToIndex(itemNumber);
  // Update the list item only in the case of list item found.
  if (index != -1)
  {
    retVal = listItems[index];
  }
  return retVal;
}

void List::condenseItemNumbers()
{
  uint8_t currentItemNumber = 0;
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    currentItemNumber++;
    bool itemNumberExists = false;
    for (int j = 0; j < MAX_LIST_SIZE; j++)
    {
      if (listItems[j].itemNumber == currentItemNumber)
      {
        itemNumberExists = true;
      }
    }
    // If this element number exists, continue to the next one.
    if (itemNumberExists == true) continue;
    // If this element number doesn't exist, it means we have a hole.
    int nextItemNumber = 255;
    int nextItemIndex = 0;
    bool reorder = false;
    // Find the next element in the list that should be placed in the void.
    for (int j = 0; j < MAX_LIST_SIZE; j++)
    {
      if (listItems[j].itemNumber <= nextItemNumber &&
          listItems[j].itemNumber > currentItemNumber)
      {
        nextItemIndex = j;
        nextItemNumber = listItems[j].itemNumber;
        reorder = true;
      }
    }
    // Re-number this element, if needed.
    if (reorder)
    {
      listItems[nextItemIndex].itemNumber = currentItemNumber;
    }
    // Repeat for all items in the list.
  }
}

void List::updatePointScore()
{
  // TODO: Finish this function.
}

void List::commitList()
{
  // Store the offset for the current list item in the listItem array.
  int eeprom_offset = 0;
  // Write back everything in the array (stored in RAM) to EEPROM.
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    //EEPROM.write(eeprom_offset + 0, listItems[i].itemNumber);
    for (int j = 0; j < 128; j++)
    {
      //EEPROM.write(eeprom_offset + 1 + j, listItems[i].itemName[j]);
    }
    for (int j = 0; j < 16; j++)
    {
      //EEPROM.write(eeprom_offset + 130 + j, listItems[i].creationTimeRaw[j]);
      //EEPROM.write(eeprom_offset + 139 + j, listItems[i].dueTimeRaw[j]);
    }
    for (int j = 0; j < 2; j++)
    {
      //EEPROM.write(eeprom_offset + 147 + j, listItems[i].pointScoreRaw[j]);
    }
    eeprom_offset += LIST_ITEM_SIZE;
  }
  // Uncomment this line to actually use the EEPROM.
  // Otherwise, only the cached table stored in RAM will be used.
  // EEPROM.commit();
}

void List::convertRawToTime64(uint8_t timeDataRaw[8], uint64_t *timeData)
{
  for (int i = 0; i < 8; i++)
  {
    *timeData |= (uint64_t)(timeDataRaw[i] << (i * 8));
  }
}

void List::convertTime64ToRaw(uint64_t *timeData, uint8_t timeDataRaw[8])
{
  for (int i = 0; i < 8; i++)
  {
    timeDataRaw[i] = (uint8_t)(*timeData >> (i * 8)) & 0xFF;
  }
}

// Returns -1 on failure.
int List::itemNumberToIndex(uint8_t itemNumber)
{
  int i;
  bool found = false;
  for (i = 0; i < MAX_LIST_SIZE; i++)
  {
    if (listItems[i].itemNumber == itemNumber)
    {
      found = true;
      break;
    }
  }
  if (!found) return -1;
  return i;
}
