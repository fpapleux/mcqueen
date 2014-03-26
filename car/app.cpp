/*
 * app.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <wiringPi.h>
#include "Car.h"

using namespace std;

int main (int argv, char** args) {
	Car car;
	if (car.isReady()) {
		car.printStatus();
		for (int i = 0; i < 10; i++) {
			car.leftPct(80);
			delay(1000);
			car.straight();
			delay(1000);
			car.rightPct(80);
			delay(1000);
			car.straight();
		}
	}

}



