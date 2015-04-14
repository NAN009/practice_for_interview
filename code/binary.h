//利用位移运算实现两个整数加法 
//不考虑进位相加：
// 1+1=0   1+0=1    与异或结果相同 1^1=0	1^0=1
// 0+1=1   0+0=0				   0^1=1	0^0=0
// 进位情况：
// 1+1=进位    1+0  不进位     进位情况和 与& 相同 可用&代替计算
// 0+1不进位   0+0  不进位
int plus2(int x, int y)		//y为是否进位	
{
	if (y == 0)return x;
	int sum, carry;
	sum = x^y;
	carry = (x&y) << 1;
	return plus2(sum, carry);
}
int plus3(int a, int b)
{
	int jw = a&b;
	int jg = a^b;
	while (jw)
	{
		int t_a = jg;
		int t_b = jw << 1;
		jw = t_a&t_b;
		jg = t_a^t_b;
	}
	return jg;
}
int plus1(int a, int b)
{
	return b ? plus1(a^b, a&b << 1) : a;
}
//用一个表达式判断x是否是2的n次方，不可用循环语句
bool is2N(int x)
{
	return !x&(x - 1);
}
