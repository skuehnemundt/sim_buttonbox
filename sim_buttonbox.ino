#include <ezButton.h>
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  9, 0,                  // Button Count, Hat Switch Count
  false, false, false,   // No X and Y, Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering


// const uint8_t hidReportId = 0x03
const bool testAutoSendMode = true;

/*
* 13 LED 
* 12 Zündschloss
* 11 Zündschloss 
* 8  Reset
* 7  Button
* 6  Button
* 5  Button
* 4  Button
* 3  Button
* 2  Button
* 1  Start Knopf 
*/
// create ezButton objects
ezButton toggleSwitch1(12);
ezButton toggleSwitch2(11);  
ezButton button1(8);  
ezButton button2(7);
ezButton button3(6);
ezButton button4(5);  
ezButton button5(4);  
ezButton button6(3);
ezButton button7(2);
ezButton button8(1);

const int DEBOUNCE_DELAY = 50; 

void setup() {
  Serial.begin(9600);
  
  toggleSwitch1.setDebounceTime(DEBOUNCE_DELAY);
  toggleSwitch2.setDebounceTime(DEBOUNCE_DELAY);
  
  button1.setDebounceTime(DEBOUNCE_DELAY);
  button2.setDebounceTime(DEBOUNCE_DELAY);
  button3.setDebounceTime(DEBOUNCE_DELAY);
  button4.setDebounceTime(DEBOUNCE_DELAY);
  button5.setDebounceTime(DEBOUNCE_DELAY);
  button6.setDebounceTime(DEBOUNCE_DELAY);
  button7.setDebounceTime(DEBOUNCE_DELAY);
  button8.setDebounceTime(DEBOUNCE_DELAY);
  
  pinMode(13, OUTPUT);

  Joystick.begin(); //Joystick.pressButton(byte button)
}

void loop() {
  //  MUST call the loop() function first
  
  toggleSwitch1.loop();
  toggleSwitch2.loop();
  
  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();
  button6.loop();
  button7.loop();
  button8.loop();


  

  if(button1.isPressed())
    {
    Serial.println("The button 1 is pressed");
    Joystick.pressButton(0);
    }

  if(button1.isReleased())
    {
    Serial.println("The button 1 is released");
    Joystick.releaseButton(0);
    }

  if(button2.isPressed())
    {
    Serial.println("The button 2 is pressed");
    Joystick.pressButton(1);
    }

  if(button2.isReleased())
    {
    Serial.println("The button 2 is released");
    Joystick.releaseButton(1);
    }
  if(button3.isPressed())
    {
    Serial.println("The button 3 is pressed");
    Joystick.pressButton(2);
    }

  if(button3.isReleased())
    {
    Serial.println("The button 3 is released");
    Joystick.releaseButton(2);
    }

  if(button4.isPressed())
    {
    Serial.println("The button 4 is pressed");
    Joystick.pressButton(3);
    }

  if(button4.isReleased())
    {
    Serial.println("The button 4 is released");
    Joystick.releaseButton(3);
    }

  if(button5.isPressed())
    {
    Serial.println("The button 5 is pressed");
    Joystick.pressButton(4);
    }

  if(button5.isReleased())
    {
    Serial.println("The button 5 is released");
    Joystick.releaseButton(4);
    }

  if(button6.isPressed())
    {
    Serial.println("The button 6 is pressed");
    Joystick.pressButton(5);
    }
  

  if(button6.isReleased())
    {
    Serial.println("The button 6 is released");
    Joystick.releaseButton(5);
    }
    
  if(button7.isPressed())
    {
    Serial.println("The button 7 is pressed");
    Joystick.pressButton(6);
    }

  if(button7.isReleased())
    {
    Serial.println("The button 7 is released");
    Joystick.releaseButton(6);
    }

  if(button8.isPressed())
    {
    Serial.println("The button 8 is pressed");
    Joystick.releaseButton(7);
    }

  if(button8.isReleased())
    {
    Serial.println("The button 8 is released");
    Joystick.pressButton(7);
    }

 
  //if (toggleSwitch1.isPressed())
    //Serial.println("The switch1: OFF -> ON");
  
 // if (toggleSwitch1.isReleased())
    //Serial.println("The switch1: ON -> OFF");

  //int state1 = toggleSwitch1.getState();
  //if (state1 == HIGH)
    //Serial.println("The switch1: OFF");
  //else
    //Serial.println("The switch1: ON");

  if (toggleSwitch2.isPressed())
    {
    Serial.println("The switch2: OFF -> ON");
    Joystick.pressButton(8);
    delay(500);
    Joystick.releaseButton(8);
    }

  if (toggleSwitch2.isReleased())
    {
      Serial.println("The switch2: ON -> OFF");
      Joystick.pressButton(8);
      delay(500);
      Joystick.releaseButton(8);
    }

  int state2 = toggleSwitch2.getState();
  
  if (state2 == HIGH) 
    { 
    digitalWrite(13, LOW);
    //Serial.println("The switch2: OFF");
    }
  else
    {
    //Serial.println("The switch2: ON");
    digitalWrite(13, HIGH);
    }
}
