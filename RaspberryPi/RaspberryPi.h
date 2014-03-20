/*
 * RaspberryPi.h
 *
 *  Created on: Mar 19, 2014
 *      Author: fabien
 */

#ifndef RASPBERRYPI_H_
#define RASPBERRYPI_H_

class RaspberryPi
{
public:
	RaspberryPi		(void);
	~RaspberryPi	(void);

	void			delay 			(int milliseconds);
	int				millis 			(void);

	int				isReady (void);	// Indicates that the init sequence was successful

	int 			getPiRev (void);
	DigitalPin*		getPin			(char* pinName = ""); // Pin numbers should be included between quotes
	I2cMaster*		getI2cMaster 	(char* busName = ""); // Bus numbers should be included between quotes

protected:
	DigitalPin**	digitalPins;
	I2cMaster*		i2cMaster;

private:
	int 	ready;				// Indicates that the controller was initialized successfully
	int 	piRev;				// Holds Pi board revision (0 for Rev.A, 1 for Rev.B)

	void	init				(void);
	void	close				(void);
	void	initDigitalPins		(void);
	void	initI2cMaster		(void);

};

#endif /* RASPBERRYPI_H_ */
