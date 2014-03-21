/*
 * RaspberryPi.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef RASPBERRYPI_CPP_
#define RASPBERRYPI_CPP_

#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>

namespace wpi {
#include <wiringPi.h>
#include <wiringPiI2C.h>
}

#include "RaspberryPi.h"

using namespace std;

/********************************************************************/
RaspberryPi::RaspberryPi (void)
{
	ready = -1;
	i2cReady = -1;
	i2cMasterPath = "";
	i2cFd = -1;
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
	if (wpi::wiringPiSetup() != -1) ready = 1; else ready = -1;
	if (ready) {
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
void RaspberryPi::initI2cMaster(void)
{
	if (!ready) return;
	if (piBoardRev() == 1) i2cMasterPath = "/dev/i2c-0"; else i2cMasterPath = "/dev/i2c-1";
	i2cMaster = new I2cMaster(i2cMasterPath);
	if ((i2cFd = open(i2cMasterPath, O_RDWR)) < 0) i2cReady = -1; else i2cReady = 1;
}

/********************************************************************/
void RaspberryPi::close(void) {
}

/******************************************************************/
int RaspberryPi::isReady(void) {
	return ready;
}

/******************************************************************/
int RaspberryPi::isI2cReady(void) {
	return i2cReady;
}

/******************************************************************/
int RaspberryPi::getPiRev(void) {
	// Need to figure out what different values are returned by piBoardRev
	if (piRev == -1)
		piRev = wpi::piBoardRev();
	return piRev;
}

#endif

