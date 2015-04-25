// List.h
#include "node.h"

#ifndef ELIST
#define ELIST

class ElephantList
{
  public:
  
	 ElephantList();	// CTOR
	~ElephantList();	// DTOR
	
	 bool IsEmpty(void);

	 void InsertFront(ELEPHANT* newNode);
	 
	 void Insert(ELEPHANT* newNode);

	 void Delete(string thisName);
	 
	 void PrintAll(void);
	
  private:
  	ELEPHANT *head;		// pointer to a buffer node which in turns points to first node
  	ELEPHANT *tail;		// pointer to the last node on the list
  	
};

#endif

