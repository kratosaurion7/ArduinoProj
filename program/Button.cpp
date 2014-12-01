#include "Button.h"

#include <Arduino.h>

Button::Button(int pinNumber)
{
  this->pin = pinNumber;
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
      char buf[15];
      sprintf(buf, "Clicked btn %d", pin);
      Serial.println(buf);
      this->state = CLICKED;
    }
  }else {
    if(currentState == 0)
    {
      char buf[15];
      sprintf(buf, "Released btn %d", pin);
      Serial.println(buf);
      this->state = RELEASED;
    }
  }
  
  
}
