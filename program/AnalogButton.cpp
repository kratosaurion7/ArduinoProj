#include <Arduino.h>

#include "AnalogButton.h"


AnalogButton::AnalogButton(int analogPin, int targetValue, int neutralValue) : Button(0)
{
    this->_targetVal = targetValue;
    this->pin = analogPin;
    this->_neutralVal = neutralValue;

    this->state = RELEASED;
};


AnalogButton::~AnalogButton()
{
};

bool AnalogButton::ButtonIsUp()
{
    int analogValue = analogRead(this->pin);

    if (analogValue > this->_targetVal - PREC && analogValue < this->_targetVal + PREC)
    {
        return true;
    }

    return false;
};

bool AnalogButton::ButtonIsDown()
{
    int analogValue = analogRead(this->pin);

    if (analogValue > this->_neutralVal - PREC && analogValue < this->_neutralVal + PREC)
    {
        return true;
    }

    return false;
};