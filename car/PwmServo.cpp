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
	frequency = BASE_FREQUENCY;
	resolution = BASE_RESOLUTION;
	cfg = config;
	cout << "Base frequency recorded as: " << cfg->baseFrequency << endl;
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
	ready = 1;
}

/****************************************************************/
int PwmServo::isReady(void) { return ready; }


