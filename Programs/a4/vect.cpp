// Vect.cpp
#include "stdafx.h"
#include "vect.h"

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "math.h"

using namespace std;

//-----------------------------------------------------------------------
//----- Constructors (CTOR) ---------------------------------------------

Vect::Vect()
/*
PRE:  None
POST: Will create a new vector object with the default settings
*/
{
      this->size = 3;                          // Default size
      this->pVect = new double[size];          // Creates a new block of doubles
}

//-----------------------------------------------------------------------

Vect::Vect(/*in*/long n)
/*
PRE:  n is assigned
POST: Will create a new vector object of the desired size n
*/
{
	this->size = n;								   // plug in the size of vector
	this->pVect = new double[this->size];          // Creates a new block of doubles
}
    
    

//-----------------------------------------------------------------------
// COPY CTOR
Vect::Vect(/*in*/const Vect& vect2)
/*
PRE:  vect2 is assigned
POST: Will create a new vector object of the same size as vect2 and 
      with the same values
*/
{
       this->size = vect2.size;                // Size set to the size of vect2
       this->pVect = new double[this->size];   // Creates a new block of doubles
       
       // Copy all elements of vect2 into the new vector
	   for (short i = 0; i < size; i++)
	   {
		   pVect[i] = vect2.pVect[i];				// change values in vectors through pointer
	   }
}

//-----------------------------------------------------------------------
//----- Destructor (DTOR) -----------------------------------------------

Vect::~Vect()
/*
PRE:  None
POST: Will free pVect so that memory can be used again
*/
{
	delete[] pVect;						// free memory (block of pVect)
	//pVect = 0;
}

//-----------------------------------------------------------------------
//----- Get magnitude of vector -----------------------------------------

double Vect::getMagnitude()
/*
PRE:  None
POST: Returns the magnitude of the vector
*/
{
      double magnitude;        // Holds final magnitude of vector
      double sum = 0;          // Holds sum of all elements squared
      short i = 0;             // Counter Declaration
      
      // Loops through all elements in the vector and adds up the squares of each element
	  while (i < size)
	  {
		  sum += pow(pVect[i],2);
		  i++;
	  }//while
	  
	  magnitude = sqrt(sum);	// Take square root of the sum
    
      return magnitude;
}

//-----------------------------------------------------------------------
//----- Set elements of vector ------------------------------------------

double& Vect::operator[] (/*in*/long i) const
/*
PRE:  i is assigned
POST: Returns desired dereferenced vector element 
*/
{
      // Checks that i is a valid index, if not the program exits
      if (i < 0 || i >= this->size)
      {
            cerr << "ERROR:index [" << i << "] is out of bounds." << endl;
            system("PAUSE");
            exit(-1);
      }// end if
      
      return pVect[i];				// return dereferenced element
}

//-----------------------------------------------------------------------

