/*
 * Car.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "PCA9685.h"
#include "PwmServo.h"
#include "Car.h"

using namespace std;

/****************************************************************/
Car::Car(void)
{
	i2c = NULL;
	pwm = NULL;
	servo = NULL;
	ready = -1;
	init();
}

/****************************************************************/
Car::~Car(void)
{
	if (servo != NULL) delete servo;
	if (pwm != NULL) delete pwm;
	if (i2c != NULL) delete i2c;
}

/****************************************************************/
void Car::init(void)
{
	servoConfig = {
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
	i2c = new I2cBus();
	pwm = new PCA9685(i2c, 0x40, 50);			// initializing the PWM controller at I2C address 0x40, and using 50Hz as the PWM pulse frequency
	servo = new PwmServo(&servoConfig, pwm);
	ready = 1;
}

/****************************************************************/
int Car::isReady () { return ready; }

/****************************************************************/
PwmServo* Car::getServo (void) { return servo; }

/****************************************************************/
PCA9685* Car::getPCA9685 (void) { return pwm; }

/****************************************************************/
I2cBus* Car::getI2cBus (void) { return i2c; }

/****************************************************************/
void Car::printStatus (void)
{
	cout << "CAR DETAILED STATUS" << endl;
	cout << "-------------------" << endl << endl;
	cout << "Is Ready              : " << (ready ? "Yes" : "No") << endl;
	cout << "Servo motor           : " << (servo != NULL ? "Present" : "Absent") << endl;
	cout << "PCA9685 controller    : " << (pwm != NULL ? "Present" : "Absent") << endl;
	cout << "I2C Bus               : " << (i2c != NULL ? "Present" : "Absent") << endl;
	cout << endl;
	servo->printStatus();
	pwm->printStatus();
	i2c->printStatus();
}

/****************************************************************/
int	Car::rightPct (int percent)
{
	return servo->rightPct(percent);
}

/****************************************************************/
int	Car::leftPct (int percent)
{
	return servo->leftPct(percent);
}

/****************************************************************/
int	Car::straight (void)
{
	return servo->straight();
}

