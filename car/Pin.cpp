/* Pin.cpp
 *
 * created on 4/2/2014
 * author: fabien papleux
 *
 */

#include <iostream>
#include <cstring>
#include "Pin.h"

using namespace std;


Pin::Pin (const char *newName)
{
	ready = 0;
	if (strlen(newName) <= 5) strcpy(name, newName);
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
	cout << "Pin " << getName() << ":    mode = " << getMode() << "   value = " << getValue() << "   trigger = " << getTrigger() << endl;
}

const char *Pin::getName (void)
{
	// INSERT CODE HERE
	
	return name;
}

int Pin::getMode (void)
{
	// INSERT CODE HERE
	
	return 1;
}

int Pin::getValue (void)
{
	// INSERT CODE HERE
	
	return 1;
}

int Pin::getTrigger (void)
{
	// INSERT CODE HERE
	
	return 1;
}

int Pin::setMode (int newMode)
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

int Pin::setTrigger (int newTrigger)
{
	int success = 0;
	
	// INSERT CODE HERE
	
	return success;
}

