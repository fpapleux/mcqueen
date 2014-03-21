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



	delete ctrl;
	return 0;
}



