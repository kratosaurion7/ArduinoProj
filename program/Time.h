#include <Arduino.h>

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
unsigned long deltaMillis = 0;

void UpdateTime()
{
    previousMillis = currentMillis;
    currentMillis = millis();
    deltaMillis += currentMillis - previousMillis;
};