#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "MyCharStack.h"

using namespace std;

// PROGRAMMER: Jinnan Ge

int main()
{
	string inFile;
	ifstream FIN;

	inFile = "test2.cpp";

	FIN.clear();
	FIN.open(inFile.c_str());

	if (FIN.fail())
	{
		cout << "ERROR: file called" << inFile << "does not exist." << endl;
		exit(-1);
	}
	/* To only print out the file:
	string line;
	short lineNumber = 1;
	
	getline(FIN, line);
	while (FIN)
	{
		//short lineLength;
		//lineLength = line.length();

		cout << line << endl;
		lineNumber++;

		getline(FIN, line);
	}
	*/

	string newLine;
	short newLineNumber = 1;

	getline(FIN, newLine);

	MyCharStack S;

	while (FIN)
	{
		bool NO_ERROR = true;
		short lineLength;
		lineLength = newLine.length();

		cout << newLine << endl;
		for (short i = 0; i < lineLength; i++)
		{
			switch (newLine[i])
			{
			case '(':
				if (!S.IsFull())
				{
					S.Push(newLine[i]);
					//cout << "I pushed a: " << newLine[i] << endl;
				}
				break;
			case ')':
				if (S.IsEmpty())
				{
					cout << "			missing LEFT PAREN on line " << newLineNumber << endl;
					NO_ERROR = false;
				}
				else
				{
					char c;
					c = S.Top();
					//cout << "I just dropped a " << c << endl;
					S.Pop();
				}
				break;
			default:
				//cout << "			Line " << newLineNumber << " is OK." << endl;
				// this will put the program in infinite loop
				break;
			}//switch
		}// for another char in line


		if (!S.IsEmpty())
		{
			cout << "			missing RIGHT PAREN on line " << newLineNumber << endl;
			NO_ERROR = false;
		}
		
		if (S.IsFull())
		{
			cout << "			Stack is full on line " << newLineNumber << endl;
			NO_ERROR = false;
			system("PAUSE");
			exit(-1);
		}

		if (S.IsEmpty()&& NO_ERROR)
			cout << "			Line " << newLineNumber << " is OK." << endl;


		while (!S.IsEmpty())
		{
			S.Pop();
		}

		newLineNumber++;
		getline(FIN, newLine);
	}


	FIN.close();

	system("PAUSE");
	return 0;
}