#include<iostream>
#include "5Chapter.h"
#include "6Chapter.h"
using namespace std;

int main()
{
	C c1(0), c2(10);
	for (int i = 0, tmp; i < 10; ++i)
	{
		tmp = c1.incr();
		cout << setw(tmp) << setfill(' ') << tmp << endl;
		tmp = c2.decr();
		cout << setw(tmp) << setfill(' ') << tmp << endl;
	}
	/*//��һ�����ʽ�ж�x�Ƿ���2��n�η���������ѭ�����
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
	//for (a = 0,x=0; a <= 1 && !x++; a++)//i++����x֮���ڼ�
	//	a++;
	//cout << a << " " << x << endl;
	//for (a = 0,x=0; a <= 1 && !x++; )
	//	a++;
	//cout << a << " " << x << endl;
	//cout << func(9999) << endl;
	system("pause");
	return 0;
}

