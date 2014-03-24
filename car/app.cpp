/*
 * app.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "Car.h"

using namespace std;

int main (int argv, char** args) {
	Car car;
	if (car.isReady()) {
		car.printStatus();
	}

}



