
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include "vitalSigns.h"

/*===========================================================================*
 * Programmer:		Jinnan Ge												 *
 * Program #1	 (a1)														 *	
 *																			 *
 * Date last modified:		02/05/2014										 *
 * Summary:		This program calculates the correlation coefficient (r)		 *
 *		and the strength of association based on three pairs of input values *
 *		(x,y). r represents the degree of correlation between two variables, *
 *	    where they can be positively, negatively, strongly or weakly related.*
 *===========================================================================*/

/*===========================================================================*
 * INPUT(to keyboard, stdin):												 *
 *			3 sets of non-negative, REAL (x,y) pairs						 *
 *			x - body temperature (F) ; y - respiratory rate (breaths per min)*
 *			for instance, one pair:  5.1  7.8  is a valid input for (5.1,7.8)*
 *																			 *
 * OUTPUT(to console, stdout):												 *
 *			the correlation coefficient,									 *
 *			the strength of association,									 *
 *			a message indicating whether the association is strong or weak	 *
 *			(all appear on the console screen)								 *
=============================================================================*/


using namespace std;


// ------- FUNCTION ("PROTOTYPE") DECLARATIONS ---------
void printTitle(void);

double getBodyTemperature_F(void);					// temperature based on user's input
double getRespirationRate_BPM(void);				// BPM based on user's input

double getBodyTemperature_F_random1(void);			// produces random temperature based on different time
double getBodyTemperature_F_random2(void);
double getBodyTemperature_F_random3(void);

double getRespirationRate_BPM_random1(void);		// produces random BPM based on different time
double getRespirationRate_BPM_random2(void);
double getRespirationRate_BPM_random3(void);


// ------------- main function starts here --------------

