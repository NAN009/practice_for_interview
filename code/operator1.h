//�ж�һ�������Ƿ�Ϊ2������������
bool is2Pow(int n)
{
	if (n > 1 && (n&(n - 1) == 0))
		return true;
	else
		return false;
}
//���������ͬ��������Ľ��Ϊ0�������㽻���ɡ�����Ѱ�����ɶԳ���ʱȱʧĳһ������
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