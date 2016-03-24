void setup() 
{
  Serial3.begin(115200);
}

void loop() 
{
  Serial3.read();
  Serial3.write('A');
  delay(1000);
}
