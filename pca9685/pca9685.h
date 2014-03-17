/* PCA9685.H
 * Author: Fabien Papleux
 *
 *
 */

#ifndef __PCA9685_H_
#define __PCA9685_H_

#include "../gpio/gpio.h"

using namespace std;

#define OSC_CLOCK 			25000000
#define SCALE					4096
#define PRESCALE_REG			0xfe

#define MODE1					0x00
#define MODE1_RESTART		0x80
#define MODE1_EXTCLK			0x40
#define MODE1_AI				0x20
#define MODE1_SLEEP			0x10
#define MODE1_SUB1			0x08
#define MODE1_SUB2			0x04
#define MODE1_SUB3			0x02
#define MODE1_ALLCALL		0x01

#define DEFAULT_PWM_FREQ	50		// 50Hz creates a 20ms pulse width, standard for Servos/ESC
#define DEFAULT_ADDRESS		0x40

class pca9685
{
	public:
		pca9685 (void);
		~pca9685 (void);
		int init();
		int init(int newAddr);
		int init(int newAddr, int newFrequency);
		int setPwmFrequency(int newFrequency);
		void setAddress (int newAddr);
		int sleep();
		int awaken();
		int setPwm(int channel, int start, int stop); // channel is 0-15 for each channel


	// private:
		Gpio* gpio;
		int address;
		int pwmFrequency;
		int mode1Reg;

};

#endif
