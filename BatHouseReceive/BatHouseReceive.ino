#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 1;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};

void setup() {
  Serial.begin(57600);
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  
  if (radioNumber) {
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  } else {
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
}

byte received = 0;
int bats = 0;
void loop() {
  radio.startListening();
  if (radio.available()) {
    radio.read(&received, sizeof(byte));
    //Serial.print(received);
    if (received == 1) {
      ++bats;
    } else {
      --bats;
    }
    Serial.print(received);
    Serial.print(" | ");
    Serial.println(bats);
  }
}
