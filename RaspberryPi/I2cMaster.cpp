/*
 * I2cMaster.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <fcntl.h>

#include "I2cMaster.h"

using namespace std;

/************************************************/
I2cMaster::I2cMaster (const char* path)
{
	fd = -1;
	ready = -1;
	for (int i = 0; i < 64; i++) i2cSlave[i] = NULL;
	init (path);
}

/************************************************/
I2cMaster::~I2cMaster (void)
{
	close();
}

/************************************************/
void I2cMaster::init (const char* address)
{
	if ((fd = open(address, O_RDWR)) < 0) ready = -1; else ready = 1;
}

/************************************************/
void I2cMaster::close (void)
{
	for (int i = 0; i < 64; i++)
		if (i2cSlave[i] != NULL) delete i2cSlave[i];
}

/************************************************/
int I2cMaster::isReady (void)
{
	return ready;
}

/******************************************************************/
I2cSlave* I2cMaster::addI2cSlave (const char* type, int address)
{
	if (i2cSlave[address]) delete i2cSlave[address];
	switch (type) {
		case "PCA9685":		i2cSlave[address] = new I2cSlave_PCA9685(address);
							break;
	}
	return i2cSlave[address];
}


