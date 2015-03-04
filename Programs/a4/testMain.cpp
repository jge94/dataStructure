#include "stdafx.h"
#include "testMain.h"
#include "vect.h"
#include <cassert>
#include <iostream>

/*********************************************************************
*	a4 - Vector class test suite
*/
//====================================================================
// SUMMARY:
//		This program is a test suites on its functionbility of vector 
//	calculations, and message are printed out
//--------------------------------------------------------------------
// Programmer: 
//		Jinnan Ge
//
// Dates Modified:
//		04/08/2014 started
//		04/09/2014 finished CTORs
//		04/10/2014	with all functions written out,
//					question about workingload (pointer is harder than expected)
//		04/11/2014  all functions finished
//--------------------------------------------------------------------
// INPUT: 
//		Nothing
// OUTPUT:
//		i) whether the element access, copy CTOR, relational ops,
//	arithmetic ops, scalar multiplication, dot product, cross product
//  are working fine;
//		ii) general message about condition of test suites
//		iii) a real world example of vector using
//--------------------------------------------------------------------
//	  [SAMPLE OUTPUT]
//		element access OK
//		copy CTOR OK
//		relational ops OK
//		arithmetic ops OK 
//		scalar multiplication OK 
//		dot product OK 
//		cross product OK
//		VECTOR CLASS PASSES ALL TESTS.
//
//		*** Real Vector Problem ***
//
//		There are two forces, M and N, both in directions.
//		 M is: (-1,-2,-3)
//	     N is: (1,2,3)
//		 So the combined force here is: (L = M + N) (0,0,0)
//====================================================================


bool DOUBLE_EQUAL ( double a, double b );
#define CLOSE_ENOUGH	0.01


int main (void) {
	
    // review the test_vectIO() code; this test assumes you
    // have the parameterized CTOR and operator[] working;
    test_vectIO();
	
	// ALL of these tests `assert' their expected values. Therefore, if
	// flow control gets to the output at the end of main(), all tests
	// have passed.
	
	test_element_access();			// test element access (operator[])
	test_copy_ctor();				// test copy constructor (try to change values in sub-func)
	test_relational_ops();			// test relational ops (<,>,<=,>=,==,!=)
	test_arithmatic_ops();			// test arithmatic ops (+,-)
	test_scalar_multiplication();	// test scalar multiplication (operator*)
	test_dot_product();				// test dot product (operator*)
	test_cross_product();			// test cross product (operator%)
	
	cout << "VECTOR CLASS PASSES ALL TESTS.\n";

	// A real world problem on vector
	cout << "\n\n*** Real Vector Problem ***\n" << endl;

	Vect M, N, L;		// assign all values in
	M[0] = -1;
	M[1] = -2;
	M[2] = -3;
	
	N[0] = 1;
	N[1] = 2;
	N[2] = 3;
	
	L = M + N;

	cout << "There are two forces, M and N, both in directions.\n";
	cout << "M is: " << M << endl;
	cout << "N is: " << N << endl;
	cout << "So the combined force here is: (L = M + N) " << L << endl;

	system("PAUSE");
	return 0;
}

void test_vectIO ( void ) {

    // This test doesn't actually assert anything, since the heuristic for
	// determining if IO has worked or not is by looking at the output on
	// the screen...
    {
		Vect A(3);
		A[0]	= 1;
		A[1]	= 2;
		A[2]	= 3;
		// now test operator<<()
		cout << endl << A << endl;
    }
	
}

void test_element_access ( void ) {
	// Set elements, and then try to retrieve them again (simple!).
	
	Vect A(4);
	A[0]	= 2;
	A[1]	= 6;
	A[2]	= 0;
	A[3]	= 0;
	
	assert( A[0] == 2 );	//check kids' = directed values
	assert( A[1] == 6 );
	assert( A[2] == 0 );
	assert( A[3] == 0 );
	cout << "element access OK\n";
}


void test_copy_ctor ( void ) {
	// Create a vector. Pass that vector to a function which will change element
	// values. Copy constructor should give that function it's own copy of the
	// vector. If original element values remain intact after function invocation,
	// copy ctor works.
	
	Vect A(3);
	A[0]	= 10;
	A[1]	= 20;
	A[2]	= 40;
	
	modify_vect( A );
	
    // but is A still the same once we return from the function?
	assert( A[0] == 10 );
	assert( A[1] == 20 );
	assert( A[2] == 40 );
	cout << "copy constructor OK\n";
}


