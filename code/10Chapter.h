//struct �Ƿ����ӵ��constructor/destructor����Ա������struct��class����
//����class�б���Ĭ����private��struct�б���Ĭ����public��struct�����й��캯��������������֮����Լ̳е�
//c++��struct���ڵ��������Ϊ����c++������������ǰc��������Ŀ
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
