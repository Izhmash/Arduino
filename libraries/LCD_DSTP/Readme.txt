Author: David St. Pierre
File name: LCD (library)
Version: 0.1 , July 19, 2013---------10:16 AM 7/19/2013		
	-Three pins are defined and a CMD can be sent

Version: 0.2 , July 19, 2013---------6:43 PM 7/19/2013
	-Init(),Dat(),and Cmd() working
	-most keywords are colored
	-commands for lcd are defined in the program

Version: 0.21 , July 20, 2013--------8:49 AM 7/20/2013
	-Init1 and Init2 created
	-Example code created



 ;Title   : PIC LCM  ROUTINE
          ;FileName: LCD_functions_test
          ;Author  : Richard St-Pierre / David St. Pierre
          ;-----------------------------
          ;Version : 0.1 Sept 17, 2010  Working version (BEG)
          ;                             Single Line Display
          ;-----------------------------
          ; ASSUMES LCM is interface with HC164 chip
          ;
          ; CSA-----------> +EN
          ;           GND-> R/W
          ; SDI------+----> RS
          ;       +--+--+
          ; SCK-->|     |-D0
          ;       |     |-D1
          ;       |     |-D2
          ;       | 164 |-D3
          ;       |     |-D4
          ;       |     |-D5
          ;       |     |-D6
          ;       |     |-D7
          ;       +-----+
          ;-----------------------------


To send signals to the display you send a byte out using the clock and data pins with shift out
Then you set the data pin to high (command) or low (data) then the display knows how to use the byte
Then turn the enable pin on. The display will take the byte and the state of the pin
When the display is not being used(enable pin is at the same state) you can use a piezo on a pin
or whatever you want with the pins.



--------------------------
Usage
--------------------------
To use this library, at the top of a program include the library by writing: 

#include <LCD.h>

Then before "void setup()" define the pins by typing:

LCD lcd(SDI_PIN,SCK_PIN,ENA_PIN)

The pins must be named in that order. By typing lcd lowercase the second time you show how it will be used in the rest of the procram



--------------------------
Pins
--------------------------
This folowing section provides the pin input to DAVID's PIC display 2011
				#########
<--To pic or arduino<--		#	#     -->To display-->
				 ENA	-------------PINK------------
				 CLK	-------------GRN-------------
				 DAT	-------------Yell------------
				 GND	-------------BLK-------------
				 +5V	-------------RED-------------
				 GP3	-------------ORG-------------
				#	#					
				#########


--------------------------
Commands
--------------------------
Here is a list of commands that you can send to the display:

HOME         0x02                //;Return home (1.52ms)
FSET         0x30                //;1 Line
FSET2        0x38                //;2 Line
CLS          0x01                //;Clear Screen (1.52ms)
ENTRY        0x06                //;Entry Mode (incr no-shift)
SCROL        0x07                //;Increment & shift
OFF          0x08                //;
ON           0x0C                //;
CURS         0x0E                //;
LINE1        0x80                //;Set DDRAM ADR to 1st line
LINE2        0xC0                //;Set DDRAM ADR to 2nd line
RIGHT        0x14                //;Shift Right
LEFT         0x10                //;Shift LEFT



--------------------------
Functions
--------------------------
lcd.Init();				//Initializes the display
lcd.Cmd(command);			//Sends a command to the LCD
lcd.Dat(char)				//Sends a single char to the LCD
lcd.Msg(msg[])				//TBC	(TO BE CREATED)



--------------------------
IMPORTANT
--------------------------

When defining pins at the beginging of the program the syntax is as followed:

LCD lcd(SDI_PIN,SCK_PIN,ENA_PIN)

The pins must be declared in that order.



--------------------------
WARNING
--------------------------
THIS LIBRARY COMES WITH ABSOLUTELY NO WARANTY AND I TAKE NO OWNERSHIP OVER ANY RESULT OF USING THIS LIBRARY. THE PUBLIC MAY USE, COPY, OR CHANGE THE LIBRARY. DISTRIBUTED WITHOUT MY CONSENT IS PROHIBITED