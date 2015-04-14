//����λ������ʵ�����������ӷ� 
//�����ǽ�λ��ӣ�
// 1+1=0   1+0=1    ���������ͬ 1^1=0	1^0=1
// 0+1=1   0+0=0				   0^1=1	0^0=0
// ��λ�����
// 1+1=��λ    1+0  ����λ     ��λ����� ��& ��ͬ ����&�������
// 0+1����λ   0+0  ����λ
int plus2(int x, int y)		//yΪ�Ƿ��λ	
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
//��һ�����ʽ�ж�x�Ƿ���2��n�η���������ѭ�����
bool is2N(int x)
{
	return !x&(x - 1);
}
