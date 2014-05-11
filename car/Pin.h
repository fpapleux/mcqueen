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



class Pin
{
public:
	Pin (int number);		// expects official GPIO number
	~Pin (void);
	int init (void);
	int isReady (void);
	void printStatus (void);

	/*
	string	getMode		(void);
	int 	getValue	(void);

	int 	setMode		(string newMode);
	int 	setValue	(int newValue);
	
	int		pinExport	(void);
	int		pinUnexport	(void);
	*/
	
private:
	int ready;
	int pinNumber;		// GPIO number
	int wpiNumber;		// wiringPi number

};




#endif /* PIN_H_ */
