/*
 * I2cSlave.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "I2cSlave.h"

using namespace std;

/*************************************************************/
I2cSlave::I2cSlave (int addr)
{
	address = addr;
	cout << "i2cSlave constructor" << endl;
}

/*************************************************************/
I2cSlave::~I2cSlave (void)
{

}

/*************************************************************/
void I2cSlave::init (int addr)
{

}

/*************************************************************/
void I2cSlave::close (void)
{

}

/*************************************************************/
void I2cSlave::write8 (int reg, int data)
{

}

/*************************************************************/
void I2cSlave::write16 (int reg, int data)
{

}

/*************************************************************/
int I2cSlave::read8 (int reg)
{
	return 0;
}

/*************************************************************/
int I2cSlave::read16 (int reg)
{
	return 0;
}

