#include <iostream>
#include <wiringPi.h>

#include "gpio.h"

using namespace std;

int sleepMode (Gpio gpio);
int awakeMode (Gpio gpio);


int main(int argc, char **argv)
{
	int ret;
	int saveReg;
	Gpio gpio;
	if (gpio.init()) 
		cout << "GPIO is ready to go" << endl;
	else
	{
		cout << "GPIO is not ready. Make sure wiringPi is properly installed." << endl;
		return 1;
	}
	
	cout << "Setting up i2c" << endl;	
	gpio.i2cInit();
	if (gpio.i2cIsReady()) cout << "i2c ready for use" << endl;
	else cout << "i2c was not initialized" << endl;
	
	cout << "checking out Adafruit board at slave address 0x40" << endl;
	if (gpio.i2cConnectSlave(0x40)) cout << "i2c slave identified" << endl;
	else cout << "i2c slave not initialized" << endl;

	cout << "trying to wake up the car" << endl;
	// 1. Set PWM frequency to 50Hz (standard servo/ESC frequency - pulse width of 20ms)
	saveReg = gpio.i2cReadReg8(0x40, 0x00);
	cout << "saveReg returned value: " << saveReg << endl;
	ret = sleepMode(gpio);
	cout << "sleepmode returned value: " << ret << endl;
	ret = awakeMode(gpio);
	cout << "sleepmode returned value: " << ret << endl;
	
	
	return 0;
};

int sleepMode(Gpio gpio) {
	return gpio.i2cWriteReg8(0x40, 0x00, 0x10);
}

int awakeMode(Gpio gpio) {
	return gpio.i2cWriteReg8(0x40, 0x00, 0x20);
}
