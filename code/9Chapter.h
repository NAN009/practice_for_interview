#include <vector>
#include <iostream>
using namespace std;
class Chapter9
{
public:

	void vectorExample();
	void print(vector<int > v);
	


};
void Chapter9::vectorExample()
{
	vector<int> vec;
	vec.push_back(34);
	vec.push_back(23);
	print(vec);
	vector<int>::iterator p;
	p = vec.begin();
	*p = 69;
	*(p + 1) = 70;
	print(vec);
	vec.pop_back();
	print(vec);
	vec.push_back(101);
	vec.push_back(102);
	int i = 0;
	while (i < vec.size())
		cout << vec[i++]<<" ";
	cout << endl;
	print(vec);
	
}
void Chapter9::print(vector<int > v)
{
	cout << v.size() << endl;
	vector<int>::iterator p = v.begin();
}

class CDemo
{
public:
	CDemo() :str(NULL){};
	~CDemo()
	{
		if (str)
			delete[] str;
	};
	char *str;
};
//����һ��ʲô�Ƿ��ͱ�̣����ͱ�̺�c++��STL�Ĺ�ϵ��ʲô��
//������ô��c++ ��������з��ͱ�̵ģ�
//�𰸣����ͱ����һ�ֻ��ڷ��ָ�Ч�㷨��������ʾ�ı�̷�����Ҳ����˵�����㷨Ϊ��㲢Ѱ����ʹ�乤������Ч�ʹ�������һ���Ҫ��������
//�ܶ಻ͬ���㷨����Ҫ��ͬ�ı�Ҫ��������������Щ��Ҫ�����ж��ֲ�ͬ�ı�Ҫ��������������Щ��Ҫ�����ж��ֲ�ͬʵ�ַ�ʽ��
const int *find1(const int * array, int n, int x)
{
	const int * p = array;
	for (int i = 0; i < n; ++i)
	{
		if (*p == x)
			return p;
		++p;
	}
	return 0;
}
template<typename T>
const T* My_find(T* array, T n, T x)
{
	const T *p = array;
	for (int i = 0; i < n; ++i)
	{
		if (*p == x)
			return p;
		++p;
	}
	return 0;
}

int jug(int x, int y)
{
	if (x >= 0)
		return x;
	else if (y == 0)
		return x;
	else
		return x / y;
}
int sub(int x, int y)
{
	return x + y;
}
int minu(int x, int y)
{
	return x - y;
}
void test(int(*p)(int, int), int a, int b)
{
	int Intl;
	Intl = (*p)(a, b);
	cout << a << " " << b << " " << Intl << endl;
}
void test_test()
{
	int a = 1, b = 2, c = 3, d = 4, e = -5;
	test(sub, a, b);
	test(minu,c,d);
	test(jug, e, b);
}

template<class T>
class Operate
{
public:
	static T Add(T a, T b)
	{
		return a + b;
	}
	static T Tmul(T a, T b)
	{
		return a - b;
	}
	static T Jud(T a, T b)
	{
		if (a >= 0)
			return a;
		else 
			return a / b;
	}
};
bool used[10];
vector<long long>v;
void dfs_cp9(int k,long long a)
{
	if (k&&a%k != 0)
		return;
	if (k == 9)
	{
		v.push_back(a);
		return ;
	}
	for (int i = 1; i <= 9;++i)
	if (!used[i])
	{
		used[i] = 1;
		dfs_cp9(k + 1, a * 10 + 1);
		used[i] = 0;
	}
}
