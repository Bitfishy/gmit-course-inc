/*
  Generic analogReed sensor class
 NOTE: class is configured to pinMode(pinID, INPUT)
 */

 class genericSensor{
  private:
    byte pinID;
    unsigned long timeInterval;
    unsigned long nextChangeTime = 0;

    int pinValue = 0;
    float voltage = 0;

   public:
    genericSensor(byte pinVal, unsigned long interval){
      this->pinID = pinVal;
      this->timeInterval = interval;
      pinMode(pinID, INPUT);  
    }

    void intervalCheck(unsigned long currentTime){

      if (currentTime >= nextChangeTime){
        pinValue = analogRead(pinID);
        voltage = pinValue * (5.0/1023.0);
        nextChangeTime = currentTime + timeInterval;
      }
    }

    float getPinValue(){
      return pinValue;
    }

    float getVoltage(){
      return voltage;
    }
 };
