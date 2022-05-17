#include <ArduinoBLE.h>


const int ledPin = 22;

int incomingByte = 0;   // for incoming serial data

void setup() {
  
  Serial.begin(115200); //opens serial port, sets data rate to 115200 bps
  while(!Serial){}

   pinMode(ledPin,OUTPUT);  /*declare led pin as an output pin */ 
  digitalWrite(ledPin, LOW);

  for(int loop = 0; loop < 5; loop++)
  {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500); 
  }
    BLE.setLocalName("drone");
    BLE.advertise();

}

void loop() {
  if(Serial.available() > 0)
  {
      incomingByte = Serial.read();
      // say what you got:
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);        
  }
}
