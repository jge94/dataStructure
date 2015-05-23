#include <stdafx.h>
#include <iostream>
#include <assert.h>

using namespace std;


#include "prototypes.h"



// =========================================================================
 // Summary: …
 // PRE:
 //
 // POST:
 //
 // RETURN:
 
void  getStats(const short A[], short hmr, short& max, short& min, double& mean, short& whereMax, short& whereMin)
{	
	assert (hmr > 0 && "ASSERT FAILED in getStats(): no data in arrays." );
	
	// Assume the first item in array is both min and max
	max = min = A[0];
	whereMax = whereMin = 0;
	
	short sum = 0;
	
	short i = 1;  // no need to check index zero
	
	// Go through the array and find the largest and smallest numbers
	// Don't forget to also save WHERE (what cell#) you found the min and max 
	while (i < hmr)
	{	
		if (A[i] > max)
		{
			max = A[i];
			whereMax = i;
		}
			
		else if (A[i] < min)
		{
			min = A[i];
			whereMin = i;
		}
		
		sum = sum + A[i];
		i++;

		

	} // end while more data in array to check


    
	mean = sum / i;
	
	cout << "Max: " << max << endl;
	cout << "whereMax: " << whereMax << endl;
	cout << "Min: " << min << endl;
	cout << "whereMin: " << whereMin << endl;
	cout << "Mean:" << mean << endl;
} // =========== end getStats() ==================================
