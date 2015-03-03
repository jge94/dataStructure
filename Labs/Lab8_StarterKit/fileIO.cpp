#include "stdafx.h"
#include <iostream>	// need for console and keyboard
#include <fstream>	// need for file streams
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>


using namespace std;

const char DELIMITER = ',';    // comma-separated-values (.csv)

// ======================================================
//  good example for open files for READING and WRITING
// ======================================================
int main()
{
	cout << "interation, random#" << endl;
	srand(time(NULL));

	// ----------------------------------
	string OutFile = "output.csv";
	ofstream FOUT;                  // stream to connect to output file

	FOUT.open(OutFile.c_str());

	if (FOUT.fail())				// but did the attempt to open fail?
	{
		cout << "ERROR: file called " << OutFile << " did NOT open." << endl;
		exit(-1);
	} // if



	// files opened OK .... time to read the story

	FOUT << "iteration" << DELIMITER << "radom#" << DELIMITER << "word" << endl;

	for (short i = 1; i <= 10; i++)
	{
		int x;
		x = rand() % 4 + 1;

		string numTrans;
		switch (x)
		{
		case 1:
			numTrans = "one";
			break;
		case 2:
			numTrans = "two";
			break;
		case 3:
			numTrans = "three";
			break;
		case 4:
			numTrans = "four";
			break;
		default:
			cout << "Oops, why am I in default? Error!" << endl;
			break;
		}// end switch

		//string file;
		//ifstream FIN;

		//file = "output";

		FOUT << i << DELIMITER <<  x << DELIMITER << numTrans << endl;


		cout << i << DELIMITER << x << endl;
	}// end for
	FOUT.close();
	


	
	/*
	string inFile;			// filename to open and search
	ifstream fin;			// stream to connect to input file
	
	
	// ----------------------------------
	inFile = "story.txt";
	
	fin.clear();
	fin.open( inFile.c_str() );		// try to open the file	
	if ( fin.fail() )				// but did the attempt fail?
	{
		cout << "ERROR: file called " << inFile << " did NOT open." << endl;
		exit(-1);
	} // if
	
	// ----------------------------------
	string outFile = inFile + ".csv";
	ofstream fout;                  // stream to connect to output file
	
	fout.open( outFile.c_str() );		
	
	if ( fout.fail() )				// but did the attempt to open fail?
	{
		cout << "ERROR: file called " << outFile << " did NOT open." << endl;
		exit(-1);
	} // if
	
	
	// files opened OK .... time to read the story
	
	string line;
	short  lineNumber=1;
	
	// read lines of the story until End Of File (EOF)
	getline(fin, line);
	while (fin)
	{
		short lineLength;
		lineLength = line.length();
		
		
		fout << lineNumber << DELIMITER << lineLength << endl;
		lineNumber++;
		
        // grab next line
		getline(fin, line);
	} // while not EOF
	
	fin.close();
	fout.close();
	*/
	system("PAUSE");
	return 1;

	
}

