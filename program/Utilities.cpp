#include "Utilities.h"

char* ReadEEPROM(int chars, int startIndex)
{
  char buf[chars];

  int i;
  for(i = startIndex;i < chars;i++)
  {
    buf[i] = EEPROM.read(i);
  }
  
  return buf;
}

void WriteEEPROM(char* chars, int count)
{
  if(count == 0)
    return;
  
  int i;
  for(i = 0;i < count;i++)
  {
    Serial.print(chars[i]);
    EEPROM.write(i, chars[i]);
  }
}

void ClearEEPROM(int characters, int startIndex)
{
  int i;
  for(i = startIndex;i < characters;i++)
  {
    EEPROM.write(i, (char)255);
  }
}
