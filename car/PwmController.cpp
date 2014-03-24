/*
 * PwmController.cpp
 *
 * Implements the PCA9685 PWM controller
 *
 *  Created on: Mar 24, 2014
 *      Author: fabien papleux
 */

#include "PwmController.h"

/********************************************************/
PwmController::PwmController(void)
{
	init();
}

/********************************************************/
PwmController::~PwmController(void)
{

}

/********************************************************/
int PwmController::init (void)							// initializes the controller
{
	ready = -1;
	ready = 1;
	return ready;
}

/********************************************************/
int PwmController::isReady (void) { return ready; }


/********************************************************/
int PwmController::getPwmFrequency (void)
{
	return 1;
}

/********************************************************/
int PwmController::getPwmResolution (void)
{
	return 1;
}

/********************************************************/
int PwmController::setPwm (int address, int data)
{
	return 1;
}

/********************************************************/
int PwmController::getPwm (int address)
{
	return 1;
}

/********************************************************/
int PwmController::printStatus (void)
{
	return 1;
}


