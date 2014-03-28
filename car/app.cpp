/*
 * app.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <wiringPi.h>
#include "Car.h"

using namespace std;

int main (int argv, char** args) {

	Car car;
	string in;
	int throttle;

	car.printStatus();

	if (car.isReady()) {
		car.stop();
		in = "";
		while (in != "quit") {
			throttle = 0;
			cout << "Set throttle to: ";
			cin >> in;

			try { throttle = stoi(in); }
			catch (const invalid_argument& e) { }

			if (throttle) { car.getEsc()->setPwm(throttle); }
		}
		car.stop();
	}

}



