/**

	main.h  -- suite of functions to test functionality
               of the vect class

**/

#include <cassert>
#include <iostream>
#include <math.h>

#include "vect.h"


void test_vectIO( void );
void test_element_access( void );
void test_copy_ctor( void );
void modify_vect(Vect X);	// pass-by-value test
void test_relational_ops( void );
void test_arithmatic_ops( void );
void test_scalar_multiplication(void); 
void test_dot_product(void);		// test dot product (operator*)
void test_cross_product( void );