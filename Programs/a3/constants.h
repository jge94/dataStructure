#ifndef _CONSTANTS_H
#define _CONSTANTS_H

//----------------------------------------------------------------------
//  SPECIFICATION FILE (constants.h)
//  This module defines constants used for the program
//----------------------------------------------------------------------


const short ID_MIN = 6;						// min for new ID # (new jobs)
const short ID_MAX = 100;					// maximum for ID #


const short TYPE_CONST = 100;				// constant for types of job (to be randomly generated)

const char DELIMITER = ',';					// delimiter for the output .csv file


// =====================  PROBABILITY OF OCCURRENCE =================
// for different job types
const int PRINT_PROB = 20;					// high-end of printing				 probability of job "print": 0.2
const int COMPILE_PROB = 50;				// high-end of compiling			 probability of job "compile": 0.3
const int EMAIL_PROB = 90;					// high-end of emailing				 probability of job "email": 0.5
const int OTHER_PROB = 100;					// high-end of other				 probability of job "other": 0.1


// =====================  TOTAL TIME FOR JOB =================
// in seconds

// NORMAL RANGE OF PRINTING:  1 - 5
const double LOW_PRINT_TIME = 1.0;					// low-end of printing
const double HIGH_PRINT_TIME = 5.0;					// high-end of printing

// NORMAL RANGE OF COMPILING:  10 - 100
const double LOW_COMPILE_TIME = 10.0;				// low-end of compiling
const double HIGH_COMPILE_TIME = 100.0;				// high-end of compiling

// NORMAL RANGE OF EMAILING:  3 - 20
const double LOW_EMAIL_TIME = 3.0;					// low-end of emailing
const double HIGH_EMAIL_TIME = 20.0;				// high-end of emailing

// NORMAL RANGE OF OTHER:  0 - 45
const double LOW_OTHER_TIME = 0.0;					// low-end of other
const double HIGH_OTHER_TIME = 45.0;				// high-end of other


#endif		// _CONSTANTS_H not defined