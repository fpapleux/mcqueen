/*
 * I2cBus.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef I2CMASTER_H_
#define I2CMASTER_H_

#include "I2cSlave.h";

class I2cMaster {

public:
	I2cMaster (char* address);
	~I2cMaster (void);
	void init (char* address);
	void close ();

private:
	int ready;
	int fd;
	I2cSlave* slave[32];
};


#endif /* I2CBUS_H_ */
