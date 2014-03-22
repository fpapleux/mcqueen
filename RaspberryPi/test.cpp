/*
 * test.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "RaspberryPi.h"

using namespace std;

int main (int argv, char** args) {

	RaspberryPi* ctrl = new RaspberryPi();
	if (ctrl->isReady())
	{
		cout << "Raspberry Pi is ready" << endl;
		I2cMaster* i2c = ctrl->getI2cMaster();
		if (i2c->isReady())
		{
			cout << "Raspberry Pi's I2C Master is ready" << endl;
		}
		else cout << "Raspberry Pi's I2C Master did not initialize" << endl;
	}
	else cout << "Raspberry Pi did not initialize" << endl;

	delete ctrl;
	return 0;
}



