/*
CPP
*/
#include "Arduino.h"
#include "LCD.h"

LCD::LCD(int SDI_PIN,int SCK_PIN, int ENA_PIN)
{
	pinMode(SDI_PIN, OUTPUT);			//Setting all the pins for the display to output
	pinMode(SCK_PIN, OUTPUT);
	pinMode(ENA_PIN, OUTPUT);
	_SDI_PIN = SDI_PIN;				//Making thepin number equal to the private variables
	_SCK_PIN = SCK_PIN;
	_ENA_PIN = ENA_PIN;
	
	
}

void LCD::Cmd(byte command)
{
  digitalWrite(_ENA_PIN, HIGH);                    	//Seting Enable pin high because it only reads when turned high
  shiftOut(_SDI_PIN, _SCK_PIN, MSBFIRST, command);   	//Shifting out the command
  digitalWrite(_SDI_PIN,LOW);          			//Seting SDI pin low to indicate a command              
  digitalWrite(_ENA_PIN,LOW);                       	//Turn the enable pin low then high to read the data/command sent
  delay(10);                                       
  digitalWrite(_ENA_PIN,HIGH);  
}
void LCD::Dat(byte data)
{
  digitalWrite(_ENA_PIN, HIGH);				//The same as CMD but the SDI pin is turned high
  shiftOut(_SDI_PIN, _SCK_PIN, MSBFIRST,data);
  digitalWrite(_SDI_PIN,HIGH);       			//Indicating data being sent                 
  digitalWrite(_ENA_PIN,LOW);  
  delay(10);
  digitalWrite(_ENA_PIN,HIGH); 
}
void LCD::Init1()
{
 delay(100);						//Thes five lines are needed to initialize the display
 Cmd(FSET);                               
 Cmd(FSET);
 Cmd(ENTRY);
 Cmd(CLS);
 Cmd(ON);
}
void LCD::Init2()
{
 delay(100);						//Created for a two line display
 Cmd(FSET2);                               
 Cmd(FSET2);
 Cmd(ENTRY);
 Cmd(CLS);
 Cmd(ON);
}
void LCD::Msg(char *msg)
{
 int i = 0;
 while(msg[i])
	{
	Dat(msg[i]);
	i++;
	}
}
