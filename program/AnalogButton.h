#pragma once

#include "Button.h"

#define PREC 2

class AnalogButton : public Button
{
public:
    AnalogButton(int analogPin, int targetValue, int neutralValue);
    ~AnalogButton();

    void Update();

    

private:
    bool SignalWithinRange(int currentSignal);

    bool SignalIsNeutral(int currentSignal);

    int _targetVal;

    int _neutralVal;
};

