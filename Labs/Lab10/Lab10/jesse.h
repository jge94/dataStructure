#ifndef JESSE_H
#define JESSE_H

#include "stdafx.h"
const int MAX_LENGTH = 100;
//using namespace std;

class jesse
{
public:

	jesse();
	jesse(char X[]);
	void PRINT() const;
	short getLength() const;
	void getsCopyOf(jesse x);
	inline char* getText() { return text; };
	bool isEqual(jesse X);
	void concat(char *s);
	void upperCase();
	void reverse();

private:

	char text[MAX_LENGTH + 1];
	short length;
};

#endif