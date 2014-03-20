/*
 * RaspberryPi.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef RASPBERRYPI_CPP_
#define RASPBERRYPI_CPP_

#include <iostream>

namespace wpi {
	#include <wiringPi.h>
	#include <wiringPiI2C.h>
}

#include "RaspberryPi.h"

using namespace std;

/********************************************************************/
RaspberryPi::RaspberryPi (void)
{
	ready = 0;
	piRev = -1;
	init();
}

/********************************************************************/
RaspberryPi::~RaspberryPi (void)
{
	close();
}

/********************************************************************/
void RaspberryPi::init (void)
{
	if (wpi::wiringPiSetup() != -1) ready = 1; else ready = 0;
	if (ready)
	{
		if (piRev == -1) piRev = wpi::piBoardRev();
		initDigitalPins();
		initI2cMaster();
	}
	else
	{
		cout << "Could not initialize Raspberry Pi controller. (wiringPiSetup failed)";
	}
}

/********************************************************************/
void RaspberryPi::initDigitalPins (void)
{
}

/********************************************************************/
void RaspberryPi::initI2cMaster (void)
{
}

/********************************************************************/
void RaspberryPi::close (void) { }

/******************************************************************/
int RaspberryPi::isReady (void) { return ready; }

/******************************************************************/
int RaspberryPi::getPiRev (void)
{
	// Need to figure out what different values are returned by piBoardRev
	if (piRev == -1) piRev = wpi::piBoardRev();
	return piRev;
}




#endif



