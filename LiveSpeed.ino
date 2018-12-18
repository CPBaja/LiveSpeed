/*
	LiveSpeed.ino - Main code to display live speed.
	Created by Rahul Goyal and Tyler Davis, February 15, 2018.
	Released to Cal Poly Baja SAE. ;)
*/

#include "LiveDisplay.h"
#include "WheelSpeed.h"

const byte PORT = 3;
const byte TRIGGERS = 12;
const byte CHARS = 3;

unsigned long REFRESH_RATE = 250;//miliseconds
unsigned long prev_write;

// Instantiate front wheel speed
WheelSpeed fWheel = WheelSpeed(TRIGGERS);
  


void setup() {

	// // Open serial communications and wait for port to open:
	// Serial.begin(9600);
	// while (!Serial) {
	// 	;	// Wait for serial port to connect. Needed for native USB port only.
	// }

	// Set up front wheel
	const byte fWheelInterrupt = digitalPinToInterrupt(PORT);
	attachInterrupt(fWheelInterrupt, fWheelISR, RISING);

	// Set up display
	myDisplay.begin();
	prev_write = millis();
}

\

void loop() {
	if(prev_write - millis() >= REFRESH_RATE){
		prev_write = millis();
		myDisplay.clear();
		myDisplay.title("Engine RPM");
		myDisplay.write(fWheel.getRPS() * 5.75958653, CHARS);	// Assumes 11" effective wheel radius
	}
}



void fWheelISR() {
	fWheel.calcRPS();
}
