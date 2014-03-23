/*
 * app.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include "Car.h"

int main (int argv, char** args) {
	Car car();
	if (car.isReady()) cout << "The car is ready" << endl;

}



