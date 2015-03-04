
#include "stdafx.h"
#include <iostream>
#include <string>
#include "vitalSigns.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*===============================================================*
 Summary:
		 This file contains all functions main.cpp needs to generate the 
		 final result.

 Function names:
		 void printTitle(void);

		 double getBodyTemperature_F(void);					// temperature based on user's input
		 double getRespirationRate_BPM(void);				// BPM based on user's input

		 double getBodyTemperature_F_random1(void);			// produces random temperature based on different time
		 double getBodyTemperature_F_random2(void);
		 double getBodyTemperature_F_random3(void);

 =================================================================*/



// -------------------\
//  printTitle \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: title of this program
// --------------------------------------------------------------
void  printTitle(void)
{
	string foo = string(70, '*');
	cout << "\n" << foo << endl;
	cout << "               Regression analysis on three pairs of  " << endl;
	cout << "                 (BodyTemp, RespirationRate) values \n " << endl;
	cout << foo << endl;
}


// -------------------\
//  getBodyTemperature \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
double getBodyTemperature_F(void)
{
									// ----- VARIABLE declarations -----
    double temp;					// INPUT: body temperature


	cout << "\nEnter a body temp(F): ",
		cin >> temp;

	while (temp < 0)				// trap negative input
	{
		cout << "Invalid input! Please enter a non-negative, body temp(F): ",
			cin >> temp;
	}
    
    return temp;
}
// end getBodyTemperature_F


// -------------------\
//  getBodyTemperature_random1 (at time 1)\
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: randomly simulated body temperature in degrees F
// --------------------------------------------------------------
double getBodyTemperature_F_random1(void)
{
									// ----- VARIABLE declarations -----
	double temp;					// body temperature
	
	srand(time(NULL));				// 1st seed for random: @ time(NULL)
	temp = 95 + (rand() % 10);		// produces random number from 95 F to 105 F

	return temp;
}
// end getBodyTemperature_F_random1


// -------------------\
//  getBodyTemperature_random1 (at time 2)\
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: randomly simulated body temperature in degrees F
// --------------------------------------------------------------

double getBodyTemperature_F_random2(void)
{
									// ----- VARIABLE declarations -----
	double temp;					// body temperature

	srand(time(NULL) + 10);			// 2nd seed for random: @ time(NULL)+10
	temp = 95 + (rand() % 10);

	return temp;
}
// end getBodyTemperature_F_random2


// -------------------\
//  getBodyTemperature_random1 (at time 3)\
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: randomly simulated body temperature in degrees F
// --------------------------------------------------------------

double getBodyTemperature_F_random3(void)
{
									// ----- VARIABLE declarations -----
	double temp;					// body temperature

	srand(time(NULL) + 20);			// 3rd seed for random: @ time(NULL)+20
	temp = 95 + (rand() % 10);

	return temp;
}
// end getBodyTemperature_F_random3



// -------------------\
//  getBodyTemperature \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
double getRespirationRate_BPM(void)
{
									// ----- VARIABLE declarations -----
	double breathRate;				// INPUT: breaths per minute

	cout << "Enter a corresponding respiratory rate: ",
		cin >> breathRate;

	while (breathRate < 0)			// trap negative input
	{
		cout << "Invalid input! Please enter a number that is non-negative, breaths per minute): ",
			cin >> breathRate;
	}
    
    return breathRate;
}
// end getRespirationRate_BPM


// -------------------\
//  getBodyTemperature_radom (at time 1)\
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
double getRespirationRate_BPM_random1(void)
{
										// ----- VARIABLE declarations -----
	double breathRate;					// breaths per minute

	srand(time(NULL));					// 1st seed for random: @ time(NULL)
	breathRate = 10 + (rand() % 50);	// random number from 10 to 60

	return breathRate;
}
// end getRespirationRate_BPM_random1


// -------------------\
//  getBodyTemperature_radom (at time 2)\
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
double getRespirationRate_BPM_random2(void)
{
										// ----- VARIABLE declarations -----
	double breathRate;					// breaths per minute

	srand(time(NULL) + 10);				// 2nd seed for random: @ time(NULL)+10
	breathRate = 10 + (rand() % 50);

	return breathRate;
}
// end getRespirationRate_BPM_random2



// -------------------\
//  getBodyTemperature_radom (at time 3)\
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
double getRespirationRate_BPM_random3(void)
{
										// ----- VARIABLE declarations -----
	double breathRate;					// breaths per minute

	srand(time(NULL) + 20);				// 3rd seed for random: @ time(NULL)+20
	breathRate = 10 + (rand() % 50);	// random number from 10 to 60

	return breathRate;
}
// end getRespirationRate_BPM_random3

// end all functions