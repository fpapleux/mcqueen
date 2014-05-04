/* Pin.cpp
 *
 * created on 4/2/2014
 * author: fabien papleux
 *
 */

#include <iostream>
#include <string>
#include <cstring>
#include "Pin.h"

using namespace std;


Pin::Pin (const char *newName)
{
	ready = 0;
	name = newName;
	init();
}

Pin::~Pin (void)
{
}

int Pin::init (void)
{
	ready = 0;
	
	// INSERT CODE HERE
	// exporting pin on the system to communicate with it

	
	return ready;
}

int Pin::isReady (void)
{
	return ready;
}

void Pin::printStatus (void)
{
	cout << "Status of pin " << name << endl;
	cout << endl;
}

string Pin::getMode (void)
{
	// INSERT CODE HERE
	
	return 1;
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

