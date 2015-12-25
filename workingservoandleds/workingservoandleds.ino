#include <Servo.h>
Servo myServo;        // Create Servo object to control the servo 

int ledonline = 7;
int ledforward = 5;
int ledreverse = 2;

void setup() { 
  myServo.attach(9);  // Servo is connected to digital pin 9 

  // initialize the digital pin as an output.
  pinMode(ledonline, OUTPUT);   
  pinMode(ledforward, OUTPUT); 
  pinMode(ledreverse, OUTPUT);
  
    delay(1000);   // wait for one second
       digitalWrite(ledonline, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000); // wait for two seconds
} 

void loop() {
 //fast 
  digitalWrite(ledforward, HIGH);   // turn the LED on (HIGH is the voltage level)
  myServo.writeMicroseconds(1300);  // Clockwise
  delay(2000);
    myServo.writeMicroseconds(1510);  // Stop
    digitalWrite(ledforward, LOW);  // turn the LED off by making the voltage LOW
    delay(2000); 
    
     //medium 
  digitalWrite(ledforward, HIGH);   // turn the LED on (HIGH is the voltage level)
  myServo.writeMicroseconds(1300);  // Clockwise
  delay(1000);
    myServo.writeMicroseconds(1510);  // Stop
    digitalWrite(ledforward, LOW);  // turn the LED off by making the voltage LOW
    delay(2000); 
    
         //slow 
  digitalWrite(ledforward, HIGH);   // turn the LED on (HIGH is the voltage level)
  myServo.writeMicroseconds(1300);  // Clockwise
  delay(500);
    myServo.writeMicroseconds(1510);  // Stop
    digitalWrite(ledforward, LOW);  // turn the LED off by making the voltage LOW
    delay(2000); 
    
    //micro
    
    digitalWrite(ledforward, HIGH);   // turn the LED on (HIGH is the voltage level)
  myServo.writeMicroseconds(1300);  // Clockwise
  delay(200);
    myServo.writeMicroseconds(1510);  // Stop
    digitalWrite(ledforward, LOW);  // turn the LED off by making the voltage LOW
    delay(2000); 
    
    
    digitalWrite(ledreverse, HIGH);   // servo forward turn on foward led
      myServo.writeMicroseconds(1700);  // counter-clockwise
  delay(2000);
  myServo.writeMicroseconds(1510);  // Stop
  digitalWrite(ledreverse, LOW);  // turn the LED off by making the voltage LOW
  delay(2000); 
  
       //medium 
  digitalWrite(ledreverse, HIGH);   // turn the LED on (HIGH is the voltage level)
  myServo.writeMicroseconds(1700);  // counter-clockwise
  delay(1000);
    myServo.writeMicroseconds(1510);  // Stop
    digitalWrite(ledreverse, LOW);  // turn the LED off by making the voltage LOW
    delay(2000); 
    
         //slow 
  digitalWrite(ledreverse, HIGH);   // turn the LED on (HIGH is the voltage level)
  myServo.writeMicroseconds(1700);  // couter-clockwise
  delay(500);
    myServo.writeMicroseconds(1510);  // Stop
    digitalWrite(ledreverse, LOW);  // turn the LED off by making the voltage LOW
    delay(2000); 
    
    //micro
    
    digitalWrite(ledreverse, HIGH);   // turn the LED on (HIGH is the voltage level)
  myServo.writeMicroseconds(1700);  // Clockwise
  delay(200);
    myServo.writeMicroseconds(1510);  // Stop
    digitalWrite(ledreverse, LOW);  // turn the LED off by making the voltage LOW
    delay(2000); 
  
  
}
