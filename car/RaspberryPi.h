/*
 * RaspberryPi.h
 *
 *  Created on: Mar 26, 2014
 *      Author: fabien
 */

#ifndef RASPBERRYPI_H_
#define RASPBERRYPI_H_

#include "I2cBus.h"

class RaspberryPi
{
public:
	RaspberryPi ();
	~RaspberryPi ();

	int initPi (void);
	int initI2cBus (void);
	int isReady ();
	void printStatus();

	I2cBus *getI2cBus (void);

private:
	int ready;
	I2cBus *i2c;

};




#endif /* RASPBERRYPI_H_ */
