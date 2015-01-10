#ifndef BUTTON_H
#define BUTTON_H

enum BUTTON_STATE{
  CLICKED,
  RELEASED
};

class Button{
 
  public:
    BUTTON_STATE state;
    
    /*Button();*/
    Button(int pinNumber);
    ~Button();

    bool ButtonRepeat;

    virtual void SetUpdateFunc(void (*func)());
    
    virtual void Update();
    
  protected:
    int pin;

    void(*_updateAction)();

};

#endif
