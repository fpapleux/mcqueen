/*
 * RaspberryPi.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien papleux
 *
 *  Software based on the wiringPi library, by Gordon Henderson, http://wiringpi.com
 *  See bottom of the document for wiringPi technical information from the site.
 *  I copied the information from the site to be able to develop while offline.
 *
 */

#ifndef RASPBERRYPI_H_
#define RASPBERRYPI_H_

#include "I2cMaster.h"

#define I2C_SLAVE	0x0703

class RaspberryPi
{
public:
	RaspberryPi			(void);
	~RaspberryPi		(void);

	void	init		(void);
	void	delay 		(int milliseconds);
	int		millis 		(void);

	int		isReady		(void);		// Indicates that the init sequence was successful
	int		isI2cReady	(void);	// Indicates whether or not the I2C bus was initialized.

	int 	getPiRev	(void);
	I2cMaster*		getI2cMaster	(char* busName = ""); // Bus numbers should be included between quotes

	// DigitalPin*		getPin			(char* pinName = ""); // Pin numbers should be included between quotes

protected:
	// DigitalPin**	digitalPins;
	I2cMaster*		i2cMaster;

private:
	int 	ready;				// Indicates that the controller was initialized successfully
	int 	piRev;				// Holds Pi board revision (0 for Rev.A, 1 for Rev.B)
	int		i2cReady;
	char	i2cMasterPath[40];
	int		i2cFd;

	void	close				(void);
	void	initDigitalPins		(void);
	void	initI2cMaster		(void);

};

#endif /* RASPBERRYPI_H_ */

/*
 * WiringPi defines 17 pins, (21 on a Rev. 2 board) but some of them and the functions we can
 * use may potentially cause problems with other parts of the Raspberry Pi Linux system.
 *
 * Pins 0 through 6 (BCM_GPIO 17, 18,  21, 22, 23, 24, 25 respectively, substitute 27 for 21 on a Rev. 2 board):
 * These are safe to use at any time and can be set to input or output with or without the internal pull-up or
 * pull-down resistors enabled.
 *
 * Pin 7 (BCM_GPIO 4) This is normally OK to use, however it is used by the 1-Wire kernel driver and it can
 * optionally be connected to a GPIO clock source.
 *
 * PWM: You can change the function of pin 1 (BCM_GPIPO 18) to be PWM output, however if you are currently
 * playing music or using the audio system via the 3.5mm jack socket, then you’ll find one channel of audio
 * PWM coming through the pin! If you are not using the audio at all, (or the audio is going via the HDMI
 * cable), then this pin is free to be used in PWM mode.
 *
 * Pins 8 and 9 (BCM GPIO 0 and 1 on a Rev. 1 board, 2 and 3 on a Rev. 2 board): These are the I2C pins.
 * You may use them for digital IO if you are not using any I2C drivers which use these pins, however note
 * that they have on-board 1.8KΩ resistors pulling the signals to the 3v3 supply. This feature does make
 * them handy for switch inputs where the switch simply shorts the pin to ground without having to enable
 * the internal pull-up resistors.
 *
 * Pins 10, 11, 12, 13 and 14 (GPIO 8, 7, 10, 9 and 11 respectively): These are used for the SPI interface.
 * Like the I2C interface, if you are not using it, then you can freely use them for your own purposes.
 * Unlike I2C, these pins do not have any external pull up (or pull down) resistors.
 *
 * Pins 15 and 16 (GPIO 14 and 15): These are used by the UART for Tx and Rx respectively. If you want to use
 * these pins as general purpose I/O pins then you need to make sure that you reboot your Pi with the
 * serial console disabled. See the file /boot/cmdline.txt and edit it appropriately.
 *
 * Pins 17, 18, 19 and 20: (BCM_GPIO 28, 29, 30 and 31) These are additional GPIO pins on the Rev. 2 board.
 *
 */
