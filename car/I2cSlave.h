/*
 * I2cSlave.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef I2CSLAVE_H_
#define I2CSLAVE_H_

class I2cSlave
{

public:
	I2cSlave (int addr);
	~I2cSlave (void);
	void init (int addr);
	void close (void);
	void write8 (int reg, int data);
	void write16 (int reg, int data);
	int read8 (int reg);
	int read16 (int reg);

protected:
	int address;
};

#endif /* I2CSLAVE_H_ */
