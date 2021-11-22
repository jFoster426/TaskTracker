#include "handleLED.h"

void handleUpdateLED(uint8_t ledValue)
{
  if (ledValue & 0b00001)
  {
    digitalWrite(LED1_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED1_PIN, LOW);
  }
  if (ledValue & 0b00010)
  {
    sr.setBit(LED2_BIT);
  }
  else
  {
    sr.clrBit(LED2_BIT);
  }
  if (ledValue & 0b00100)
  {
    sr.setBit(LED3_BIT);
  }
  else
  {
    sr.clrBit(LED3_BIT);
  }
  if (ledValue & 0b01000)
  {
    sr.setBit(LED4_BIT);
  }
  else
  {
    sr.clrBit(LED4_BIT);
  }
  if (ledValue & 0b10000)
  {
    sr.setBit(LED5_BIT);
  }
  else
  {
    sr.clrBit(LED5_BIT);
  }
}
