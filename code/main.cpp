#include<iostream>
using namespace std;
int func(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
	}
	return count;
}
//��һ�����ʽ�ж�x�Ƿ���2��n�η���������ѭ�����
bool is2N(int x)
{
	return !x&(x - 1);
}

int f(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
}
//����λ������ʵ�����������ӷ�
int plus2(int x, int y)
{
	if (y == 0)return x;
	int sum, carry;
	sum = x^y;
	carry = (x&y) << 1;
	return plus2(sum,carry);
}
int main()
{
	cout << plus2(2,3) << endl;
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

