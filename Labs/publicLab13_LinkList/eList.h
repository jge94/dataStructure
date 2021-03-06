// List.h
#include "node.h"

#ifndef ELIST
#define ELIST

class ElephantList
{
  public:
  
	 ElephantList();	// CTOR
	~ElephantList();	// DTOR
	
	 bool IsEmpty(void) const;
	 
	 void Insert(ELEPHANT*);
	 
	 void PrintAll(void) const;
	
  private:
  	ELEPHANT *head;		// pointer to a buffer node which in turns points to first node
  	ELEPHANT *tail;		// pointer to the last node on the list
  	
};

#endif

