#define MIN_PULSE_WIDTH       550     // the shortest pulse sent to a servo  
#define MAX_PULSE_WIDTH      2250     // the longest pulse sent to a servo 
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define PULSE_TIMES            20
#define SERVO_PIN              11

void writeServo(int angle), writeServo(int pin, int angle);

void setup()
{
  pinMode(SERVO_PIN, OUTPUT);
}

void loop()
{ 
  writeServo(0);
  delay(2000);
  writeServo(180);
  delay(2000);
}

void writeServo(int angle)
{
    int pulseDuration = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    for(int i = 0; i < PULSE_TIMES; i++)  
    {
        digitalWrite(11,HIGH);
	delayMicroseconds(pulseDuration);
	digitalWrite(11,LOW);
	delay(20); 
    }
}

void writeServo(int pin, int angle)
{
    int pulseDuration = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    for(int i = 0; i < PULSE_TIMES; i++)  
    {
        digitalWrite(pin,HIGH);
	delayMicroseconds(pulseDuration);
	digitalWrite(pin,LOW);
	delay(20); 
    }
}


