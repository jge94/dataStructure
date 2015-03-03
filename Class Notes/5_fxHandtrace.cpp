#include <iostream>

using namespace std;

void tallyUp(short, short, short&);		// function (prototype) declaration

int main(void)
{                                           //    assume this INPUT
	short sum = 0;							// |  3  5
	short x,y;								// |  7  -2
                                            // |  <ctrl-d>EOF
    
	cout << "Enter two ints (ctrl-D for EOF) >> ";
	cin >> x >> y;
	
	while (cin)		// WHILE NOT EOF
	{
		cout << "BEFORE CALL:  x = " << x << "  y = " << y
        << "  sum = " << sum << endl;
        
        tallyUp(x,y,sum);
		
		cout << "AFTER  CALL:  x = " << x << "  y = " << y
        << "  sum = " << sum << endl;
        
		cout << "Enter two ints (ctrl-D for EOF) >> ";
		cin >> x >> y;
	} // not EOF
	
	cout << endl << "AT END: Sum = " << sum << endl;
	
	return 1;
} // main

//--------------------------------------
void tallyUp(short a, short b, short& c)
{
	a++;
	b++;
	c = a + b + c;
}


/* sample OUTPUT
 Enter two ints (ctrl-D for EOF) >> 3 5
 BEFORE CALL:  x = 3  y = 5  sum = 0
 AFTER  CALL:  x = 3  y = 5  sum = 10
 
 Enter two ints (ctrl-D for EOF) >> 7 -2
 BEFORE CALL:  x = 7  y = -2  sum = 10
 AFTER  CALL:  x = 7  y = -2  sum = 17
 
 Enter two ints (ctrl-D for EOF) >>
 
 AT END: Sum = 17
*/
