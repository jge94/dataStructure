// Lab10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "jesse.h"

using namespace std;


int main()
{
	jesse A;
	A.PRINT();
	jesse B("foo");
	B.PRINT();
	cout << endl << B.getLength() << endl;
	jesse C("fee");
	A.getsCopyOf(C);
	cout << "TEST GET COPY OF!!" << endl;
	A.PRINT();
	cout << endl;
	
	/*if (A.isEqual(B))
		cout << "A equals B!" << endl;

	if (A.isEqual(C))
		cout << "A equals C!" << endl;
	else
		cout << "A != C." << endl;*/

	if (A.isEqual(B) == 0)
		cout << "Same jesse..." << endl;
	else
		cout << "Nope. Not the same. " << endl;

	jesse D;
	D.concat("foo");
	D.PRINT();
	cout << endl;

	cout << "to upper case: " << endl;
	D.upperCase();
	D.PRINT();
	cout << endl;

	jesse E("abcedf");
	E.reverse();
	cout << "to reverse order: " << endl;
	E.PRINT();
	cout << endl;
	
	system("PAUSE");
	return 0;
}

