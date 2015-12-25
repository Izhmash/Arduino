//#include <LiquidCrystal.h>
#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 1;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);
/**********************************************************/

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte addresses[][6] = {"1Node","2Node"};

void setup() 
{
  Serial.begin(9600);
  //lcd.begin(16, 2);
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

unsigned long received = 0;
char * msg;

//unsigned char * r;
void loop() 
{
  //lcd.setCursor(0, 1);
  radio.startListening();
  if (radio.available() > 0) {
    radio.read(&received, sizeof(unsigned long));
    Serial.println(received);
    //lcd.print(received);
  }
  //delay(100);
}
