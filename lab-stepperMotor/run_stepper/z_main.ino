#define PinA 6
#define PinB 7
#define PinC 8
#define PinD 9 
#define pinID A0 
#define NUMBER_OF_STEPS_PER_REV 512

void setup(){
  pinMode (PinA, OUTPUT);
  pinMode (PinB, OUTPUT);
  pinMode (PinC , OUTPUT);
  pinMode (PinD, OUTPUT);
}


void loop(){
  //oneStepCW(20);  

  int rawValue = analogRead(A0);
  int delayValue = map(rawValue, 0, 1023, 5, 100); 

   for ( int i = 0; i < 512; i++)
    oneStepCW(5);

   for ( int i = 0; i < 512; i++)
    oneStepCCW(5);
}
