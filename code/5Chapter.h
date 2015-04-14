int func(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
	}
	return count;
}
int f(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
}
//有两个变量a,b,不用if  ?: switch  或其他判断语句，找出两个数中较大的
int max1(int a, int b)
{
	return ((a + b) + abs(a - b)) / 2;
}
int min1(int a, int b)
{
	return (a + b - abs(a - b)) / 2;
}
int max2(int a, int b)//****
{
	int c = a - b;
	char *strs[2] = { "a Large ", "b Large " };
	c = unsigned(c) >> sizeof(int)* 8 - 1;
	return c;
}
//给三个整数a,b,c，实现取中间数，不可用sort,整数操作尽可能少
inline int max(int a, int b){ return a > b ? a : b; }
inline int min(int a, int b){ return a < b ? a : b; }
int minddle1(int a, int b, int c)
{
	int t1 = max(a, b);
	int t2 = max(b, c);
	int t3 = max(a, c);
	return min(t1, min(t2, t3));
}
//交换a,b，不用中间变量
void swap1(int a, int b)//如果a、b较大，则a+b越界
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap2(int a, int b)//异或：不同为真  故：0^任何数=任何数
{
	a = a^b;
	b = a^b;		//b=a^b=a^b^b=0^a=a
	a = a^b;		//a=a^b^a=b
}
//5.7  c和++的关系
//在c++程序中调用被c编译器编译后的函数，为什么要加extern "c"？
//c++语言支持函数重载，C语言不支持。函数被c++编译后在库中的名字与C语言的不同，假设某个函数的原型为
//void foo(int x,int y)。该函数被c编译器编译后在库中的名字为_foo，而c++编译器则产生想_foo_int_int之类的名字
//即：c++提供了c连接交换指定符号extern "c" 解决名字匹配问题

//头文件中的 ifndef/define/endif是干什么用的？
//防止该头文件被重复引用

//评价一下c与c++的各自特点。如果一个程序既需要大量运算，又要一个好的用户界面，还需要其他软件大量交流，应该怎样选择合适的语言？
//c是一种结构化语言，重点在于算法和数据结构。c程序的设计首先考虑的是如何通过一个过程，对输入进行运算处理
//得到输出（或实现过程控制）。而对于c++，首先考虑的是如何构造一个对象模型，让这个模型能够契合与之对应的
//问题域，这样就可以通过过去对象状态信息得到输出或实现过程控制
//对于大规模数值运算，c、c++和java/.net直接没有明显的性能差异，不过，如果运算涉及向量计算、矩阵计算
//可以使用Fortran或matlab编写计算组件，如com
//大规模用户界面相关软件可以考虑使用.net进行开发（window环境下），而且.net同com之间的互操作比较容易，对数据库访问比较好

//5.8
//如果switch语句后面不加break,就一次执行      
void switch1()
{
	int n = 'c';
	switch (n++)
	{
	default:std::cout << "error"; break;
	case 'a':case'A':case'b':case'B':std::cout << "ab"; break;
	case'c':case'C':std::cout << "c";
	case'd':case'D':std::cout << "d";
			
	}
	switch (n)
	{
	case '100': std::cout << n;
	}
}

//选秀节目打分，分为专家评委和大众评委，score[]数组里面存放每个评委打的分数，judge_type[]存放与score[]
//对应评委类型，judge_type==1表示专家评委，==2表示大众，n表示评委总数，打分规则：专家和大众的分数分别取
//一个平均数（取整），然后总分=专家平均分+0.6+大众*0.4，总分取整，函数返回选手得分
int cal_score(int score[], int judge_type[], int n)
{
	int judge1=0, judge2=0,judge1_count=0;
	for (int i = 0; i < n; ++i)
	{
		if (judge_type[i] == 1)
		{
			judge1 += score[i];
			judge1_count++;
		}
		else
			judge2 += score[i];
	}
	return judge1 / judge1_count*0.6 + judge2 / (n - judge1_count)*0.4;
}