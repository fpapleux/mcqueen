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
	int freq;
	int factor;
	
	cout << "system status..." << endl;
	
	reg = i2c.gpio->i2cReadReg8 (0x40, 0x00);
	cout << "Mode 1 register status: 0x" << hex << reg << endl;
	
	channel = 8;
	addr = (channel * 4) + 6;
	cout << "Channel 8 - talking to registers 0x" << addr << ", 0x" << addr + 1 << ", 0x" << addr + 2 << ", 0x" << addr + 3 << endl;
	
	reg = i2c.gpio->i2cReadReg8 (0x40, addr);
	cout << "Register 0x" << hex << addr << ": 0x" << reg << endl;
	reg = i2c.gpio->i2cReadReg8 (0x40, addr + 1);
	cout << "Register 0x" << addr + 1 << ": 0x" << reg << endl;
	reg = i2c.gpio->i2cReadReg8 (0x40, addr + 2);
	cout << "Register 0x" << addr + 2 << ": 0x" << reg << endl;
	reg = i2c.gpio->i2cReadReg8 (0x40, addr + 3);
	cout << "Register 0x" << addr + 3 << ": 0x" << reg << endl;
	
	reg = i2c.gpio->i2cReadReg8 (0x40, 0xfe);
	freq = (25000000 / (reg + 1)) / 4096;
	cout << "Prescale register: 0x" << reg << endl;
	cout << "Calculated frequency: " << dec << freq << "Hz" << endl;
	
	if (freq == 50)
	{
		freq = 100;
		factor = 2;
	}
	else 
	{
		freq = 50;
		factor = 1;
	}
	
	cout << "Changing PWM frequency to " << freq << "Hz" << endl;
	reg = (25000000 / (4096 * freq)) - 1;
	i2c.gpio->i2cWriteReg8 (0x40, 0x00, 0x10);
	i2c.gpio->delay(100);
	i2c.gpio->i2cWriteReg8 (0x40, 0xfe, reg);
	i2c.gpio->delay(100);
	i2c.gpio->i2cWriteReg8 (0x40, 0x00, 0x20);
	i2c.gpio->delay(100);
	
	reg = i2c.gpio->i2cReadReg8 (0x40, 0xfe);
	freq = (25000000 / (reg + 1)) / 4096;
	cout << "Prescale register: 0x" << hex << reg << endl;
	cout << "Calculated frequency: " << dec << freq << "Hz" << endl;
	
	
	
	
	
	
	return 0;
}
