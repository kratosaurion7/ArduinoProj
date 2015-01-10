#include <EEPROM.h>


#include "Button.h"
#include "AnalogButton.h"
#include "Time.h"

//#define BTN_DEBUG_OUTPUT

#define ANALOG_PIN A0
#define ANALOG_NEUTRAL 511

#define LED_R 8
#define LED_Y 9
#define LED_G 10

Button *btnOne;
Button *btnTwo;

void setup() {
 
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
  //
  //btnOne = new Button(btn1_pin);
  //btnTwo = new Button(btn2_pin);

  btnOne = new AnalogButton(ANALOG_PIN, 84, ANALOG_NEUTRAL);
  btnTwo = new AnalogButton(ANALOG_PIN, 798, ANALOG_NEUTRAL);

  btnOne->SetUpdateFunc(LightFunctionOne);
  btnTwo->SetUpdateFunc(LightFunctionTwo);
  
  btnOne->ButtonRepeat = true;

  Serial.begin(9600);
};

void loop() {
    UpdateTime();

    btnOne->Update();
    btnTwo->Update();
    
    return;

    //delay(200); // Global delay

    int v = CheckAnalogPin0();

    if (v >= 82 && v <= 85)
    {
        digitalWrite(LED_R, HIGH);

        delay(150);

        digitalWrite(LED_Y, HIGH);
        digitalWrite(LED_R, LOW);

        delay(150);

        digitalWrite(LED_Y, LOW);
        digitalWrite(LED_G, HIGH);

        delay(150);

        digitalWrite(LED_R, LOW);
        digitalWrite(LED_Y, LOW);
        digitalWrite(LED_G, LOW);

        delay(150);
    }

    if (v >= 798 && v <= 799)
    {
        digitalWrite(LED_R, HIGH);
        digitalWrite(LED_G, HIGH);

        delay(150);

        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);

        delay(150);

        digitalWrite(LED_R, HIGH);
        digitalWrite(LED_G, HIGH);

        delay(150);

        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);

        delay(150);

        digitalWrite(LED_Y, HIGH);

        delay(150);

        digitalWrite(LED_Y, LOW);

        delay(150); // Delay to wait
    }
};

void LightFunctionOne()
{
    digitalWrite(LED_R, HIGH);

    delay(150);

    digitalWrite(LED_Y, HIGH);
    digitalWrite(LED_R, LOW);

    delay(150);

    digitalWrite(LED_Y, LOW);
    digitalWrite(LED_G, HIGH);

    delay(150);

    digitalWrite(LED_R, LOW);
    digitalWrite(LED_Y, LOW);
    digitalWrite(LED_G, LOW);

    delay(150);
};

void LightFunctionTwo()
{
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);

    delay(150);

    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);

    delay(150);

    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);

    delay(150);

    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);

    delay(150);

    digitalWrite(LED_Y, HIGH);

    delay(150);

    digitalWrite(LED_Y, LOW);

    delay(150); // Delay to wait

}

int CheckAnalogPin0()
{
    int analogState = analogRead(ANALOG_PIN);

    if (deltaMillis > 1000)
    {
        char buf[25];

        sprintf(buf, "Analog signal is : [%d]", analogState);
        //sprintf(buf, "Time: %lu", deltaMillis);
        Serial.println(buf);
        deltaMillis = 0;
    }

    return analogState;
};