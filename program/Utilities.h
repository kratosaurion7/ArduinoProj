#ifndef UTILITIES_H
#define UTILITIES_H

#include <Arduino.h>

#include <EEPROM.h>


char* ReadEEPROM(int chars, int startIndex);
void WriteEEPROM(char* chars, int count);
void ClearEEPROM(int characters, int startIndex);

#endif
