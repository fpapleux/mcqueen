/*
 * PwmEsc.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <wiringPi.h>
#include "PCA9685.h"
#include "PwmEsc.h"

using namespace std;

/****************************************************************/
PwmEsc::PwmEsc (PwmEscConfig* config, PCA9685* controller)
{
	ready = 0;
	baseConfig = config;
	currentPos = -1;
	pwm = controller;
	init();
}

/****************************************************************/
PwmEsc::~PwmEsc(void)
{
	pwm->setPwm(cfg.channel, cfg.posInit);
}

/****************************************************************/
int PwmEsc::init(void)
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
	cfg.posIdle = (int) baseConfig->posIdle * resolutionFactor * frameSizeFactor;
	cfg.posMinForward = (int) baseConfig->posMinForward * resolutionFactor * frameSizeFactor;
	cfg.posMaxForward = (int) baseConfig->posMaxForward * resolutionFactor * frameSizeFactor;
	cfg.posMinBackward = (int) baseConfig->posMinBackward * resolutionFactor * frameSizeFactor;
	cfg.posMaxBackward = (int) baseConfig->posMaxBackward * resolutionFactor * frameSizeFactor;

	// cout << "Sending " << cfg.posInit << " to the car's servo for initialization." << endl;
	pwm->setPwm(cfg.channel, cfg.posMaxForward);
	delay(100);
	pwm->setPwm(cfg.channel, cfg.posIdle);
	delay(100);
	pwm->setPwm(cfg.channel, cfg.posInit);
	currentPos = cfg.posInit;
	ready = 1;
	return ready;
}

/****************************************************************/
int PwmEsc::isReady(void) { return ready; }

/****************************************************************/
void PwmEsc::printStatus (void)
{
	cout << "PWM ESC STATUS" << endl;
	cout << "--------------" << endl << endl;
	cout << "Is Ready      :  " << (isReady() ? "Yes" : "No") << endl;
	cout << "Frequency     :  " << cfg.frequency << endl;
	cout << "Resolution    :  " << cfg.resolution << endl;
	cout << "Initial Pos   :  " << cfg.posInit << endl;
	cout << "Idle          :  " << cfg.posIdle << endl;
	cout << "Min Forward   :  " << cfg.posMinForward << endl;
	cout << "Max Forward   :  " << cfg.posMaxForward << endl;
	cout << "Min Backward  :  " << cfg.posMinBackward << endl;
	cout << "Max Backward  :  " << cfg.posMaxBackward << endl;
	cout << endl;
}


/****************************************************************/
int PwmEsc::setPwm (int value)
{
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, value);
		currentPos = value;
	}
	return 1;
}

/****************************************************************/
int PwmEsc::stop (void)
{
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, cfg.posIdle);
		currentPos = cfg.posIdle;
	}
	return 1;
}

/****************************************************************/
int PwmEsc::forwardPct (int percent)
{
	int value;
	int pctValue = (abs(cfg.posMaxForward - cfg.posMinForward) / 100) * percent;
	cout << "pctValue=" << pctValue << endl;
	if (percent == 0) value = cfg.posIdle;
	else value = (fmin(cfg.posMinForward, cfg.posMaxForward) == cfg.posMinForward ? cfg.posMinForward + pctValue : cfg.posMinForward - pctValue);
	cout << "Moving to position forward " << percent << "% with value " << value << " based on min " << cfg.posMinForward << " and max " << cfg.posMaxForward << endl;
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, value);
		currentPos = value;
	}
	return 1;
}

/****************************************************************/
int PwmEsc::backwardPct (int percent)
{
	int value;
	int pctValue = (abs(cfg.posMaxBackward - cfg.posMinBackward) / 100) * percent;
	if (percent == 0) value = cfg.posIdle;
	else value = (fmin(cfg.posMinBackward, cfg.posMaxBackward) == cfg.posMinBackward ? cfg.posMinBackward + pctValue : cfg.posMinBackward - pctValue);
	cout << "Moving to position backward " << percent << "% with value " << value << " based on min " << cfg.posMinBackward << " and max " << cfg.posMaxBackward << endl;
	if (ready && pwm->isReady()) {
		pwm->setPwm(cfg.channel, value);
		currentPos = value;
	}
	return 1;
}


/****************************************************************/
int PwmEsc::speedPct (int percent)
{
	cout << "Setting ESC PWM to " << percent << "%" << endl;
	if (! percent) return stop();
	else if (percent < 0) return backwardPct(abs(percent));
	else return forwardPct (percent);
}

/****************************************************************/
int PwmEsc::getPwm (void)
{
	int result = -1;
	if (ready && pwm->isReady())
		result = pwm->getPwm(cfg.channel);
	return result;
}




