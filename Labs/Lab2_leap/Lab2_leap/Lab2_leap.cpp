// Lab2_leap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	short year;	// user-entered year

	cout << "Enter an integer year >> ";
	cin >> year;

	cout << endl;
	cout << "The year " << year;

	// YOU write the expression for the IF statement

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 100 == 400))
		cout << " IS a leap year." << endl;
	else
		cout << " is NOT a leap year." << endl;

	system("PAUSE");
	return 0;

}  // main

