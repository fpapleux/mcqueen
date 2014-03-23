/*
 * I2cSlave_PCA9685.h
 *
 *  Created on: Mar 22, 2014
 *      Author: fabien papleux
 */

#ifndef I2CSLAVE_PCA9685_H_
#define I2CSLAVE_PCA9685_H_

#include "I2cSlave.h"

class I2cSlave_PCA9685 : public I2cSlave
{
public:
	I2cSlave_PCA9685 (int addr);
	~I2cSlave_PCA9685 (void);
	// void init (int addr);
	// void close (void);
	// void write8 (int reg, int data);
	// void write16 (int reg, int data);
	// int read8 (int reg);
	// int read16 (int reg);


private:

};

#endif /* I2CSLAVE_PCA9685_H_ */