void modify_vect (Vect X) {
	// X is a local Vect, but whose memory is being changed?
	X[0] = 97;  X[1] = 98;  X[2] = 99;
	// oh no, scope of X is done; call DTOR for X!!!
}

void test_relational_ops ( void ) {
	// this test defines 3 vectors, and attempts to query the expected results of
	// all relations between them.
	
	Vect A (3);
	A[0]	= 1;
	A[1]	= 2;
	A[2]	= 0;	// length now == sqrt(5)
	
	Vect B (3);
	B[0]	= 1;
	B[1]	= 1;
	B[2]	= 1;	// length now == sqrt(3)
	
	Vect C (3);
	C[0]	= 1;
	C[1]	= 1;
	C[2]	= 1;	// length now == sqrt(3)
	
	Vect D (3);
	D[0]	= 0;
	D[1]	= 2;
	D[2]	= 1;	// length now == sqrt(5)
	
	assert( B < A );
	assert( !( B > A ) );
	
	assert( B <= A );
	assert( !( B >= A ) );
	
	assert( !( B < C ) );
	assert( !( C < B ) );
	assert( B <= C );
	assert( C <= B );
	
	assert( A == D );
	assert( B == C );
	
	assert( !( A == B ) );
	assert( !( C == D ) );
	assert( A != B );
	assert( C != D );
	
	cout << "relational ops OK\n";
}

void test_arithmatic_ops ( void ) {
	// Very simple element-wise test of addition and subtraction.
	
	Vect A (3);
	A[0]	= 1;
	A[1]	= 2;
	A[2]	= 0;	// length now == sqrt(5)
	
	Vect B (3);
	B[0]	= 1;
	B[1]	= 1;
	B[2] = 1;	// length now == sqrt(3)

	{
		Vect C(3);
		C = A + B;

		assert(C[0] == 2);
		assert(C[1] == 3);
		assert(C[2] == 1);
	}

	{
		Vect C(3);
		C = A - B;

		assert(C[0] == 0);
		assert(C[1] == 1);
		assert(C[2] == -1);
	}
	
	
 

	  //4/1/2014 -- adding integer to a Vect not currently defined; don't test
	/*{
		Vect C (3);
		C		= A + 2;
		
		assert( C[0] == 3 );
		assert( C[1] == 4 );
		assert( C[2] == 2 );
	}
	
	{
		Vect C (3);
		C		= A - 2;
		
		assert( C[0] == -1 );
		assert( C[1] == 0 );
		assert( C[2] == -2 );
	}*/
	cout << "arithmatic ops OK\n";
}

void test_scalar_multiplication(void)
{
	// test whether scalar multiplication works for not
	Vect D(3);
	D[0] = 1;
	D[1] = 2;
	D[2] = 3;	// length now == sqrt(5)

	Vect E;
	E = D * 2;

	assert(E[0] == 2);
	assert(E[1] == 4);
	assert(E[2] == 6);
	
	cout << "scalar multiplication OK\n";
}

void test_dot_product ( void ) {
	// Test basic properties of the dot product:
	// * dot product of a vector by itself is the length of that vector
	// * dot product of orthogonal vectors is zero
	
	Vect A (3);
	A[0]	= 1;
	A[1]	= 0;
	A[2]	= 0;
	
	Vect B (3);
	B[0]	= 0;
	B[1]	= 1;
	B[2]	= 0;	// A and B are now orthogonal
	
	{
		double c	= A * A;
		assert( DOUBLE_EQUAL(c, 1.0) );
	}

	{
		double c	= A * B;
		assert( DOUBLE_EQUAL(c, 0.0) );
	}
	
	cout << "dot product OK\n";
}

void test_cross_product ( void ) {
	// Test basic property of the cross product:
	// * cross product of two orthogonal vectors is a third orthogonal vector
	// In this case, the basis vectors of three-space are used.
	
	Vect A (3);
	A[0]	= 1;
	A[1]	= 0;
	A[2]	= 0;
	
	Vect B (3);
	B[0]	= 0;
	B[1]	= 1;
	B[2]	= 0;	// A and B are now orthogonal
	
	Vect C	= A ^ B;
	assert( C[0] == 0 );
	assert( C[1] == 0 );
	assert( C[2] == 1 );

	cout << "cross product OK\n";
}


// PRE	: none
// POST	: <retval> == true || <retval> == false
// PARAMETERS:
//	a	IN
//	b	IN
bool DOUBLE_EQUAL(double a, double b) 
{
	double c = a - b;						// difference between a and b
	if (c < 0)
		c = -1.0 * c;							// absolute value
	return (c < CLOSE_ENOUGH);					// close enough to zero?
}




