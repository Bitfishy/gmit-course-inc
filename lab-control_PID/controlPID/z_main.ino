

#define PIN_LED1 8    // pin that LED is attached to:
#define pinID A1      // ananlog pin that the depth sensor is attached to:
#define PIN_SERVO 11  // pin that servo motor is attached to:
#define PIN_RELAY 6

//PID constants
double kp = 2;
double ki = 5;
double kd = 1;
 
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input, output, setPoint;
double cumError, rateError;

  Blinker blink1 = Blinker(PIN_LED1, 1000, 2000);

  genericSensor sensor(A2, 200);
  relayModule relay(PIN_RELAY,200);
//  depthSensor testDepthSensor = depthSensor(pinID, 50);
//  servoActuator testservo(PIN_SERVO, 50);


void setup() { // Calls setup function:
   Serial.begin(9600); // open the serial port at 9600bps:
   setPoint = 0;
} 

void loop() { // calls loop function:
  unsigned long currentTime = millis();

  bool onOff = 1;
  blink1.check();
  sensor.intervalCheck(currentTime);

float sensorValue = sensor.getPinValue();

Serial.println(sensorValue);
Serial.print("");

relay.setRelay(currentTime,onOff);

double set = computePID(sensorValue,currentTime);

}

double computePID(double inp, unsigned long currentTime){     
        
        elapsedTime = (double)(currentTime - previousTime);        //compute time elapsed from previous computation
        
        error = setPoint - inp;                                // determine error
        cumError += error * elapsedTime;                // compute integral
        rateError = (error - lastError)/elapsedTime;   // compute derivative
 
        double out = kp*error + ki*cumError + kd*rateError;                //PID output               
 
        lastError = error;                                //remember current error
        previousTime = currentTime;                        //remember current time
 
        return out;       


//  testDepthSensor.check(); // function to test depth sensor:
  
//   Serial.println(testDepthSensor.getDepth());   // command to print distance readings:
 // Serial.print(" ");

//  testservo.setAngle(testDepthSensor.getDepth()); // function to test servo motor controlled with depth sensor.
}
