#define PIN_LED1 8 // pin that LED is attached to
#define pinID A0 // ananlog pin that the depth sensor is attached to
//#define PIN_SERVO 10  // pin that servo motor is attached to


/*
 BLINKER CLASS VARIABLES DECLARATION
  DEPTHSENSOR CLASS VARIABLES DECLARATION
 */
  Blinker blink1 = Blinker(PIN_LED1, 1000, 2000);
 depthSensor testDepthSensor = depthSensor(pinID, 500); // Calls function with two arguments:
// servoActuator testservo(PIN_SERVO, 50);


void setup() { // Calls setup function:
   Serial.begin(9600); // Open the serial port at 9600bps:
} 

void loop() { // Calls loop function:

  blink1.check();
  testDepthSensor.check(); //Function to test depth sensor:
  
   Serial.println(testDepthSensor.getValue());   //Command to print distance readings
  Serial.print(" ");

 // testservo.setAngle(testDepthSensor.getDepth()); // Distance readings placed inside function to control servo
}