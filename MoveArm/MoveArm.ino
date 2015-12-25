/*
Continuous Servo Movement by Ian Ballou
March  2015     V2.0
*/

#include <Servo.h> 

Servo servo1;
int servoPin = 9;  //change depending on the servo pin
byte servoSpeed;
byte servoSpeedReverse;
int moveTime;

int i;


void setup()
{
  //Serial.begin(9600);
  
  moveTime = 1800;   //change for a different time in miliseconds
  
  servoSpeed = 100;  //change for a different servo speed:
  servoSpeedReverse = 45;  //0 = full-speed one way, 180 = full speed
                     //another way, 90 = stop
  servo1.attach(servoPin);
  
  pinMode(8, INPUT);  //PIR pin input
  pinMode(7, INPUT);  //PIR pin input
  pinMode(6, INPUT);  //PIR pin input
  pinMode(5, INPUT);  //PIR pin input
  
  i = 0;
}

void loop()
{  
  while (digitalRead(8) == HIGH || digitalRead(7) == HIGH || 
    digitalRead(6) == HIGH) {
    i++;
    //Serial.println(i);
    servo1.write(0);
    delay(2700);
    servo1.write(90);
    delay(500);
    servo1.write(180);
    delay(2700);
    servo1.write(90);
    delay(500);
    if(i == 4) {
      software_Reset();
    } 
  }
}

void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
  asm volatile ("  jmp 0");  
}  

