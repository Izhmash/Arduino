#include <LCD.h>
LCD lcd(11,13,12);            //Defining pins

void setup()
{
  lcd.Init2();			//2 Line display
  
  
}
void loop()
{
  lcd.Cmd(CLS);
  delay(10);
  lcd.Msg("Hello there");
  lcd.Cmd(LINE2);
  lcd.Msg("How are you?");  
}
