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
	int mode;
	int pct;
	int pin;

	car.printStatus();

	if (car.isReady()) {
		car.stop();
		in = "";
		while (in != "quit") {

			while (in != "W" && in != "w" && in != "P" && in != "p" && in != "Q" && in != "q") {
				cout << "(W)heels, (P)ower, P(i)n control, (Q)uit : ";
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

			if (in == "i" || in == "I") {
				pct = 0;
				pin = -1;
				cout << "Which pin: ";
				cin >> in;
				try { pin = stoi(in); }
				catch (const invalid_argument& e) { }
				if (pin != -1) {
					cout << "Value: ";
					cin >> in;
					try { pct = stoi(in); }
					catch (const invalid_argument& e) { }
					car.getRaspberryPi()->getGpio()->getPin(pin)->setValue(pct);
				}
			}
		}
		Gpio *gp = car.getRaspberryPi()->getGpio();
		gp->getPin(15)->setValue(0);
		gp->getPin(16)->setValue(0);
		gp->getPin(18)->setValue(0);
		gp->getPin(13)->setValue(1);
		delay(150);
		for (int t = 0; t < 10; t++) {
			gp->getPin(15)->setValue(1);
			gp->getPin(13)->setValue(0);
			delay(150);
			gp->getPin(16)->setValue(1);
			gp->getPin(15)->setValue(0);
			delay(150);
			gp->getPin(18)->setValue(1);
			gp->getPin(16)->setValue(0);
			delay(150);
			gp->getPin(16)->setValue(1);
			gp->getPin(18)->setValue(0);
			delay(150);
			gp->getPin(15)->setValue(1);
			gp->getPin(16)->setValue(0);
			delay(150);
			gp->getPin(13)->setValue(1);
			gp->getPin(15)->setValue(0);
			delay(150);
		}
		car.stop();
	}

}



