/*
	LiveSpeed.ino - Main code to display live speed.
	Created by Rahul Goyal and Tyler Davis, February 15, 2017.
	Released to Cal Poly Baja SAE. ;)
*/

#include <LiveDisplay.h>
#include <WheelSpeed.h>

int PORT = 2;
int TRIGGERS = 1;
int CHARS = 3;

float rps;

// Instantiate front wheel
WheelSpeed frontWheel = WheelSpeed(TRIGGERS);

// Instantiate live display
LiveDisplay myDisplay = LiveDisplay(CHARS);



void setup() {

	// Open serial communications and wait for port to open:
	Serial.begin(9600);
	while (!Serial) {
		;	// Wait for serial port to connect. Needed for native USB port only.
	}

	myDisplay.begin();

	int frontWheelInterrupt = digitalPinToInterrupt(PORT);
	attachInterrupt(frontWheelInterrupt, stateChangeISR, RISING);

}



void loop() {

	rps = frontWheel.getRPS();
	myDisplay.update(String(rps));

}



void stateChangeISR() {
	frontWheel.calcRPS();
}
