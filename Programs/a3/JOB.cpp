#include "stdafx.h"
#include <iostream>
#include "JOB.h"
#include "constants.h"
#include <string>


// ------- Function used to produce random double --------
/* Returns a random double between min and max */
double fRand(double min, double max);

short ID_CONST = 1;					  // initialize ID number for new jobs

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructors (CTOR)
JOB::JOB()		// DEFAULT CTOR
{
	/* POST: Data structure JOB created with randomly assigned values in it*/

	short typeOfJob = rand() % TYPE_CONST + 1;		// calculate possibility

	if (typeOfJob <= PRINT_PROB)					// first 20% of the 100: print
	{
		ID = ID_CONST;								// ID#
		name = "Print";
		totalTime = fRand(LOW_PRINT_TIME, HIGH_PRINT_TIME);		//randomly generated double values between two constants
		remainTime = totalTime;									//initial value: time remaining = total time (not in CPU yet)
	}
	else if (typeOfJob > PRINT_PROB && typeOfJob <= COMPILE_PROB)	//same as above
	{
		//ID = rand() % ID_MAX + 1;
		ID = ID_CONST;
		name = "Compile";
		totalTime = fRand(LOW_COMPILE_TIME, HIGH_COMPILE_TIME);
		remainTime = totalTime;
	}
	else if (typeOfJob > COMPILE_PROB && typeOfJob <= EMAIL_PROB)
	{
		ID = ID_CONST;
		name = "Email";
		totalTime = fRand(LOW_EMAIL_TIME, HIGH_EMAIL_TIME);
		remainTime = totalTime;
	}
	else
	{
		ID = ID_CONST;
		name = "Other";
		totalTime = fRand(LOW_OTHER_TIME, HIGH_OTHER_TIME);
		remainTime = totalTime;
	}

	ID_CONST++;					// to make ID# different: increase ID# 

}//end DEFAULT CTOR


// CTOR for known (assigned) ID ------
JOB::JOB(/* in */int nextID)
{
	/*POST: Data structure JOB created with known ID number*/

	short typeOfJob = rand() % TYPE_CONST + 1;			// same as commented before

	if (typeOfJob <= PRINT_PROB)
	{
		ID = nextID;
		name = "Print";
		totalTime = fRand(LOW_PRINT_TIME, HIGH_PRINT_TIME);
		remainTime = totalTime;
	}
	else if (typeOfJob > PRINT_PROB && typeOfJob <= COMPILE_PROB)
	{
		ID = nextID;
		name = "Compile";
		totalTime = fRand(LOW_COMPILE_TIME, HIGH_COMPILE_TIME);
		remainTime = totalTime;
	}
	else if (typeOfJob > COMPILE_PROB && typeOfJob <= EMAIL_PROB)
	{
		ID = nextID;
		name = "Email";
		totalTime = fRand(LOW_EMAIL_TIME, HIGH_EMAIL_TIME);
		remainTime = totalTime;
	}
	else
	{
		ID = nextID;
		name = "Other";
		totalTime = fRand(LOW_OTHER_TIME, HIGH_OTHER_TIME);
		remainTime = totalTime;
	}

	// produce different IDs
}// end 2nd CTOR


// ================ getter FUNCTIONS ====================
// these functions are used to retrieve data (private) in the JOB

int JOB::getID(/* out */) const 
{
	/* PRE:  Assigned (ID)
	   POST: RETURN == ID of JOB*/
	return(ID);
}

string JOB::getName(/* out */)
{
	/* PRE:  Assigned (name)
	   POST: RETURN == name of JOB*/
	return(name);
}

double JOB::getTotalTime(/* out */) const
{
	/* PRE:  Assigned (TotalTime)
	POST: RETURN == totalTime of JOB*/
	return(totalTime);
}

double JOB::getRemainTime(/* out */) const
{
	/* PRE:  Assigned (remainTime)
	   POST: RETURN == remainTime of JOB*/
	return(remainTime);
}

