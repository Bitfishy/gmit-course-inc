/*
  Smoothing with the millis function
The delay function can blockother code from running but the millis function wont.
For example with
 the millis function you can still read a sensor or update a display. 
*/

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.

long timeNow=0; // Hold the milliseond value for now
long timer=0; //general purpuse timer

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() //Main Loop
 {
 timeNow = millis();//millis function
 if((timeNow-timer)>=1000) // Observe and change as required
 {
 timer = timeNow;
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
 Serial.println(timeNow);
 //CALL your function etc
 }
 }


 