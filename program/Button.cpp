#include "Button.h"

#include <Arduino.h>

Button::Button(int pinNumber)
{
  this->pin = pinNumber;

  this->_updateAction = NULL;

  ButtonRepeat = false;
};

Button::~Button()
{
  
};

void Button::Update()
{
  if(this->state == RELEASED)
  {
    if(this->ButtonIsUp())
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
  }else {
    if(this->ButtonIsDown())
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

bool Button::ButtonIsUp()
{
    int buttonValue = digitalRead(pin);

    return buttonValue == HIGH;
};

bool Button::ButtonIsDown()
{
    return !ButtonIsUp();
}

void Button::SetUpdateFunc(void(*func)())
{
    this->_updateAction = func;
};