int main()
{	
	// ------- DECLARE CONSTANTS --------
	const short								// ----- CONSTANT declarations -----
            N = 3;                          // number of (x,y) pairs
	
	const double STRENGTH = 0.50;			// value to measure strength of association
	
	
	// ------ DECLARE VARIABLES	------
	
	double									// ----- VARIABLE declarations -----
		x1, y1,								// first  (x,y) pair
		x2, y2,								// second (x,y) pair
		x3, y3,								// third  (x,y) pair


		SumX, SumY,							// sums of the x and y values
		SumSquareX, SumSquareY,				// sums of the squares of the x and y values  SUM((Xi)^2)
		SumXSquared, SumYSquared,			// sums of the x and y values squared		  (SUM Xi)^2
		SumXY,								// sum of the products of x and y values
		Numerator, Denominator,				// numerator & denominator of corr. coeff.

		CorrelationCoefficient,				// the correlation cofficient (r)
		StrengthOfAssociation;				// the strength of association (r-squared)

	short choiceNum;						// 1 or 2 that indicates which option the user prefers
	// ----- end variable declarations ------


	printTitle();			// call function to print title of the program

	
	// prompt user's input: ENTER BY HAND or RANDOMLY GENERATED
	cout << "If you want to enter the body temperatures and Breaths Per Minute values, enter 1." << endl;
	cout << "If you want the system to generate random values, enter 2." << endl;
	cout << "My choice is: ",
		cin >> choiceNum;		// index of which option the user prefers


	// trap invalid input
	while ((choiceNum != 1) && (choiceNum != 2))
	{
		cout << "\nInvalid input! Please enter again:" << endl;
		cout << "If you want to enter the body temperatures and Breaths Per Minute values, enter 1." << endl;
		cout << "If you want the system to generate random values, enter 2." << endl;
		cout << "My choice is: ",
			cin >> choiceNum;
	}// while



	// -------- for ones who prefers entering values manually --------------

	if (choiceNum == 1)	
	{

		// prompt user for input from the keyboard

		x1 = getBodyTemperature_F();			// first  (x,y) pair
		y1 = getRespirationRate_BPM();			// now (x1, y1) was stored with value in them

		x2 = getBodyTemperature_F();			// second  (x,y) pair
		y2 = getRespirationRate_BPM();			// values from input stored in them

		x3 = getBodyTemperature_F();			// third  (x,y) pair
		y3 = getRespirationRate_BPM();			// values from input stored in them


		// -------------- Calculations Starts Here ------------

		SumX = x1 + x2 + x3;
		SumY = y1 + y2 + y3;

		SumSquareX = pow(x1, 2) + pow(x2, 2) + pow(x3, 2);
		SumSquareY = pow(y1, 2) + pow(y2, 2) + pow(y3, 2);

		SumXSquared = pow(SumX, 2);
		SumYSquared = pow(SumY, 2);

		// all variables are defined following ones in the variable declarations


		// ------------ Trap Invalid Input -------------
		// when division by 0 or square root of negative number,
		// recognize as invalid number and ask to input again

		while ((N*SumSquareX <= SumXSquared) || (N*SumSquareY <= SumYSquared))
		{
			cout << endl;
			if (((N*SumSquareX) == SumXSquared) || (N*SumSquareY == SumYSquared))
				cout << "Invalid input! Division by zero. Please enter again : " << endl;
			else
				cout << "Invalid input! Square root of a negative number. Please enter again: " << endl;

			// now, input again...
			x1 = getBodyTemperature_F();
			y1 = getRespirationRate_BPM();

			x2 = getBodyTemperature_F();
			y2 = getRespirationRate_BPM();

			x3 = getBodyTemperature_F();
			y3 = getRespirationRate_BPM();

			// -------- Basic Calculations Start Here -------

			SumX = x1 + x2 + x3;
			SumY = y1 + y2 + y3;

			SumSquareX = pow(x1, 2) + pow(x2, 2) + pow(x3, 2);
			SumSquareY = pow(y1, 2) + pow(y2, 2) + pow(y3, 2);

			SumXSquared = pow(SumX, 2);
			SumYSquared = pow(SumY, 2);

		} // END while invalid input

	} // END if the user wants to enter values


	// ----------- for ones who prefer randomly generated values ---------

	else if (choiceNum == 2)
	{
		cout << "Producing randomly generated body temperature and breath rate..." << endl;		// echo on user's choice

		x1 = getBodyTemperature_F_random1();			// 1st set of values at a random time
		y1 = getRespirationRate_BPM_random1();

		x2 = getBodyTemperature_F_random2();			// 2nd set of values at another random time
		y2 = getRespirationRate_BPM_random2();

		x3 = getBodyTemperature_F_random3();			// 3rd set of values at another different time
		y3 = getRespirationRate_BPM_random3();


		// -------------- Calculations Starts Here ------------

		SumX = x1 + x2 + x3;
		SumY = y1 + y2 + y3;

		SumSquareX = pow(x1, 2) + pow(x2, 2) + pow(x3, 2);
		SumSquareY = pow(y1, 2) + pow(y2, 2) + pow(y3, 2);

		SumXSquared = pow(SumX, 2);
		SumYSquared = pow(SumY, 2);


		// ------------ Trap Invalid Generated Values -----------------
		// if the randomly generated values make square roots of negative numbers
		
		while ((N*SumSquareX <= SumXSquared) || (N*SumSquareY <= SumYSquared))
		{
			cout << "\n Numbers generated are invalid for calculation. Generating again..." << endl;

			x1 = getBodyTemperature_F_random1();			// generate another 3 sets of new values
			y1 = getRespirationRate_BPM_random1();

			x2 = getBodyTemperature_F_random2();
			y2 = getRespirationRate_BPM_random2();

			x3 = getBodyTemperature_F_random3();
			y3 = getRespirationRate_BPM_random3();

			// ------- calculate again, then check validity ---------

			SumX = x1 + x2 + x3;
			SumY = y1 + y2 + y3;

			SumSquareX = pow(x1, 2) + pow(x2, 2) + pow(x3, 2);
			SumSquareY = pow(y1, 2) + pow(y2, 2) + pow(y3, 2);

			SumXSquared = pow(SumX, 2);
			SumYSquared = pow(SumY, 2);

		} // END while invalid number

	}// END else if the user wants random values


	// -------- echo user's input -----------

	cout << "\nYour three (BodyTempF, RespirationRate) pairs are: " << endl;

	printf("	(x,y) pair 1:  (%6.2f, %6.2f)\n", x1, y1);
	printf("	(x,y) pair 2:  (%6.2f, %6.2f)\n", x2, y2);
	printf("	(x,y) pair 3:  (%6.2f, %6.2f)\n", x3, y3);

	// end echoing input
    

	// ------------- all valid input, so calculate r and r-squred ------------

	SumX = x1 + x2 + x3;
	SumY = y1 + y2 + y3;

	SumSquareX = pow(x1, 2) + pow(x2, 2) + pow(x3, 2);
	SumSquareY = pow(y1, 2) + pow(y2, 2) + pow(y3, 2);

	SumXSquared = pow(SumX, 2);
	SumYSquared = pow(SumY, 2);

	SumXY = x1 * y1 + x2 * y2 + x3 * y3;
	Denominator = (sqrt(N*SumSquareX - SumXSquared)) * (sqrt(N*SumSquareY - SumYSquared));
	Numerator = N * SumXY - SumX * SumY;
	
	CorrelationCoefficient = Numerator / Denominator;
	StrengthOfAssociation = pow (CorrelationCoefficient, 2);


	// ------------- TEST -----------------
	cout << "SumX: " << SumX << endl;
	cout << "SumY: " << SumY << endl;
	cout << "SumSquareX: " << SumSquareX << endl;
	cout << "SumSquareY: " << SumSquareY << endl;
	cout << "SumXSquared: " << SumXSquared << endl;
	cout << "SumYSquared: " << SumYSquared << endl;
	cout << "SumXY: " << SumXY << endl;
	cout << "Numerator: " << Numerator << endl;
	cout << "Denominator: " << Denominator << endl;

	cout << "Correlation Coefficient:" << CorrelationCoefficient << endl;


	// ------------ print out r and r-squared ------------
	
	string foo = string(70, '*');
	cout << "\n" << foo << endl;
	printf("		correlation coefficient:  %6.2f \n", CorrelationCoefficient);
	printf("		strength of association:  %6.2f \n", StrengthOfAssociation);
	cout << foo << endl << "\n";


	// --------- print out strong or weak correlation --------

	if (StrengthOfAssociation >= STRENGTH)					// r^2 greater than or equal to 0.5
		cout << "STRONG r-squared (means r^2 is 0.50 or greater)" << endl;
	else													// r^2 less than 0.5
		cout << "WEAK r-squared (means r^2 is less than 0.50)" << endl;
		
	cout << endl;
    cout << endl << "Done." << endl << endl;

	system("PAUSE");
	return 0;
	
} // end main()


