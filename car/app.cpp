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
	int pct;

	car.printStatus();

	if (car.isReady()) {
		car.stop();
		in = "";
		while (in != "quit") {

			while (in != "W" && in != "w" && in != "P" && in != "p" && in != "Q" && in != "q") {
				cout << "(W)heels, (P)ower (Q)uit : ";
				cin >> in;
			}

			if (in == "p" || in == "P") {
				pct = 0;
				cout << "Set % throttle to: ";
				cin >> in;
				try { pct = stoi(in); }
				catch (const invalid_argument& e) { }
				if (pct) { car.speedPct(pct); }
			}

			if (in == "w" || in == "W") {
				pct = 0;
				cout << "Set % turn to: ";
				cin >> in;
				try { pct = stoi(in); }
				catch (const invalid_argument& e) { }
				if (pct) { car.turnPct(pct); }
			}

			if (in == "q" || in == "Q") {
				in = "quit";
			}
		}
		car.stop();
	}

}



