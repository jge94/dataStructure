
#include "stdafx.h"
#include <iostream>
#include <math.h>

/*--------------------------------------------------------------
 Programmer:
			Jinnan Ge
 
 Summary:
			This program calculates the real roots of the function
			based on the user's input.
 
 Date last modified:
			01/30/2014
 ----------------------------------------------------------------*/

/*--------------------------------------------------------------
 INPUT(keyboard, stdin):	
			three coefficients of the function ax^2+bx+c = 0
 
 OUTPUT(console, stdout):
			property of the function's graph (parabola / linear)
			number of real root(s)
			value of real root(s)
 ---------------------------------------------------------------*/

using namespace std;



int main(void)
{	
	double  A ,     // --------- VARIABLE declarations ---------
            B ,		// three coefficients for quadratic equation
            C ;		//			Ax**2 + Bx + C
	
	cout << "                      (REAL) ROOT FINDING" << endl;
	cout << endl;
	

	// prompt user for input from the keyboard
	cout << "Please enter three coefficients for quadratic equation." << endl;
	
	//A
	cout << "Enter A: ";
	while (!(cin >> A))			// trap non-double input
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid input. Please try again: ";
	}

	//B
	cout << "Enter B: ";
	while (!(cin >> B))			// trap non-double input
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid input. Please try again: ";
	}

	//C
	cout << "Enter C: ";		// trap non-double input
	while (!(cin >> C))
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid input. Please try again: ";
	}
	cout << endl;
	// --------------- end prompting input -------------------
	
	
	double 
		rootONE,      // first root
		rootTWO;      // second root
	
	// trap division by zero and squre root of negative numbers
	if (A != 0 && ((B*B - 4 * A*C) >= 0) )
	{
		// compute the first root
		rootONE = (-B + sqrt(B*B - 4 * A*C)) / (2 * A);

		// now compute the second root
		rootTWO = (-B - sqrt(B*B - 4 * A*C)) / (2 * A);
	}

    
	// trap division by zero -- if it is a parabola
	if (A != 0)
	{	
		// determine the number of real roots

		// two real roots
		if ((B*B - 4 * A*C) > 0)
		{
			cout << "This function is a parabola. There are TWO real roots: " << endl;
			cout << "First root is:  " << rootONE << endl;
			cout << "Second root is: " << rootTWO << endl;
			cout << endl;
		} // END if two real roots

		// one repeated root
		else if ((B*B - 4 * A*C) == 0)
		{
			cout << "This function is a parabola. There is only ONE (repeated) real root: " << endl;
			cout << "The root is: " << rootONE << endl;
			cout << endl;
		} // END else if one real root

		// no real root
		else
		{
			cout << "This function is a parabola with no intersection with the X-axis. " << endl;
			cout << "Thus, these A, B, C coefficients lead to an equation with NO REAL ROOTs. The roots are complex." << endl;
			cout << endl;
		} // END else no roots

	} // END if A != 0


	// start another condition: A = 0, all linear equations
	else // if A = 0 (it is not a quadratic function)
	{
		// if B != 0, functions not parallel to X-axis
		if (B != 0)
		{
			// a linear funnction that does not go throught the origin
			if (C != 0)
			{
				double							// ----- VARIABLE DECLARATIONS -----
					rootLINE;					// root of the linear equation
					rootLINE = - C / B;			// based on A = 0, Bx + C = 0

				cout << " This function is linear. There is only ONE real root and it is: " << rootLINE << endl;
				cout << endl;

			} // END if C!= 0


			// if C=0, then it passes through the origin
			else // a=0, b!=0, c =0
			{
				cout << "This function is linear and it passes through the origin. There is only ONE real root and it is: 0" << endl;
				cout << endl;
			} // END else C=0

		} // END B != 0

		// A = 0 AND B = 0
		else  // B = 0
		{
			// line parallel to X-axis
			if (C != 0)
			{
				cout << "This function is linear and parallel to the X-axis. There is NO root." << endl;
				cout << endl;
			} // END if C != 0

			// line overlapping X-axis (A=B=C=0)
			else // C=0
			{
				cout << "This function is linear and it overlaps the X-axis. There are infinitely many roots." << endl;
				cout << endl;
			} // END else C = 0

		} // END else B = 0

	} // END if A = 0
	 
	
	//system("PAUSE");
	return 0;
	
} // main
