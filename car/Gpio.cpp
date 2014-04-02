/*
 * Gpio.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: fabien papleux
 */
#include <iostream>
#include "Gpio.h"

using namespace std;

Gpio::Gpio ()
{
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

