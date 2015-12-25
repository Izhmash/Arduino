#include <Servo.h>

#define LED_PIN 11
Servo SERVO;
int servoPos;
void setup()
{ 
  SERVO.attach(9);
  pinMode(LED_PIN,OUTPUT);
}
void loop()
{
  for(int i = 0; i < 255; i++)
  {
    servoPos = map(i,0,255,40,140);
    analogWrite(LED_PIN,i);
    SERVO.write(servoPos);
    delay(5);  
  }

  for(int k = 255; k > 0; k--)
  {
    servoPos = map(k,0,255,40,140);
    analogWrite(LED_PIN,k);
    SERVO.write(servoPos);
    delay(5);  
  }

}


