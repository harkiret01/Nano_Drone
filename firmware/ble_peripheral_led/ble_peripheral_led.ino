#include <ArduinoBLE.h>   //Include the arduino BLE library

/*Custom 128 bit service and characteristics*/
const char* deviceServiceUuid = "faa94135-6303-4274-a2ce-8fa28849ac9c";         
const char* deviceServiceCharacteristicUuid = "a6671089-7187-4a45-adee-6020212f014d";

BLEService motorService(deviceServiceUuid); 
BLEByteCharacteristic ledCharacteristic(deviceServiceCharacteristicUuid, BLERead | BLEWrite);

String command = "";

const int ledPin = 22;

void setup() {
  
  pinMode(ledPin,OUTPUT);  /*declare led pin as an output pin */ 
  digitalWrite(ledPin, LOW);

  Serial.begin(115200); //Initialize the serial interface
  while (!Serial);      //Wait until the interface is ready

    // begin initialization
  if (!BLE.begin()) 
  {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }
  
  // set advertised local name and service UUID:
  BLE.setLocalName("drone");
  BLE.setAdvertisedService(motorService);

  // add the characteristic to the service
  motorService.addCharacteristic(ledCharacteristic);

  // add service
  BLE.addService(motorService);

  // set the initial value for the characeristic:
  ledCharacteristic.writeValue(-1);

  // start advertising
  BLE.advertise();

  Serial.println("BLE drone Peripheral");
}

void loop() {
  BLEDevice central = BLE.central();
  Serial.println("- Discovering central device...");
  delay(500);

  if (central) {
    Serial.println("* Connected to central device!");
    Serial.print("* Device MAC address: ");
    Serial.println(central.address());
    Serial.println(" ");
    
    digitalWrite(ledPin, LOW);

    while (central.connected()) {
      if (Serial.available() > 0){
         Serial.print("data received");
         command = "";
         command = Serial.readString();
         if(command == "1")
         {
          for(int loop = 0; loop < 5; loop++){
            digitalWrite(ledPin, HIGH);
            delay(500);
            digitalWrite(ledPin, LOW);
            delay(500); 
          }
         }
       }
       else
       {
          digitalWrite(ledPin, LOW);
       }
    }
    
    Serial.println("* Disconnected to central device!");
  }
}
