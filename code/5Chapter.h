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
//����������a,b,����if  ?: switch  �������ж���䣬�ҳ��������нϴ��
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
//����������a,b,c��ʵ��ȡ�м�����������sort,����������������
inline int max(int a, int b){ return a > b ? a : b; }
inline int min(int a, int b){ return a < b ? a : b; }
int minddle1(int a, int b, int c)
{
	int t1 = max(a, b);
	int t2 = max(b, c);
	int t3 = max(a, c);
	return min(t1, min(t2, t3));
}
//����a,b�������м����
void swap1(int a, int b)//���a��b�ϴ���a+bԽ��
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap2(int a, int b)//��򣺲�ͬΪ��  �ʣ�0^�κ���=�κ���
{
	a = a^b;
	b = a^b;		//b=a^b=a^b^b=0^a=a
	a = a^b;		//a=a^b^a=b
}
//5.7  c��++�Ĺ�ϵ
//��c++�����е��ñ�c�����������ĺ�����ΪʲôҪ��extern "c"��
//c++����֧�ֺ������أ�C���Բ�֧�֡�������c++������ڿ��е�������C���ԵĲ�ͬ������ĳ��������ԭ��Ϊ
//void foo(int x,int y)���ú�����c������������ڿ��е�����Ϊ_foo����c++�������������_foo_int_int֮�������
//����c++�ṩ��c���ӽ���ָ������extern "c" �������ƥ������

//ͷ�ļ��е� ifndef/define/endif�Ǹ�ʲô�õģ�
//��ֹ��ͷ�ļ����ظ�����

//����һ��c��c++�ĸ����ص㡣���һ���������Ҫ�������㣬��Ҫһ���õ��û����棬����Ҫ�����������������Ӧ������ѡ����ʵ����ԣ�
//c��һ�ֽṹ�����ԣ��ص������㷨�����ݽṹ��c�����������ȿ��ǵ������ͨ��һ�����̣�������������㴦��
//�õ��������ʵ�ֹ��̿��ƣ���������c++�����ȿ��ǵ�����ι���һ������ģ�ͣ������ģ���ܹ�������֮��Ӧ��
//�����������Ϳ���ͨ����ȥ����״̬��Ϣ�õ������ʵ�ֹ��̿���
//���ڴ��ģ��ֵ���㣬c��c++��java/.netֱ��û�����Ե����ܲ��죬��������������漰�������㡢�������
//����ʹ��Fortran��matlab��д�����������com
//���ģ�û��������������Կ���ʹ��.net���п�����window�����£�������.netͬcom֮��Ļ������Ƚ����ף������ݿ���ʱȽϺ�

//5.8
//���switch�����治��break,��һ��ִ��      
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

//ѡ���Ŀ��֣���Ϊר����ί�ʹ�����ί��score[]����������ÿ����ί��ķ�����judge_type[]�����score[]
//��Ӧ��ί���ͣ�judge_type==1��ʾר����ί��==2��ʾ���ڣ�n��ʾ��ί��������ֹ���ר�Һʹ��ڵķ����ֱ�ȡ
//һ��ƽ������ȡ������Ȼ���ܷ�=ר��ƽ����+0.6+����*0.4���ܷ�ȡ������������ѡ�ֵ÷�
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