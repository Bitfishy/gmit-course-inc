#define PinA 6
#define PinB 7
#define PinC 8
#define PinD 9
#define NUMBER_OF_STEPS_PER_REV 512


//Example function to write logic to pins
void writePINS(int a,int b,int c,int d){
  digitalWrite(PinA,a);
  digitalWrite(PinB,b);
  digitalWrite(PinC,c);
  digitalWrite(PinD,d);
}

void oneStepCW(int delayValue){
  writePINS(1,0,0,0);
  delay(delayValue);
  writePINS(1,1,0,0);
  delay(delayValue);
  writePINS(0,1,0,0);
  delay(delayValue);
  writePINS(0,1,1,0);
  delay(delayValue);
  writePINS(0,0,1,0);
  delay(delayValue);
  writePINS(0,0,1,1);
  delay(delayValue);
  writePINS(0,0,0,1);
  delay(delayValue);
  writePINS(1,0,0,1);
  delay(delayValue);
}

//Example function to write logic to pins
void reversePINS(int a,int b,int c,int d){
  digitalWrite(PinA,a);
  digitalWrite(PinB,b);
  digitalWrite(PinC,c);
  digitalWrite(PinD,d);
}

void oneStepCCW(int delayValue){
  reversePINS(1,0,0,0);
  delay(delayValue);
  reversePINS(1,1,0,0);
  delay(delayValue);
  reversePINS(0,1,0,0);
  delay(delayValue);
  reversePINS(0,1,1,0);
  delay(delayValue);
  writePINS(0,0,1,0);
  delay(delayValue);
  reversePINS(0,0,1,1);
  delay(delayValue);
  reversePINS(0,0,0,1);
  delay(delayValue);
  reversePINS(1,0,0,1);
  delay(delayValue);
}
