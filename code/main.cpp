#include<iostream>
#include "5Chapter.h"
using namespace std;

int main()
{
	switch1();
	/*//用一个表达式判断x是否是2的n次方，不可用循环语句
	!x&(x - 1);	
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
	cout << b << endl;
	float a = 1.2f;
	cout <<a<<" "<< (int)a << endl;
	cout << (int&)a << endl;
	cout << &a <<" "<<a <<endl;
	cout << boolalpha << ((int)a == (int&)a) << endl;
	float b = 0.0f;
	cout << (int)b << endl;
	cout << &b << endl;
	cout << (int&)b << endl;
	cout << boolalpha << ((int)b == (int&)b) << endl;*/
	//int a,x;
	//for (a = 0,x=0; a <= 1 && !x++; a++)//i++先用x之后在加
	//	a++;
	//cout << a << " " << x << endl;
	//for (a = 0,x=0; a <= 1 && !x++; )
	//	a++;
	//cout << a << " " << x << endl;
	//cout << func(9999) << endl;
	system("pause");
	return 0;
}

