// Lab12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "myStr.h"
using namespace std;

short myStrLen(char s[]);
short myStrLenP(char *ps);
void myStrCpy(char to[], char from[]);
void myStrCpyP(char *pTo, char *pFrom);

int main()
{

	//myStr StringA;
	//myStr StringB;
	//cout << String << endl;
	char s[20];
	strcpy_s(s, "foobar"); // yes, you can use strcpy() to setup
	short Length;
	Length = myStrLen(s);
	cout << "Length of " << s << " is : " << Length << endl;
	Length = myStrLenP(s);
	cout << "Length of " << s << " is : " << Length << endl;
	char A[20];
	myStrCpy(A, "test");
	cout << "Changed string is: " << A << endl;
	char B[20];
	myStrCpyP(B, "testAgain");
	cout << "Changed string 2 is: " << B << endl;

	system("PAUSE");
	return 0;
}



short myStrLen(char s[])
{
	short L = 0;
	for (short i = 0; s[i] != '\0'; i++){
		L++;
	}
	return(L);
}

short myStrLenP(char *ps)
{
	short i = 0;
	while (*ps != '\0')
	{
		i++;
		ps++;
	}
	return (i);
}

void myStrCpy(char to[], char from[])
{
	/* This section is working fine
	short i = 0;
	for (i = 0; from[i] != '\0'; i++)
	{
		to[i] = from[i];
	}
	to[i] = '\0';*/

	// John Moore code
	//for (short i = 0; to[i] = from[i]; i++)
		//;
	// John Moore code ver.2
	short i = 0;
	while (to[i++] = from[i])
		;
}

void myStrCpyP(char *pTo, char *pFrom)
{
	//short i = 0;
	/*while (*pFrom != '\0')
	{
	*pTo = *pFrom;
	pFrom++;
	pTo++;
	}
	*pTo = '\0';*/

	// John Moore code
	short i = 0;
	while (*pTo = *pFrom)
	{
		pTo++;
		pFrom++;
	}
}

