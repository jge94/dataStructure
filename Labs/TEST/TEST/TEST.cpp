// TEST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	string inFile;
	ifstream FIN;

	inFile = "test.txt";
	
	FIN.clear();

	FIN.open(inFile.c_str());
	
	//getline(FIN, inFile);

	if (FIN.fail())
	{
		cout << "The file "<< inFile << " can't be opened. " << endl;
		system("PAUSE");
		exit(-1);
	}
	
	string outFile = inFile + "Output.txt";
	ofstream FOUT;

	FOUT.open(outFile.c_str());

	if (FOUT.fail())
	{
		cout << "The file out: " << outFile << "can't be opened. " << endl;
		system("PAUSE");
		exit(-1);
	}

	string line;
	short numLine = 1;

	getline(FIN, line);

	while (FIN)
	{
		short lenLine = line.length();
		FOUT << line << endl;
		FOUT << "Line number is: " << numLine << endl;
		numLine++;
		getline(FIN, line);
	}

	FIN.close();
	FOUT.close();
	
	system("PAUSE");
	return 0;
}

