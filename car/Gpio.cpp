/*
 * Gpio.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <wiringPi.h>
#include "Pin.h"
#include "Gpio.h"


using namespace std;

/*
 * ---------------------------------------------------------------------------------------------------
 * CONSTRUCTOR
 * Must receive the Raspberry Pi revision number (1 or 2)
 * ---------------------------------------------------------------------------------------------------
 */
Gpio::Gpio (int raspiVersion)
{
	// Ensures that the object is recorded as not ready until full successful initialization
	ready = 0;


	// Records which RaspberryPi version is in use. If receives anything than 1 or 2, records as 0.
	// A value of 0 will prevent the GPIO from completing initialization.  This is done in anticipation
	// that new board versions will come out and the software will naturally try to initialize a new
	// board with old code
	if ((raspiVersion == 1) || (raspiVersion == 2))
		version = raspiVersion;
	else
		version = 0;


	// Initializes all pins to null.  They will be initializes as part of the init sequence
	for (int t = 0; t < 26; t++) pin[t] = 0;


	// Starts actual device initializing sequence
	init();
}




/*
 * ---------------------------------------------------------------------------------------------------
 * DESTRUCTOR
 * ---------------------------------------------------------------------------------------------------
 */
Gpio::~Gpio (void)
{
	// destroys all pin objects associated with this gpio
	for (int t = 0; t < 26 ; t++)
	{
		if (pin[t]) delete pin[t];
	}

}

/*
 * ---------------------------------------------------------------------------------------------------
 * int init (void)
 *
 * ---------------------------------------------------------------------------------------------------
 */
int Gpio::init (void)
{
	if ((version == 1) || (version == 2))
	{
		// Not initializing I2C, UART or SPI pins by default.
		pin[4] = new Pin(4);
		pin[17] = new Pin(17);
		pin[18] = new Pin(18);
		pin[21] = new Pin(21);
		pin[22] = new Pin(22);
		pin[23] = new Pin(23);
		pin[24] = new Pin(24);
		pin[25] = new Pin(25);
	}
	ready = 1;

	return ready;
}

int Gpio::isReady (void)
{
	return ready;
}

void Gpio::printStatus (void)
{
	cout << "GPIO Status" << endl;
	cout << "-----------" << endl;
	cout << endl;
	cout << "Is Ready : " << (isReady() ? "Yes" : "No") << endl;
	cout << endl;
}

