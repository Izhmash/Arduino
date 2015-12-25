#include <GP2D02.h>;

int vIn[] = {40,36};
int vOut[] = {38,34};   
int nSensors = 2;
nGP2D02 sensors(vIn,vOut,nSensors);

void setup()
{
    Serial.begin(9600);
};

void loop()
{
    byte ranges[nSensors];
    sensors.getRawRanges(&ranges[0]);
    for (int i = 0; i < nSensors; i++) 
    {
        Serial.print(int(ranges[i]));
        Serial.print("\t");
    }
    Serial.println();
};
