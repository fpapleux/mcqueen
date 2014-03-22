/*
 * I2cSlave.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef I2CSLAVE_H_
#define I2CSLAVE_H_

class I2cSlave {

public:
	I2cSlave (char* initString);
	virtual ~I2cSlave (void);
	virtual void init (char* initString);
	virtual void close (void);
	virtual void write8 (int data);
	virtual void write16 (int data);
	virtual int read8 (void);
	virtual int read16 (void);

private:

};

#endif /* I2CSLAVE_H_ */
