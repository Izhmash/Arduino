#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3); // RX, TX


void setup() {
  Serial.begin(9600);
  xbee.begin(9600);
}

void loop() {
  //Read
  while(xbee.available() > 0) {
    int xbeeInput = xbee.read();
    if(xbeeInput != -1) {
      Serial.write(xbeeInput);
    }
  }
    
  //Write
  while(Serial.available() > 0){
    int serialInput = Serial.read();
    if(serialInput != -1) {
      xbee.write(serialInput);
    }
  }
}
