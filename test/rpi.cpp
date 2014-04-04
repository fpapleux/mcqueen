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

	string line;

	// Points to the file containing this machine's system/cpu information
	string cpuInfoPath = "/proc/cpuinfo";

	// Opens the file for reading, using the C string version of the path
	ifstream f(cpuInfoPath.c_str());

	// While there are lines to read in the file,
	while (f >> line) {
		cout << line << endl;
	}

	// closing the file
	f.close();

}




