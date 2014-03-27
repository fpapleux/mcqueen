/*
 * PwmServo.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "PCA9685.h"
#include "PwmServo.h"

using namespace std;

/****************************************************************/
PwmServo::PwmServo (PwmServoConfig* config, PCA9685* controller)
{
	ready = 0;
	baseConfig = config;
	currentPos = -1;
	pwm = controller;
	init();
}

/****************************************************************/
PwmServo::~PwmServo(void)
{
	pwm->setPwm(cfg.channel, cfg.posInit);
}

/****************************************************************/
int PwmServo::init(void)
{
	ready = 0;
	if (! pwm->isReady()) pwm->reset();
	if (! pwm->isReady()) {
		cout << "PWM Controller could not be initialized." << endl;
		exit(1);
	}
	cfg.frequency = pwm->getFrequency();
	cfg.resolution = pwm->getResolution();
	cfg.channel = baseConfig->channel;

	double resolutionFactor = cfg.resolution / baseConfig->resolution;
	double frameSizeFactor = (1000 / cfg.frequency) / (1000 / baseConfig->frequency);
	cfg.posInit = (int) baseConfig->posInit * resolutionFactor * frameSizeFactor;
	cfg.posStraight = (int) baseConfig->posStraight * resolutionFactor * frameSizeFactor;
	cfg.posMinLeft = (int) baseConfig->posMinLeft * resolutionFactor * frameSizeFactor;
	cfg.posMaxLeft = (int) baseConfig->posMaxLeft * resolutionFactor * frameSizeFactor;
	cfg.posMinRight = (int) baseConfig->posMinRight * resolutionFactor * frameSizeFactor;
	cfg.posMaxRight = (int) baseConfig->posMaxRight * resolutionFactor * frameSizeFactor;

	// cout << "Sending " << cfg.posInit << " to the car's servo for initialization." << endl;
	pwm->setPwm(cfg.channel, cfg.posInit);
	currentPos = cfg.posInit;
	ready = 1;
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
int PwmServo::setPwm (int value)
{
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, value);
		currentPos = value;
	}
	return 1;
}

/****************************************************************/
int PwmServo::straight (void)
{
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, cfg.posStraight);
		currentPos = cfg.posStraight;
	}
	return 1;
}

/****************************************************************/
int PwmServo::leftPct (int percent)
{
	int value;
	int pctValue = (abs(cfg.posMaxLeft - cfg.posMinLeft) / 100) * percent;
	if (percent == 0) value = cfg.posStraight;
	else value = (fmin(cfg.posMinLeft, cfg.posMaxLeft) == cfg.posMinLeft ? cfg.posMinLeft + pctValue : cfg.posMinLeft - pctValue);
	cout << "Moving to position left " << percent << "% with value " << value << " based on min " << cfg.posMinLeft << " and max " << cfg.posMaxLeft << endl;
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, value);
		currentPos = value;
	}
	return 1;
}

/****************************************************************/
int PwmServo::rightPct (int percent)
{
	int value;
	int pctValue = (abs(cfg.posMaxRight - cfg.posMinRight) / 100) * percent;
	if (percent == 0) value = cfg.posStraight;
	else value = (fmin(cfg.posMinRight, cfg.posMaxRight) == cfg.posMinRight ? cfg.posMinRight + pctValue : cfg.posMinRight - pctValue);
	// cout << "Moving to position right " << percent << "% with value " << value << " based on min " << cfg.posMinRight << " and max " << cfg.posMaxRight << endl;
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, value);
		currentPos = value;
	}
	return 1;
}


/****************************************************************/
int PwmServo::turnPct (int percent)
{
	if (! percent) return straight();
	else if (percent < 0) return leftPct(abs(percent));
	else return rightPct (percent);
}

/****************************************************************/
int PwmServo::getPwm (void)
{
	int result = -1;
	if (ready && pwm->isReady())
		result = pwm->getPwm(cfg.channel);
	return result;
}

