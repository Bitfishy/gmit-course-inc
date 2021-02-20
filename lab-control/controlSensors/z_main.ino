#define PIN_LED1 8
#define pinID A1

/*
 BLINKER CLASS VARIABLES DECLARATION
  DEPTHSENSOR CLASS VARIABLES DECLARATION
 */
Blinker blink1 = Blinker(PIN_LED1, 1000, 2000);
depthSensor testDepthSensor = depthSensor (pinID, 50); // Calls function with two arguments:

void setup() { // Calls setup function:
   Serial.begin(9600); // Open the serial port at 9600bps:
}

void loop() { // Calls loop function:
   blink1.check();
  testDepthSensor.check(); // Function to test depth sensor:
  
  // Print out the value you read from the depth sensor:
  Serial.println(testDepthSensor.getValue());
  Serial.print(" ");
};