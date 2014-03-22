/*
 * I2cSlave_PCA9685.h
 *
 *  Created on: Mar 22, 2014
 *      Author: fabien papleux
 */

#ifndef I2CSLAVE_PCA9685_H_
#define I2CSLAVE_PCA9685_H_

#include "I2cSlace.h"

class I2cSlave_PCA9685 : public I2cSlave
{
public:
	I2cSlave_PCA9685 (int addr2);
	~I2cSlave_PCA9685 (void);
	// void init (int address);
	// void close (void);
	// void write8 (int reg, int data);
	// void write16 (int reg, int data);
	// int read8 (int reg);
	// int read16 (int reg);


private:

};

#endif /* I2CSLAVE_PCA9685_H_ */
