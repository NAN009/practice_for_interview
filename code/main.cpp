#include<iostream>
#include <stdio.h>
#include <string.h>
//#include "5Chapter.h"
//#include "6Chapter.h"
//#include "7Chapter.h"
//#include "8Chapter.h"
//#include "9Chapter.h"
//#include "10Chapter.h"
#include "operator1.h"
#include "11Chapter.h"
#include "Cstrings.h"
#include "preprocessing.h"
#include "function.h "
#include "15_chapterSort.h"
#include "��ָoffer.h"
using namespace std;
#define NORM2(x,y) ((x)*(x)+(y)*(y))

int main(void)
{
	char matrix[3][3] = { { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' } };
	int a[] = {8,0,0,9,1,0,7,2,0};
	char c[30] = "we  are happy";

	ReplaceBlank(c, 30);
	for (int i = 0; i < 30; ++i)
		cout << c[i];
	system("pause");
	return 0;
}

