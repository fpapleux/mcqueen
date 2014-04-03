/*
 * RaspberryPi.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <string.h>
#include <wiringPi.h>
#include "RaspberryPi.h"
#include "I2cBus.h"

using namespace std;




RaspberryPi::RaspberryPi (void)
{
	ready = 0;
	i2c = NULL;
	gpio = NULL;
	init();
}




RaspberryPi::~RaspberryPi (void)
{
	if (i2c) delete i2c;
	if (gpio) delete gpio;
}




int RaspberryPi::isReady (void)
{
	return ready;
}




int RaspberryPi::init (void)
{
	int success = 0;
	ready = 0;

	if (wiringPiSetup() != -1) success = 1;
	if (success) success = initGpio();
	if (success) success = initI2cBus();
	if (success) ready = 1;
	return ready;
}




int RaspberryPi::initI2cBus (void)
{
	if (! i2c) i2c = new I2cBus();
	if (! i2c->isReady()) i2c->init();
	return i2c->isReady();
}




int RaspberryPi::initGpio (void)
{
	if (! gpio) gpio = new Gpio();
	if (! gpio->isReady()) gpio->init();
	return gpio->isReady();
}




I2cBus *RaspberryPi::getI2cBus (void)
{
	return i2c;
}




Gpio *RaspberryPi::getGpio (void)
{
	return gpio;
}




void RaspberryPi::printStatus (void)
{
	cout << "Raspberry Pi Status" << endl;
	cout << "-------------------" << endl;
	cout << endl;
	cout << "Is Ready   : " << (ready ? "Yes" : "No") << endl;
	cout << "Gpio       : " << (gpio != NULL ? string("Present ").append((gpio->isReady() ? "and Ready" : "but Not Ready"))  : "Absent") << endl;
	cout << "I2C Bus    : " << (i2c != NULL ? string("Present ").append((i2c->isReady() ? "and Ready" : "but Not Ready"))  : "Absent") << endl;
	cout << endl;
	if (gpio) gpio->printStatus();
	if (i2c) i2c->printStatus();
}
