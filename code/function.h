#include<iostream>
using namespace std;
void f(int r, int &s)
{
	int x;
	x = 2 * r + 1;
	s = s*r;
	r = s - x;
	return;
}
int t(int x)
{
	int a;
	a = 3 * x - 1;
	f(x, a);
	return a + x;
}