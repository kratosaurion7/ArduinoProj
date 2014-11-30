#include <EEPROM.h>
#include "Utilities.h"

#include "Button.h"



char message[] = "Hello EEPROM";

int btn1_pin = 4;
int btn2_pin = 2;

//BUTTON_STATE previousState = RELEASED;

Button *btnOne;
Button *btnTwo;


void setup() {
 
  pinMode(btn1_pin, INPUT);
  pinMode(btn2_pin, INPUT);
  
  btnOne = new Button(btn1_pin);
  btnTwo = new Button(btn2_pin);
  
  Serial.begin(9600);
}

void loop() {
  btnOne->Update();
  btnTwo->Update();
  
//  int currentState = digitalRead(inputPin);
//  
//  if(previousState == RELEASED)
//  {
//    if(currentState == 1)
//    {
//      Serial.println("Clicked");
//      previousState = CLICKED;
//    }
//  }else {
//    if(currentState == 0)
//    {
//      Serial.println("Released");
//      previousState = RELEASED;
//    }
//    
//  }
  
  delay(50);
  
}
