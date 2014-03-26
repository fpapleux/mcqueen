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
	int b;
	Car car;
	if (car.isReady()) {
		car.printStatus();
		for (int i = 0; i < 5; i++) {
			for (b = -100; b < 100; b++) {
				car.turnPct(b);
				delay(10);
			}
			for (b = 100; b > -100; b--) {
				car.turnPct(b);
				delay(10);
			}
		}
	}

}



