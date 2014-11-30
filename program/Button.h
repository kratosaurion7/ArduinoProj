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
