int PWM_Pin1 = 3;   /*-bottom right*/
int PWM_Pin2 = 9;   /*bottom left*/
int PWM_Pin3 = 10;  /*top left*/
int PWM_Pin4= 11;   /* top right*/

const int ledPin = 22;
const int ledPin2 = 23;
const int ledPin3 = 24;

void setup()
{
pinMode(PWM_Pin1,OUTPUT);  /*declare D3 pin as an output pin */ 
pinMode(PWM_Pin2,OUTPUT);  /*declare D3 pin as an output pin */ 
pinMode(PWM_Pin3,OUTPUT);  /*declare D3 pin as an output pin */ 
pinMode(PWM_Pin4,OUTPUT);  /*declare D3 pin as an output pin */ 

}
// loop() executes continously 
void loop()
{
       digitalWrite(ledPin, HIGH);
       digitalWrite(ledPin2, LOW);
       digitalWrite(ledPin3, HIGH);
  for(int x = 0; x < 000; x++)
  {
      delayMicroseconds(1000);      // pauses for 50 microseconds
  }

  for(int m = 1; m < 255; m++)
  {
     analogWrite(PWM_Pin1, m);
     //analogWrite(PWM_Pin2, m);
     //analogWrite(PWM_Pin3, m);
     //analogWrite(PWM_Pin4, m);
      for(int y =0; y <10; y++)
      {
        delayMicroseconds(1000);      // pauses for 50 microseconds
      }
  }
        for(int y =0; y < 50000; y++)
      {
        delayMicroseconds(1000);      // pauses for 50 microseconds
      }
  analogWrite(PWM_Pin1, 0);
  analogWrite(PWM_Pin2, 0);
  analogWrite(PWM_Pin3, 0);
  analogWrite(PWM_Pin4, 0);

  for(int i =0; i < 2000; i++)
  {
      delayMicroseconds(1000);      // pauses for 50 microseconds
  }
}
