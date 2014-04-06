/*
 * RaspberryPi.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <wiringPi.h>
#include "RaspberryPi.h"
#include "Gpio.h"
#include "I2cBus.h"

using namespace std;




RaspberryPi::RaspberryPi (void)
{
	ready = 0;
	cpuModel = "";
	cpuRevision = -1;
	cpuSerial = "";
	i2c = NULL;
	gpio = NULL;
	init();
}




RaspberryPi::~RaspberryPi (void)
{
	if (i2c) delete i2c;
	if (gpio) delete gpio;
}




int RaspberryPi::isReady (void)
{
	return ready;
}




int RaspberryPi::init (void)
{
	int success = 0;
	ready = 0;

	if (wiringPiSetup() != -1) success = 1;
	if (success) success = initGpio();
	if (success) success = initI2cBus();
	if (success) ready = 1;
	return ready;
}




int RaspberryPi::initI2cBus (void)
{
	if (! i2c) i2c = new I2cBus();
	if (! i2c->isReady()) i2c->init();
	return i2c->isReady();
}




int RaspberryPi::initGpio (void)
{
	if (cpuRevision == -1) getCpuInfo();
	if ((cpuRevision != -1) && (! gpio)) gpio = new Gpio(cpuRevision);
	if (! gpio->isReady()) gpio->init();
	return gpio->isReady();
}




I2cBus *RaspberryPi::getI2cBus (void)
{
	return i2c;
}




Gpio *RaspberryPi::getGpio (void)
{
	return gpio;
}


void RaspberryPi::getCpuInfo (void)
{
	cpuModel = "";
	cpuRevision = -1;
	cpuSerial = "";

	string line, l;
	stringstream ss;
	int t;
	string cpuInfoPath = CPUINFO;
	ifstream f(cpuInfoPath.c_str());
	if (! f.is_open()) return;
	while (getline(f, line))
	{
		if (line.find("Revision") != -1)
		{
			ss << line >> l >> l >> hex >> cpuRevision >> dec;
		}
		if (line.find("model name") != -1)
		{
			cpuModel = line.substr(13, line.length() - 13);
		}
		if (line.find("Serial") != -1)
		{
			ss << line >> l >> l >> cpuSerial;
		}
	}
	f.close();
	cout << "CPU Serial = [" << cpuSerial << "]" << endl;
	cout << "CPU model = [" << cpuSerial << "]" << endl;
	cout << "CPU Revision = [" << cpuSerial << "]" << endl;
}


int RaspberryPi::getRevision (void)
{
	if (version) return version;


	while (getline(f, line)) {
		// cout << "line is: [" << line << "]" << endl;
		// found = line.find("Revision");
		// cout << "Value of found: " << found << endl << endl;
		if (line.find("Revision") != -1) {
			found = 1;
			ss << line;
			ss >> l1 >> l2 >> hex >> rev;
		}
	}

	if (found) {
		cout << "L1: [" << l1 << "]" << endl;
		cout << "L2: [" << l2 << "]" << endl;
		cout << "Revision is " << dec << rev << " en hexa 0x" << hex << rev;
	}

	// closing the file
	f.close();



	return version;
}


void RaspberryPi::printStatus (void)
{
	cout << "Raspberry Pi Status" << endl;
	cout << "-------------------" << endl;
	cout << endl;
	cout << "Is Ready   : " << (ready ? "Yes" : "No") << endl;
	cout << "Gpio       : " << (gpio != NULL ? string("Present ").append((gpio->isReady() ? "and Ready" : "but Not Ready"))  : "Absent") << endl;
	cout << "I2C Bus    : " << (i2c != NULL ? string("Present ").append((i2c->isReady() ? "and Ready" : "but Not Ready"))  : "Absent") << endl;
	cout << endl;
	if (gpio) gpio->printStatus();
	if (i2c) i2c->printStatus();
}
