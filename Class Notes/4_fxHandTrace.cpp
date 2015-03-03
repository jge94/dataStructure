
#include "stdafx.h"
#include <iostream>	// function DECLARATIONS for library functions

#define _USE_MATH_DEFINES
#include <cmath>		//	and also get built-in constant for pi (M_PI)
//#define M_PI 3.1415926

using namespace std;

// function (“PROTOTYPE”) DECLARATIONS for my own user-defined functions
void printTitle(void);
double circleArea(double);
double circleCircumference(double);

int main(void)
{
	// variable DECLARATIONS
	double    radius, circumference, area;
	
	printTitle();		// CALL to print the title for my output
	
	cout << "Enter a circle radius (cm) >> ";
	cin >> radius;
	while (cin)		// while NOT EOF
	{
	    area = circleArea(radius);			 // CALL to get area
	    circumference = circleCircumference(radius); // CALL to get circumference
		
	    cout << "radius = " << radius << " cm" << endl
		<< "circumference = " << circumference << " cm" << endl
		<< "area = " << area << " cm^2" << endl << "-------------------------" << endl;
		
	    cout << "Enter a circle radius (cm) >> ";
	    cin >> radius;
	} // while NOT EOF
	
	cout << endl << "All done ..." << endl;
	
	return(0);
} // main


// function DEFINITIONS
//---------------------------------------------------------
void printTitle(void)
{
	cout << "========== CIRCLE INFORMATION =========" << endl << endl;
	
} // title


//---------------------------------------------------------
double circleArea(double r)
{
	return  M_PI * pow(r,2.0);
	
} // circleArea


//---------------------------------------------------------
double circleCircumference(double r)
{
	double answer;	// declare a LOCAL variable (if you need one)
	answer = 2 * M_PI * r;

	system("PAUSE");
	
	return answer;
	
} // circleCircumference


