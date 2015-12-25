#include <UTFT.h>

extern uint8_t SmallFont[];

UTFT myGLCD(SSD1289,38,39,40,41);

//green max = 83
void setup()
{
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  analogWrite(9, 255);
  randomSeed(analogRead(A0));
  myGLCD.setColor(255, 83, 255);
}

void loop()
{
  myGLCD.clrScr();

  for (int i = 0; i < 255; i++) {
    //for (int j = 0; j < 255; j++) {
      //for (int k = 0; k < 255; k++) {
        //myGLCD.fillScr(0, i, 0);
        //delay(10);
        myGLCD.fillRect(150, 100, i, 239);
        //myGLCD.printNumI((long)i, 100, 100);
      //}  
    //}
  }
  //myGLCD.fillScr(random(255), random(255), random(255));
  //myGLCD.fillScr(255, 0, 0);
  //delay(1000);
  //myGLCD.setColor(255, 83, 255);
  //myGLCD.fillRect(150, 100, 200, 239);
  //delay(1000);
  //myGLCD.fillScr(255, 0, 25);
  //delay(1000);
}