Vect& Vect::operator=(/*in*/const Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Copies all elements of vect2 to vector making the call and
changes its size if needed to match vect2
Returns cloned vector
*/
{
	delete[] pVect;								// free block of memory to assign new values

	pVect = new double[vect2.size];				// create new block of doubles
	size = vect2.size;							// set size of LHS vector equal to RHS

	for (short i = 0; i < vect2.size; i++)		// loop through the new pVect to assign all  RHS values to LHS
	{
		this->pVect[i] = vect2.pVect[i];		// assign RHS to LHS
	}// end for

	return *this;
}

//-----------------------------------------------------------------------
//----- Vector arithmetic ----------------------------------------------

//	[ADDITION]
const Vect Vect::operator+(/*in*/const Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns vector temp which is the sum of the vector making
the call and vect2
*/
{
	Vect tempVect;									// new vector to store the sum of two vectors

	if (this->size < vect2.size)					// dimension of v1 < dimension of v2
	{
		tempVect.size = vect2.size;					// size of result vector = the larger dimension

		for (short i = 0; i < size; i++)			// result vector = v1 + v2 until temp reaches the size of v1

			tempVect.pVect[i] = pVect[i] + vect2.pVect[i];	// result element = some dimension of v1+v2

		for (short i = size; i < vect2.size; i++)	// rest of result-vector = only elements in v2

			tempVect.pVect[i] = vect2.pVect[i];		// result = only v2

	}// end dimension(v1) < dimension(v2)

	else if (this->size == vect2.size)				// if dim(v1) equals dim(v2)	
	{
		tempVect.size = size;						// result-vector = size of either one

		for (short i = 0; i < size; i++)			// loop through until (size-1)

			tempVect.pVect[i] = pVect[i] + vect2.pVect[i];		// assign sum
	}//end else if

	else											// dimension of v1 > v2
	{
		tempVect.size = this->size;					// result-vector = size of larger vector

		for (short i = 0; i < vect2.size; i++)		// loop thru until the smaller size
			tempVect.pVect[i] = pVect[i] + vect2.pVect[i];		// assign sum

		for (short i = vect2.size; i < size; i++)	// loop from the smaller size to the larger size
			tempVect.pVect[i] = pVect[i];			// assign only the larger vector
	}
    
	return tempVect;								// return result-vector
}


//-----------------------------------------------------------------------
//	[SUBTRACTION]

const Vect Vect::operator-(/*in*/const Vect& vect2)			// same principles as ADDITION
/*
PRE:  vect2 is an assigned vector
POST: Returns vector temp which is the difference of the vector making
the call and vect2
*/
{

	Vect tempVect;
	if (this->size < vect2.size)					// dimension of v1 < dimension of v2
	{
			tempVect.size = vect2.size;

			for (short i = 0; i < size; i++)		// tempVect = v1 + v2 until temp reaches the size of v1
				tempVect.pVect[i] = pVect[i] - vect2.pVect[i];

			for (short i = size; i < vect2.size; i++)	// rest of tempVect = only v2
				tempVect.pVect[i] = vect2.pVect[i];

	}// end D v1 < D v2

	else if (this->size == vect2.size)
	{
		tempVect.size = size;
		for (short i = 0; i < size; i++)
			tempVect.pVect[i] = pVect[i] - vect2.pVect[i];
	} // end else if

	else												// dimension of v1 > v2
	{
		tempVect.size = this->size;
		for (short i = 0; i < vect2.size; i++)
			tempVect.pVect[i] = pVect[i] - vect2.pVect[i];
		for (short i = vect2.size; i < size; i++)
			tempVect.pVect[i] = pVect[i];
	}//end else
	return tempVect;
}

//-----------------------------------------------------------------------
//	 [Scalar Multiplication]

const Vect Vect::operator*(/*in*/const double& mult)
/*
PRE:  mult is an assigned double
POST: returns the scalar multiplication of the vector
*/
{
	Vect result;								// result vector
	result.size = size;							// store the current vector's size
	for (short i = 0; i < size; i++)			// loop thru until reaching the size
	{
		result.pVect[i] = pVect[i] * mult;		// every element in different dimenion times the double
	}
	return result;
}


//-----------------------------------------------------------------------
//	 [Dot Product]

const double Vect::operator*(/*in*/const Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: returns the dot product of two vectors, which is also a double
*/
{
	double result = 0;							// intialize the result
	long realSize;								// the real size when calculating (take the rest as 0)

	if (this->size < vect2.size)				// if sizeOf(v1) < sizeOf(v2)
		realSize = size;						// take the smaller size
	else										// if sizeOf(v1) > sizeOf(v2)
		realSize = vect2.size;					// take the smaller size

	for (short i = 0; i < realSize; i++)		// loop thru the real size (smaller one between two vectors)
	{
		result += pVect[i] * vect2.pVect[i];	// dot product = sum of products
	}

	return result;
}


//-----------------------------------------------------------------------
//	[Cross Product]

const Vect Vect::operator^(/*in*/const Vect& vect2)
/*
PRE: assigned( this->size ) and vector.size (argument) both have size==3
	 must be vector * vector
POST: return the cross product of the two vectors
*/
{
	Vect crossVect;						// result vector of cross product
	if (size != 3 || vect2.size != 3)	// if either of the two vectors have dimenion greater than 3
	{
		// warn users: print out message
		cout << "Invalid calculation! Cross product must be used among two 3-dimensional vectors." << endl;
		return *this;					// return original vector
	}
	else								// if satisfied by the dimension requirements
	{
		crossVect.size = 3;				// since two vectors all have size of 3, result also = size of 3

		crossVect.pVect[0] = pVect[1] * vect2.pVect[2] + pVect[2] * vect2.pVect[1];		// formulas
		crossVect.pVect[1] = pVect[2] * vect2.pVect[0] + pVect[0] * vect2.pVect[2];
		crossVect.pVect[2] = pVect[0] * vect2.pVect[1] + pVect[1] * vect2.pVect[0];
		return crossVect;
	}
}


//-----------------------------------------------------------------------
//----- Compare vectors -------------------------------------------------

//	[Equal To]
bool Vect::operator==(/*inout*/Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns true or false
*/
{
      if (this->getMagnitude() == vect2.getMagnitude())    // if equal
           return true;
      else
          return false;					// result = boolean of equal or not
}

//-----------------------------------------------------------------------
//	[Inequality]

bool Vect::operator!=(/*inout*/Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns true or false
*/
{
	if (this->getMagnitude() != vect2.getMagnitude())	//assign in magnitude
		return true;
	else
		return false;
}

//-----------------------------------------------------------------------
//	[Less Than]

bool Vect::operator<(/*inout*/Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns true or false
*/
{
	if (this->getMagnitude() < vect2.getMagnitude())
		return true;
	else
		return false;
}


//-----------------------------------------------------------------------
//	[Greater than]

bool Vect::operator>(/*inout*/Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns true or false
*/
{
	if (this->getMagnitude() > vect2.getMagnitude())
		return true;
	else
		return false;
}


//-----------------------------------------------------------------------
//	[Less or Equal Than]

bool Vect::operator<=(/*inout*/Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns true or false
*/
{
	if (this->getMagnitude() <= vect2.getMagnitude())
		return true;
	else
		return false;
}


//-----------------------------------------------------------------------
//	[Greater or Equal to]

bool Vect::operator>=(/*inout*/Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns true or false
*/
{
	if (this->getMagnitude() >= vect2.getMagnitude())
		return true;
	else
		return false;
}
//-----------------------------------------------------------------------



//-----------------------------------------------------------------------
//----- Print vectors ---------------------------------------

ostream& operator<<(/*inout*/ostream& output, /*in*/const Vect& vector)
/*
PRE:  << operators still used with cout and vector is an assigned vector
POST: Returns ostream output for the vector

operator assignment "<<": prints vector in <a,b,c...> format
*/
{ 
      output << '<' << vector.pVect[0]; //front bracket
     
      // Loops through remaing elements and prints them
      for(short i=1; i < vector.size; i++)
            output << ',' << vector.pVect[i]; //dimen. values
     
      output << '>'; //back bracket
     
      return output; 
}

//-----------------------------------------------------------------------