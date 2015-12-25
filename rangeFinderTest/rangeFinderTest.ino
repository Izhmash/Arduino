#include <GP2D02.h>;

int vIn = 40;
int vOut = 38;  
GP2D02 sensor(vIn, vOut);
const int delayMs = 100;

void setup()
{
  //digitalWrite(51, HIGH);
  Serial.begin(9600);
};

void loop()
{
  int range = sensor.getRawRange();
  Serial.println(range);
  delay(delayMs);
};

