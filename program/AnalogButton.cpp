#include "Arduino.h"

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

void AnalogButton::Update()
{
    int currentValue = analogRead(pin);

    if (this->state == RELEASED)
    {
        if (SignalWithinRange(currentValue))
        {
#if defined(BTN_DEBUG_OUTPUT)
            char buf[15];
            sprintf(buf, "Clicked btn %d", pin);
            Serial.println(buf);
#endif
            if (this->ButtonRepeat == false)
            {
                this->state = CLICKED;
            }

            if (this->_updateAction != NULL)
            {
                this->_updateAction();
            }
        }
    }
    else {
        if (this->SignalIsNeutral(currentValue)) // change to neutral
        {
#if  defined(BTN_DEBUG_OUTPUT)
            char buf[15];
            sprintf(buf, "Released btn %d", pin);
            Serial.println(buf);
#endif
            this->state = RELEASED;
        }
    }
};

bool AnalogButton::SignalWithinRange(int currentSignal)
{
    if (currentSignal > this->_targetVal - PREC && currentSignal < this->_targetVal + PREC)
    {
        return true;
    }

    return false;
};

bool AnalogButton::SignalIsNeutral(int currentSignal)
{
    if (currentSignal > this->_neutralVal - PREC && currentSignal < this->_neutralVal + PREC)
    {
        return true;
    }

    return false;
};