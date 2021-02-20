
/*
 * DepthSensor CLASS DEFINITION:
 */
class depthSensor {
  private:
    // Declare variable to read the input on analog pin 1:
    byte pinID;

    unsigned long timeOn; // Declaration for time on variable :
    unsigned long nextChangeTime = 0; // variable to reset time to 0:
    int val = 0; // Variable to store the value read:
    float voltage = 10;
}

  public:
//Constructer: Function with two parameters:
    depthSensor(byte pinVal, unsigned long interval,) {
      //Declare pinVal as a parameter:
      this->pinID = pinVal;
       //Declare interval as a parameter:
      this->timeOn = interval;
      // Secound part of the depthSensor function but with variable argumenmts?
      pinMode(pinID, INPUT);
    }

    // Checks whether it is time to turn on depthSensor:
    void check() {
      // Millis function:
      unsigned long currentTime = millis();
      // If statement with conditions to utilise millis function:
      if(currentTime >= nextChangeTime) {
        // When the current time is equal to nextChangeTime then nextChangeTime becomes equal to currentTime on the next interval:
          nextChangeTime = currentTime + timeOn;
        }
    }
    // GetValue function:
     float getValue(){
       
       // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
       float voltage = pinVal * (5.0 / 1023.0);
       // Converts the analog reading to cm:
       float distance = -22.19*voltage+57.66;

};


