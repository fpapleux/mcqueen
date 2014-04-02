/*
 * RaspberryPi.h
 *
 *  Created on: Mar 26, 2014
 *      Author: fabien
 */

#ifndef RASPBERRYPI_H_
#define RASPBERRYPI_H_

#include "Gpio.h"
#include "I2cBus.h"

class RaspberryPi
{
public:
	RaspberryPi ();
	~RaspberryPi ();

	int init (void);
	int initI2cBus (void);
	int initGpio (void);

	int isReady ();
	void printStatus();

	I2cBus	*getI2cBus (void);
	Gpio	*getGpio (void);

private:
	int ready;
	I2cBus	*i2c;
	Gpio	*gpio;

};




#endif /* RASPBERRYPI_H_ */
