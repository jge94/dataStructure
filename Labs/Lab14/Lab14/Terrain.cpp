#include "stdafx.h"
using namespace std;

#include "Terrain.h"



Terrain::Terrain()
{
	rowDim = 0;
	colDim = 0;
}


Terrain::Terrain(string filename)
{
	rowDim = 0;
	colDim = 0;

	loadMap(filename);
}

Terrain::~Terrain()
{

}

void Terrain::printMap(void) const
{
    // print map without robot(@) showing; probably not used
	cout << "============" << endl;
	for (short i = 0; i < getRowDimension(); i++)
	{
		cout << "|";
		for (short j = 0; j <  getColDimension(); j++)
	        cout << Map[i][j];
		cout << "|" << endl;
	}
	cout << "============" << endl << endl;
	
} // printMap()


void Terrain::printMap(short row, short col) const
{
    // print map with robot(@) showing at [row, col]
	cout << "============" << endl;
	for (short i = 0; i < getRowDimension(); i++)
	{
		cout << "|";
		for (short j = 0; j < getColDimension(); j++)
		{
            if ((row == i) && (col == j) )
            {
                   cout << THE_ROBOT; 			
            }
            else
	           cout << Map[i][j];
        }
		cout << "|" << endl;
	}
	cout << "============" << endl << endl;

} // printMap()




void Terrain::loadMap(string filename)
{
    mapFileName = filename; // store filename in the Terrain object
    
    ifstream inputStream;
	inputStream.open( filename.c_str() );	// careful: open requires a "C-style" string (array of char)
	if( !inputStream )
	{
		cerr << "*** Error opening map with filename: " << filename << endl;
		//system("PAUSE");
		exit(-1);
	}

	cout << "Map " << filename << " open successfully ..." << endl;
	
	string nextLine;
	// snag header line but throw away
	getline( inputStream, nextLine);
	
	// snag first line of terrain data
	getline( inputStream, nextLine);

	// we're assuming all lines (after this one) are the same width (i.e., length)
	colDim = nextLine.size();
	//cout << yDim << endl;
	
	while ( inputStream )	// while more lines in Terrain map (while NOT EOF)
	{
		for (short i=0; i < colDim; i++)
		{
			// take char at a time and load into Map matrix
			Map[rowDim][i] = nextLine[i];
		}
		
		rowDim++;
		
		// snag another line (if there)
		getline( inputStream, nextLine);
	} // while not EOF

} // loadMap()


// inline short getXDimensionOnMap(void) { return xDim; }

// inline short getYDimensionOnMap(void) { return yDim; }



void Terrain::setHistoryMarker( short row, short col, char marker)
{
	Map[row][col] = marker;
}


char Terrain::whatIsHere(short row, short col) const
{
	if (row < this->getRowDimension() && row >= 0 && col < this->getColDimension() && col >=0 )
		return Map[row][col];
	else return NULL;
}







