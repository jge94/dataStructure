// Lab13_new.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "node.h"
#include <iostream>
using namespace std;

ELEPHANT* create(void);
ELEPHANT* create(string newName);
ELEPHANT* create(string newName, short newAge);

int _tmain(int argc, _TCHAR* argv[])
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
		cout << "Name is: " << temp->name << endl;
		temp = temp->next;
	}

	ELEPHANT *tempELE;
	tempELE = create("Elmer", 13);
	cout << "TEMP name: " << tempELE->name << endl;
	cout << "TEMP age: " << tempELE->age << endl;
	system("PAUSE");
	return 0;
}

ELEPHANT* create(void)
{
	ELEPHANT* temp;
	temp = new ELEPHANT;
	temp->next = 0;
	return temp;
}

ELEPHANT* create(string newName)
{
	ELEPHANT* temp;
	temp = new ELEPHANT;
	temp->name = newName;
	temp->next = 0;
	return temp;
}


ELEPHANT* create(string newName, short newAge)
{
	ELEPHANT* temp;
	temp = new ELEPHANT;
	temp->name = newName;
	temp->age = newAge;
	temp->next = 0;
	return temp;
}
