//#define �����ԷֺŽ���������Ҫ������������
#define SUB(x,y) x-y
#define ACCESS_BEFORE(element,offset,value)*SUB(&element,offset)=value
#define SECOND_PER_YEAR (365*24*60*60)unsigned long
#define MIN(x,y) ((x)<=(y)? (x):(y))

const int BUF_SIZE = 100;
//class A
//{
//public:
//	A();
//	~A(){};
//public:
//	inline const BYTE * GetBuffer() const{return m_pBuf; }//[A] [B]
//	int Pop(void);
//private:
//	const BYTE *const m_pBuf;//[C] [D] 
//};
//A::A() : m_pBuf()
//{
//	BYTE *pBuf = new BYTE[BUF_SIZE];
//	if (pBuf == NULL)
//		return;
//	for (int i = 0; i < BUF_SIZE; ++i)
//	{
//		pBuf[i] = i;
//	}
//	m_pBuf = pBuf;
//}
//int main()
//{
//	A a;
//	const BYTE *pB = a.GetBuffer();
//	if (pB != NULL)
//	{
//		for (int i = 0; i < BUF_SIZE; ++i)
//			printf("%u", pB[i++]);
//	}
//
//	system("pause");
//	return 0;
//}
class  Point
{
	int xVal, yVal;
public:
	int GetY() const;
};
int Point::GetY() const
{
	return yVal;
}

//const��#define��ʲô��ͬ��
// c++������const���峣����Ҳ������#define���峣����ǰ�߱Ⱥ����������ŵ㣺
//const �������������ͣ����곣��û���������͡����������Զ�ǰ�߽������Ͱ�ȫ��飬�Ժ���ֻ�����ַ��滻��û������
//��ȫ��飬�������ַ��滻�п��ܻ����ҽ�����������
//��Щ���ɻ��ĵ��Թ��߿��Զ�const �������е��ԣ����ǲ��ܶԺ곣�����е��ԡ�const��c++������ȡ���곣��

class A_class
{
	void f() const
	{

	}
};
//����������������Ҫ�޸���ĳ�Ա����������ô�죿
//��c++�����У�����������ݳ�Ա����mutable������Ϊconst�ĳ�Ա�������Ϳ����޸�
#include<iostream>
#include <iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
class C
{
public:
	C(int i) :m_Count(i){}
	int incr() const
	{
		return ++m_Count;
	}
	int decr() const
	{
		return --m_Count;
	}
private:
	mutable int m_Count;
};
//int main()
//{
//	C c1(0), c2(10);
//	for (int i = 0, tmp; i < 10; ++i)
//	{
//		tmp = c1.incr();
//		cout << setw(tmp) << setfill(' ') << tmp << endl;
//		tmp = c2.decr();
//		cout << setw(tmp) << setfill(' ') << tmp << endl;
//	}
//	system("pause");
//	return 0;
//}
struct  
{
	short a1;
	short a2;
	short a3;
}A;
struct B
{
	long a1;
	short a2;
};
struct C1
{
private:
	bool m_b;
	int m_c;
	bool m_d;
};
struct D
{
private:
	
	int m_c;
	bool m_b;
	bool m_d;
};
//int main()
//{
//	char *ss1 = "0123456789";
//	char ss2[] = "0123456789";
//	char ss3[100] = "0123456789";
//	int ss4[100];
//	char q1[] = "abc";
//	char q2[] = "a\n";
//	char *q3 = "a\n";
//	char *str1 = (char *)malloc(100);
//	void *str2 = (void *)malloc(100);
//	cout << sizeof(ss1) << endl;
//	cout << sizeof(ss2) << endl;
//	cout << sizeof(ss3) << endl;
//	cout << sizeof(ss4) << endl;
//	cout << sizeof(q1) << endl;
//	cout << sizeof(q2) << endl;
//	cout << sizeof(q3) << endl;
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(str1) << endl;
//	cout << sizeof(str2) << endl;
//
//}

class A1
{
public:
	int a;
	static int b;
	A1();
	~A1();
};
class A2
{
public:
	int a;
	char c;
	A2();
	~A2();
};
class A3
{
public:
	float a;
	char c;
	A3();
	~A3();
};
class A4
{
public:
	float a;
	int b;
	char c;
	A4();
	~A4();
};
class A5
{
public:
	double d;
	float a;
	int b;
	char c;
	A5();
	~A5();
};
class F
{};
class F2
{

};
class G :public F
{};
class H :public virtual G
{};
class I :public F, public F2
{};
//�������� �궨��
