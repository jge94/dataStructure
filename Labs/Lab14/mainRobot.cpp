#include "stdafx.h"
#include <string>
#include <iostream>

#include <stack>

#include "enums.h"
#include "Terrain.h"

using namespace std;

// -------------------------------------------------------------------------
// prototypes for FXs in this file
//
// RECURSIVE search (with backtracking when needed)
bool seekTheGoal( short row, short col, Terrain map );

// Robot queries
bool atGoal( const short row, const short col, const Terrain& map);
bool alreadyBeenHere( const short row, const short col, const Terrain& map);
bool okToGoHere(short row, short col, const Terrain& map);

// check starting location
bool checkStart(short row, short col, Terrain map);

void pauseOutput();
// -------------------------------------------------------------------------

int main()
{
	Terrain T("map3.txt");
	stack<int> *S;
	S = new stack<int>;
	S->push(up);

	// Robot starts HERE 
	// (doesn't check if it lands in a hole/rock :(   .... need to fix)

	short row=3, col=0;
	
	if (checkStart(row, col, T)){

		if (seekTheGoal(row, col, T))
			cout << "FOUND THE GOAL" << endl;

		else
			cout << "Can't get to GOAL from he-ah." << endl;
	}
	else
		cout << "Invaid starting location" << endl;
	
	system("PAUSE");
   	return 1;
	
} // end main()


//------------\
// seekTheGoal \
//----------------------------------------------------------------
bool seekTheGoal( short row, short col, Terrain map )
//================================================================
// Summary: Starting at [row,col], recursively move robot(@) to
//          find the Goal (G). Leave a trail of X for visited cells.
//          Try (i) LEFT, (ii) RIGHT, (iii) UP, then (iv) DOWN.
//          Backtrack if Goal is not found and robot is stuck.
//
// PRE:  robot(@) is located at cell: [row, col] on map
// POST: Returns TRUE if Goal is found; otherwise FALSE.
// Side Effect(s): map is pass-by-value so updated on each call
//================================================================
{
	map.printMap( row, col );
	
	pauseOutput();
	
	if ( atGoal( row, col, map ) )
		return true;
	
	else if ( alreadyBeenHere( row, col, map ) )
			return false;
	
	else // haven't been here before; where to next?
	{
			// -- RIGHT? --------------------------------------
			if ( okToGoHere(row, col+1, map) )
			{
				map.setHistoryMarker(row, col, BEENHERE);
				if ( seekTheGoal(row, col+1, map) )
					return true;
				else {
					// show BACKTRACK visually
					map.setHistoryMarker(row, col+1, BEENHERE);
					map.setHistoryMarker(row, col, THE_ROBOT);
					cout << "Backtracking ..." << endl;
					map.printMap( row, col );
					pauseOutput();
				}
			}
			
			// hmmm, RIGHT didn't work out ....
			// -- LEFT? --------------------------------------
            if ( okToGoHere(row, col-1, map) )
            {
                map.setHistoryMarker(row, col, BEENHERE);
                if ( seekTheGoal(row, col-1, map) )
                    return true;
                else {
                    // show BACKTRACK visually
                    map.setHistoryMarker(row, col-1, BEENHERE);
                    map.setHistoryMarker(row, col, THE_ROBOT);
                    cout << "Backtracking ..." << endl;
                    map.printMap( row, col );
					pauseOutput();
                }
            
            }
		
            // hmmm, LEFT didn't work out ....
            // -- UP? --------------------------------------
			if (okToGoHere(row+1, col, map))
			{
				map.setHistoryMarker(row, col, BEENHERE);
				if (seekTheGoal(row+1, col, map))
					return true;
				else {
					// show BACKTRACK visually
					map.setHistoryMarker(row+1, col, BEENHERE);
					map.setHistoryMarker(row, col, THE_ROBOT);
					cout << "Backtracking ..." << endl;
					map.printMap(row, col);
					pauseOutput();
				}

			}

            // hmmm, UP didn't work out ....
            // -- DOWN? --------------------------------------
			if (okToGoHere(row - 1, col, map))
			{
				map.setHistoryMarker(row, col, BEENHERE);
				if (seekTheGoal(row - 1, col, map))
					return true;
				else {
					// show BACKTRACK visually
					map.setHistoryMarker(row - 1, col, BEENHERE);
					map.setHistoryMarker(row, col, THE_ROBOT);
					cout << "Backtracking ..." << endl;
					map.printMap(row, col);
					pauseOutput();
				}

			}
			return false;
		
	} // else haven't been here before
		
}
	
		 


//-------\
// atGoal \
//----------------------------------------------------------------
bool atGoal( const short row, const short col, const Terrain& map)
// ==========================================================================
{
	return ( map.whatIsHere( row, col ) == GOAL );
}

//----------------\
// alreadyBeenHere \
//----------------------------------------------------------------
bool alreadyBeenHere( const short row, const short col, const Terrain& map)
{
	return ( map.whatIsHere( row, col ) == BEENHERE );
}


//-----------\
// okToGoHere \
//----------------------------------------------------------------
bool okToGoHere(short row, short col, const Terrain& map)
{
		// Columbus check ...
		// make sure robot doesn't try to fall off the edge of the world
		if ( (row < 0) || (row >= map.getRowDimension()) ||
			 (col < 0) || (col >= map.getColDimension()) )
			return false;
		
		switch ( map.whatIsHere(row,col) )
		{
			case ROCK: 
				return false;
			case HOLE: 
				return false;
			case BEENHERE: 
				return false;
				
			case GOAL: 
				return true;
			case OPEN: 
				return true;
				
			default: 
				return false;
		}
	
		return false;
}


void pauseOutput()
{
	// pause 'til (RETURN/ENTER)
	char junk;
	junk = getchar();
}

bool checkStart(short row, short col, Terrain map)
{
	if (map.whatIsHere(row, col) == OPEN || map.whatIsHere(row,col) == GOAL)
	{
		if (map.whatIsHere(row - 1, col) == OPEN || map.whatIsHere(row, col - 1) == OPEN || map.whatIsHere(row + 1, col) == OPEN || map.whatIsHere(row, col + 1) == OPEN || map.whatIsHere(row - 1, col) == GOAL || map.whatIsHere(row, col - 1) == GOAL || map.whatIsHere(row + 1, col) == GOAL || map.whatIsHere(row, col + 1) == GOAL)
		{
			return true;
		}
		else return false;
	}
	else return false;
}
	



