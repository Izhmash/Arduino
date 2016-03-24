byte cnt;
char data;
void displayBinary(byte num);
int ledPin[] = {9, 10, 11};

void setup() 
{
  Serial.begin(115200);
  cnt = 0;
}

void loop() 
{
  Serial.write('d');
  while (Serial.read() != 'A'); //wait for resp.
  displayBinary(cnt);
  if (cnt > 6) {
    cnt = 0;
  }
  else {
    ++cnt;    //resp. rx'd
  }
  //Serial1.write('f');
}

void displayBinary(byte num)
{
  for (int i = 0; i < 3; ++i) {
    if (bitRead(num, i) == 1){
      digitalWrite(ledPin[i], HIGH);
    }
    else {
      digitalWrite(ledPin[i], LOW);
    }
  }
}

