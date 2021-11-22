#include "HandleServer.h"

void handleRoot()
{
  // Make sure to update the timeAtLastRequest to show that
  // the website is still active!
  timeAtLastRequest = millis();
  // Debug
  Serial.print("\nClient connected!\n");
  Serial.print("Sending webpage contents.\n");
  // Read the contents of the HTML webpage.
  // String s = MAIN_page;
  // Send the webpage to the client.
  server.send_P(200, "text/html", MAIN_page);
  // Update the connection status for the main program.
  currentlyConnected = true;
}

void resetListCounter()
{
  // Make sure to update the timeAtLastRequest to show that
  // the website is still active!
  timeAtLastRequest = millis();
  listCounter = 0;
  // Debug
  Serial.print("\nReset listCounter to zero.\n");
}

void sendListItem()
{
  // Make sure to update the timeAtLastRequest to show that
  // the website is still active!
  timeAtLastRequest = millis();
  // Send the list contents to the client
  // (It should be waiting for list items).
  // How much data do we need in the buffer?
  //         23  for "http://www.j.com/t.html"
  //          5  for "?num=".
  //          2  for item number.
  //          6  for "&name=".
  //        255  for name.
  //          7  for "&rTime=".
  //         20  for remainingTime.
  // Total: 318  bytes (round up for safety).
  char dataToSend[333] = { '\0' };
  // Store if we have reached the end of the list.
  bool listEnd = false;
  // Special case: listCounter has reached the end of the list.
  if (listCounter >= MAX_LIST_SIZE)
  {
    listEnd = true;
  }
  // Don't send empty list items.
  while (listEnd == false &&
         myTaskList.listItems[listCounter].itemNumber == 255)
  {
    // Reached the end of the list, don't try and send any more.
    if (++listCounter >= MAX_LIST_SIZE)
    {
      listEnd = true;
    }
  }
  if (listEnd)
  {
    // Debug.
    Serial.print("\nNo more list items to send!\n");
    server.send(200, "text/plane", "end");
  }
  else
  {
    // Debug.
    Serial.print("\nSending list item ");
    Serial.print(listCounter);
    Serial.print(" to webpage.\n");
    // Send the next existing list item.
    strcat(dataToSend, "http://www.j.com/t.html?num=");
    char itemNumBuf[4];
    itoa(myTaskList.listItems[listCounter].itemNumber, itemNumBuf, 10);
    strcat(dataToSend, itemNumBuf);
    strcat(dataToSend, "&name=");
    strcat(dataToSend, myTaskList.listItems[listCounter].itemName);
    strcat(dataToSend, "&dueTime=");
    // Get the due date and time into a formatted string to send to the webpage.
    char buf[32] = { '\0' };
    strftime(buf, sizeof(buf), "%b %d", localtime((const time_t *)(&myTaskList.listItems[listCounter].dueTime)));
    char dueTimeStr[64] = { '\0' };
    strcat(dueTimeStr, "Due on ");
    strcat(dueTimeStr, buf);
    strcat(dueTimeStr, ", at ");
    strftime(buf, sizeof(buf), "%H:%M:%S.", localtime((const time_t *)(&myTaskList.listItems[listCounter].dueTime)));
    strcat(dueTimeStr, buf);
    // Send the due time to the website.
    strcat(dataToSend, dueTimeStr);
    server.send(200, "text/plane", dataToSend);
    // Increment listCounter so we don't get stuck on the same list item!
    listCounter++;
  }
}

