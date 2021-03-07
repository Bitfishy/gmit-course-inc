#include <Servo.h>

  // servoMotor Class:
  class servoActuator{

  private:
    byte pinServo;
    unsigned long timeOn;  // declaration for time on variable:
   // int angleVal;          // variable for angle value:
    
  public:
    // Constructor to input private variables into public
      servoActuator(byte pinVal,unsigned long interval){
      this->pinServo = pinVal;
      this->timeOn = interval;
      pinMode(pinServo, OUTPUT);
    }

      Servo servoMotor;   // creates servo motor object:

     // Function to call angle
     void setAngle (int angle){

      servoMotor.attach(pinServo);             // attaches the servo motor variable to pin(11):
      int angleVal = analogRead(A1);           // analogRead transfers data to angleVal variable:
      angle = map(angleVal, 0, 1023, 0, 255);  /* map function with 5 arguments: (map angleVal varriable, fromLow: the lower bound of the value's current range, 
                                                  fromHigh: the upper bound of the value's current range, toLow: the lower bound of the value's target range, 
                                                  toHigh: the higher bound of the value's target range)
                                                  My servo motors upper bound value in this case is 255, which is equal to 180 degrees. */
      servoMotor.write(angle);                 // write function/angle setting:
      delay(timeOn);                           // delay function/interval:
    }
    
    };

     
