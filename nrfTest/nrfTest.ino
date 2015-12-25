#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};

void setup() {
  Serial.begin(57600);
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  
  if (radioNumber) {
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  } else {
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
}

void loop() {
  unsigned long sent = 40;
  unsigned long received = 0;
  
  radio.stopListening();
  radio.write(&sent, sizeof(unsigned long));
  delay(1000);
  
  /*
  radio.startListening();
  if (radio.available()) {
    radio.read(&received, sizeof(unsigned long));
  }
  delay(1000);
  
  Serial.println(received);
  */
}
