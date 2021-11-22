#include "StateMachine.h"

const char settingsMenuItems[][17] =
{
  "LCD Backlight",
  "Set 12/24h Time",
  "Set Due Time",
  "Set WiFi AP Mode",
  "Exit Settings",
  // The "X" is not a setting, it just signifies to the code
  // that it is the end of the settings table.
  "X"
};

char currentSettings[][17] =
{
  "ON",
  "12-Hour Time",
  "5:00 PM",
  "WiFi Device Mode",
  // Exit Settings does not need a 2nd line.
  ""
};

int currentState = STATE_SHOW_TASK;
int menuState = 0;

int newListItemDueTime = DUE_TIME_5PM;

bool use24HourTime = false;

bool lcdBacklight = true;

void animate()
{
  for (int i = 0; i < 10; i++)
  {
    if (i % 2 == 0)
    {
      handleUpdateLED(0b10101);
    }
    else
    {
      handleUpdateLED(0b01010);
    }
    delay(200);
  }
  handleUpdateLED(0b00000);
  delay(1000);
}

void handleStateMachine()
{
  if (currentState == STATE_SHOW_TASK)
  {
    // Change to the settings menu when the rear button is pressed.
    if (rearButtonPressed == true)
    {
      currentState = STATE_SHOW_SETTINGS;
    }
    if (frontButtonPressed == true)
    {
      // This is the completed item state. Briefly show a congratulations
      // message and cool LED animation!
      // Find the 1st item in the task list.
      int completedItemIdx = myTaskList.findItemByItemNumber(1);
      // Check if this item exists. If it doesn't exist, then don't show
      // the animation!
      if (completedItemIdx != -1)
      {
        // Set the item in the task list to completed.
        // Note: The webpage will send a request that checks this parameter,
        // and once that happens, the list item will be removed.
        myTaskList.listItems[completedItemIdx].completed = true;
        // If we have a proper time sync (i.e. the website was connected at one point).
        if (timeSyncedSincePowerOn)
        {
          // Get the approximate system time based on the last sync with the website.
          uint64_t currentTime = ((millis() - millisAtTimeSync) / 1000) + epochAtTimeSync;
          // There are 86400 seconds in one day. Two days allows for a small
          // grace period.
          uint64_t streakLimiterN = currentTime - 2 * 86400;
          uint64_t streakLimiterP = currentTime - 1 * 86400;
          // If the last task completed was within the streak boundaries (i.e. the last task
          // was completed yesterday, not the day before, and not today), then increment the
          // total streak counter.
          if (timeLastTaskCompleted > streakLimiterN &&
              timeLastTaskCompleted < streakLimiterP)
          {
            // Add one to the total streak.
            totalStreak++;
            // Set the time the last task was completed to now.
            // Note: This needs to happen only when incrementing the streak counter, this is because
            // without it, we could complete tasks every day and still not have an increase in the
            // totalStreak. This is because the condition checking against streakLimiterP would be
            // failing because the last task that was completed was today, so the device thinks we
            // already incremented totalStreak for that day.
            timeLastTaskCompleted = currentTime;
            // Commit the data to memory.
            writeStreakDataToEEPROM();
          }
          // Check if the lower streak boundary has been exceeded, and if it has then we have
          // to (sadly) reset the streak counter to zero.
          if (timeLastTaskCompleted < streakLimiterN)
          {
            // Special case if the streak counter is zero we need to increment it,
            // no matter what.
            totalStreak = 1;
            // See above: only write to the time last completed if necessary.
            timeLastTaskCompleted = currentTime;
            // Commit the data to memory.
            writeStreakDataToEEPROM();
          }
          // If we completed before the due time, show the fun animation.
          if (currentTime < myTaskList.listItems[completedItemIdx].dueTime)
          {
            char line2[16] = { '\0' };
            char streakNum[5];
            itoa(totalStreak, streakNum, 10);
            strcat(line2, streakNum);
            strcat(line2, " day streak!");
            handleUpdateLCD("Task Completed!", line2);
            animate();
          }
        }
        // In this case, the website has not been connected ever, and we are working in
        // offline mode. Do not increment or reset the streak counter in this case.
        else
        {
          handleUpdateLCD("Task Completed!", "Offline Mode");
          animate();
        }
        // If the website is NOT connected, we have to remove the list item ourselves.
        if (currentlyConnected == false)
        {
          // Perform the removal.
          myTaskList.removeItem(myTaskList.listItems[completedItemIdx].itemNumber);
          // Shift all the list elements up one position.
          myTaskList.condenseItemNumbers();
          myTaskList.commitList();
        }
      }
    }
    else
    {
      // Consider this the "idle" state. We are just showing the first
      // task list that needs to be done.
      // Get the first item in the list.
      int index = myTaskList.findItemByItemNumber(1);
      // If there is actually an item in the list, the index will
      // not be -1.
      if (index != -1)
      {
        char displayItemName[128] = { '\0' };
        strcpy(displayItemName, myTaskList.listItems[index].itemName);
        char *displayItemNameScroller = &displayItemName[0];
        // TODO: Implement scrolling for long names!
        // TODO: Make this customizable!
        char dueTimeStr[17] = { '\0' };
        char buf[10] = { '\0' };
        time_t currentListItemDueTime = (time_t)myTaskList.listItems[index].dueTime;
        if (use24HourTime == true)
        {
          // Get the hour formatted in 24-hour time.
          strftime(buf, sizeof(buf), "%H", localtime(&currentListItemDueTime));
        }
        else
        {
          // Get the hour formatted in 12-hour time.
          strftime(buf, sizeof(buf), "%I", localtime(&currentListItemDueTime));
        }
        strcat(dueTimeStr, "Due at ");
        strcat(dueTimeStr, buf);
        strcat(dueTimeStr, ":00");
        // Append a " PM" to the string in 12-hour mode.
        if (use24HourTime == false)
        {
          strcat(dueTimeStr, " PM");
        }
        // TODO: strcat(dueTimeStr, "tmr, ");
        handleUpdateLCD(displayItemNameScroller, dueTimeStr);
      }
      else
      {
        // There is nothing in the task list!
        handleUpdateLCD("You have nothing", "in your list!");
      }
    }
  }
  else if (currentState == STATE_SHOW_SETTINGS)
  {
    // Update the LCD first to avoid glitching when leaving the
    // STATE_SHOW_SETTINGS state.
    handleUpdateLCD(settingsMenuItems[menuState], currentSettings[menuState]);
    if (frontButtonPressed == true)
    {
      // Handle changing the LCD backlight state.
      if (strcmp(settingsMenuItems[menuState], "LCD Backlight") == 0)
      {
        if (strcmp(currentSettings[menuState], "ON") == 0)
        {
          strcpy(currentSettings[menuState], "OFF");
          sr.clrBit(LCD_BKLT_BIT);
        }
        else if (strcmp(currentSettings[menuState], "OFF") == 0)
        {
          strcpy(currentSettings[menuState], "ON");
          sr.setBit(LCD_BKLT_BIT);
        }
      }
      // Handle changing the time format.
      if (strcmp(settingsMenuItems[menuState], "Set 12/24h Time") == 0)
      {
        if (strcmp(currentSettings[menuState], "12-Hour Time") == 0)
        {
          strcpy(currentSettings[menuState], "24-Hour Time");
          use24HourTime = true;
        }
        else if (strcmp(currentSettings[menuState], "24-Hour Time") == 0)
        {
          strcpy(currentSettings[menuState], "12-Hour Time");
          use24HourTime = false;
        }
      }
      // Handle changing the due times. Current options are 1:00 PM through 5:00 PM
      // in 1 hour increments.
      if (strcmp(settingsMenuItems[menuState], "Set Due Time") == 0)
      {
        if (strcmp(currentSettings[menuState], "1:00 PM") == 0)
        {
          strcpy(currentSettings[menuState], "2:00 PM");
          newListItemDueTime = DUE_TIME_2PM;
        }
        else if (strcmp(currentSettings[menuState], "2:00 PM") == 0)
        {
          strcpy(currentSettings[menuState], "3:00 PM");
          newListItemDueTime = DUE_TIME_3PM;
        }
        else if (strcmp(currentSettings[menuState], "3:00 PM") == 0)
        {
          strcpy(currentSettings[menuState], "4:00 PM");
          newListItemDueTime = DUE_TIME_4PM;
        }
        else if (strcmp(currentSettings[menuState], "4:00 PM") == 0)
        {
          strcpy(currentSettings[menuState], "5:00 PM");
          newListItemDueTime = DUE_TIME_5PM;
        }
        else if (strcmp(currentSettings[menuState], "5:00 PM") == 0)
        {
          strcpy(currentSettings[menuState], "1:00 PM");
          newListItemDueTime = DUE_TIME_1PM;
        }
      }
      // Handle changing WiFi modes.
      if (strcmp(settingsMenuItems[menuState], "Set WiFi AP Mode") == 0)
      {
        // Toggle the WiFi state.
        if (currentWiFiState == WIFI_DEV_MODE)
        {
          currentWiFiState = WIFI_AP_MODE;
          strcpy(currentSettings[menuState], "WiFi AP Mode");
        }
        else if (currentWiFiState == WIFI_AP_MODE)
        {
          currentWiFiState = WIFI_DEV_MODE;
          strcpy(currentSettings[menuState], "WiFi Device Mode");
        }
        restartWiFi = true;
      }
      // Exit the STATE_SHOW_SETTINGS state and back into the
      // STATE_SHOW_TASK state.
      if (strcmp(settingsMenuItems[menuState], "Exit Settings") == 0)
      {
        currentState = STATE_SHOW_TASK;
        menuState = 0;
      }
    }
    // Rear menu button increments the current setting.
    if (rearButtonPressed == true)
    {
      menuState++;
      // Have we reached the end of the settings menu?
      if (strcmp(settingsMenuItems[menuState], "X") == 0)
      {
        menuState = 0;
      }
    }
  }
}
