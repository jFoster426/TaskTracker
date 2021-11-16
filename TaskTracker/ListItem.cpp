#include "ListItem.h"

ListItem::ListItem()
{
  // Initialize all the data to 0.
  itemNumber = 0;
  for (int i = 0; i < 128; i++)
  {
    itemName[i] = '\0';
  }
  for (int i = 0; i < 8; i++)
  {
    creationTimeRaw[i] = 0;
    dueTimeRaw[i] = 0;
  }
  for (int i = 0; i < 2; i++)
  {
    pointScoreRaw[i] = 0;
  }
  creationTime = 0;
  dueTime = 0;
}
