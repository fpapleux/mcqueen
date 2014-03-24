/*
 * PwmServo.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "PwmServo.h"

using namespace std;

/****************************************************************/
PwmServo::PwmServo (PwmServoConfig* config)
{
	cfg.frequency = BASE_FREQUENCY;
	cfg.resolution = BASE_RESOLUTION;
	baseConfig = config;
	cout << "Base frequency recorded as: " << baseConfig->frequency << endl;
	ready = -1;
	reset();
}

/****************************************************************/
PwmServo::~PwmServo(void)
{
}

/****************************************************************/
void PwmServo::reset(void)
{
	double resolutionFactor = cfg.resolution / baseConfig->resolution;
	double frameSizeFactor = (1000 / cfg.frequency) / (1000 / baseConfig->frequency);
	cfg.posIdle = (int) baseConfig->posIdle * resolutionFactor * frameSizeFactor;
	cfg.posMinLeft = (int) baseConfig->posMinLeft * resolutionFactor * frameSizeFactor;
	cfg.posMaxLeft = (int) baseConfig->posMaxLeft * resolutionFactor * frameSizeFactor;
	cfg.posMinRight = (int) baseConfig->posMinRight * resolutionFactor * frameSizeFactor;
	cfg.posMaxRight = (int) baseConfig->posMaxRight * resolutionFactor * frameSizeFactor;
	ready = 1;
}

/****************************************************************/
int PwmServo::isReady(void) { return ready; }


/****************************************************************/
int PwmServo::setFrequency (int freq) { cfg.frequency = freq; reset(); }

/****************************************************************/
int PwmServo::setResolution (int resolution) { cfg.resolution = resolution; reset(); }

