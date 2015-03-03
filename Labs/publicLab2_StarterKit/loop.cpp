#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	printf("CONSTANT is: %.15f 0.1\n");
	// do NOT change float's to double
	const float 
	INCREMENT = 0.1;			// constant to keep adding to sum
   	
	float sum;					// variable to hold the sum
	
	// starting at ZERO, this code will continue to add 
	//  the INCREMENT to sum until reaching 2.0
	
	int CONSTANT;
	CONSTANT = 0.000000000001;

	sum = 0.0;
	while ((sum - 2.0) <= CONSTANT)   // do NOT change the test; leave it as is
	{
      	
		cout << "Now sum is: " << sum << endl;
		sum = sum + INCREMENT;
		//if ((sum - 2.0) <= CONSTANT)
		printf("sum is: %.15f \n", sum);
		
	} // while

	float sum2;
	sum2 = 0;
	for (int n = 20; n > 0; n--)
	{
		sum2 = sum2 + INCREMENT;
	}
	
	printf("Sum2 is: %.15f \n", sum2);

	cout << endl << "DONE LOOP and sum is " << sum << endl;
	
	// WINDOWS users (uncomment next line)
	system("PAUSE");
	
	return 0;
} // main
