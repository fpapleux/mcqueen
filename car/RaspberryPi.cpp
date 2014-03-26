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
	ready = -1;
	i2c = NULL;
	if (initPi()) {
		initI2cBus();
		if (i2c->isReady()) ready = 1;
	}
}



RaspberryPi::~RaspberryPi (void)
{
	if (i2c) delete i2c;
}



int RaspberryPi::isReady (void)
{
	return ready;
}


int RaspberryPi::initPi (void)
{
	if (wiringPiSetup() != -1) return 1;
	else return -1;
}

int RaspberryPi::initI2cBus (void)
{
	if (! i2c) i2c = new I2cBus();
	if (! i2c->isReady()) i2c->init();
	return i2c->isReady();
}



I2cBus *RaspberryPi::getI2cBus (void)
{
	return i2c;
}


void RaspberryPi::printStatus (void)
{
	cout << "Raspberry Pi Status" << endl;
	cout << "-------------------" << endl;
	cout << endl;
	cout << "Is Ready   : " << (ready ? "Yes" : "No") << endl;
	cout << "I2C Bus    : " << (i2c != NULL ? strcat("Present ", (i2c->isReady() ? "and Ready" : "but Not Ready"))  : "Absent");
	cout << endl;
	if (i2c) i2c->printStatus();
}
