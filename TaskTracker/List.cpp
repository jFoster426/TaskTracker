#include "List.h"

List::List()
{
}

// Load data from EEPROM.
void List::loadDataFromEEPROM()
{
  // Store the offset for the current list item in the listItem array.
  int eeprom_offset = 0;
  // Load all the list items from memory.
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    listItems[i].itemNumber = EEPROM.read(eeprom_offset + 0);
    for (int j = 0; j < 128; j++)
    {
      listItems[i].itemName[j] = EEPROM.read(eeprom_offset + 1 + j);
    }
    // Print the due time information to the Serial monitor.
    Serial.print("\nList Item ");
    Serial.print(i);
    Serial.print(" due time raw: ");
    for (int j = 0; j < 8; j++)
    {
      listItems[i].creationTimeRaw[j] = EEPROM.read(eeprom_offset + 130 + j);
      listItems[i].dueTimeRaw[j]      = EEPROM.read(eeprom_offset + 139 + j);
      Serial.print(listItems[i].dueTimeRaw[j], HEX);
      Serial.print(" ");
    }
    // Convert to user-readable form, all in one uint64_t.
    convertRawToTime64(listItems[i].creationTimeRaw, &listItems[i].creationTime);
    convertRawToTime64(listItems[i].dueTimeRaw, &listItems[i].dueTime);
    Serial.print("\ndue time: ");
    Serial.print(listItems[i].dueTime, HEX);
    Serial.print("\n");
    for (int j = 0; j < 2; j++)
    {
      listItems[i].pointScoreRaw[j] = EEPROM.read(eeprom_offset + 147 + j);
    }
    eeprom_offset += LIST_ITEM_SIZE;
  }
}

// Add a new item to the list.
// Input arguments:
// char *itemName - the name of the list item.
// uint64_t cTime - the time that the list item was created (the current time).
// uint64_t dTIme - the "due date" for the list item.
// Return value: 0 on success, -1 on failure (no space for new list item).
int List::addNewItem(char *itemName, uint64_t cTime, uint64_t dTime)
{
  // Store if the list is currently full (defaults to true and is set to false
  // if there exists a list item that's empty).
  bool full = true;
  // Iterator storing the first list item that is empty.
  int i;
  for (i = 0; i < MAX_LIST_SIZE; i++)
  {
    // Break if we found an empty list item (we can put more information in it).
    // Note: Since we are using emulated EEPROM, an empty list item will have an
    // item number equal to 255 (all 1's in FLASH).
    if (listItems[i].itemNumber == 255)
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
  // Put the new item at the end of the list (highest possible item number...
  // Note: NOT 255, which would be empty item).
  listItems[i].itemNumber = 254;
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
  // Make sure to set the item's completion status to false, otherwise
  // an old list item may still remain and have previously set completed to true.
  // This would cause the list item to be removed immediately when it is created!
  listItems[i].completed = false;
  return 0;
}

// Remove an item from the list.
// Input arguments:
// uint8_t itemNumber - the item number (not the index!) of the item to be removed.
// Return value: 0 on success, -1 on failure (the list item number could not be found).
int List::removeItem(uint8_t itemNumber)
{
  int index = List::findItemByItemNumber(itemNumber);
  // This item number does not exist, so we can't delete it.
  if (index == -1) return -1;
  // We only need to reset the item number (allows it to be over-written).
  listItems[index].itemNumber = 255;
  return 0;
}

// Rename an item in the list.
// Input arguments:
// uint8_t itemNumber - the item number (not the index!) of the item to be renamed.
// char *newName - the new name for the item.
// Return value: 0 on success, -1 on failure (list item number could not be found).
int List::renameItem(uint8_t itemNumber, char *newName)
{
  // Attempt to find the list item by its item number.
  int index = List::findItemByItemNumber(itemNumber);
  // This item number does not exist, so we can't delete it.
  if (index == -1) return -1;
  // Copy the new tmpName into the list item's itemName.
  strcpy(listItems[index].itemName, newName);
  return 0;
}

// Swap two list items. The function only swaps the item numbers for the two list
// items, not the data itself (would help save EEPROM memory cycles in a non-
// emulated EEPROM system).
// Input arguments:
// uint8_t itemNumber1 - The first list item to swap.
// uint8_t itemNumber2 - The second list item to swap.
// Return value: 0 on success, -1 on failure (list item number could not be found).
int List::swapItems(uint8_t itemNumber1, uint8_t itemNumber2)
{
  // Store the indices where the two list items we want to swap are located in
  // memory.
  int index1 = List::findItemByItemNumber(itemNumber1);
  int index2 = List::findItemByItemNumber(itemNumber2);
  // If either don't exist then just return a failure code.
  if (index1 == -1 || index2 == -1) return -1;
  // We don't need to swap the data, just swap the item numbers!
  int tmp = listItems[index1].itemNumber;
  listItems[index1].itemNumber = listItems[index2].itemNumber;
  listItems[index2].itemNumber = tmp;
  return 0;
}

// Get list item data for a given list item number.
// Input arguments:
// uint8_t itemNumber - the item number (not the index!) of the list item we
//                      wish to retrieve the information for.
// Return value: ListItem will contain itemNumber = 0 on failure,
//               ListItem will contain itemNumber > 0 on success.
ListItem List::getListItemData(uint8_t itemNumber)
{
  // Default initialization of ListItem is everything = 0.
  ListItem retVal;
  int index = findItemByItemNumber(itemNumber);
  // Update the list item only in the case of list item found.
  if (index != -1)
  {
    retVal = listItems[index];
  }
  return retVal;
}

// Condense the list item numbers.
// i.e. For list item numbers 1, 2, 4, 5, 6, 9 (3, 7, 8 were removed),
//      condense the list to  1, 2, 3, 4, 5, 6 (remove "holes" in the list).
// Input arguments: None.
// Return value: None.
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
    int nextItemNumber = 254;
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

// Returns the index of the list item whose name is equal to itemName.
// If no element is found, return -1.
int List::findItemByItemName(char *itemName)
{
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    if (strcmp(itemName, listItems[i].itemName) == 0 &&
        listItems[i].itemNumber != 255)
    {
      return i;
    }
  }
  return -1;
}

