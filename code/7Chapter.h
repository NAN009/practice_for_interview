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
void Li4()
{
	int a[3];
	a[0] = 0; a[1] = 1; a[2] = 2;
	int *p, *q;
	p = a;
	q = &a[2];
	cout << a[q - p] << endl;
}