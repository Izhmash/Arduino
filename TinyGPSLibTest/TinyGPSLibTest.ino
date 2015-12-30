#include <TinyGPS++.h>

static const int RXPin = 19, TXPin = 18;
static const uint32_t GPSBaud = 115200;

// The TinyGPS++ object
TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);
  Serial1.begin(GPSBaud);
}

void loop() {
   while (Serial1.available() > 0) {
     if (gps.encode(Serial1.read()))
       Serial.println(gps.location.lat());
   }
}
