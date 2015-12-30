//sample home coordinates format: 44°29.64797'N 73°6.74070'W

#define BUFFSIZE  90
//char* data;
int buffInc;

void displayGPSData(void);

void setup() 
{
  Serial.begin(115200);
  //Serial1.begin(9600);
  Serial1.begin(115200);
  //data = new char[90]; 
}

void loop() 
{
  displayGPSData();
}

void displayGPSData(void)
{
  buffInc = 0;
  while (1) {
    int i = 0;
    char c = Serial1.read();
    if (c == -1) {
      continue;
    }
    Serial.print(c);
    if (c == '\n') {
      continue;
    }
    if (c == '\r') {
      return;
    }
  }
}

