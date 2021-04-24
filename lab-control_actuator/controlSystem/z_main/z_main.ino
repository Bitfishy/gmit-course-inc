
#define PIN_LED1 8    // pin that LED is attached to:
#define pinID A1      // ananlog pin that the depth sensor is attached to:
#define PIN_SERVO 11  // pin that servo motor is attached to:


/*
 BLINKER CLASS VARIABLES DECLARATION
  DEPTHSENSOR CLASS VARIABLES DECLARATION
   SERVO MOTOR CLASS VARIABLES DECLARATION
 */
  Blinker blink1 = Blinker(PIN_LED1, 1000, 2000);
  depthSensor testDepthSensor = depthSensor(pinID, 50);
  servoActuator testservo(PIN_SERVO, 50);


void setup() { // Calls setup function:
   Serial.begin(9600); // open the serial port at 9600bps:
} 

void loop() { // calls loop function:

  blink1.check();
  testDepthSensor.check(); // function to test depth sensor:
  
   Serial.println(testDepthSensor.getDepth());   // command to print distance readings:
   Serial.print(" ");

  testservo.setAngle(testDepthSensor.getDepth()); // function to test servo motor controlled with depth sensor.
}
