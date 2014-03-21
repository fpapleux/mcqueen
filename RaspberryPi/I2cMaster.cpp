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
I2cMaster::I2cMaster (char* path)
{
	int i;
	fd = -1;
	for (i = 0; i < 32; i++) slave[i] = 0;
	ready = -1;
	init(path);
}

/************************************************/
I2cMaster::~I2cMaster (void)
{
	close();
}

/************************************************/
void I2cMaster::init (char* address)
{
	if ((fd = open(i2cMasterPath, O_RDWR)) < 0) i2cReady = -1; else i2cReady = 1;

}

/************************************************/
void I2cMaster::close ()
{
}




