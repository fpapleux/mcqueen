/*
 * Car.h
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#ifndef CAR_H_
#define CAR_H_

class Car
{

public:
	Car(void);
	~Car(void);
	void reset(void);			// initializes the car system, puts all systems in neutral and ready to begin operating (isReady)

	// managing direction .. returns 1 for success
	int rightPct (int percent);
	int leftPct (int percent);
	int straight ();

	// managing throttle
	int forwardPct (int percent);
	int backwardPct (int percent);
	int stop ();

	// car state information
	int isReady();				// Car initialization was successful
	int isMoving();				// throttle is non-zero
	int isIdle();				// throttle is zero and wheels are not moving
	int getCurrentDirectionPct();	// returns current percentage turn (left is negative. idle is 0. right is positive)
	int getCurrentSpeedPct();		// returns current speed in % (backward is negative. idle is 0. forward is positive)

private:
	int ready;

};

#endif /* CAR_H_ */
