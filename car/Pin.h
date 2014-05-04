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

#define EXPORT_PATH		"/sys/class/gpio/export"
#define	UNEXPORT_PATH	"/sys/class/gpio/unexport"
#define PIN_PATH		"/sys/class/gpio/"			// add pin name number to this path
#define	VALUE_PATH		"/value"						// append to pin path + pin number
#define DIRECTION_PATH	"/direction"

#define HIGH			1
#define LOW				0

using namespace std;

class Pin
{
public:
	Pin (const char *name);
	~Pin (void);
	int init (void);
	int isReady (void);
	void printStatus (void);
	
	string	getMode		(void);
	int 	getValue	(void);

	int 	setMode		(string newMode);
	int 	setValue	(int newValue);
	
	int		pinExport	(void);
	int		pinUnexport	(void);
	
private:
	int ready;
	string name;

};




#endif /* PIN_H_ */
