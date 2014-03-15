#include <iostream>
#include <wiringPi.h>

#include "gpio.h"

using namespace std;

int main(int argc, char **argv)
{
	Gpio gpio;
	if (gpio.setup()) 
		cout << "GPIO is ready to go" << endl;
	else
	{
		cout << "GPIO is not ready. Make sure wiringPi is properly installed." << endl;
		return 1;
	}
	gpio.pinMode(7, OUTPUT);
	gpio.digitalWrite(7, HIGH);
	gpio.delay(400);
	gpio.digitalWrite(7, LOW);
	gpio.delay(400);
	gpio.digitalWrite(7, HIGH);
	gpio.delay(400);
	gpio.digitalWrite(7, LOW);
	gpio.delay(400);
	gpio.digitalWrite(7, HIGH);
	gpio.delay(400);
	gpio.digitalWrite(7, LOW);
	
	cout << "Setting up i2c" << endl;
	
	gpio.i2cSetup();
	if (gpio.isI2CReady()) cout << "I2C ready for use" << endl;
	else cout << "I2C was not initialized" << endl;
	
	return 0;
};

