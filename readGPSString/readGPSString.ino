//sample home coordinates format: 44°29.64797'N 73°6.74070'W

#define BUFFSIZE  90
//char* data;

String getGPSLine();

void setup() 
{
  Serial.begin(115200);
  //Serial1.begin(9600);
  Serial1.begin(115200);
  //data = new char[90];
  String GGA = "";
  while(!isGGA(GGA)) {
    GGA = getGPSLine(); 
  }
  /*String RMC = getGPSLine();
  String GGA = getGPSLine();
  String GSA = getGPSLine();*/
  Serial.println(GGA); 
}

void loop() 
{
  //getGPSLine();
}

String getGPSLine()
{
  String d = "";
  while (1) {
    int i = 0;
    char c = Serial1.read();
    if (c == -1) {
      continue;
    }
    d += c;
    if (c == '\n') {
      continue;
    }
    if (c == '\r') {
      return d;
    }
  }
}

boolean isGGA(String s)
{
  String gpsLine = s;
  if (gpsLine.substring(1, 7) == "$GPGGA") {
    return true;
  }
  return false;
}

