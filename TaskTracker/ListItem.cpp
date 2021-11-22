#include "ListItem.h"

ListItem::ListItem()
{
  // Simply initialize all the data to 0.
  // However, initialize itemNumber to 255 to 
  // signify an empty list item.
  itemNumber = 255;
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
  completed = false;
}
