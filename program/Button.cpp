#include "Button.h"

#include <Arduino.h>

//Button::Button()
//{
//    this->pin = 0;
//    this->_updateAction = NULL;
//};

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
  int currentState = digitalRead(pin);
  
  if(this->state == RELEASED)
  {
    if(currentState == 1)
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
    if(currentState == 0)
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

void Button::SetUpdateFunc(void(*func)())
{
    this->_updateAction = func;
};
