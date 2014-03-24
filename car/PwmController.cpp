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



