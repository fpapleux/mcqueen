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

	struct cpu_data {
		string implementer;
		string architecture;
		string variant;
		string part;
		string revision;
	} cpu;

	string model, serialNumber, revision;



	string line;
	stringstream ss;
	int rev;

	// Points to the file containing this machine's system/cpu information
	string cpuInfoPath = CPUINFO;

	// Opens the file for reading, using the C string version of the path
	ifstream f(cpuInfoPath.c_str());

	// If the file did not open, stop here
	if (! f.is_open()) return 0;

	// While there are lines to read in the file,

	while (getline(f, line)) {
		cout << line << endl;
		if (line.find("Revision")) {
			ss << line;
			ss >> line >> line >> hex >> rev;
		}
	}

	if (rev != 0) cout << "Revision is " << dec << rev << " en hexa 0x" << hex << rev;

	// closing the file
	f.close();
}



