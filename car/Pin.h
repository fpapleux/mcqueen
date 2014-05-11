/*
 * Pin.h
 *
 *  Created on: Apr 2, 2014
 *      Author: fabien papleux
 *
 *  This implementation of the Pin class is made for the Raspberry Pi
 */

#ifndef PIN_H_
#define PIN_H_

#include <string>

using namespace std;

#define	MODE_IN		 0
#define	MODE_OUT	 1
#define	VALUE_LOW	 0
#define	VALUE_HIGH	 1


class Pin
{
public:
	Pin (int number);		// expects official GPIO number
	~Pin (void);
	int init (void);
	int isReady (void);
	void printStatus (void);

	int 	setMode		(int newMode);
	int		getMode		(void);

	int 	setValue	(int newValue);
	int 	getValue	(void);
	
private:
	int ready;
	int pinNumber;		// GPIO number
	int wpiNumber;		// wiringPi number

	int mode;			// keeps track of the pin mode
	int value;			// current value of the pin
};




#endif /* PIN_H_ */
