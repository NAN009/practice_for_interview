//判断一个整数是否为2的正整数次幂
bool is2Pow(int n)
{
	if (n > 1 && (n&(n - 1) == 0))
		return true;
	else
		return false;
}
//异或：两个相同的数异或后的结果为0，且满足交换律。用于寻找数成对出现时缺失某一个数。
void swap_no_arithm(int a, int b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}
int add_no_arithm(int a, int b)
{
	if (b == 0)
		return a;
	int sum = a^b;
	int carry = (a&b) << 1;
	return add_no_arithm(sum, carry); 
}
int average(int a, int b)
{
	return (a&b) + ((a^b) >> 1);
}