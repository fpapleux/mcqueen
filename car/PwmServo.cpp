/*
 * PwmServo.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <cmath>
#include "PwmController.h"
#include "PwmServo.h"

using namespace std;

/****************************************************************/
PwmServo::PwmServo (PwmServoConfig* config, PwmController* controller)
{
	baseConfig = config;
	currentPos = -1;
	pwm = controller;
	init();
}

/****************************************************************/
PwmServo::~PwmServo(void)
{
}

/****************************************************************/
int PwmServo::init(void)
{
	ready = -1;
	if (! pwm->isReady()) pwm->init();
	if (! pwm->isReady()) {
		cout << "PWM Controller could not be initialized." << endl;
		exit(1);
	}
	cfg.frequency = pwm->getPwmFrequency();
	cfg.resolution = pwm->getPwmResolution();

	double resolutionFactor = cfg.resolution / baseConfig->resolution;
	double frameSizeFactor = (1000 / cfg.frequency) / (1000 / baseConfig->frequency);
	cfg.posInit = (int) baseConfig->posInit * resolutionFactor * frameSizeFactor;
	cfg.posStraight = (int) baseConfig->posStraight * resolutionFactor * frameSizeFactor;
	cfg.posMinLeft = (int) baseConfig->posMinLeft * resolutionFactor * frameSizeFactor;
	cfg.posMaxLeft = (int) baseConfig->posMaxLeft * resolutionFactor * frameSizeFactor;
	cfg.posMinRight = (int) baseConfig->posMinRight * resolutionFactor * frameSizeFactor;
	cfg.posMaxRight = (int) baseConfig->posMaxRight * resolutionFactor * frameSizeFactor;

	if (pwm->setPwm(cfg.address, cfg.posInit)) {
		currentPos = cfg.posInit;
		ready = 1;
	}
	return ready;
}

/****************************************************************/
int PwmServo::isReady(void) { return ready; }

/****************************************************************/
void PwmServo::printStatus (void)
{
	cout << "SERVO STATUS" << endl;
	cout << "------------" << endl << endl;
	cout << "Is Ready      :  " << (isReady() ? "Yes" : "No") << endl;
	cout << "Frequency     :  " << cfg.frequency << endl;
	cout << "Resolution    :  " << cfg.resolution << endl;
	cout << "Initial Pos   :  " << cfg.posInit << endl;
	cout << "Straight      :  " << cfg.posStraight << endl;
	cout << "Min Left      :  " << cfg.posMinLeft << endl;
	cout << "Max Left      :  " << cfg.posMaxLeft << endl;
	cout << "Min Right     :  " << cfg.posMinRight << endl;
	cout << "Max Right     :  " << cfg.posMaxRight << endl;
	cout << endl;
}


/****************************************************************/
int PwmServo::straight (void)
{
	int result = -1;
	if (ready && pwm->isReady())
		result = pwm->setPwm(cfg.address, cfg.posStraight);
	if (result) currentPos = cfg.posStraight;
	return result;
}

/****************************************************************/
int PwmServo::setPwm (int value)
{
	int result = -1;
	if (ready && pwm->isReady())
		result = pwm->setPwm(cfg.address, value);
	if (result) currentPos = value;
	return result;
}

/****************************************************************/
int PwmServo::leftPct (int percent)
{
	int result = -1;
	int value;
	if (percent == 0) value = cfg.posStraight;
	else value = (int) ((abs(cfg.posMaxLeft - cfg.posMinLeft) / 100) * percent) + fmin(cfg.posMinLeft, cfg.posMaxLeft);
	if (ready && pwm->isReady())
		result = pwm->setPwm(cfg.address, value);
	if (result) currentPos = value;
	return result;
}

/****************************************************************/
int PwmServo::rightPct (int percent)
{
	int result = -1;
	int value;
	if (percent == 0) value = cfg.posStraight;
	else value = (int) ((abs(cfg.posMaxRight - cfg.posMinRight) / 100) * percent) + fmin(cfg.posMinRight, cfg.posMaxRight);
	if (ready && pwm->isReady())
		result = pwm->setPwm(cfg.address, value);
	if (result) currentPos = value;
	return result;
}


/****************************************************************/
int PwmServo::getPwm (void)
{
	int result = -1;
	if (ready && pwm->isReady())
		result = pwm->getPwm(cfg.address);
	return result;
}

