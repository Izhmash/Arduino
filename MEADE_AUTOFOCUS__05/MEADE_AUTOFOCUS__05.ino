#include <Servo.h>
 Servo servo1;
 //int pos=0;
 int buttonPin = 7;
 int buttonPin2=5;
 int ledPin = 2;
  
void setup() 
{
 pinMode(buttonPin, INPUT_PULLUP);
 pinMode(buttonPin2, INPUT_PULLUP);
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
 servo1.attach (9);
     servo1.writeMicroseconds(1500);
 
}

void loop() 
{ 
  int buttonVal2= digitalRead (buttonPin2);
  Serial.println(buttonVal2);
  int buttonVal= digitalRead (buttonPin);
  Serial.println(buttonVal);
  //if(buttonVal== LOW && buttonVal2== LOW)
  //{
    //servo1.writeMicroseconds(1500);
    //delay(25);
  //}  
  if(buttonVal == LOW && buttonVal2 == HIGH)
  {
    servo1.writeMicroseconds(1300);
    delay(25);
    servo1.writeMicroseconds(1500);
    digitalWrite(ledPin, LOW);
  }
  if(buttonVal2 == LOW && buttonVal == HIGH)
  {
    
    digitalWrite(ledPin, HIGH);
    servo1.writeMicroseconds(1700);
    delay(25);
    servo1.writeMicroseconds(1500);
    digitalWrite(ledPin, LOW);
    
  }
 
}