// Returns the index of the list item whose number is equal to itemNumber.
// If no element is found, return -1.
int List::findItemByItemNumber(uint8_t itemNumber)
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

void List::commitList()
{
  // Store the offset for the current list item in the listItem array.
  int eeprom_offset = 0;
  // Write back everything in the array (stored in RAM) to EEPROM.
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    // Make sure to update the creationTime and dueTime from their uint64_t
    // counterparts, as these are the ones that will be edited in the main program!
    convertTime64ToRaw(&listItems[i].creationTime, listItems[i].creationTimeRaw);
    convertTime64ToRaw(&listItems[i].dueTime,      listItems[i].dueTimeRaw);
    EEPROM.write(eeprom_offset + 0, listItems[i].itemNumber);
    for (int j = 0; j < 128; j++)
    {
      EEPROM.write(eeprom_offset + 1 + j, listItems[i].itemName[j]);
    }
    // Print the due time information to the Serial monitor.
    Serial.print("List Item ");
    Serial.print(i);
    Serial.print(" due time: ");
    Serial.print(listItems[i].dueTime, HEX);
    Serial.print("\ndue time raw: ");
    for (int j = 0; j < 8; j++)
    {
      EEPROM.write(eeprom_offset + 130 + j, listItems[i].creationTimeRaw[j]);
      EEPROM.write(eeprom_offset + 139 + j, listItems[i].dueTimeRaw[j]);
      Serial.print(listItems[i].dueTimeRaw[j], HEX);
      Serial.print(" ");
    }
    Serial.print("\n");
    for (int j = 0; j < 2; j++)
    {
      EEPROM.write(eeprom_offset + 147 + j, listItems[i].pointScoreRaw[j]);
    }
    eeprom_offset += LIST_ITEM_SIZE;
  }
  // Debug.
  Serial.print("\nCommitting data to EEPROM!\n");
  // Uncomment this line to actually use the EEPROM.
  // Otherwise, only the cached table stored in RAM will be used.
  if (EEPROM_COMMIT == true)
  {
    Serial.print("Executing EEPROM.commit();\n");
    EEPROM.commit();
  }
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
