
/*
 * DepthSensor CLASS DEFINITION
 */
class depthSensor {
  private:
    byte PIN_ID;

    boolean ledState = LOW;

    //unsigned long timeLedOn;
    //unsigned long timeLedOff;

    unsigned long nextChangeTime = 0;
}
  public:
    DepthSensor(byte PIN_ID, unsigned long timeLedOn, unsigned long timeLedOff) {
      this->PIN_ID = PIN_ID;
    //  this->timeLedOn = timeLedOn;
    //  this->timeLedOff = timeLedOff;

      pinMode(PIN_ID, OUTPUT);
    }


// the loop routine runs over and over again forever:
void loop() {
    // read the input on analog pin 1:
   int sensorValue = analogRead(A1);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
   float voltage = sensorValue * (5.0 / 1023.0);
   // Converts the analog reading to cm:
   float distance = -22.19*voltage+57.66;
}

/*
    // Checks whether it is time to turn on or off the LED.
    void check() {
      unsigned long currentTime = millis();

      if(currentTime >= nextChangeTime) {

        if(ledState) {
          // LED is currently turned On. Turn Off LED.
          ledState = LOW;
          nextChangeTime = currentTime + timeLedOff;
        }
        else{
          // LED is currently turned Off. Turn On LED.
          ledState = HIGH;
          nextChangeTime = currentTime + timeLedOn;
        }

        digitalWrite(pinLED, ledState);
      }
    }
};

*/
