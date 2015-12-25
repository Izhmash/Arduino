#include <Servo.h>
 Servo servo1;
 int pos=0;
 int buttonPin = 12;
 int buttonPin2=11;
 int ledPin = 13;
  
void setup() 
{
 pinMode(buttonPin, INPUT_PULLUP);
 pinMode(buttonPin2, INPUT_PULLUP);
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
 servo1.attach (1);
}

void loop() 
{
  int buttonVal= digitalRead (buttonPin);
  Serial.println(buttonVal);
  if(buttonVal == LOW)
  {
    servo1.writeMicroseconds(1510);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    servo1.writeMicroseconds(1300);
    delay(1000);
  //servo1.write(90);
  //delay(15);
  }
  //else
  //{
   //servo1.writeMicroseconds(1510); 
   //delay(2000);
   //servo1.write(0); 
   //delay(15);
  //}
}
