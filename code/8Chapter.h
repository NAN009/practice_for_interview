//ѭ�����ݹ������
//�ݹ麯����һ������ֱ�ӵ����Լ������ͨ�������Ĺ��̻�����������ӵص����Լ��ĺ���
//�ݹ麯��mystrlen(char *buf,int N)������ʵ��ͳ���ַ����е�һ�����ַ�ǰ���ַ�����
#include <iostream>
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