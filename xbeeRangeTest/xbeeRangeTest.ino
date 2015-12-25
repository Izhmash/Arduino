#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int cnt;
char data;

void setup() 
{
  Serial1.begin(9600);
  lcd.begin(16, 2);
  cnt = 0;
  data = 0;
  lcd.clear();
}

void loop() 
{
  lcd.clear();
  lcd.print(cnt);
  Serial1.write('d');
  while (Serial1.read() != 'A'); //wait for resp.
  ++cnt;    //resp. rx'd
  //Serial1.write('f');
  delay(1000);
}
