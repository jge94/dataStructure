/*===========================================================================*
* Programmer:		Jinnan Ge												 *
* Program #4:		(a3)													 *
*																			 *
*																			 *
* Date Modified:															 *
*	 03/19/2014(jg)	created class JOB, started JOB.h and JOB.cpp			 *
*	 03/20/2014(jg)	finished JOB.h and JOB.cpp, tested creating JOB object	 *
*	 03/23/2014(jg)	finished pushing&popping, calculating JOB object in queue*
*	 03/24/2014(jg)	finished adding "new jobs arrives" functions			 *
*	 03/25/2014(jg) finished printing out results in .xls, .csv and graphs	 *
*																	         *
*																			 *
* Summary:																	 *
*	   This program simulates working process of CPU: accepting and working	 *
*   on different jobs and assigning time slice for jobs until finishing them.*
*============================================================================*/

/*===========================================================================*
* INPUT(from keyboard, stdin):												 *
*		timeSlice: time slice to assgin to each job (in sec)				 *
*		(NOTICE: time slice can not be zero)								 *
*		simTime: (simulation time)											 *
*				 time length to allow new jobs to enter the queue			 *
*		jobProb: (probability of new jobs)									 *
*				 probability that a new job enters the queue while another	 *
*				 job is in the CPU											 *
*																			 *
* OUTPUT(to console, stdout):												 *
*		ID number of the job												 *
*		status of the job ( whether in CPU, whether finished)				 *
*		time remaining for the job to be finished							 *
*		name of the job														 *
*		CPU time the job takes up											 *
*		CPU idling time for the job (if not finished)						 *
*		relationship with the queue (enQueued, deQueued)					 *
*		total CPU time for all jobs											 *
*		total CPU time for idling time										 *
*		status of new added jobs											 *
*																			 *
*		(file, .csv)														 *
*		file containing data about time and number of jobs					 *
*		[Attached] analysis on a sample output								 *
=============================================================================*/

/*=======================================================================================================

	SAMPLE OUTPUT: 
			            +++++ simQ 1.0 +++++

*			Enter time slice to assign to each job: 10.0

			Enter length of time to allow new jobs to enter the queue: 50

			Enter the probability of a new job entering the queue while another job is in the CPU: 0.5

			Job#1 is DeQueued and enters the CPU with 1.24 seconds remaining....
			Job#1 -- Print -- is now in CPU
			Job#1 -- Print -- has finished without using all the timeslice; CPU idles for 8.76 sec
			Job#1 -- Print -- has 0 seconds remaining (1.24 seconds total CPU time used so far).
			Job#1 is FINISHED
			---------------------------------------------------------------------------------------
			......

========================================================================================================*/

// -- LIBRARIES needed ---
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "JOB.h"
#include "constants.h"
#include <queue>
#include <fstream>

// enable access to all names in std
using namespace std;

