#include <iostream>
#include "pca9685.h"

using namespace std;

int main (int argv, char** args)
{
	pca9685 i2c;
	i2c.init();
	int reg;
	int channel;
	int addr;
	
	
	cout << "system status..." << endl;
	
	reg = i2c.gpio->i2cReadReg8 (0x40, 0x00);
	cout << "Mode 1 register status: " << reg << endl;
	
	channel = 8;
	addr = (channel * 4) + 6;
	cout << "Channel 8 - talking to registers " << addr << ", " << addr + 1 << ", " << addr + 2 << ", " << addr + 3 << endl;
	
	reg = i2c.gpio->i2cReadReg8 (0x40, addr);
	cout << "Register " << addr << ": " << reg << endl;
	reg = i2c.gpio->i2cReadReg8 (0x40, addr + 1);
	cout << "Register " << addr + 1 << ": " << reg << endl;
	reg = i2c.gpio->i2cReadReg8 (0x40, addr + 2);
	cout << "Register " << addr + 2 << ": " << reg << endl;
	reg = i2c.gpio->i2cReadReg8 (0x40, addr + 3);
	cout << "Register " << addr + 3 << ": " << reg << endl;
	

	return 0;
}
