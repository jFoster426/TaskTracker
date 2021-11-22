#include "HandleLCD.h"

char lcdLineBuf[2][17] = { '\0' };

void handleUpdateLCD(const char *line1, const char *line2)
{
  bool clearLCD = false;
  bool writeLCD = false;
  if (strcmp(line1, lcdLineBuf[0]) != 0)
  {
    if (sizeof(lcdLineBuf[0]) > sizeof(line1))
    {
      clearLCD = true;
    }
    strcpy(lcdLineBuf[0], line1);
    if (lcdLineBuf[0][17] != '\0') lcdLineBuf[0][17] = '\0';
    writeLCD = true;
  }
  if (strcmp(line2, lcdLineBuf[1]) != 0)
  {
    if (sizeof(lcdLineBuf[1]) > sizeof(line2))
    {
      clearLCD = true;
    }
    strcpy(lcdLineBuf[1], line2);
    if (lcdLineBuf[1][17] != '\0') lcdLineBuf[1][17] = '\0';
    writeLCD = true;
  }
  if (clearLCD == true)
  {
    srLCD.clear();
  }
  if (writeLCD == true)
  {
    srLCD.setCursor(0, 0);
    srLCD.print(lcdLineBuf[0]);
    srLCD.setCursor(0, 1);
    srLCD.print(lcdLineBuf[1]);
  }
}
