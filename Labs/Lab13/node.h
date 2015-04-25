// node.h -- these are the NODES on the list
#ifndef an_ELEPHANT
#define an_ELEPHANT

//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
// NODE for ONE elephant
typedef
struct anELEPHANT
{
	short  age;					// hold an elephant's age and name only 
    string name;
    
	struct anELEPHANT  *next;	// pointer to next node in the list
	
}ELEPHANT;

#endif

