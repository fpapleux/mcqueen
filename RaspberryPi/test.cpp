/*
 * test.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "RaspberryPi.h"
#include "I2cMaster.h"
#include "I2cSlave_PCA9685.h"

using namespace std;

int main (int argv, char** args) {

	RaspberryPi* ctrl = new RaspberryPi();

	if (! ctrl->isReady()) { cout << "Raspberry Pi is ready" << endl; return 1; }
	cout << "Raspberry Pi is ready" << endl;

	I2cMaster* i2c = ctrl->getI2cMaster();
	if (! i2c->isReady()) { cout << "Raspberry Pi's I2C Master did not initialize" << endl; return 1; }
	cout << "Raspberry Pi's I2C Master is ready" << endl;

	I2cSlave_PCA9685* i2cSlave = (I2cSlave_PCA9685*) i2c->addI2cSlave(I2C_PCA9685, 0x40);
	if (i2cSlave == NULL)  { cout << "PCA9685 did not initialize" << endl; return 1; }
	cout << "PCA9685 connected." << endl;


	delete ctrl;
	return 0;
}



