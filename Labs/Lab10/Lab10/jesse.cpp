#include "stdafx.h"
#include <iostream>
#include "jesse.h"
#include <stack>

using namespace std;

//++++++++ DEFAULT CTOR++++++++++
jesse::jesse()
{
	strcpy_s(text, "DEFAULT TEXT");
	length = strlen(text);
}

jesse::jesse(char X[])
{
	strcpy_s(text, X);
	length = strlen(text);
}

void jesse::PRINT() const
{
	cout << text << endl;
	
}

short jesse::getLength() const	// not const?? WHY??
{
	return length;
}

void jesse::getsCopyOf(jesse x)
{
	strcpy_s(text, x.getText());
	length = strlen(text);
}

/*
char* jesse::getText()
{
	return text;
}
*/

bool jesse::isEqual(jesse X)
{
	/*char* xText;
	//xText = ['f', 'o', 'o'];		WHY WRONG?
	bool equal;
	//strcpy_s(xText, X.getText());		WHY WRONG?
	for (short i = 0; i < length; i++)
	{
		if (text[i] == xText[i])
			equal = true;
		else
			equal = false;
	}
	return equal;*/
	
	/*if (strcmp(this->text, X.text)) //THIS IS WRONG BECAUSE IT RETURNS 0 IF THE SAME
		cout << "Yes! Two are the same!" << endl;
	else
		cout << "Nope, two jesse are not the same. " << endl;*/
	
	cout << strcmp(this->text, X.text) << endl;		//this can be omitted

	return(strcmp(this->text, X.text));
}


void jesse::concat(char *s)
{
	strcat_s(this->text, s);	//THIS  does concatenation
	length = strlen(text);
}

void jesse::upperCase()
{
	//length = strlen(text);
	for (short i = 0; i < length; i++)
	{
		text[i] = toupper(text[i]);
	}
}


void jesse::reverse()
{
	stack <char> A;
	short i = 0;
	while (i < length )
	{
		A.push(text[i]);
		i++;
	}

	for (i = 0; i < length; i++)
	{
		text[i] = A.top();
		//char popChar = A.front();
		A.pop();
	}
}

