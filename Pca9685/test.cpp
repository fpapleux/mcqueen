#include <iostream>
#include "Pca9685.h"

using namespace std;

int main (int argv, char** args)
{
	Pca9685 i2c;
	i2c.init();
	int reg, reg2;;
	int reg1Lo, reg1Hi, reg2Lo, reg2Hi;
	int channel;
	int addr;
	int freq;
	int factor;
	
	cout << "CAR SERVO SYSTEM STATUS AND TEST" << endl << endl;
	
	reg = i2c.gpio->i2cReadReg8 (0x40, 0x00);
	cout << "Mode 1 register status: 0x" << hex << reg << endl;
	
	channel = 8;
	addr = (channel * 4) + 6;
	cout << "Channel 8 - talking to registers 0x" << addr << ", 0x" << addr + 1 << ", 0x" << addr + 2 << ", 0x" << addr + 3 << endl;
	
	reg1Lo = i2c.gpio->i2cReadReg8 (0x40, addr);
	cout << "Register 0x" << hex << addr << ": 0x" << reg1Lo << endl;
	reg1Hi = i2c.gpio->i2cReadReg8 (0x40, addr + 1);
	cout << "Register 0x" << addr + 1 << ": 0x" << reg1Hi << endl;
	reg2Lo = i2c.gpio->i2cReadReg8 (0x40, addr + 2);
	cout << "Register 0x" << addr + 2 << ": 0x" << reg2Lo << endl;
	reg2Hi = i2c.gpio->i2cReadReg8 (0x40, addr + 3);
	cout << "Register 0x" << addr + 3 << ": 0x" << reg2Hi << endl << endl;
	
	cout << "PWM PRESCALE STATUS AND TEST" << endl << endl;
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
	cout << "Calculated frequency: " << dec << freq << "Hz" << endl << endl;
	
	cout << "ANALYZING PWM VALUES AND TESTING SERVO" << endl << endl;
	int servoStraight = (330 * factor);
	int servoLeft = (450 * factor);
	int servoRight = (220 * factor);
	
	reg2 = (reg2Hi << 8) + reg2Lo;
	cout << "Channel " << dec << channel << endl;
	cout << "LED_OFF_L register = 0x" << hex << addr + 2 << dec << " (" << addr + 2 << ")" << endl;
	cout << "LED_OFF_H register = 0x" << hex << addr + 3 << dec << " (" << addr + 3 << ")" << endl;
	cout << "Value of LED_OFF_L = 0x" << hex << reg2Lo << " (" << dec << reg2Lo << ")" << endl;
	cout << "Value of LED_OFF_H = 0x" << hex << reg2Hi << " (" << dec << reg2Hi << ")" << endl;
	cout << "Adjusted value of LED_OFF_H (16-bit definition) is 0x" << hex << (reg2Hi << 8) << endl;
	cout << "Full value is 0x" << hex << reg2 << " - decimal " << dec << reg2 << endl;
	cout << endl;
	
	cout << "SERVO STRAIGHT" << endl;
	cout << "Value to set the LED_OFF registers: " << dec << servoStraight << " (0x" << hex << servoStraight << dec << ")" << endl;
	reg = servoStraight;
	reg1Lo = 0;
	reg1Hi = 0;
	reg2Lo = reg & 0x00ff;
	reg2Hi = reg >> 8;
	cout << "reg = " << dec << reg << " {0x" << hex << reg << ")" << endl;
	cout << "reg2Lo: 0x" << hex << reg2Lo << " or " << dec << reg2Lo << endl;
	cout << "reg2Hi: 0x" << hex << reg2Hi << " or " << dec << reg2Hi << endl;
	reg = (reg2Hi << 8) + reg2Lo;
	cout << "Recomposed reg = " << dec << reg << " (0x" << hex << reg << ")" << endl;
	
	cout << "Sending command to the Servo..." << endl << endl;
	i2c.gpio->i2cWriteReg8 (0x40, addr + 2, reg2Lo);
	i2c.gpio->i2cWriteReg8 (0x40, addr + 3, reg2Hi);
	i2c.gpio->delay(2000);
	
	cout << "Turning left..." << endl;
	reg = servoLeft;
	reg2Lo = reg & 0x00ff;
	reg2Hi = reg >> 8;
	i2c.gpio->i2cWriteReg8 (0x40, addr + 2, reg2Lo);
	i2c.gpio->i2cWriteReg8 (0x40, addr + 3, reg2Hi);
	i2c.gpio->delay(2000);
	
	
	return 0;
};

