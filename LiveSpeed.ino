/*
	LiveSpeed.ino - Main code to display live speed.
	Created by Rahul Goyal and Tyler Davis, February 15, 2018.
	Released to Cal Poly Baja SAE. ;)
*/

#include "LiveDisplay.h"
#include "WheelSpeed.h"

const int PORT = 2;
const int TRIGGERS = 1;
const int CHARS = 3;

// Instantiate front wheel speed
WheelSpeed frontWheel = WheelSpeed(TRIGGERS);
  


void setup() {

	// // Open serial communications and wait for port to open:
	// Serial.begin(9600);
	// while (!Serial) {
	// 	;	// Wait for serial port to connect. Needed for native USB port only.
	// }

	// Set up front wheel
	const int frontWheelInterrupt = digitalPinToInterrupt(PORT);
	attachInterrupt(frontWheelInterrupt, frontWheelISR, RISING);

	// Set up display
	myDisplay.begin();

}



void loop() {
	myDisplay.clear();
	myDisplay.title("   Speed");
	myDisplay.write(frontWheel.getRPS(), CHARS);
}



void frontWheelISR() {
	frontWheel.calcRPS();
}
