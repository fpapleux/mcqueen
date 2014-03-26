/*
 * Car.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <string>
#include "PwmServo.h"
#include "PCA9685.h"
#include "I2cBus.h"
#include "RaspberryPi.h"
#include "Car.h"

using namespace std;

/****************************************************************/
Car::Car(void)
{
	pi = NULL;
	i2c = NULL;
	pwm = NULL;
	servo = NULL;
	esc = NULL;
	ready = 0;
	init();
}

/****************************************************************/
Car::~Car(void)
{
	if (servo) delete servo;
	if (esc) delete esc;
	if (pwm) delete pwm;
	if (pi) delete pi;
}

/****************************************************************/
void Car::init(void)
{
	ready = 0;

	servoConfig.channel 	= 8;
	servoConfig.frequency 	= 50;
	servoConfig.resolution 	= 4096;
	servoConfig.posInit 	= 330;
	servoConfig.posStraight = 330;
	servoConfig.posMinLeft 	= 331;
	servoConfig.posMaxLeft 	= 460;
	servoConfig.posMinRight = 329;
	servoConfig.posMaxRight = 215;

	escConfig.channel 			= 9;
	escConfig.frequency 		= 50;
	escConfig.resolution 		= 4096;
	escConfig.posInit 			= 335;
	escConfig.posIdle 			= 335;
	escConfig.posMinForward 	= 340;
	escConfig.posMaxForward		= 375;
	escConfig.posMinBackward	= 334;
	escConfig.posMaxBackward	= 310;

	pi = new RaspberryPi();
	if (pi && pi->isReady()) {
		i2c = 	pi->getI2cBus();
		pwm = 	new PCA9685 	(i2c, 0x40, 50);			// initializing the PWM controller at I2C address 0x40, and using 50Hz as the PWM pulse frequency
		servo = new PwmServo 	(&servoConfig, pwm);
		esc = 	new PwmEsc		(&escConfig, pwm);
		if (i2c->isReady() && pwm->isReady() && servo->isReady() && esc->isReady()) ready = 1;
	}
}

/****************************************************************/
int Car::isReady () { return ready; }

/****************************************************************/
PwmServo *Car::getServo (void) { return servo; }

/****************************************************************/
PwmEsc *Car::getEsc (void) { return esc; }

/****************************************************************/
PCA9685 *Car::getPCA9685 (void) { return pwm; }

/****************************************************************/
I2cBus *Car::getI2cBus (void) { return i2c; }

/****************************************************************/
RaspberryPi *Car::getRaspberryPi (void) { return pi; }

/****************************************************************/
void Car::printStatus (void)
{
	string out;
	cout << "CAR DETAILED STATUS" << endl;
	cout << "-------------------" << endl << endl;
	cout << "Is Ready              : " << (ready ? "Yes" : "No") << endl;
	cout << "Raspberry Pi          : " << (pi    ? string("Present").append((pi->isReady()    ? " and Ready" : " but not ready")) : "Absent") << endl;
	cout << "Pi I2C Bus            : " << (i2c   ? string("Present").append((i2c->isReady()   ? " and Ready" : " but not ready")) : "Absent") << endl;
	cout << "PCA9685 (PWM)         : " << (pwm   ? string("Present").append((pwm->isReady()   ? " and Ready" : " but not ready")) : "Absent") << endl;
	cout << "Servo (direction)     : " << (servo ? string("Present").append((servo->isReady() ? " and Ready" : " but not ready")) : "Absent") << endl;
	cout << "ESC (throttle)        : " << (esc 	 ? string("Present").append((esc->isReady()   ? " and Ready" : " but not ready")) : "Absent") << endl;
	cout << endl;
	pi->printStatus();
	pwm->printStatus();
	servo->printStatus();
	esc->printStatus();
}

/****************************************************************/
int	Car::turnRightPct (int percent)
{
	return servo->rightPct(percent);
}

/****************************************************************/
int	Car::turnLeftPct (int percent)
{
	return servo->leftPct(percent);
}

/****************************************************************/
int	Car::straight (void)
{
	return servo->straight();
}

/****************************************************************/
int	Car::turnPct (int percent)
{
	return servo->turnPct(percent);
}

/****************************************************************/
int	Car::turn (int pwmValue)
{
	return servo->setPwm(pwmValue);
}

int	Car::forwardPct (int percent)
{
	return esc->forwardPct(percent);
}

int	Car::backwardPct (int percent)
{
	return esc->backwardPct(percent);
}

int	Car::stop (void)
{
	return esc->stop();
}

/****************************************************************/
int	Car::speedPct (int percent)
{
	return esc->speedPct(percent);
}
