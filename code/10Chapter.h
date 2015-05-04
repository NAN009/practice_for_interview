//struct 是否可以拥有constructor/destructor及成员函数？struct和class区别？
//区别：class中变量默认是private，struct中变量默认是public。struct可以有构造函数、析构函数，之间可以继承等
//c++中struct存在的意义就是为了让c++编译器兼容以前c开发的项目
#include<iostream>
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
