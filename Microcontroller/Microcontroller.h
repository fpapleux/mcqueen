/*
 * Microcontroller.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 */

#ifndef MICROCONTROLLER_H_
#define MICROCONTROLLER_H_

class Microcontroller {

public:
	Microcontroller(void);
	virtual ~Microcontroller(void);

	virtual void init (void);
	virtual void close ();
	virtual DigitalPin* getPin (char* pinName = "");		// Pin numbers should be included between quotes
	virtual I2cMaster* getI2cMaster (char* busName = "");		// Bus numbers should be included between quotes

protected:
	virtual void initDigitalPins (void);
	virtual void initI2cBus (void);

private:

};

#endif /* MICROCONTROLLER_H_ */
