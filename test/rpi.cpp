/*
 * rpi.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#define CPUINFO "/proc/cpuinfo"

int main () {

	string cpuModel, cpuSerial;
	int cpuRevision = -1;

	string line, l;
	stringstream ss;
	int rev;
	int found = 0;

	// Points to the file containing this machine's system/cpu information
	string cpuInfoPath = CPUINFO;

	// Opens the file for reading, using the C string version of the path
	ifstream f(cpuInfoPath.c_str());

	// If the file did not open, stop here
	if (! f.is_open()) return 0;

	// While there are lines to read in the file,

	while (getline(f, line)) {
		if (line.find("Revision") != -1)
		{
			cout << "Found Revision..." << endl;
			ss << line;
			ss >> l >> l >> hex >> cpuRevision >> dec;
		}
		if (line.find("model name") != -1)
		{
			cout << "Found model name" << endl;
			cpuModel = line.substr(13, line.length() - 13);
		}
		if (line.find("Serial") != -1)
		{
			cout << "Found serial number" << endl;
			ss << line;
			ss >> l >> l >> cpuSerial;
		}
	}
	f.close();
	cout << "CPU Serial = [" << cpuSerial << "]" << endl;
	cout << "CPU model = [" << cpuSerial << "]" << endl;
	cout << "CPU Revision = [" << cpuSerial << "]" << endl;

}



