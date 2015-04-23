//指针与引用
void swap11(int p, int q)
{
	int temp;
	temp = p;
	p = q;
	q = temp;
}
//void swap21(int *p, int *q)
//{
//	int *temp;
//	*temp = *p;
//	*p = *q;
//	*q = *temp;
//}
void swap3(int *p, int *q)
{
	int *temp;
	temp = p;
	p = q;
	q = temp;
}
void swap4(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void swap5(int &p, int &q)
{
	int temp;
	temp = p;
	p = q;
	q = temp;
}