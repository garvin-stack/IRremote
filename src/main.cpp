#include <Arduino.h>
#include <IRremote.h>

//receiver
void decoder(){
  if(IrReceiver.decode()){
      if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
        // We have an unknown protocol here, print extended info
        IrReceiver.printIRResultRawFormatted(&Serial, true);            
        IrReceiver.resume(); // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
      } 
      else {
        IrReceiver.resume(); // Early enable receiving of the next IR frame
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.printIRSendUsage(&Serial);
      }
  }
}

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(26, ENABLE_LED_FEEDBACK);
  IrSender.begin(33);
  pinMode(14, INPUT);
}

void loop() {
  int x = digitalRead(14);
  if(x != 0){
    //Power
    IrSender.sendSamsung(0x7, 0x2, 1);
  }
  //Vol Up
  //IrSender.sendSamsung(0x7, 0x7, <numberOfRepeats>);
  //Vol Down
  //IrSender.sendSamsung(0x7, 0xB, <numberOfRepeats>);
  //Mute
  //IrSender.sendSamsung(0x7, 0xF, <numberOfRepeats>);
  decoder();
}
