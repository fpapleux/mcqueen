/* Pin.cpp
 *
 * created on 4/2/2014
 * author: fabien papleux
 *
 */

#include <iostream>
#include <string>
#include <cstring>
#include <wiringPi.h>
#include "Pin.h"

using namespace std;

static int gpioToWiringPi[32] =
	{
	8,	9,	-1,	-1,	7,	-1,	-1,	11,
	10,	13,	12,	14,	0,	0,	15,	16,
	-1,	0,	1,	-1,	-1,	2,	3,	4,
	5,	6,	-1,	-1,	-1,	-1,	-1,	-1
	};


Pin::Pin (int newNumber)
{
	// Assumes 'wiringPiSetup' is called only once, and not at Pin level
	ready = 0;
	pinNumber = newNumber;
	wpiNumber = gpioToWiringPi[newNumber];	// translates into wiringPi numbering for calls
	init();
}

Pin::~Pin (void)
{
}

int Pin::init (void)
{
	ready = 0;
	
	// INSERT CODE HERE

	
	return ready;
}

int Pin::isReady (void)
{
	return ready;
}

void Pin::printStatus (void)
{
	cout << "Status of pin " << pinNumber << endl;
	cout << endl;
}


/*
string Pin::getMode (void)
{
	// INSERT CODE HERE
	
	return "none";
}

int Pin::getValue (void)
{
	// INSERT CODE HERE
	
	return 1;
}

int Pin::setMode (string newMode)
{
	int success = 0;
	
	// INSERT CODE HERE
	
	return success;
}

int Pin::setValue (int newValue)
{
	int success = 0;
	
	// INSERT CODE HERE
	
	return success;
}
*/
