/*
 * test.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: fabien papleux
 */

#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string in;
	int throttle;
	in = "";
	while (in != "quit") {
		throttle = 0;
		cout << "Set throttle to: ";
		cin >> in;
		cout << "Value entered [" << in << "]" << endl;
		try
		{
			throttle = stoi(in);
		}
		catch (const invalid_argument& e)
		{
			cout << " --> Error: input was not a valid integer." << endl;
		}
		if (throttle) cout << " --> You entered: " << throttle << endl;
	}

}

