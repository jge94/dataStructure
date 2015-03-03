
// 1_whereIs.cpp

// sample code to learn how the compiler allocates memory on the
// runtime stack ... and on the Heap
#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	double a=1, b=2, c=3;
	double d[4] = {100,101,102,103};
	double e=18, f=19;
	double g[4] = {200,201,202,203};
	short h=22, i=23;
    short* p = new short[3];
    p[0] = 34;  p[1] = 40;  p[2] = 36;

	cout << "       ADDRESS           VALUE" << endl << endl;
	cout << "    a = " << (unsigned long) &a    << "     " << a << endl;
	cout << "    b = " << (unsigned long) &b    << "     " << b << endl;
	cout << "    c = " << (unsigned long) &c    << "     " << c << endl;
	
	cout << " d[0] = " << (unsigned long) &d[0]    << "     " << d[0] << endl;
	cout << " d[1] = " << (unsigned long) &d[1]	   << "     " << d[1] << endl;
	cout << " d[2] = " << (unsigned long) &d[2]	   << "     " << d[2] << endl;
	cout << " d[3] = " << (unsigned long) &d[3]    << "     " << d[3] << endl;
	cout << " d[4] = " << (unsigned long) &d[4]    << "     " << d[4] << endl;

	cout << "    e = " << (unsigned long) &e    << "     " << e << endl;
	cout << "    f = " << (unsigned long) &f    << "     " << f << endl;
	
	cout << " g[0] = " << (unsigned long) &g[0]    << "     " << g[0] << endl;
	cout << " g[1] = " << (unsigned long)&g[1] << "     " << g[1] << endl;
	cout << " g[2] = " << (unsigned long)&g[2] << "     " << g[2] << endl;
	cout << " g[3] = " << (unsigned long) &g[3]    << "     " << g[3] << endl;
	cout << " g[4] = " << (unsigned long) &g[4]    << "     " << g[4] << endl;
	
	cout << "    h = " << (unsigned long) &h    << "     " << h << endl;
	cout << "    i = " << (unsigned long) &i    << "     " << i << endl;
    
    cout << "    p = "    <<  (unsigned long) &p        << "       " << (unsigned long)p  << endl;
    cout << "    p[0] = " <<  (unsigned long)&p[0]      << "       " << p[0]  << endl;
	cout << "    p[1] = " <<  (unsigned long)&p[1]      << "       " << p[1]  << endl;
	cout << "    p[2] = " <<  (unsigned long)&p[2]      << "       " << p[2]  << endl;

	cout << endl << "TEST!!!!!" << endl;
	cout << "p is: " << p << endl;
	cout << "p[0] is: " << p[0] << endl;
	cout << "*p is: " << *p << endl;
	//cout << "*p[0] is: " << *p[0] << endl;	!!!!WRONG
	cout << "(*p)+2 is: " << (*p)+2 << endl;
	cout << "*(p+2) is: " << *(p + 2) << endl;
	//cout << "(*p)++ is: " << (*p)++ << endl;
	cout << endl;
	cout << "*p is: " << *p << endl;
	p++;
	cout << "*p is: " << *p << endl;
	cout << "p is: " <<( unsigned long) p << endl;

	
	cout << endl << "Done." << endl;
	system("PAUSE");
	return 1;
}

	