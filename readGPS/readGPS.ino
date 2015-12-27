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
  Serial2.begin(115200);
}

void loop() {
  /*while (Serial2.available()) {
    data += Serial2.read();
  }*/
  
  for (int i = 0; i < BUFFSIZE; i++) {
    char c = Serial2.read();
    if (c == -1 || c == '\n') {
      continue;
    }
    if (c == '\r') {
      continue;
    }
    data[i] = c;
  }
  
  Serial.println(data);
  //readline();
  //Serial.println(buffer);
  delay(1000);
}

/*void readline(void) {
  char c;
  
  buffidx = 0; // start at begninning
  while (1) {
    c = Serial2.read();
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
