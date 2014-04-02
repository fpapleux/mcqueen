/*
 * Gpio.h
 *
 *  Created on: Apr 1, 2014
 *      Author: fabien papleux
 */

#ifndef GPIO_H_
#define GPIO_H_

class Gpio
{

public:
	Gpio();
	~Gpio();

	int init (void);
	int isReady (void);
	void printStatus (void);

private:
	int ready;

};




#endif /* GPIO_H_ */
