/* GPIO.H
 * 
 * Author: Fabien Papleux
 * 
 * Thanks: Gordon Henderson for wiringPi
 * 
 * The GPIO library forms a class wrapper for the wiringPi functions.
 * I am only implementing the methods and properties that I want to
 * leverage in other parts of the code.
 * 
 * This library uses the pin numbering used by wiringPi.
 * +----------+-Rev2-+------+--------+------+-------+
 * | wiringPi | GPIO | Phys | Name   | Mode | Value |
 * +----------+------+------+--------+------+-------+
 * |      0   |  17  |  11  | GPIO 0 | IN   | Low   |
 * |      1   |  18  |  12  | GPIO 1 | IN   | Low   |
 * |      2   |  27  |  13  | GPIO 2 | IN   | Low   |
 * |      3   |  22  |  15  | GPIO 3 | IN   | Low   |
 * |      4   |  23  |  16  | GPIO 4 | IN   | Low   |
 * |      5   |  24  |  18  | GPIO 5 | IN   | Low   |
 * |      6   |  25  |  22  | GPIO 6 | IN   | Low   |
 * |      7   |   4  |   7  | GPIO 7 | IN   | Low   |
 * |      8   |   2  |   3  | SDA    | ALT0 | High  | -- I2C
 * |      9   |   3  |   5  | SCL    | ALT0 | High  | -- I2C
 * |     10   |   8  |  24  | CE0    | ALT0 | High  |
 * |     11   |   7  |  26  | CE1    | ALT0 | High  |
 * |     12   |  10  |  19  | MOSI   | ALT0 | Low   |
 * |     13   |   9  |  21  | MISO   | ALT0 | Low   |
 * |     14   |  11  |  23  | SCLK   | ALT0 | Low   |
 * |     15   |  14  |   8  | TxD    | ALT0 | High  | -- serial
 * |     16   |  15  |  10  | RxD    | ALT0 | High  | -- serial
 * |     17   |  28  |   3  | GPIO 8 | ALT2 | Low   |
 * |     18   |  29  |   4  | GPIO 9 | ALT2 | Low   |
 * |     19   |  30  |   5  | GPIO10 | ALT2 | Low   |
 * |     20   |  31  |   6  | GPIO11 | ALT2 | Low   |
 * +----------+------+------+--------+------+-------+
 * 
 */ 

#ifndef __GPIO_H
#define __GPIO_H

using namespace std;

class Gpio
{
	private:
		int ready;				// Indicates whether Gpio is ready for use
		int piRev;				// 0 for Rev.A and 1 for Rev.B, as returned by piRevBoard
		const char* i2cMaster;	// Name of the I2C bus master on the Raspi
		int i2cSlave;			// Keeps number of the last i2c slave selected
		int i2cFd;				// file descriptor for the current I2C bus
	
	public:
		Gpio(void);
		~Gpio(void);
		
		// Basic Pi/GPIO interface
		int 	init			(void);
		int 	isReady			(void);
		int		piBoardRev		(void);
		void 	pinMode			(int pin, int mode);
		void 	digitalWrite	(int pin, int value);
		int 	digitalRead		(int pin);
		
		// I2C interface -- uses physical pin 3 for SDA and 5 for SCL
		// Note: this implementation wraps wiringPi a little differently
		// in order to make it easier to implement multiple I2C devices
		int 	i2cInit();
		int 	i2cIsReady();
		int		i2cConnectSlave	(int address);
		int		i2cRead			(int dev);
		int		i2cReadReg8		(int dev, int reg);
		int		i2cReadReg16	(int dev, int reg);
		int		i2cWrite		(int dev, int data);
		int		i2cWriteReg8	(int dev, int reg, int data);
		int		i2cWriteReg16 	(int dev, int reg, int data);
		
		// Arduino methods from the wiringPi module
		void	delay			(unsigned int howLong);
		void	delayMicroseconds (unsigned int howLong);
		unsigned int millis	(void);
		unsigned int micros	(void);

};

#endif
