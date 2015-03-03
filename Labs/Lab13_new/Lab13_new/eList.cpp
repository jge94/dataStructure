
#include "stdafx.h"
#include "eList.h"
#include "node.h"
#include <iostream>
#include <string>

using namespace std;

ElephantList::ElephantList()
{
	head = tail = new ELEPHANT;
	head->name = "BUFFER";
	head->next = 0;
}

ElephantList::~ElephantList()	// DTOR
{
	ELEPHANT *front, *back;
	front = head->next;
	back = head;
	while (front->next != 0)
	{
		delete back;
		front = front->next;
	}
}

bool IsEmpty(void)
{
	return true;
}

void InsertFront(ELEPHANT* newNode)
{

}

void Insert(ELEPHANT* newNode)
{

}

void Delete(string thisName)
{

}

void PrintAll(void)
{

}