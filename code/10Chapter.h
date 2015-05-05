//struct 是否可以拥有constructor/destructor及成员函数？struct和class区别？
//区别：class中变量默认是private，struct中变量默认是public。struct可以有构造函数、析构函数，之间可以继承等
//c++中struct存在的意义就是为了让c++编译器兼容以前c开发的项目
#include<iostream>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
using namespace std;
enum BREED
{
	GOLDEN,
	CAIRN,
	DANDIE,
	SHETLADN,
	DOBERMAN,
	LAB
};
struct Mannal
{
public:
	Mannal() :itsAge(2), itsWeight(5){}
	~Mannal(){}

	int GetAge()const
	{
		return itsAge;
	}
	void SetAge(int age)
	{
		itsAge = age;
	}
	int GetWeight()const
	{
		return itsWeight;
	}
	void SetWeight(int weight)
	{
		itsWeight = weight;
	}
	 
	void Speak()const
	{
		cout << "\n Mammal sound !";
	}
	void Sleep()const
	{
		cout << "\n Shhh,I'm sleeping.";
	}
private:
	int itsAge;
	int itsWeight;
};
struct Dog:public Mannal
{

public:
	Dog():itsBreed(GOLDEN){}
	~Dog(){}

	BREED GetBreed()const{ return itsBreed; }
	void SetBreed(BREED breed){ itsBreed = breed; }
	void WagTali()const { cout << " Tail wagging....\n"; }
	void BegForFood()const { cout << "Begging for food...\n"; }
private:
	BREED itsBreed;
};

struct Test
{
	Test(int){}
	Test(){}
	void fun(){}
};
class base
{
private:
	int m_i;
	int m_j;
public:
	base(int i) :m_j(i), m_i(m_j){}
	base() :m_j(0), m_i(m_j){}
	int get_i(){ return m_i; }
	int get_j(){ return m_j; }
};
//编写类String的构造函数、析构函数和赋值函数
//class String
//{
//public:
//	String(const char *str = NULL);
//	String(const String &other);
//	~String(void);
//	
//	//String &operate = (const String &other);
//private:
//	char *m_data;
//};
//String::~String(void)
//{
//	delete[] m_data;
//}
//String::String(const char *str)
//{
//	if (str == NULL)
//	{
//		m_data = new char[1];
//		*m_data = '\0';
//	}
//	else
//	{
//		int length = strlen(str);
//		m_data = new char[length + 1];
//		strcpy(m_data, str);
//	}
//}


class NamedStr
{
public:
	NamedStr()
	{
		static const char s_szName[] = "Default name";
		static const char s_szStr[] = "Default string";
		m_pName = new char[strlen(s_szName) + 1];
		m_pData = new char[strlen(s_szStr) + 1];
		strcpy(m_pName, s_szName);
		strcpy(m_pData, s_szStr);
	}
	NamedStr(const char *pName, const char *pData)
	{
		m_pName = new char[strlen(pName)+1];
		m_pData = new char[strlen(pData)+1];
		strcpy(m_pName, pName);
		strcpy(m_pData, pData);
	}
	~NamedStr()
	{
		delete[] m_pName;
		delete[] m_pData;
	}
	void Print()
	{
		cout << "Name:" << m_pName << endl;
		cout << "String:" << m_pData << endl;
	}
private:
	char *m_pName;
	char *m_pData;
};
//错误
//class Point
//{
//private:
//	float x;
//	float y;
//public:
//	Point(float a = 0.0f, float b = 0.0f) :x(a),y(b){};
//	friend float distance(Point &left, Point &right);
//};
//float distance(Point &left, Point right)
//{
//	return ((left.x - right.x)^ 2 + (left.y + right.y) ^ 2) ^ 0.5;
//}
//模板类的友元重载
template <class T>
class Test1;
template<class T>
ostream & operator <<(ostream out, const Test1<T> &obj);
template<class T>
class Test1
{
private:
	int num;
public:
	Test1(int n = 0){ num = n; }
	Test1(const Test1<T> &copy){ num = copy.num; }
	friend ostream & operator<< <>(ostream & out, const Test1<T> &obj);
};

template<class T>
ostream &operator <<(ostream & out, const Test1<T> &obj)
{
	out << obj.num;
	return out;
}

