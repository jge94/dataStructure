#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string inFile;
	ifstream FIN;
	
	inFile = "test.cpp";
	
	FIN.clear();
	FIN.open(inFile.c_str());

	if (FIN.fail())
	{
		cout << "ERROR: file called" << inFile << "does not exist." << endl;
		exit(-1);
	}

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

	FIN.close();
	system("PAUSE");
	return 0;
}