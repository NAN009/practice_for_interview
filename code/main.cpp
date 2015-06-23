#include<iostream>
#include <stdio.h>
#include <string.h>
//#include "5Chapter.h"
//#include "6Chapter.h"
//#include "7Chapter.h"
//#include "8Chapter.h"
//#include "9Chapter.h"
//#include "10Chapter.h"
#include "11Chapter.h"
using namespace std;
#define NORM2(x,y) ((x)*(x)+(y)*(y))

int main()
{
	double a, b = 0.0000000001;
	a = sqrt(b);
	cout << a << " " << sizeof(a) << endl << b << " " << sizeof(b) << endl;
	
	system("pause");
	return 0;
}

