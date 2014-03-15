/* GPIO.CPP
 * 
 * (c) Copyright 2014, Fabien Papleux. All Rights Reserved.
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
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "gpio.h"

using namespace std;


/******************************************************************/
Gpio::Gpio(void)
{
	int i;
	ready = 0;
	piRev = -1;
	i2cFd = 0;
	for (i = 0; i <= 127; i++) i2cSlave[i] = false;
	setup();
};

/******************************************************************/
Gpio::~Gpio(void)
{
	ready = 0;
};

/******************************************************************/
int Gpio::setup(void)
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
int Gpio::i2cSetup()
{
	if (piBoardRev() == 1)
		i2cMaster = "/dev/i2c-0";
	else
		i2cMaster = "/dev/i2c-1";

	if ((i2cFd = open (i2cMaster, O_RDWR)) < 0)
		return 0;
	else return i2cFd;
};

/******************************************************************/
int Gpio::isI2CReady()
{
	return i2cFd;
};






int whatever()
{
	
	/*

	int i2c = 0;
	if ((i2c = wiringPiI2CSetup(0x40)) == -1) {
		printf("\nCould not initialize the I2C device at address 0x40\n");
		return 1;
	}
	
	Wire.begin();
	// Adafruit_PWMServoDriver* driver = new Adafruit_PWMServoDriver(0x40);
	
	*/
	
	return 0;
};

#endif
