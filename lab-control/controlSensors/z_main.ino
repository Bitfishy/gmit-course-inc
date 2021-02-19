//#define PIN_LED1 8
#define PIN_ID A1

/*
 *  BLINKER CLASS VARIABLES DECLARATION
 */
//Blinker blink1 = Blinker(PIN_LED1, 500, 500);
depthSensor testDepthSensor = depthSensor (Pin_ID,500);

void setup() {
   Serial.begin(9600);
}

void loop() {
 // blink1.check();
  
  Serial.println(voltage);
  Serial.print(" ");
}