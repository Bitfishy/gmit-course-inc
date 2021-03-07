//#define 

class servoActuator {
  private:
    byte pinID;
    unsigned long timeOn;

  public:

    servoActuator(byte pinVal,unsigned long interval) {
      this->pinID = pinVal;
      this->timeOn = interval;
      pinMode(pinID, OUTPUT);
    }

    void setAngle(int angle){
     //Set values

     }
 };
