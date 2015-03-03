#include <stdafx.h>
#include <iostream>
using namespace std;

const short MAX=10;    // I'm guessing that I won't need more than MAX 
short hmr = 0;

#include "prototypes.h"

int main(void)
{
	short A[MAX];	// array to hold input data
	short hmr;		// HowManyReally (hmr) get put into A (<= MAX)
	hmr = 0;

	getData(A, hmr);
	cout << "A was filled with " << hmr << " elements." << endl;
	
    
	printData(A, hmr);
    
	short max, min, whereMax, whereMin;
	double mean;
    
	getStats(A, hmr, max, min, mean, whereMax, whereMin);
    
	// now print the stats out here
    
    
    
	
	// WINDOWS
	system("PAUSE");
	
	return 0;
} // =========== end main() ==================================


void getData(short A[], short& hmr)
{	/*---------------------------------------------------------
	 SUMMARY: read values from keyboard into array A until a negative
	 
	 Global: MAX is maximum number of elements in A
	 
	 PRE: 		A is empty; hmr is unknown
	 POST:	 	(by reference): 
        hmr indicates number of input values put into A
        A is filled with hmr elements
	 ------------------------------------------------------------*/
	short temp, i=0;
	
	cout << "Enter the number: ",
		cin >> temp;
	
	//cout << "A[" << i << "]: " << A[i] << endl;

	while (  (temp >= 0) && (i < MAX) ) // while non-neg and still have room in A
	{

		A[i] = temp;	// store input into A
		   		// move index down to next open box in A
		i++;

		//cout << "A[" << i << "]: " << A[i] << endl;
		//cout << "i BEFORE: " << i << endl;
		
		if (i < (MAX))
		{
		cout << "Enter the number: ",
			cin >> temp;
		}

		//i++;

		//cout << "i: " << i << endl;
        
	} // while not negative input and array is not full
	
	//cout <<"MAX: "<< MAX<<endl;
	//cout << "hmr: " << hmr<<endl;

	hmr = i;			// hmr elements were read in
	if (hmr == MAX)
		cout << "WARNING: array is FULL" << endl;
	
	
} // =========== end getData() ==================================


void printData(const short A[], short hmr)
{	/*---------------------------------------------------
	 SUMMARY: print values in array A to the console
	 
	 PRE: 	hmr indicates number of elements actually in A
	        A is filled with hmr elements
	 POST:  nothing
     Side Effect: values printed to console (stdout)
	 -----------------------------------------------------*/	
	for (short i=0;  i < hmr;   i++)
		cout << "A[" << i << "] = " << A[i] << endl;
	
} 
// =========== end printData() ==================================