void handleAddNewItem()
{
  // Make sure to update the timeAtLastRequest to show that
  // the website is still active!
  timeAtLastRequest = millis();
  // Store the name of the new item.
  char itemName[128] = { '\0' };
  server.arg("itemName").toCharArray(itemName, 128);
  // Store the time that the new item was added.
  char creationTimeStr[20] = { '\0' };
  server.arg("creationTime").toCharArray(creationTimeStr, 20);
  // The creation time was right now, so we should update the system time to sync
  // with this creation time. This allows the ESP to determine the current date.
  millisAtTimeSync = millis();
  epochAtTimeSync = atoll(creationTimeStr);
  // Sometimes the HTTP request goes through twice. Handle this by
  // checking if the itemName is the same as one that already exists
  // in the list (findItemByName returns -1 if the item does not exist).
  if (myTaskList.findItemByItemName(itemName) != -1) return;
  // Debug this information to the Serial monitor (in case it is connected).
  Serial.print("New Item Added to List:\n");
  Serial.print("Item Name: \"");
  Serial.print(itemName);
  Serial.print("\"\n");
  Serial.print("Time Created: ");
  Serial.print(creationTimeStr);
  Serial.print("\n");
  // Convert into some user-readable time (instead of EPOCH time).
  time_t creationTime = (time_t)epochAtTimeSync;
  char buf[80];
  strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", localtime(&creationTime));
  Serial.print(buf);
  Serial.print("\n");
  // 1636578000 is the date and time for 11/10/2021 1:00:00 PM (PST).
  // 24 hours to seconds = 24 * 3600 = 86400 seconds.
  // Use this to set the due time to 1:00:00 PM on the following day.
  time_t dueTime = (time_t)(1636578000);
  while (dueTime < creationTime)
  {
    // Increment dueTime by one full day (24 hours).
    dueTime += 86400;
  }
  // Current offset is calibrated for 1PM, don't need to do anything in that case.
  if (newListItemDueTime == DUE_TIME_1PM)
  {
  }
  // Convert the due time with the custom user setting.
  else if (newListItemDueTime == DUE_TIME_2PM)
  {
    dueTime += (1 * 3600);
  }
  else if (newListItemDueTime == DUE_TIME_3PM)
  {
    dueTime += (2 * 3600);
  }
  else if (newListItemDueTime == DUE_TIME_4PM)
  {
    dueTime += (3 * 3600);
  }
  else if (newListItemDueTime == DUE_TIME_5PM)
  {
    dueTime += (4 * 3600);
  }
  strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", localtime(&dueTime));
  Serial.print("Time Due: ");
  Serial.print((uint64_t)dueTime);
  Serial.print("\n");
  Serial.print(buf);
  Serial.print("\n\n");
  // Now actually add the item to our task list.
  // 1st parameter is the item name.
  // 2nd parameter is the creation time (current time).
  // 3rd parameter is the due time.
  myTaskList.addNewItem(itemName, (uint64_t)creationTime, (uint64_t)dueTime);
}

void handleReOrderItem()
{
  // Make sure to update the timeAtLastRequest to show that
  // the website is still active!
  timeAtLastRequest = millis();
  // This character array stores the name of the list item that
  // we are currently reordering.
  char inputStr[128] = { '\0' };
  // The current argument number. (TODO: condense itemIter and argNum).
  int argNum = 0;
  int itemIdx;
  uint8_t itemIter = 1;
  // Debug this information to the Serial monitor (in case it is connected).
  Serial.print("List has been reorderd.\n");
  Serial.print("(Old List Item Number) --> (New List Item Number)\n");
  // This loop breaks when the GET request URL has no more arguments
  // (when we have reached the end of the list).
  while (1)
  {
    // Get the name of the
    server.arg(argNum++).toCharArray(inputStr, 128);
    if (strcmp("", inputStr) == 0)
    {
      break;
    }
    //
    itemIdx = myTaskList.findItemByItemName(inputStr);
    if (itemIdx == -1)
    {
      continue;
    }
    // Show the Serial monitor the changes that took effect.
    Serial.print(myTaskList.listItems[itemIdx].itemNumber);
    Serial.print(" --> ");
    Serial.print(itemIter);
    Serial.print("\n");
    // Perform the reordering.
    myTaskList.listItems[itemIdx].itemNumber = itemIter++;
  }
}

