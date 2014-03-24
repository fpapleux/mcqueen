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
	currentPos = -1;
	reset();
}

/****************************************************************/
PwmServo::~PwmServo(void)
{
}

/****************************************************************/
void PwmServo::reset(void)
{
	ready = -1;
	double resolutionFactor = cfg.resolution / baseConfig->resolution;
	double frameSizeFactor = (1000 / cfg.frequency) / (1000 / baseConfig->frequency);
	cfg.posInit = (int) baseConfig->posInit * resolutionFactor * frameSizeFactor;
	cfg.posStraight = (int) baseConfig->posStraight * resolutionFactor * frameSizeFactor;
	cfg.posMinLeft = (int) baseConfig->posMinLeft * resolutionFactor * frameSizeFactor;
	cfg.posMaxLeft = (int) baseConfig->posMaxLeft * resolutionFactor * frameSizeFactor;
	cfg.posMinRight = (int) baseConfig->posMinRight * resolutionFactor * frameSizeFactor;
	cfg.posMaxRight = (int) baseConfig->posMaxRight * resolutionFactor * frameSizeFactor;

	// Insert code here to initialize the servo itself and set its position to posInit

	currentPos = cfg.posInit; //
	ready = 1;
}

/****************************************************************/
int PwmServo::isReady(void) { return ready; }

/****************************************************************/
void PwmServo::setFrequency (int freq) { cfg.frequency = freq; reset(); }

/****************************************************************/
void PwmServo::setResolution (int resolution) { cfg.resolution = resolution; reset(); }

/****************************************************************/
void PwmServo::printStatus (void) {
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
