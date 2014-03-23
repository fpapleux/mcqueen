/*
 * I2cBus.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef I2CMASTER_H_
#define I2CMASTER_H_

#include "I2cSlave.h"

// codes to use to define the type of I2cSlave you are adding using in addI2cSlave
#define I2C_PCA9685		1


class I2cMaster {

public:
	I2cMaster (const char* address);
	~I2cMaster (void);

	void 		init 			(const char* address);
	void 		close 			(void);
	int 		isReady 		(void);
	I2cSlave*	addI2cSlave		(int type, int address);
	I2cSlave*	getI2cSlave		(int address);

private:
	int 		ready;
	int 		fd;
	I2cSlave*	i2cSlave[64];

};

#endif /* I2CBUS_H_ */
