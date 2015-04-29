//循环、递归与概率
//递归函数：一个函数直接调用自己本身或通过其他的过程或函数调用语句间接地调用自己的函数
//递归函数mystrlen(char *buf,int N)是用来实现统计字符串中第一个空字符前面字符长度
#include <iostream>
#include <windows.h>
using namespace  std;
int myStrlen(char *buf, int N)
{
	if (buf[0] == 0 || N == 0)
		return 0;
	else if (N == 1)
		return 1;
	int t = myStrlen(buf, N / 2);
	if (t < N / 2)
		return t;
	else
		return (t + myStrlen(buf + N / 2, (N + 1) / 2));
}

int f_recursion(int m, int n)
{
	if (1 == m)
		return n;
	if (1 == n)
		return m;
	return f_recursion(m - 1, n) + f_recursion(m, n - 1);
}
int f1(int m, int n)
{
	int a[5][5];
	for (int i = 0; i != m; ++i)
		a[i][0] = i + 1;
	for (int i = 0; i != n; ++i)
		a[0][n] = i + 1;
	for (int i = 1; i != m;++i)
		for (int j = 1; j != n; ++j)
			a[i][j] = a[i - 1][j] + a[i][j - 1];
	return a[m - 1][n - 1];
}

class Program
{
public:
	static int x(int n)
	{
		if (n <= 3)
			return 1;
		else
			return x(n - 2) + x(n - 4) + 1;
	}

};

//统计每个ASCII字符出现的次数
void histogram(char* src)
{
	int i;
	char hist[256];//memset()
	for (i = 0; i < 256; ++i)
		hist[i] = 0;
	while (*src != '\0')
	{
		hist[*src++]++;
	}
	for (i = 0; i < 256; ++i)
		cout << hist[i];
}

//设计一个定时器程序，当输入一个时间，就按照输入值停留多久
void timer1(double x)
{
	double cnt = 0;
	cnt = x * 1000;
	Sleep(cnt);
}
#define max(a,b) ((a)<(b)?(b):(a))
#define abs(a) ((a)>0?(a):-(a))
int foo(int x, int y)
{
	int t = max(abs(x), abs(y));
	int u = t + t;
	int v = u - 1;
	v = v*v + u;
	if (x == -t)
		v += u + t - y;
	else if (y == -t)
		v += 3 * u + x - t;
	else if (y == t)
		v += t - x;
	else
		v += y - t;
	return v;
}
#define  LOOP 1000
void main1()
{
	int rgnC = 0;
	for (int i = 0; i < LOOP; ++i)
	{
		int x = rand();
		int y = rand();
		if (x*x + y*y < RAND_MAX*RAND_MAX)
			rgnC++;
	}
	cout << rgnC;
}