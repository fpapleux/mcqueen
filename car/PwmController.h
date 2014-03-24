/*
 * PwmController.h
 *
 *  Created on: Mar 24, 2014
 *      Author: fabien papleux
 */

#ifndef PWMCONTROLLER_H_
#define PWMCONTROLLER_H_

class PwmController
{
public:
	PwmController(void);
	~PwmController(void);

	 int init (void);						// initializes the controller
	 int isReady (void);					// returns 1 if controller is ready
	 int getPwmFrequency (void);			// Returns the current frequency
	 int getPwmResolution (void);			// Returns the current resolution used by the PWM controller
	 int setPwm (int address, int data);	// Sets the start & stop PWM value for me (still figure out meRef)
	 int getPwm (int address);				// Gets the stop value of the PWM
	 int printStatus (void);				// Sends detailed status of the controller to the screen

private:
	 int ready;

};




#endif /* PWMCONTROLLER_H_ */
