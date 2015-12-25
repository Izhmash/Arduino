void setup() 
{
  Serial1.begin(9600);
}

int value = 48;
void loop() 
{
  Serial1.write(value);
  ++value;
  if (value == 58) {
    value = 48;
  }
  delay(1000);
}
