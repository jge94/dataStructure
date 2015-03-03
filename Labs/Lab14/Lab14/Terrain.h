//#include "stdafx.h"
#ifndef TERRAIN
#define TERRAIN

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const short MAX_row = 10;
const short MAX_col = 10;

const char THE_ROBOT = '@';

class Terrain
{
	public:
		Terrain();
		Terrain(string filename);
		~Terrain();
	
		void loadMap(string filename);
	
		inline short getRowDimension(void) const { return rowDim; }
		inline short getColDimension(void) const { return colDim; }
	
		void setHistoryMarker( short row, short col, char marker);
		
	    char whatIsHere(short row, short col) const;
			
		void  printMap(void) const;
		void  printMap(short, short) const;  // print robot at (row,col)
	
	private:
		string mapFileName;

		char  Map[MAX_row][MAX_col];

		short rowDim;  // actual row-dimension of map
		short colDim;  // actual col-dimension of map

};

#endif
