
#include <iostream>

using namespace std;

const short
  	MAX = 5;
    
 
 int main(void)
 {
 	short i, ar[MAX], x;		// array of MAX integers and index, i

	cout << "Begin ..." << endl;
	cout << "MEMORY address of ar[0] is: " << &ar[0] << endl;
	cout << "MEMORY address of ar[5] is: " << &ar[5] << endl;
	cout << "MEMORY address of x is:     " << &x << endl << endl;
	cout << "MEMORY address of i is:     " << &i << endl << endl;
	 
	i = 0;
   	// initialize the entire array to all negative ones (-1)
 	while (i <= MAX) 
 	{
   		ar[i] = -1;
		i++;
  	}  // while initialize array



	// print the entire array
 	while (i <= MAX) 
  	{
   		cout << "ar[" << i << "] = " << ar[i] << endl;
   		i++;
 	} // while print array
 	






 	return 0;
 	 
}  // main
