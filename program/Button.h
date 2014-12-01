#ifndef BUTTON_H
#define BUTTON_H

enum BUTTON_STATE{
  CLICKED,
  RELEASED
};

class Button{
 
  public:
    BUTTON_STATE state;
    
    Button(int pinNumber);
    ~Button();
    
    void Update();
    
  private:
    int pin;
};

#endif
