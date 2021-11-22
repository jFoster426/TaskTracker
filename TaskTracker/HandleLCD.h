#ifndef HandleLCD_h
#define HandleLCD_h

#include "Arduino.h"
#include <string.h>
#include "ShiftRegisterLCD.h"

extern ShiftRegisterLCD srLCD;

void handleUpdateLCD(const char *line1, const char *line2);

#endif
