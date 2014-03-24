/*
 * PwmServo.h
 *
 *  Created on: Mar 23, 2014
 *      Author: fabien papleux
 */

#ifndef PWMSERVO_H_
#define PWMSERVO_H_

// Update these depending on servo use

/* 50Hz is the typical clock for servos. it means the controller runs 50 cycles in 1 second,
 * which means that each cycle is 20ms. Servos typically require to be high for 1ms per frame
 * to be full on one side, 1.5ms to be in the middle and 2ms to be full on the other side.
 * If your controller is a PCA9685 (like the Adafruit 16-channel 12-bit controller), the 12-bit
 * definition means that your frame's scale goes from 0 to 4095.
 *
 * If your frame is 20ms and you want to be up for 1ms, you need to be up for 1/20th of the
 * size of your frame, which would be 4096 / 20 = 205.
 */

#define	BASE_FREQUENCY		50
#define BASE_RESOLUTION		4096

struct PwmServoConfig {
	int baseFrequency;
	int baseResolution;
	int posIdle;
	int posMinLeft;
	int posMaxLeft;
	int posMinRight;
	int posMaxRight;
};

class PwmServo
{
public:
	PwmServo (PwmServoConfig* config);
	~PwmServo (void);
	void reset (void);
	int isReady (void);

	// int leftPct (int percent);
	// int rightPct (int percent);
	// int straight (void);

private:
	int ready;
	int frequency;
	int resolution;
	PwmServoConfig* cfg;
};

#endif /* PWMSERVO_H_ */
