#include <iostream>

using namespace std;


int main()
{
  float x,y,z;

  do {
	cout << "Enter two integers:";
	cin >> x >> y;

	z = x / (float)y;
	cout << x << "/" << y << " is: " << z << endl;

  } while ( x >= 0 );

  cout << endl << "Done." << endl;

} // main()

/* tested on MacOS X 10.7.5, 2.5GHz Intel Core i5 [01/28/2014]

short x,y,z;
z = x / y;   // INTEGER DIVISION by ZERO
OUTPUT
Enter two integers:4 0
Floating point exception: 8
-------
short x,y,z;
z = x / (float)y;   // DIVISION by (casted) integer ZERO
OUTPUT
Enter two integers:4 0
4/0 is: 0
Enter two integers:0 0
0/0 is: 0
-------
float x,y,z;
z = x / y;	// DIVISION by float ZERO
OUTPUT
Enter two integers:4 0
4/0 is: inf
Enter two integers:0 0
0/0 is: nan
*/
