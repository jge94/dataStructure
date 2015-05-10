#include "stdahx.h"
#include <iostream>

using namespace std;

const short
  	MAX = 3;

 
 int main(void)
 {
 	short  
 		someArray[MAX];		// array of MAX integers
	short
		i;			// index for array  
	

   	for (i=0; i < MAX; i++)
   		someArray[i] = 10 - i;
   		
   	for (i = MAX-1; i >= 0; i--)
   		cout << someArray[i] << "  ";
   		
   	cout << endl;
   	



	// WINDOWS users
	//system("PAUSE");


	return 0;
} // main
