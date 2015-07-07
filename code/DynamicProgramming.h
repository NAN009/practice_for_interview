#include <iostream>
#include <algorithm>
using namespace std;
//��̬�滮�����ƵĽ������
//1���������Ž�Ľ��
//2���ݹ鶨�����Ž��ֵ
//3�����Ե����ϵķ�ʽ�������Ž��ֵ
//4���ɼ�����Ľ������һ�����Ž�
//longest common subsequence
int c[100][100];
int LCS_length(const char *x, const char *y)
{
	if (x == nullptr || y == nullptr)
		return 0;
	int lenX = strlen(x), lenY = strlen(y);
	for (int i = 0; i < lenX; ++i)
		c[i][0] = 0;
	for (int i = 0; i < lenY; ++i)
		c[0][i] = 0;
	for (int i = 1; i < lenX; ++i)
	{
		for (int j = 1; j < lenY; ++j)
		{
			if (x[i] == y[j])
				c[i][i] = c[i - 1][j - 1] + 1;
			else
			{
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	return c[lenX][lenY];
}
#define INF 999999
int LCS_Memo(string x, string y, int i, int j)
{
	if (c[i][j] < INF)
		return c[i][j];
	if (i == 0 || j == 0)
		c[i][j] = 0;
	else if (x[i - 1] == y[j - 1])
		c[i][j] = c[i - 1][j - 1] + 1;
	else
	{
		int p = LCS_Memo(x, y, i - 1, j);
		int q = LCS_Memo(x, y, i, j - 1);
		if (p >= q)
			c[i][j] = p;
		else
			c[i][j] = q;
	}
	return c[i][j];		
}
int LCS_length1(string x, string y)
{
	memset(c, INF, sizeof(c));
	return LCS_Memo(x, y, x.size(), y.size());
}
//����һ��Դ����Ŀ�괮���ܹ��������²����� 1���ڸ���λ���ϲ���һ���ַ���2���滻�����ַ���3��ɾ�������ַ���дһ�����򣬷�����С��������ʹ�ý�����Щ������Դ������Ŀ�괮��Դ��Ŀ�괮���ȶ�С��2000
int calculateStringDistance(string strA, int pABegin, int pAEnd, string strB, int pBBegin, int pBEnd)
{
	if (pABegin > pAEnd)
	if (pBBegin > pBEnd)
		return 0;
	else
		return pBEnd - pBBegin + 1;
	if (pBBegin > pBEnd)
	if (pABegin > pAEnd)
		return 0;
	else
		return pAEnd - pABegin + 1;
	if (strA[pABegin] == strB[pBBegin])
	{
		return calculateStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin + 1, pBEnd);
	}
	else
	{
		int t1 = calculateStringDistance(strA, pABegin, pAEnd, strB, pBBegin+1, pBEnd);
		int t2 = calculateStringDistance(strA, pABegin+1, pAEnd, strB, pBBegin, pBEnd);
		int t3 = calculateStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin + 1, pBEnd);
		return min(t2,min(t1,t3)) + 1;
	}
		

}