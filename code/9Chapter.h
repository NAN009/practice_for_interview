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
//解释一下什么是泛型编程，泛型编程和c++及STL的关系是什么？
//你是怎么在c++ 环境里进行泛型编程的？
//答案：泛型编程是一种基于发现高效算法的最抽象表示的编程方法。也就是说，以算法为起点并寻找能使其工作且有效率工作的最一般必要条件集。
//很多不同的算法都需要相同的必要条件集，并且这些必要条件有多种不同的必要条件集，并且这些必要条件有多种不同实现方式。
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
