class relayModule{
  private:
   byte pinID;

   boolean ledState = LOW;

   unsigned long timeInterval;
   unsigned long nextChangeTime = 0;

  public:
   relayModule(byte pinTmp, unsigned long interval){
    pinID = pinTmp;
    timeInterval = interval;
    pinMode(pinID, OUTPUT); 
   }

   void setRelay(unsigned long currentTime, bool onOffSet){

    if(currentTime >= nextChangeTime){

      digitalWrite(pinID, onOffSet);
      nextChangeTime = currentTime + timeInterval;
    }
   }
 };