void handleRemoveItem()
{
  // Make sure to update the timeAtLastRequest to show that
  // the website is still active!
  timeAtLastRequest = millis();
  char inputStr[128] = { '\0' };
  server.arg("itemName").toCharArray(inputStr, 128);
  if (strcmp("", inputStr) == 0)
  {
    return;
  }
  int itemIdx = myTaskList.findItemByItemName(inputStr);
  // Check for a valid item index.
  if (itemIdx == -1)
  {
    // Show the Serial monitor that this was a 
    // duplicate request.
    Serial.print("List item to be removed does not exist!\n");
    return;
  }
  // Show the Serial monitor which item was removed.
  Serial.print("List item: ");
  Serial.print(myTaskList.listItems[itemIdx].itemNumber);
  Serial.print(" (index ");
  Serial.print(itemIdx);
  Serial.print(" in array) has been removed.\n");
  // Perform the removal.
  myTaskList.removeItem(myTaskList.listItems[itemIdx].itemNumber);
  // Condense the list item numbers to avoid an empty list bug.
  myTaskList.condenseItemNumbers();
}

void handleFinishedItem()
{
  // Make sure to update the timeAtLastRequest to show that
  // the website is still active!
  timeAtLastRequest = millis();
  // Get the webpage time.
  char inputStr[128] = { '\0' };
  server.arg("time").toCharArray(inputStr, 128);
  // Update the time variables to match the website time.
  millisAtTimeSync = millis();
  epochAtTimeSync = atoll(inputStr);
  // Update the variable which stores if the website has been connected in
  // the last power cycle.
  timeSyncedSincePowerOn = true;
  // We need to send back to the server if the last item was completed
  //  or not. We also need to send back the streak counter for today!
  // How much data do we need in the buffer?
  //         23  for "http://www.j.com/t.html"
  //         10  for "?finished=".
  //          5  for "true" / "false" / "dne".
  //         15  for "&streakCounter=".
  //         10  for the streak number (in ASCII).
  //          9  for "&dueTime="
  //          2  for "13" (global due time in 24-hour format)
  // Total:  74  bytes (round up for safety).
  char dataToSend[80] = { '\0' };
  strcat(dataToSend, "http://www.j.com/t.html?finished=");
  // Find the first item in the list.
  int itemIdx = myTaskList.findItemByItemNumber(1);
  // If the item does not exist, just send a not applicable code
  // back to the server. It will be waiting for a response.
  if (itemIdx == -1)
  {
    strcat(dataToSend, "dne");
  }
  // Check if the item was completed, and send the appropriate
  // text to the webpage. At this point the list object is
  // confirmed to exist.
  else if (myTaskList.listItems[itemIdx].completed == true)
  {
    strcat(dataToSend, "true");
    // Now that the webpage and the ESP are synced, we can remove
    // this item from the list.
    myTaskList.removeItem(1);
    // Push all the list items up one (2-3-4-5... to 1-2-3-4...).
    myTaskList.condenseItemNumbers();
  }
  else
  {
    strcat(dataToSend, "false");
  }
  // Also add the streak counter to the argument list.
  strcat(dataToSend, "&streakCounter=");
  // Create a place to store the converted ASCII text.
  char buf[10];
  // Convert from int to char array.
  itoa(totalStreak, buf, 10);
  // Add this data to the end of the last argument.
  strcat(dataToSend, buf);
  // Also add the global due time to the argument list.
  strcat(dataToSend, "&dueTime=");
  // Convert from int to char array.
  itoa(newListItemDueTime, buf, 10);
  // Add this data to the end of the last argument.
  strcat(dataToSend, buf);
  // Send the entire data argument to the server. Either "true",
  // "false", or "dne", as well as the totalStreak variable so
  // we can update that parameter on the webpage at the same time.
  server.send(200, "text/plane", dataToSend);
}
