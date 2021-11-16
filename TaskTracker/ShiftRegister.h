#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Arduino.h"
#include <stdint.h>

class ShiftRegister
{
  public:
    int srclr, srclk, rclk, oe, ser;

    uint16_t currentData;

    ShiftRegister();
    ShiftRegister(int srclrPin, int srclkPin, int rclkPin, int oePin, int serPin);

    void init(int srclrPin, int srclkPin, int rclkPin, int oePin, int serPin);

    void write(uint16_t data);

    void enableOutput();
    void disableOutput();
    void pulseLatch();

    void setBit(int b);
    void clrBit(int b);
    void writeBit(int b, int v);

    void clrData();
};

#endif
