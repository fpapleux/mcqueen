/*
 * Car.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "Car.h"
#include "PwmServo.h"

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



