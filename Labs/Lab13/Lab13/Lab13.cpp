// Lab13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "node.h"

#include <iostream>

//#include "eList.h"
#include <string>

using namespace std;

/*struct ELEPHANT
{
	short  age;					// hold an elephant's age and name only 
	string name;

	ELEPHANT  *next;	// pointer to next node in the list

};*/

int main()
{

	ELEPHANT *head, *one, *two, *three;
	
	head = new ELEPHANT;
	head->name = "BUFFER";
	
	one = new ELEPHANT;
	one->name = "Elmet";
	head->next = one;

	two = new ELEPHANT;
	two->name = "Edna";
	one->next = two;

	three = new ELEPHANT;
	three->name = "Eloise";
	two->next = three;

	ELEPHANT *temp;
	temp = head->next;

	for (short i = 0; i < 3; i++)
	{
		cout << "Name is: "<< temp->name << endl;
		temp = temp->next;
	}
	
	system("PAUSE");
	return 0;
}

