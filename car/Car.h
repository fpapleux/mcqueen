/*
 * Car.h
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#ifndef CAR_H_
#define CAR_H_

#include "PwmServo.h"
#include "PCA9685.h"
#include "I2cBus.h"

class Car
{

public:
	Car (void);
	~Car (void);
	void init (void);			// initializes the car system, puts all systems in neutral and ready to begin operating (isReady)
	void printStatus (void);	// prints full status of the car

	// managing direction .. returns 1 for success
	//int 	rightPct (int percent);
	//int 	leftPct (int percent);
	//int 	straight (void);

	// managing throttle
	//int 	forwardPct (int percent);
	//int 	backwardPct (int percent);
	//int 	stop (void);

	// car state information
	int 	isReady (void);					// Car initialization was successful
	//int 	isMoving (void);				// throttle is non-zero
	//int 	isIdle (void);					// throttle is zero and wheels are not moving

	PwmServo*		getServo (void);			// returns a pointer to the servo for querying
	PCA9685*		getPCA9685 (void);		 	// returns a pointer to the PwmController
	I2cBus*			getI2cBus (void);			// returns a pointer to the I2cBus object

	//int 	getCurrentDirectionPct (void);	// returns current % turn (left is negative. idle is 0. right is positive)
	//int 	getCurrentSpeedPct (void);		// returns current speed in % (backward is negative. idle is 0. forward is positive)

private:
	int 			ready;
	PwmServoConfig	servoConfig;
	PwmServo		*servo;						// points to the servo motor of the car
	PCA9685			*pwm;
	I2cBus			*i2c;
	//static MicroController mc();
};

#endif /* CAR_H_ */
