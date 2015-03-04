#ifndef myJOB
#define myJOB
//----------------------------------------------------------------------
//  SPECIFICATION FILE (JOB.h)
//  This module declares a new type for ONE JOB
//----------------------------------------------------------------------

// libraries needed
#include "stdafx.h"
#include "constants.h"
#include <string>

// enable access to all names in std
using namespace std;

class JOB
{
public:
	JOB();								// defalut CTOR
	JOB(int nextID);					// (2nd) CTOR with known ID#

	// ------- getter FUNCTIONS --------
	int getID() const;					// get ID#
	string getName();					// get name of the JOB
	double getTotalTime() const;		// get total time it takes to finish the JOB
	double getRemainTime() const;		// get remaining time it takes to finish the JOB
	double getTotalCPU() const;			// get total time CPU spent on this JOB
	double getIdleTime() const;			// get total time CPU spent on idling when processing this JOB

	// ------- setter FUNCTIONS -------
	void setID(int newID);						// set ID#
	void setName(string newName);				// set name of the JOB
	void setTotalTime(double newTotalTime);		// set total time it takes to finish the JOB
	void setRemainTime(double newRemainTime);	// set remaining time it takes to finish the JOB
	void setTotalCPU(double newTotalCPU);		// set total time CPU spent on this JOB
	void setIdleTime(double newIdleTime);		// set total time CPU spent on idling when processing this JOB

	// ----------- print FUNCTION ---------
	void printJob(const double timeRemain);		// print the information in JOB

private:
	int ID;					// ID#
	string name;			// job name
	double totalTime;		// total time it takes to finish the JOB
	double remainTime;		// remaining time it takes to finish the JOB
	double totalCPU;		// total time CPU spent on this JOB
	double idleTime;		// total time CPU spent on idling when processing this JOB
};	// end class JOB

#endif		//myJOB not defined