#include "shiftRegister.h"

ShiftRegister::ShiftRegister()
{
}

ShiftRegister::ShiftRegister(int srclrPin, int srclkPin, int rclkPin, int oePin, int serPin)
{
  ShiftRegister::init(srclrPin, srclkPin, rclkPin, oePin, serPin);
}

void ShiftRegister::init(int srclrPin, int srclkPin, int rclkPin, int oePin, int serPin)
{
  srclr = srclrPin;
  srclk = srclkPin;
  rclk  = rclkPin;
  oe    = oePin;
  ser   = serPin;

  pinMode(srclr, OUTPUT);
  pinMode(srclk, OUTPUT);
  pinMode(rclk,  OUTPUT);
  pinMode(oe,    OUTPUT);
  pinMode(ser,   OUTPUT);

  ShiftRegister::disableOutput();
  ShiftRegister::clrData();
  ShiftRegister::pulseLatch();
  ShiftRegister::enableOutput();
}

void ShiftRegister::write(uint16_t data)
{
  shiftOut(ser, srclk, MSBFIRST, (data >> 8) & 0xff);
  shiftOut(ser, srclk, MSBFIRST, data & 0xff);
  ShiftRegister::pulseLatch();
  ShiftRegister::enableOutput();

  currentData = data;
}

void ShiftRegister::enableOutput()
{
  digitalWrite(oe, LOW);
}

void ShiftRegister::disableOutput()
{
  digitalWrite(oe, HIGH);
}

void ShiftRegister::pulseLatch()
{
  digitalWrite(rclk, HIGH);
  delay(1);
  digitalWrite(rclk, LOW);
}

void ShiftRegister::setBit(int b)
{
  uint16_t d = currentData | (1 << b);
  ShiftRegister::write(d);
}

void ShiftRegister::clrBit(int b)
{
  uint16_t d = currentData & ~(1 << b);
  ShiftRegister::write(d);
}

void ShiftRegister::writeBit(int b, int v)
{
  if (v) ShiftRegister::setBit(b);
  else   ShiftRegister::clrBit(b);
}

void ShiftRegister::clrData()
{
  digitalWrite(srclr, LOW);
  delay(1);
  digitalWrite(srclr, HIGH);

  currentData = 0x0000;
}
