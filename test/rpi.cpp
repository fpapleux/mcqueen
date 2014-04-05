/*
 * rpi.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

	// Points to the file containing this machine's system/cpu information
	string cpuInfoPath = "/proc/cpuinfo";

	// Opens the file for reading, using the C string version of the path
	ifstream f(cpuInfoPath.c_str());

	// If the file did not open, stop here
	if (! f.is_open()) return 0;

	// While there are lines to read in the file,

	while (getline(f, line)) {
		cout << line << endl;
	}

	// closing the file
	f.close();
}



