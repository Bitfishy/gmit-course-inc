/*
 * DepthSensor CLASS DEFINITION:
 */
class depthSensor {
  private:
    // Declare variable to read the input on analog pin 1:
    byte pinID;
    unsigned long timeOn;             // declaration for time on variable:
    unsigned long nextChangeTime = 0; // variable to reset time to 0:
    int val = 0;                      // variable to store the value read:
    float voltage = 0;                
    float distance = 0;


  public:
//Constructer: Function with two parameters:
    depthSensor(byte pinVal, unsigned long interval){
      //Declare pinVal as a parameter:
      this->pinID = pinVal;
       //Declare interval as a parameter:
      this->timeOn = interval;
      // Secound part of the depthSensor function but with variable argumenmts?
      pinMode(pinID, INPUT);
    }

    // Calculations:
    void check() {
      // Millis function, system clock: 
      unsigned long currentTime = millis();
      // If statement with conditions to utilise millis function:
      if(currentTime >= nextChangeTime) {
        val = analogRead(pinID);// read the input pin:
        // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
          voltage = val * (5.0 / 1023.0);
           // Converts the analog reading to cm:
          distance =  -22.19*voltage+57.66;
       // When the current time is equal to nextChangeTime then nextChangeTime becomes equal to currentTime on the next interval:
          nextChangeTime = currentTime + timeOn;
         
        }
    } 
     // Function to get voltage:
        float getValue(){
          return voltage;
        }
    // Function to get distance:
        float getDepth(){
         return distance;
       }
        
    };
