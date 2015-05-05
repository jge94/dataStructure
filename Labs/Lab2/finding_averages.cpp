// Lab2_finding_averages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main(void)
{
	float numOfBoys,
		totalNum,
		averageNum,
		i;
	
	numOfBoys = 0;
	totalNum = 0;
	i = 0;

	cout << "Enter the number of pretty, pretty friends: ",
		cin >> numOfBoys;
	//i = 1;

	while ( numOfBoys >= 0)
	{
		i = i + 1;
		cout << "i: " << i << endl;
		totalNum = totalNum + numOfBoys;

		cout << "Total: " << totalNum << endl;
		//int numOfBoys;
		cout << "Enter the number of pretty, pretty friends: ",
			
			cin >> numOfBoys;

		
		//cout << "Total: " << totalNum << endl;
		
		//i = i + 1;
		//cout << "i: " << i << endl;
	}
	
	cout << endl;
	cout << "Total: " << totalNum << endl;
	cout << "i: " << i << endl;
	averageNum = (totalNum) / (i);
	printf("The average is: %5.2f \n", averageNum);

	system("PAUSE");
	return 0;
}


