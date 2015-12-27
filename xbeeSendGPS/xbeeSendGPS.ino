#define BUFFSIZE  140
char* data;

void readLine(void);

void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(115200);
  //data = new char[90]; 
}

void loop() 
{
  if(Serial1.available() > 0) {
    //Serial.println(Serial1.peek());
    if (Serial1.read() == 102) { //f
      //Serial.println("Rx");
      data = getGPSData();
      Serial1.println(data);
      Serial.println(data);
    }
  }
  //delay(1000);
}

char* getGPSData()
{
  char* d = new char[BUFFSIZE];
  for (int i = 0; i < BUFFSIZE; i++) {
    char c = Serial2.read();
    if (c == -1 || c == '\n') {
      continue;
    }
    if (c == '\r') {
      continue;
    }
    d[i] = c;
  }
  return d;
}

