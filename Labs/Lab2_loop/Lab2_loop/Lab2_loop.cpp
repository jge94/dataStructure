// Lab2_loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	int num;
	cout << "Enter number of loops: ",
		cin >> num;

	for (int n = num; n > 0; n--)
	{
		cout << "Such a lovely place" << endl;
	}
	
	cout << endl;
	cout << "Such a lovely face." << endl;
	system("PAUSE");

	return 0;
} // main


