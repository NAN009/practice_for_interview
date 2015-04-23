//循环、递归与概率
//递归函数：一个函数直接调用自己本身或通过其他的过程或函数调用语句间接地调用自己的函数
//递归函数mystrlen(char *buf,int N)是用来实现统计字符串中第一个空字符前面字符长度
int myStrlen(char *buf, int N)
{
	if (buf[0] == 0 || N == 0)
		return 0;
	else if (N == 1)
		return 1;
	int t = myStrlen(buf, N / 2);
	if (t < N / 2)
		return t;
	else
		return (t + myStrlen(buf + N / 2, (N + 1) / 2));
}