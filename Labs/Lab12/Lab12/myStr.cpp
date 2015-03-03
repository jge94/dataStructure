#include "stdafx.h"
#include "myStr.h"
#include <iostream>
using namespace std;

myStr::myStr()
{
	strcpy_s(s, "DEFAULT");
	cout << s << endl; 
}

short myStr::myStrLen(char s[])
{
	short L=0;
	for (short i = 0; s[i] != '\0'; i++){
		L++;
	}
	return(L);
}

short myStr::myStrLenP(char *ps)
{
	short i = 0;
	while(*ps != '\0')
	{
		i++;
		ps++;
	}
	return (i);
}

void myStr::myStrCpy(char to[], char from[])
{
	for (short i = 0; from[i] != '\0'; i++)
	{
		to[i] = from[i];
	}
}

void myStr::myStrCpyP(char *pTo, char *pFrom)
{
	//short i = 0;
	while (*pFrom != '\0')
	{
		*pTo = *pFrom;
		pFrom++;
		pTo++;
	}
}