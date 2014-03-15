/* GPIO.H
 * 
 * (c) Copyright 2014, Fabien Papleux, All Rights Reserved.
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
		int ready; // Indicates whether Gpio is ready for use
	
	public:
		Gpio(void);
		~Gpio(void);
		int isReady(void);
		int initialize(void);
		void pinMode(int pin, int mode);
		void digitalWrite(int pin, int value);
		int digitalRead(int pin);
};

#endif
