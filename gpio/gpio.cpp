/* GPIO.CPP
 * 
 * (c) Copyright 2014, Fabien Papleux. All Rights Reserved.
 * 
 */ 

// #include <inttypes.h>

#ifndef __GPIO_CPP
#define __GPIO_CPP

#include "gpio.h"
#include <stdio.h>
#include <wiringPi.h>


Gpio::Gpio(void)
{
	if (wiringPiSetup() != -1) ready = 1; else ready = 0;
};

Gpio::~Gpio(void)
{
	ready = 0;
};

int Gpio::initialize(void)
{
	if (wiringPiSetup() != -1) ready = 1; else ready = 0;
	return ready;
};

int Gpio::isReady(void)
{
	return ready;
};

void Gpio::pinMode (int pin, int mode)
{
	if (this->ready) pinMode(pin, mode);
	else printf("GPIO not ready.");
};

void Gpio::digitalWrite (int pin, int value)
{
	if (! this->ready) 
	{
		printf("GPIO not ready.");
		return;
	}
	if (value != 0) value = HIGH; else value = LOW;
	digitalWrite(pin, value);
	return;
};

int Gpio::digitalRead (int pin)
{
	if (! this->ready) 
	{
		printf("GPIO not ready.");
		return -1;
	}
	return digitalRead(pin);
};



int whatever()
{
	
	/*
	 * Testing led blinking on pin 7 on the base wiringPi. Works great.
		int c;
		pinMode(7, OUTPUT);
		for (c = 0; c < 20; c++) {
			digitalWrite(7, HIGH);
			delay(1000);
			digitalWrite(7, LOW);
			delay(1000);
		}

	int i2c = 0;
	if ((i2c = wiringPiI2CSetup(0x40)) == -1) {
		printf("\nCould not initialize the I2C device at address 0x40\n");
		return 1;
	}
	
	printf ("I2C device initialized");
	
	Wire.begin();
	// Adafruit_PWMServoDriver* driver = new Adafruit_PWMServoDriver(0x40);
	
	*/
	
	return 0;
};

#endif
