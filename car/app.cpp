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
		car.stop();
		for (int i = 0; i < 5; i++) {
			car.speedPct(i * 14);
			for (b = -100; b < 100; b++) {
				car.turnPct(b);
				delay(5);
			}
			for (b = 100; b > -100; b--) {
				car.turnPct(b);
				delay(5);
			}
		}
		car.stop();
	}

}



