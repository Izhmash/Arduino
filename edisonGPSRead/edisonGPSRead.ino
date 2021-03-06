#define BUFFSIZE  90

void readLine(void);
char data[BUFFSIZE];

//#define GPSRATE 9600
//#define GPSRATE 38400

// GPS parser for 406a
//#define BUFFSIZ 90 // plenty big
//char buffer[BUFFSIZ];
//char *parseptr;
//char buffidx;

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
}

void loop() {
  /*while (Serial1.available()) {
    data += Serial1.read();
  }*/
  
  for (int i = 0; i < BUFFSIZE; i++) {
    char c = Serial1.read();
    if (c == -1 || c == '\n') {
      continue;
    }
    if (c == '\r') {
      continue;
    }
    data[i] = c;
  }
  
  Serial.print(data);
  Serial.println(" END");
  //readline();
  //Serial.println(buffer);
  delay(500);
}

/*void readline(void) {
  char c;
  
  buffidx = 0; // start at begninning
  while (1) {
    c = Serial1.read();
    if (c == -1)
      continue;
    Serial.print(c);
    if (c == '\n')
      continue;
    if ((buffidx == BUFFSIZ-1) || (c == '\r')) {
      buffer[buffidx] = 0;
      return;
    }
    buffer[buffidx++]= c;
  }
}*/
