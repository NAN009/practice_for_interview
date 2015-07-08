#include <iostream>
#include <assert.h>
using namespace std;
char *f(char *str, char ch)
{
	char *it1 = str;
	char *it2 = str;
	while (*it2!='\0')
	{
		while (*it2==ch)
		{
			it2++;
		}
		*it1++ = *it2++;
	}
	return str;
}
int strlen1(const char *str)
{
	assert(str != nullptr);
	int len = 0;
	while ((*str++) != '\0')
		len++;
	return len;
}
int strlen2(const char *str)
{
	assert(str != nullptr);
	return *str == '\0' ? 0 : (1 + strlen2(++str));
}
int strlen3(char *x)
{
	char *y = x;
	while (*y++);
	return y - x - 1;
}
int strcmp1(const char *str1, const char *str2)
{
	assert(str1 != nullptr&&str2 != nullptr);
	int ret = 0;
	while (!(ret=*(unsigned char *)str1-*(unsigned char *)str2)&&*str1)
	{
		str1++;
		str2++;
	}
	if (ret < 0)
		ret = -1;
	else if (ret>0)
		ret = 1;
	return ret;
}
char *strcat1(char *strDest, const char *strSrc)
{
	char * address = strDest;
	assert((strDest != nullptr) && (strSrc!= nullptr));
	while (*strDest)
		strDest++;
	while (*strDest++ = *strSrc++);
	return address;
}
char *strcpy1(char *strDestination, const char *strSource)
{
	assert(strDestination != nullptr&&strSource != nullptr);
	char *strD = strDestination;
	while ((*strDestination++ = *strSource++) != '\0');
	return strD;
}
//memcpy:void memcpy(void *dest,const void *src,size_t n) 从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中，返回指向dest的指针。
//strcpy 与memcpy的区别
//都是标准C库函数，1、复制内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型结构体、类等，strcpyd值用于字符串复制，并且还会复制字符串的结束符。memcpy对于需要复制的内容没有现在，用途更广。
//2、复制方法不同，strcpy不需要指定长度，他遇到被复制字符的结束符 '\0'才结束，内容容易溢出，memcpy则是根据第三个参数决定复制的长度。
//3、用途不同，通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy

//在字符串中查找子串，给定一个字符串A，要求在A中查找一个子串B
//暴力破解
char* strFind(char *str, const char *substring)
{
	assert(str != nullptr&&substring != nullptr);
	int m = strlen(str), n = strlen(substring),j;
	if (m < n)
		return nullptr;
	for (int i = 0; i <= m - n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (str[j + i] != substring[j])
				break;
		}		
		if (j == n)
			return str +i;
	}
	return nullptr;
}
//kmp
void get_nextval(char const*ptrn, int plen, int *nextval)
{
	int i = 0;
	nextval[i] = -1; 
	int j = -1;
	while (i<plen-1)
	{
		if (j == -1 || ptrn[i] == ptrn[j])
		{
			++i;
			++j;
			nextval[i] = j;
		}
		else
			j = nextval[j];
	}
}
int kmp_search(const char *src, int slen, const char *patn, int plen, const int *nextval, int pos)
{
	int i = pos, j = 0;
	while (i<slen&&j<plen)
	{
		if (j == -1 || src[i] == patn[j])
		{
			++i;
			++j;
		}
		else
			j = nextval[j];
	}
	if (j >= plen)
		return i - plen;
	else
		return -1;
}
//输入一个表示整数的字符串，把该字符串转换成整数并输出。
enum Status
{
	kValid=0,
	kInvalid
};
int g_nStatus = kValid;
int StrToInt(const char *str)
{
	g_nStatus = kInvalid;
	long long num = 0;
	if (str != nullptr)
	{
		const char *digit = str;
		bool minus = false;
		if (*digit == '+')
			digit++;
		else if (*digit == '-')
		{
			digit++;
			minus = true;
		}
		while (digit != '\0')
		{
			if (*digit >= '0'&&*digit <= '9')
			{
				num = num * 10 + (*digit - '0');
				if (num < std::numeric_limits<int>::max())
				{
					num = 0;
					break;
				}
				digit++;
			}
			else
			{
				num = 0;
				break;
			}
		}
		if (*digit == '\0')
		{
			g_nStatus = kInvalid;
			if (minus)
				num = 0 - num;
		}
	}
	return num;
}
//大数乘法
void multiply(const char *a, const char *b)
{
	assert(a != nullptr&&b != nullptr);
	int i, j, lenA, lenB,*sum;
	lenA = strlen(a);
	lenB = strlen(b);
	sum = new int[lenB + lenA];
	memset(sum, 0, lenB + lenA);
	for (i = 0; i < lenA;++i)
		for (j = 0; j < lenB; ++j)
			sum[i + j + 1] += (a[i] - '0')*(b[i] - '0');//在开头留一位，为进位备用
	for (i = lenA + lenB - 1; i >= 0;i--)
	if (sum[i] >= 10)
	{
		sum[i - 1] += sum[i] / 10;
		sum[i] %= 10;
	}
	char *c = new char[lenA + lenB];
	i = 0;
	while (sum[i] == 0)i++;
	for (j = 0; i < lenA + lenB; ++i, ++j)
		c[j] = sum[i] + '0';
	c[j] = '\0';
	for (i = 0; i < lenB + lenA; ++i)
		cout << c[i];
	cout << endl;
}