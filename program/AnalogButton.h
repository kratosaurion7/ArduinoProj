#pragma once

#include "Button.h"

#define PREC 2

class AnalogButton : public Button
{
public:
    AnalogButton(int analogPin, int targetValue, int neutralValue);
    ~AnalogButton();

private:
    bool ButtonIsUp();

    bool ButtonIsDown();

    int _targetVal;

    int _neutralVal;
};

