/*
 * PwmLvSonarEz2.h
 *
 *  Created on: Jul 2, 2014
 *      Author: fabien papleux
 */

#ifndef PWMLVSONAREZ2_H_
#define PWMLVSONAREZ2_H_

#include "PCA9685.h"

/*** This class requires a PWM controller class (implemented here as PCA9685) where to send the following commands:
 *
 * int reset (void)							// resets controller
 * int isReady (void)						// returns 1 if controller is ready
 * int getFrequency ()						// Returns the current frequency used by the controller to determine pulse width
 * int getResolution (void)					// Returns the current resolution of the PWM controller (PCA9685 is standard at 12)
 * int setPwm (int channel, int data)		// Sets the stop PWM value for a channel.  (the start value is to be assumed as 0)
 * int getPwm (int channel)					// Gets the current stop value of the PWM
 *
 */

/* 50Hz is the typical clock for servos. it means the controller runs 50 cycles in 1 second,
 * which means that each cycle is 20ms. Servos typically require to be high for 1ms per frame
 * to be full on one side, 1.5ms to be in the middle and 2ms to be full on the other side.
 * If your controller is a PCA9685 (like the Adafruit 16-channel 12-bit controller), the 12-bit
 * definition means that your frame's scale goes from 0 to 4095.
 *
 * If your frame is 20ms and you want to be up for 1ms, you need to be up for 1/20th of the
 * size of your frame, which would be 4096 / 20 = 205.
 */


class PwmLvSonarEz2
{
public:
	PwmLvSonarEz2 (PCA9685 *controller, int myChannel, Pin *onPin);
	~PwmLvSonarEz2 (void);

	int		init (void);
	int		isReady (void);
	void	printStatus(void);

	int on (void);
	int off (void);
	int getPwm (void);

private:
	int ready;
	int lastPwm;					// Holds the current PWM value (position)
	int channel;
	Pin *pin;
	PCA9685 *pwm;					// pointer to a PWM controller, the address of which should be provided at creation time
};




#endif /* PWMLVSONAREZ2_H_ */
