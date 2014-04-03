/*
 * Gpio.h
 *
 *  Created on: Apr 1, 2014
 *      Author: fabien papleux
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Pin.h"

#define	GPIO_4	4

class Gpio
{

public:
	Gpio (int raspiVersion);		// expecting '1' for Raspberry version 1 and '2' for version 2
	~Gpio();

	int init (void);
	int isReady (void);
	void printStatus (void);

private:
	int version;
	int ready;
	Pin pins[32];
};




#endif /* GPIO_H_ */
