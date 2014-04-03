/*
 * Pin.h
 *
 *  Created on: Apr 2, 2014
 *      Author: fabien papleux
 */

#ifndef PIN_H_
#define PIN_H_

class Pin
{
public:
	Pin (const char *name);
	~Pin (void);
	int init (void);
	int isReady (void);
	void printStatus (void);
	
	const char *getName (void);
	int getMode (void);
	int getValue (void);
	int getTrigger (void);
	
	int setMode (int newMode);
	int setValue (int newValue);
	int setTrigger (int newTrigger);
	
private:
	int ready;
	char name[5];
};




#endif /* PIN_H_ */
