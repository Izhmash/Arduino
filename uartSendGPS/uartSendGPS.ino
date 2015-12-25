#define BUFFSIZE  90
char data[BUFFSIZE];

void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(115200);
}

void loop() 
{
  /*int i;
  for (i = 0; i < BUFFSIZE; i++) {
    char c = Serial2.read();
    if (c == -1 || c == '\n') {
      continue;
    }
    if (c == '\r') {
      continue;
    }
    data[i] = c;
  }
  Serial.write(data);
  Serial.println();
  Serial1.write(data);
  delay(500);*/
  Serial1.write('D');
  delay(500);
}
