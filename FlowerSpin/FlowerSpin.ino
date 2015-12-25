/*
 * FlowerSpin by Ian Ballou
 * March 21	2015
 * V 1.0
 */

#include <Servo.h>
#include <Adafruit_NeoPixel.h>

namespace pins {
	const byte servoPin = 9;
	const byte ledPin = 6;
	const byte irReceivePin = 2;
	const byte irLedPin = 13;  
}

Servo servo;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, pins::ledPin, 
							NEO_GRB + NEO_KHZ800);
boolean toggle;

void setup() {
	digitalWrite(0, HIGH);
	servo.attach(pins::servoPin);	
	pinMode(pins::ledPin, OUTPUT);
	pinMode(pins::irLedPin, OUTPUT);
	pinMode(pins::irReceivePin, INPUT);
	toggle = false;
	//attachInterrupt(0, changeToggle, FALLING);
	strip.setBrightness(100);
	strip.setPixelColor(0, 0xFFFF00);
	Serial.begin(9600);
}

void loop() {
	/*if (toggle) {
		strip.setPixelColor(0, 0xFF00FF);
	} else {
		strip.setPixelColor(0, 0xFFFF00);
	}*/
	strip.show();
	servo.write(97);
	strip.setPixelColor(0, 0xFF00FF);
	strip.show();
	delay(2000);
	servo.write(85);
	strip.setPixelColor(0, 0xFFFF00);
	strip.show();
	delay(2450);
		
}

void changeToggle() {
	toggle = !toggle;
	
	if (toggle) {
		strip.setPixelColor(0, 0xFF00FF);
	} else {
		strip.setPixelColor(0, 0xFFFF00);
	}
}
