/*
 * Gpio.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: fabien papleux
 */
#include <iostream>
#include "Pin.h"
#include "Gpio.h"


using namespace std;

Gpio::Gpio (int raspiVersion)
{
	ready = 0;
	if ((raspiVersion == 1) || (raspiVersion == 2)) version = raspiVersion;
	else version = 0;
	init();
}

Gpio::~Gpio (void)
{
}

int Gpio::init (void)
{
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

