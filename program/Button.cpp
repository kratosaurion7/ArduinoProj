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
      Serial.println("Clicked");
      this->state = CLICKED;
    }
  }else {
    if(currentState == 0)
    {
      Serial.println("Released");
      this->state = RELEASED;
    }
  }
  
  
}
