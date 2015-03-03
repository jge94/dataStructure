#include <iostream>

using namespace std;


struct RECORD
{
	short id;
	string firstName;
	string lastName;
	double gpa;
};

void printRecord ( const RECORD& r );

void printAllRecords (const RECORD all[], const short hmr);

int main()
{
	RECORD oneRec;

	oneRec.id = 1234;
	oneRec.firstName = "Sal";
	oneRec.lastName = "Lee";
	oneRec.gpa = 2.98;

	printRecord( oneRec );

	// ---- array of structs -------------
	RECORD course[3];

	short hmr = 0;
	course[0].id = 4234;
	course[0].firstName = "Dick";
	course[0].lastName = "Jones";
	course[0].gpa = 3.12;
	hmr++;

	course[1].id = 9999;
	course[1].firstName = "Oh";
	course[1].lastName = "Whoops";
	course[1].gpa = 1.49;
	hmr++;

	printAllRecords ( course, hmr );

	return 0;
}

void printRecord ( const RECORD& r )
{
	cout << "--------------------------------" << endl;
	cout << "ID: " << r.id << endl;
	cout << "Name: " << r.firstName << " " << r.lastName << endl;
	printf("GPA: %.2f\n", r.gpa);
	cout << "--------------------------------" << endl;
}

void printAllRecords (const RECORD all[], const short hmr)
{
	for (short i=0; i < hmr; i++)
		printRecord( all[i] );

}
