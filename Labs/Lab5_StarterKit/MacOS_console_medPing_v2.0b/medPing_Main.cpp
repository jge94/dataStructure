/*--------------------------------------------------------------
Programmer:
Summary:
Date last modified:
----------------------------------------------------------------*/

/*--------------------------------------------------------------
INPUT:
OUTPUT:
---------------------------------------------------------------*/


#include "stdafx.h"
#include "medPing.h"
#include <windows.h>
#include <fstream>
#include <string>
#include <assert.h>

struct dataFrame
{
	double temp;
	short bpm;
	short pulseRate;
	short bloodPre;
	short systolic;
	short diastolic;
	short gluLevel;
};

//--------------
// medPing_Main \
//----------------------------------------------------------------------
int medPing_Main()
{
	// create a medPing object
	medPing mP;

	double temp;
	short bpm, pulseRate, gluLevel, //bloodPre,
		systolic, diastolic;
	
	const short SLEEP_TIME = 100;

	

	dataFrame allRecords[5];

	short i;	//index
	for (i = 0; i < 5; i++)
	{
		temp = mP.getBodyTemperature_F();
		allRecords[i].temp = temp;

		bpm = mP.getRespirationRate_BPM();
		allRecords[i].bpm = bpm;

		pulseRate = mP.getPulseRate_BPM();		// 60 - 100 beats per minute
		allRecords[i].pulseRate = pulseRate;

		mP.getBloodPressure_mmHg(systolic, diastolic);
		allRecords[i].systolic = systolic;
		allRecords[i].diastolic = diastolic;

		gluLevel = mP.getGlucoseLevel_mgdL();
		allRecords[i].gluLevel = gluLevel;
	//cout << "Number of running: " << i;
		Sleep(SLEEP_TIME);
	}
	// print a message to the cell phone

	/*
	mP.CELL_PrintF("\nHello medPing patient ...\n\n");

	mP.CELL_PrintF("Body temperature is: %5.2f \n ", temp);
	mP.CELL_PrintF("Respiration rate is: %5.2hd \n ", bpm);
	mP.CELL_PrintF("Pulse rate is: %5.2hd \n ", pulseRate);
	mP.CELL_PrintF("Blood pressure is: %hd over %hd \n ", systolic, diastolic);
	mP.CELL_PrintF("Glucose level is: %5.2hd \n ", gluLevel);
	cout << endl;
	*/
	//short index;

	for (i = 0; i < 5; i++)
	{
		cout << "Number of run: " << i << endl;
		mP.CELL_PrintF("Body temperature is: %5.2f \n ", allRecords[i].temp);
		mP.CELL_PrintF("Respiration rate is: %5.2hd \n ", allRecords[i].bpm);
		mP.CELL_PrintF("Pulse rate is: %5.2hd \n ", allRecords[i].pulseRate);
		mP.CELL_PrintF("Blood pressure is: %hd over %hd \n ", allRecords[i].systolic, allRecords[i].diastolic);
		mP.CELL_PrintF("Glucose level is: %5.2hd \n ", allRecords[i].gluLevel);
		cout << endl;
	}

	
	//ifstream FIN;
	ofstream FOUT;
	
	//const char TAB = "\t";
	string fileName;

	fileName = "medicalHistory.xls";
	FOUT.open(fileName.c_str());
	
	assert(FOUT.is_open());
	
	//path = fileName;

	//FIN.open(path.c_str());
	
	//if (FIN.is_open())
	//{
	//string line;
		
	FOUT << "Temperature" << "\t" << "Respiration Rate" << "\t" << "Pulse Rate" << "\t" << "Blood Pressure" << "\t" << "Gluosce Level" << endl;
	//getline(FIN, line);
		
	for (i = 0; i < 5; i++)
	{
		//FOUT << "Number of run: " << i << endl;
		FOUT << allRecords[i].temp << "\t";
		FOUT << allRecords[i].bpm << "\t";
		FOUT << allRecords[i].pulseRate << "\t";
		FOUT <<  allRecords[i].systolic << allRecords[i].diastolic << "\t";
		FOUT << allRecords[i].gluLevel;
		FOUT << endl;
	}
	
		
	//}

	ofstream fileOUT;

	string anotherFile, nameFile;

	cout << "Enter the .csv file name: ",
		cin >> nameFile;
	
	anotherFile = nameFile + ".csv";
	
	fileOUT.open(anotherFile.c_str());
	
	assert(fileOUT.is_open());
	
	for (i = 0; i < 5; i++)
	{
		//FOUT << "Number of run: " << i << endl;
		fileOUT << allRecords[i].temp << ",";
		fileOUT << allRecords[i].bpm << ",";
		fileOUT << allRecords[i].pulseRate << ",";
		fileOUT << allRecords[i].systolic << allRecords[i].diastolic << ",";
		fileOUT << allRecords[i].gluLevel;
		fileOUT << endl;
	}

	
	system("PAUSE");
	return 0;

} // end medPing_Main()
