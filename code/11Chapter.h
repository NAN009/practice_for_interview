#include<iostream>
using namespace std;
class A
{
protected:
	int m_data;
public:
	A(int data = 0)
	{
		m_data = data;
	}
	int GetData()
	{
		return doGetData();
	}
	virtual int doGetData()
	{
		return m_data;
	}
};
class B :public A
{
protected:
	int m_data;
public:
	B(int data = 1)
	{
		m_data = data;
	}
	int doGetData()
	{
		return m_data;
	}
};
class C :public B
{
protected:
	int m_data;
public:
	C(int data = 2)
	{
		m_data = data; 
	}
};

class A1
{
public:
	void virtual f()
	{
		cout << "A" << endl;
	}
};
class B1 :public A1
{
public:
	void virtual f()
	{
		cout << "B" << endl;
	}
};
