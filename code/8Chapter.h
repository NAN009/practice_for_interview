//ѭ�����ݹ������
//�ݹ麯����һ������ֱ�ӵ����Լ������ͨ�������Ĺ��̻�����������ӵص����Լ��ĺ���
//�ݹ麯��mystrlen(char *buf,int N)������ʵ��ͳ���ַ����е�һ�����ַ�ǰ���ַ�����
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