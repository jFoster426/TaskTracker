#ifndef HandleLED_h
#define HandleLED_h

#include "ShiftRegister.h"

// Control the four LEDs connected to the shift register,
// as well as the fifth LED connected to IO15.
const int LED1_PIN = 15;
const int LED2_BIT = 0;
const int LED3_BIT = 1;
const int LED4_BIT = 2;
const int LED5_BIT = 3;

extern ShiftRegister sr;

void handleUpdateLED(uint8_t ledValue);

#endif
