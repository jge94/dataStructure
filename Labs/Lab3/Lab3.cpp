
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	ifstream FIN;
	string fileName, fullPath;
	cout << "Enter filename to open: ";
	cin >> fileName;
	fullPath = "1_FileIO/" + fileName;		// concat folder and filename
	FIN.open(fullPath.c_str());			// open requires old-style C string
	if (FIN.is_open())
	{
		string oneLine;
		//getline(FIN, oneLine);	 // read one line from FIN stream
			//cout << oneLine << endl;
		//FIN.close();
	}
	else
		cout << "NASTY MESSAGE : " << fullPath << "didn’t open!" << endl;
		

	const char TAB = '\t';

	ofstream FOUT;
	string newFile;
	newFile = fileName + ".xls";
	FOUT.open(newFile);
	FOUT << "Line#" << TAB << "Number of chars" << TAB << "Number of vowels" << endl;

	string oneLine;
	int index;
	index = 0;

	getline(FIN, oneLine);

	int oneLineLength;

	while (FIN)
	{
		//getline(FIN, oneLine);
		int oneLineLength;
		oneLineLength = oneLine.length();
		


		int vowel = 0;
		while(index <= (oneLineLength - 1))
		if (oneLine[index] == 'a' || oneLine[index] == 'e' || 'i' || 'o' || 'u')
				vowel++;

		//myFile << index << TAB << oneLineLength << vowel << TAB << endl;
		index++;

		getline(FIN, oneLine);
	}
	
	int vowel = 0;
	FOUT << index << TAB << oneLineLength << vowel << TAB << endl;
	FOUT.close();


	//myFile << 

	system("PAUSE");

	return 0;
}
