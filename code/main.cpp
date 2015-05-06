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


int main()
{
	
	A1 *pa = new A1();
	pa->f();
	B1* pb = (B1*)pa;
	pb->f();
	delete pa, pb;
	pa = new B1();
	pa ->f();
	pb = (B1*)pa;
	pb->f();
	system("pause");
	return 0;
}

