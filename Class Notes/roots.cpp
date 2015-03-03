

#include <iostream>
#include "stdafx.h"
#include <math.h>

/*--------------------------------------------------------------
 Programmer:
 
 Summary:
 
 Date last modified:
 
 ----------------------------------------------------------------*/

/*--------------------------------------------------------------
 INPUT:
 
 OUTPUT:
 ---------------------------------------------------------------*/

using namespace std;



int main(void)
{
	double  A =   1,     // three coefficients for quadratic equation
            B =   0,
            C =  -4;
	
	double rootONE,      // first root
	rootTWO;             // second root
	
	// brute force ... need to do lots of testing ...
    /
	// compute the first root
	rootONE = (-B + sqrt(B*B - 4*A*C)) / 2*A;
    
	
	// now compute the second root
	rootTWO = (-B - sqrt(B*B - 4*A*C)) / 2*A;
	
	
	cout << "First root is:  " << rootONE << endl;
	cout << "Second root is: " << rootTWO << endl;  
	
	system("PAUSE");
	return 0;
	
} // main