double JOB::getTotalCPU(/* out */) const
{
	/* PRE:  Assigned (totalCPU)
	   POST: RETURN == total CPU time elapsed on JOB*/
	return(totalCPU);
}

double JOB::getIdleTime(/* out */) const
{
	/* PRE:  Assigned (idleTime)
	   POST: RETURN == idleTime of JOB*/
	return(idleTime);
}

// ================== setter FUNCTIONS =====================
void JOB::setID(/* in */int newID)
{
	/* PRE:  Assigned (newID) && JOB object
	POST: returns nothing; set the ID of JOB == newID*/
	ID = newID;
}

void JOB::setName(/* in */string newName)
{
	/* PRE:  Assigned (newName)
	POST: returns nothing; name of JOB == newName*/
	name = newName;
}

void JOB::setTotalTime(/* in */double newTotalTime)
{
	/* PRE:  Assigned (newTotalTime)
	POST: returns nothing; total CPU time of JOB == newTotalTime*/
	totalTime = newTotalTime;
}

void JOB::setRemainTime(/* in */double newRemainTime)
{
	/* PRE:  Assigned (newRemainTime)
	POST: returns nothing; remainTime of JOB == newRemainTime*/
	remainTime = newRemainTime;
}

void JOB::setTotalCPU(/* in */double newTotalCPU)
{
	/* PRE:  Assigned (newTotalCPU)
	POST: returns nothing; total CPU time of JOB == newTotalCPU*/
	totalCPU = newTotalCPU;
}

void JOB::setIdleTime(/* in */double newIdleTime)
{
	/* PRE:  Assigned (newIdleTime)
	POST: returns nothing; idle time of JOB == newIdleTime*/
	idleTime = newIdleTime;
}

// ----------- print JOBs ---------
void JOB::printJob(/* in */const double timeRemain)
{
	/* PRE:  Assigned (JOB)
	POST: prints out the contents of JOB*/
	cout << "------------------------------------------------------------------------------------" << endl;
	
	printf("Job #%d is DeQueued and enters the CPU with %4.2f seconds remaining... \n", ID, remainTime);
	cout << "Job #" << ID << " -- " << name << " -- is now in the CPU" << endl;		// ID and name of the CPU

	if (timeRemain > 0)				// job still not finished
	{
		printf("Job #%d leaves CPU with %4.2f seconds remaining (%4.2f seconds total CPU time used so far). \n", ID, remainTime, totalCPU);
		cout << "Job #" << ID << " is EnQueued again" << endl;
	}//end if

	else if (timeRemain == 0)		// job just finished within the time slice
	{
		cout << "Job #" << ID << " -- " << name << " -- has finished within the timeslice; ";
		cout << "CPU idles for 0 sec" << endl;
		cout << "Job #" << ID << " -- " << name << " -- has 0 secdons remaining (";
		printf("%4.2f seconds total CPU time used so far). \n", totalCPU);
		cout << "Job #" << ID << " is FINISHED" << endl;
	}//end else if

	else // timeSlice < 0			job finished
	{
		cout << "Job #" << ID << " -- " << name << " -- has finished without using all the timeslice; ";
		printf("CPU idles for %4.2f sec \n", idleTime);
		cout << "Job #" << ID << " -- " << name << " -- has 0 seconds remaining (";
		printf("%4.2f seconds total CPU time used so far) \n", totalCPU);
		cout << "Job #" << ID << " is FINISHED" << endl;
	}
}


// ----------- random function for float --------
/* Returns a random double between min and max */
double fRand(/* inout */double min, double max)
{
	/* PRE:  Assigned (min) && (max)
	POST: RETURN == randomly generated number (double) between min and max*/
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}
/* EXPLAIN:
(double)rand() / (double)RAND_MAX returns a random number between 0 and 1
(max - min) * ( (double)rand() / (double)RAND_MAX ) returns a random number between 0 and max - min.
the whole expression will return a random number between 0 + min and min + (max-min) - i.e. min and max.
*/