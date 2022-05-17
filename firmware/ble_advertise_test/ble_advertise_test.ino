#include <ArduinoBLE.h>

const int ledPin = 22;
const int ledPin2 = 23;
const int ledPin3 = 24;

void setup() {
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  while(!BLE.begin()) 
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    for(int x = 0; x < 1000; x++)
    {
      delayMicroseconds(1000);      // pauses for 50 microseconds
    }
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    for(int x = 0; x < 1000; x++)
    {
      delayMicroseconds(1000);      // pauses for 50 microseconds
    }
  }
  //Serial.println("starting Bluetooth® Low Energy module");
  BLE.setLocalName("drone"); 
  BLE.advertise();
}

void loop() {
  // put your main code here, to run repeatedly:

}
