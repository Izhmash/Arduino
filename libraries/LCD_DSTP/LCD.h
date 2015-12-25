/*
H
*/
#ifndef LCD_h
#define LCD_h

#include "Arduino.h"
#define HOME         0x02                //;Return home (1.52ms)
#define FSET         0x30                //;1 Line
#define FSET2        0x38                //;2 Line
#define CLS          0x01                //;Clear Screen (1.52ms)
#define ENTRY        0x06                //;Entry Mode (incr no-shift)
#define SCROL        0x07                //;Increment & shift
#define OFF          0x08                //;
#define ON           0x0C                //;
#define CURS         0x0E                //;
#define LINE1        0x80                //;Set DDRAM ADR to 1st line
#define LINE2        0xC0                //;Set DDRAM ADR to 2nd line
#define RIGHT        0x14                //;Shift Right
#define LEFT         0x10                //;Shift LEFT
class LCD
{
	
	public:
		LCD(int SDI_PIN,int SCK_PIN,int ENA_PIN);	
		void Dat(byte data);
		void Cmd(byte command);
		void Init1();
		void Init2();
		void Msg(char *msg);
	private:
		int _SDI_PIN;
		int _SCK_PIN;	
		int _ENA_PIN;
		
};		


#endif