#include <LCD.h>
LCD lcd(11,13,12);
void setup()
{
  lcd.INIT2();
}
void loop()
{
  lcd.DAT('D');
  lcd.DAT('A');
  lcd.DAT('V');
  lcd.DAT('I');
  lcd.DAT('D');
  lcd.CMD(LINE2);
  delay(1000);
  lcd.DAT('S');
  lcd.DAT('T');
  lcd.DAT('.');
  lcd.DAT('P');
  lcd.DAT('I');
  lcd.DAT('E');
  lcd.DAT('R');
  lcd.DAT('R');
  lcd.DAT('E');
  lcd.CMD(CLS);
  delay(1000);
  
  
}

