int led=13;
int i;
void setup()
{
pinMode(led,OUTPUT);
}
void loop()
{
  for(i = 0; i < 255;i++)
  {
    analogWrite(led,i); 
    delay(10);
  }
  for( i = 252;i>0;i--)
  {
    analogWrite(led,i); 
    delay(10);
  }
  
  

}
