/* GPIO.CPP
 * 
 * Author: Fabien Papleux
 * 
 */ 

// #include <inttypes.h>

#ifndef __GPIO_CPP
#define __GPIO_CPP

namespace wpi {
	#include <wiringPi.h>
}

namespace i2c {
	#include <wiringPiI2C.h>
}

#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "gpio.h"

// I2C definitions
#define I2C_SLAVE	0x0703

using namespace std;

/******************************************************************/
Gpio::Gpio(void)
{
	ready = 0;
	piRev = -1;
	i2cFd = -1;
	i2cSlave = -1;
	init();
};

/******************************************************************/
Gpio::~Gpio(void)
{
	ready = 0;
};

/******************************************************************/
int Gpio::init(void)
{
	if (wpi::wiringPiSetup() != -1) ready = 1; else ready = 0;
	return ready;
};

/******************************************************************/
int Gpio::isReady(void)
{
	return ready;
};

/******************************************************************/
int Gpio::piBoardRev (void)
{
	if (piRev == -1) piRev = wpi::piBoardRev();
	return piRev;
};

/******************************************************************/
void Gpio::pinMode (int pin, int mode)
{
	if (ready) wpi::pinMode(pin, mode);
	else cout << "GPIO not ready.";
};

/******************************************************************/
void Gpio::digitalWrite (int pin, int value)
{
	if (! ready) 
	{
		cout << "GPIO not ready.";
		return;
	}
	if (value != 0) value = HIGH; else value = LOW;
	wpi::digitalWrite(pin, value);
	return;
};

/******************************************************************/
int Gpio::digitalRead (int pin)
{
	if (! ready)
	{
		cout << "GPIO not ready.";
		return -1;
	}
	return wpi::digitalRead(pin);
};

/******************************************************************/
void Gpio::delay (unsigned int howLong)
{
	wpi::delay(howLong);
};

/******************************************************************/
void Gpio::delayMicroseconds (unsigned int howLong)
{
	wpi::delayMicroseconds(howLong);
};

/******************************************************************/
unsigned int Gpio::millis (void)
{
	return wpi::millis();
};

/******************************************************************/
unsigned int Gpio::micros (void)
{
	return wpi::micros();
};

/******************************************************************/
int Gpio::i2cInit()
{
	if (! ready) return 0;
	if (piBoardRev() == 1)
		i2cMaster = "/dev/i2c-0";
	else
		i2cMaster = "/dev/i2c-1";

	if ((i2cFd = open (i2cMaster, O_RDWR)) < 0)
		return 0;
	else 
		return 1;
};

/******************************************************************/
int Gpio::i2cIsReady()
{
	return (i2cFd < 0 ? 0 : 1);
};

/******************************************************************/
int Gpio::i2cConnectSlave(int address)
{
	if (! ready) return -1;		// GPIO not set up
	if (i2cFd < 0) return -1;	// I2C bus not set up
	if (ioctl (i2cFd, I2C_SLAVE, address) < 0)
		return -1;
	i2cSlave = address;
	return 1;
};

/******************************************************************/
int	Gpio::i2cRead (int dev)
{
	if (! ready) return -1;		// GPIO not set up
	if (i2cFd < 0) return -1;	// I2C bus not set up
	if (dev != i2cSlave)
		if (! i2cConnectSlave(dev)) return -1;
	return i2c::wiringPiI2CRead (i2cFd);
};

/******************************************************************/
int	Gpio::i2cReadReg8 (int dev, int reg)
{
	if (! ready) return -1;		// GPIO not set up
	if (i2cFd < 0) return -1;	// I2C bus not set up
	if (dev != i2cSlave)
		if (! i2cConnectSlave(dev)) return -1;
	return i2c::wiringPiI2CReadReg8 (i2cFd, reg);
};

/******************************************************************/
int	Gpio::i2cReadReg16 (int dev, int reg)
{
	if (! ready) return -1;		// GPIO not set up
	if (i2cFd < 0) return -1;	// I2C bus not set up
	if (dev != i2cSlave)
		if (! i2cConnectSlave(dev)) return -1;
	return i2c::wiringPiI2CReadReg16 (i2cFd, reg);
};

/******************************************************************/
int	Gpio::i2cWrite (int dev, int data)
{
	if (! ready) return -1;		// GPIO not set up
	if (i2cFd < 0) return -1;	// I2C bus not set up
	if (dev != i2cSlave)
		if (! i2cConnectSlave(dev)) return -1;
	return i2c::wiringPiI2CWrite (i2cFd, data);
};

/******************************************************************/
int	Gpio::i2cWriteReg8 (int dev, int reg, int data)
{
	if (! ready) return -1;		// GPIO not set up
	if (i2cFd < 0) return -1;	// I2C bus not set up
	if (dev != i2cSlave)
		if (! i2cConnectSlave(dev)) return -1;
	return i2c::wiringPiI2CWriteReg8 (i2cFd, reg, data);
};

/******************************************************************/
int	Gpio::i2cWriteReg16 (int dev, int reg, int data)
{
	if (! ready) return -1;		// GPIO not set up
	if (i2cFd < 0) return -1;	// I2C bus not set up
	if (dev != i2cSlave)
		if (! i2cConnectSlave(dev)) return -1;
	return i2c::wiringPiI2CWriteReg16 (i2cFd, reg, data);
};





#endif
