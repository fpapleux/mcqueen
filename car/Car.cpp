/*
 * Car.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "PwmServo.h"
#include "Car.h"

// This is the base configuration used for the servo in the car. Adjust as necessary.
PwmServoConfig servoConfig = {
	50, 		// Hz - baseFrequency
	4096,		// 12-bits - baseResolution
	330,		// posIdle
	331,		// posMinLeft
	460,		// posMaxLeft
	329,		// posMinRight
	215			// posMaxRight
};


/****************************************************************/
Car::Car(void)
{
	servo = NULL;
	ready = -1;
	reset();
}

/****************************************************************/
Car::~Car(void)
{
	if (servo != NULL) delete servo;
}

/****************************************************************/
void Car::reset(void)
{
	servo = new PwmServo(&servoConfig);
	ready = 1;
}

/****************************************************************/
int Car::isReady () { return ready; }
/****************************************************************/
PwmServo* Car::getServo () { return servo; }



