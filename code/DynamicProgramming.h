#include <iostream>
#include <algorithm>
using namespace std;
//动态规划：递推的解决问题
//1、描述最优解的结果
//2、递归定义最优解的值
//3、按自底向上的方式计算最优解的值
//4、由计算出的结果构造一个最优解
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
//给定一个源串和目标串，能够进行如下操作： 1、在给定位置上插入一个字符；2、替换任意字符；3、删除任意字符。写一个程序，返回最小操作数，使得进行这些操作后源串等于目标串，源串目标串长度都小于2000
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