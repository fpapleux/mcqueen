#include <iostream>
#include <wiringPi.h>

#include "gpio.h"

using namespace std;

int main(int argc, char **argv)
{
	
	Gpio gpio;
	if (! gpio.isReady()) cout << "GPIO is not ready. Make sure wiringPi is properly installed.";
	else cout << "GPIO is ready to go";
	
	/*
	gpio.pinMode(7, OUTPUT);
	gpio.digitalWrite(7, HIGH);
	delay(1000);
	gpio.digitalWrite(7, LOW);
	delay(1000);
	gpio.digitalWrite(7, HIGH);
	delay(1000);
	gpio.digitalWrite(7, LOW);
	delay(1000);
	*/
	return 0;
};