// ---------main function starts here-------
int main()
{
	srand(time(NULL));													// seed rand function (only once)

	cout << "			++++++++ simQ 1.0 +++++++" << endl << endl;		// title

	string fileOUT = "Output.csv";										// output file: Output.csv
	ofstream FOUT;														// output pipe

	FOUT.open(fileOUT.c_str());

	if (FOUT.fail())													// trap if pipe is not successfully opened
	{
		cout << "ERROR: file called " << fileOUT << " did NOT open." << endl;
		exit(-1);
	} //end if

	// ------ print out header for the EXCEL file ---------
	FOUT << "Time" << DELIMITER << "Jobs" << endl;


	// --------------- ask for user's input (3) --------------

	double timeSlice;													// time slice to assgin to each job (in sec)
	cout << "Enter time slice to assign to each job: ",
		cin >> timeSlice;

	while (timeSlice == 0)												// time slice can't be 0 because CPU takes time to process jobs
	{																	// trap invalid input
		cout << "\nInvalid input! CPU takes time to finish a job. " << endl;
		cout << "Enter again: ",
			cin >> timeSlice;
	}

	double simTime;															 // (simulation time)
	cout << "\nEnter length of time to allow new jobs to enter the queue: ", //time length to allow new jobs to enter the queue
		cin >> simTime;

	double jobProb;
	cout << "\nEnter the probability of a new job entering the queue while another job is in the CPU: ",
		cin >> jobProb;														//jobProb: (probability of new jobs)
																			//probability that a new job enters the queue while another
	jobProb = jobProb * 100;												//job is in the CPU

	cout << endl;


	queue <JOB> Q;						// data structure: create a queue with every cell in the 
										// data structure of JOB (as defined)
	
	// ------- push 5 jobs onto the queue ------
	for (short i = 0; i < 5; i++)			
	{
		JOB temp;
		temp.setTotalCPU(0);
		Q.push(temp);
	}// end for							// now the queue is filled with 5 cells of data structure JOB

	double cpuForAll = 0;				// total CPU time elapsed on all jobs
	
	// ============= [PART II] ===============
	double idleTime = 0;				// temporary idling time (for a single job)
	double idleTimeTotal = 0;			// total idling time (for all jobs)
	double newTotalCPU = 0;				// temporary total CPU time (in order to be assigned in JOBs later)
	int nextID = ID_MIN;				// ID_MIN = 6 here, initialize nextID so that ID # is always different


	while (cpuForAll < simTime)			// while there is still time for simulation (CPU doesn't exceed simulation time from input)
	{
		if (!Q.empty())					// prerequisite of Q.pop()
		{
			JOB temp;					// temporary data structure of JOB (containing all the randomly assigned info)
			temp = Q.front();			// store the front of the queue in temp
			Q.pop();					// since Q is not empty, pop the front off

			double timeRemain = temp.getRemainTime() - timeSlice;		// remaining time of the current job (being processed now)

			if (timeRemain > 0)			// if there's still time remaing (job not finished)
			{
				newTotalCPU = (temp.getTotalCPU() + timeSlice);			// CPU time spent on this job gets increased by a timeSlice
				temp.setTotalCPU(newTotalCPU);							// store the new CPU time into the current job
				temp.setRemainTime(timeRemain);							// change the remaining time of the job
				Q.push(temp);											// push back to the queue (since not done)
			}//end if

			else if (timeRemain == 0)									// if the job just used up the given timeslice
			{
				newTotalCPU = (temp.getTotalCPU() + timeSlice);			// same as above
				temp.setTotalCPU(newTotalCPU);
				temp.setRemainTime(timeRemain);
			}//end else if

			else // timeSlice < 0										// if there's no remaining time (job gets finished)
			{	
				idleTime = (-timeRemain);								// CPU idles during the rest of the time
				temp.setIdleTime(idleTime);								// store in JOB
				newTotalCPU = temp.getTotalCPU() + (timeSlice - idleTime);	// same as above
				temp.setTotalCPU(newTotalCPU);
			}

			// print out each job
			temp.printJob(timeRemain);

			idleTimeTotal += idleTime;									// keep track of the total idling time
		}// end if Q is not empty

		else // if queue is empty										// if all jobs get processed
		{
			printf("\nNo job in the queue, CPU idles... \n");			// tell the user
			printf(" *** CPU idles another %4.2f seconds \n", timeSlice);		// print total idle time
			idleTimeTotal += timeSlice;									// CPU idles during every time slice (since it has nothing to do)
		}//end queue is empty


		// ------ PART II special --------
		short randProb;													// randomly generated number
		randProb = rand() % 100 + 1;									// from 1 to 100
		if ( randProb <= jobProb										// once random number is less than the assigned probability
			/*new job arrives*/)										// then conditions for new job is satisfied
		{
			JOB *newJob = new JOB(nextID);								// create new job
			Q.push(*newJob);											// push new job to the queue
			Q.back().setTotalCPU(0);									// initialize all total CPU time = 0
			cout << "\nNew job added to CPU." << endl;
		}
		
		nextID++;												// to make ID# different: start from 6 and increase
		cpuForAll += timeSlice;									// CPU time increases by timeSlice

		// ------------ print out EXCEL file -----------
		FOUT << cpuForAll << DELIMITER << Q.size() << endl;		// print to the .csv file: CPU time and # of jobs
	}

	printf(" \n\n************ Total time the CPU spent on idling is: %4.2f *************\n", idleTimeTotal);	//total CPU time elapsed
	printf("Now the time slice expired. No new jobs coming into the CPU.\n\n\n");								// change status


	// ============== [PART I] ===============					// CPU stopped taking new jobs, but only processing 
																//the jobs it already took
	while (!Q.empty())											// while there's still job not finished
	{
		JOB temp;												// remember the front of queue
		temp = Q.front();
		Q.pop();												// pop off

		double timeRemain = temp.getRemainTime() - timeSlice;

		if (timeRemain > 0)
		{
			newTotalCPU = (temp.getTotalCPU() + timeSlice);
			temp.setTotalCPU(newTotalCPU);
			temp.setRemainTime(timeRemain);
			Q.push(temp);
		}//end if
		else if (timeRemain == 0)
		{
			newTotalCPU = (temp.getTotalCPU() + timeSlice);
			temp.setTotalCPU(newTotalCPU);
			temp.setRemainTime(timeRemain);
		}//end else if
		else // timeSlice < 0
		{
			idleTime = (- timeRemain);
			temp.setIdleTime(idleTime);
			newTotalCPU = temp.getTotalCPU() + (timeSlice -idleTime);
			temp.setTotalCPU(newTotalCPU);
		}

		temp.printJob(timeRemain);

		idleTimeTotal += idleTime;
		cpuForAll += timeSlice;

		// ------------ print out EXCEL file (part 2) -----------
		FOUT << cpuForAll << DELIMITER << Q.size() << endl;
	}

	FOUT.close();						// close the pipe

	printf("\n\nTotal time of CPU's idling is: %4.2f sec\n", idleTimeTotal);		//print out CPU's total idling time
	printf("\nTotal CPU time used (for all tasks): %4.2f sec\n", cpuForAll);		// print out total CPU time elapsed
	cout << "\n\nDone." << endl;

	system("PAUSE");
	return(0);
}
