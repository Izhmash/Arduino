#include <NewPing.h>
#include <YD_MotorDriver1.h>

#define  Motor1A  2   // Motor pins to Driver board
#define  Motor1B  4
#define  Motor2A  7
#define  Motor2B  8

#define TRIGGER_PIN  5  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 //Max ping distance

YD_MotorDriver1 RobotDriver(Motor1A,Motor1B,Motor2A,Motor2B);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

unsigned int uS; //For holding the ping time in microseconds
int distance;  //For holding the distance calculation

void setup()
{
  RobotDriver.init();
  Serial.begin(9600);  //Initializing the serial port
}

void loop()
{
  uS = sonar.ping();    //storing the ping time in uS
  distance = uS / US_ROUNDTRIP_CM;    //calculating the distance 
  Serial.println(distance);
  
  RobotDriver.Motor1Speed(-300);  //forward
  RobotDriver.Motor2Speed(-300);
  if(distance < 10 && distance > 0)
  {
     RobotDriver.Motor1Speed(300);  //reverse
     RobotDriver.Motor2Speed(300);
     delay(1000);
     RobotDriver.Motor1Speed(300);  //turn
     RobotDriver.Motor2Speed(-300);
     delay(1000);
  }
}


