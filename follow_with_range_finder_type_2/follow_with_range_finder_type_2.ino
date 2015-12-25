#include <GP2D02.h>;


int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B

int vIn[] = {40,36};
int vOut[] = {38,34};   
int nSensors = 2;
nGP2D02 sensors(vIn,vOut,nSensors);

void setup()
{
    pinMode(pinI1,OUTPUT);
    pinMode(pinI2,OUTPUT);
    pinMode(speedpinA,OUTPUT);
    pinMode(pinI3,OUTPUT);
    pinMode(pinI4,OUTPUT);
    pinMode(speedpinB,OUTPUT);
    Serial.begin(9600);
};

void loop()
{
    byte ranges[nSensors];
  
    byte leftSensor = 0;
    byte rightSensor = 0;
  
    sensors.getRawRanges(&ranges[0]);
  
    //leftSensor = ranges[1];
    //rightSensor = ranges[0];
    
    for(int j = 0; j < 128; j++)
    {
        leftSensor += ranges[1];
        rightSensor += ranges[0]; 
    }
   
    //leftSensor = (leftSensor / 128) + 25;fuh
    leftSensor /= 128;
    rightSensor /= 128; 
    
    analogWrite(speedpinA,(int)rightSensor);//input a simulation value to set the speed
    analogWrite(speedpinB,(int)leftSensor);
    digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
    digitalWrite(pinI3,LOW);
    digitalWrite(pinI2,LOW);//turn DC Motor A move anticlockwise
    digitalWrite(pinI1,HIGH);
    delay(100);
};
    
    
