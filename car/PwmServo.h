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

#define	BASE_OSCCLOCK		25000000
#define	BASE_FREQUENCY		50
#define BASE_RESOLUTION		4096

struct PwmServoConfig {
	int frequency;		// in Hz
	int resolution;		// resolution of the PWM value (PCA9685 is a 12-bit resolution so values should range from 0 to 4095, which means the value here should be 4096)
	int posIdle;		// value for idle position
	int posMinLeft;		// in principle, this will be idle+-1.  For ESC's, which use the same technology, there could be a difference between purely idle and the beginning of movement
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

	int setFrequency (int freq);			// Calling this function triggers a reset of the device
	int setResolution (int resolution);		// Calling this function triggers a reset of the device

	// int leftPct (int percent);
	// int rightPct (int percent);
	// int straight (void);

private:
	int ready;
	PwmServoConfig cfg;				// actual configuration used to manipulate the servo
	PwmServoConfig* baseConfig;		// config provided by user at initialization to be used as base during operation
};

#endif /* PWMSERVO_H_ */
