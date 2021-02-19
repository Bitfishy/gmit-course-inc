  //setup function:
void setup(){
  // initialize serial communication at 9600 bits per second:
Serial.begin(9600);
}
  




// the loop routine runs over and over again forever:
void loop() {
    // read the input on analog pin 0:
   int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
   float voltage = sensorValue * (5.0 / 1023.0);
   // Converts the analog reading to cm:
   float distance = -22.19*voltage+57.66;

  // print out the value you read in this case distance (or change to voltage to see voltage):
  Serial.print("X,"); Serial.print(distance); Serial.print(" ");
  Serial.println(" ");
  //delay slows down the reading:
  delay (200);
}
