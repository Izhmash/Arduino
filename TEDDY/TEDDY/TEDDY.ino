#include <Servo.h>

#define LED1 11
#define SPEAKER 3

#define LEFT false
#define RIGHT true

int delayAmnt;

Servo servo;
int servoPos;

boolean dir;

void setup()
{
  servo.attach(9);
  pinMode(LED1, OUTPUT);
  
  delayAmnt = 5;
}

void loop()
{
  if(delayAmnt < 1)
  {
    delayAmnt = 5;
    dir = !dir;
    //tone(3, 1);
    //delay(1500);
    //noTone(3);
    /*for(int i = 10; i < 150; i++)
    {
      tone(3, i);
      delay(4);
    }*/
    for(int j = 100; j > 50; j--)
    {
      tone(3, j);
      delay(50);
      servo.write(j + 30);
    }
    noTone(3);
  }
  else
    delayAmnt -= .95;
  
  for(int i = 0; i < 255; i++)
  {
    analogWrite(LED1, i);
    delay(delayAmnt);
   
  }
  
  for(int k = 255; k > 0; k--)
  {
    analogWrite(LED1, k);
    delay(delayAmnt);
  }
  
  if(dir)
    servoPos = 140;
  else
   servoPos = 30; 
  servo.write(servoPos);
  
  
}
