/*
 * DigitalPin.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef DIGITALPIN_H_
#define DIGITALPIN_H_

#define 	HIGH		1
#define		LOW			0

class DigitalPin {

public:
	virtual ~DigitalPin();
	virtual int get();
	virtual void set(int value);
	virtual void setMode(int mode);

private:

};

#endif /* DIGITALPIN_H_ */
