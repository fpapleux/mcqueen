#include <stdio.h>
#include <wiringPi.h>
#include "gpio.h"


int main(int argc, char **argv)
{
	Gpio gpio();
	gpio.pinMode(7, OUTPUT);
	gpio.digitalWrite(7, HIGH);
	delay(1000);
	gpio.digitalWrite(7, LOW);
	delay(1000);
	gpio.digitalWrite(7, HIGH);
	delay(1000);
	gpio.digitalWrite(7, LOW);
	delay(1000);
	
	return 0;
}

