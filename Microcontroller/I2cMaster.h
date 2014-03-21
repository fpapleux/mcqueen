/*
 * I2cBus.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef I2CMASTER_H_
#define I2CMASTER_H_

class I2cMaster {

public:
	I2cMaster (char* address);
	virtual ~I2cMaster (void);
	virtual void init (char* address);
	virtual void close ();

private:

};

/************************************************/
I2cMaster::I2cMaster (char* address)
{
	init(address);
}

/************************************************/
I2cMaster::~I2cMaster (void)
{
	close();
}

#endif /* I2CBUS_H_ */
