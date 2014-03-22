/*
 * pointer.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: fabien papleux
 */
#include <iostream>

using namespace std;

int main (int argv, char** args) {
	char l1[] = "Hello";
	char* l2;
	cout << l1 << endl;
	l2 = (char *) &l1;
	cout << l2 << endl;
	l2 = (char *) "Fabien";
	cout << l2 << endl;
	cout << l1 << endl;
	return 0;
}



