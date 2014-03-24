/*
 * Car.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "PwmController.h"
#include "PwmServo.h"
#include "Car.h"

using namespace std;

// This is the base configuration used for the servo in the car. Adjust as necessary.
PwmServoConfig servoConfig = {
	8,			// Address to be used by this servo to send commands through the PWM controller
	50, 		// Hz - baseFrequency
	4096,		// 12-bits - baseResolution
	330,		// posInit
	330,		// posStraight
	331,		// posMinLeft
	460,		// posMaxLeft
	329,		// posMinRight
	215			// posMaxRight
};


/****************************************************************/
Car::Car(void) : pwm()
{
	servo = NULL;
	ready = -1;
	init();
}

/****************************************************************/
Car::~Car(void)
{
	if (servo != NULL) delete servo;
}

/****************************************************************/
void Car::init(void)
{
	servo = new PwmServo(&servoConfig, &pwm);
	ready = 1;
}

/****************************************************************/
int Car::isReady () { return ready; }

/****************************************************************/
PwmServo* Car::getServo () { return servo; }

/****************************************************************/
void Car::printStatus (void)
{
	cout << "CAR DETAILED STATUS" << endl;
	cout << "-------------------" << endl << endl;
	cout << "Is Ready   :  " << (ready ? "Yes" : "No") << endl;
	cout << endl;
	servo->printStatus();
}

