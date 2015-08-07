#include <iostream>
using namespace std;
//ֱ�Ӳ�������ÿ�ν�һ��������Ĺؼ��ּ�¼������ؼ��ִ�С���뵽ǰ��������������
//ʱ�临����O(n^2),�ռ临�Ӷ�O(1),�ȶ�����
void InsertSort(int A[], int n)
{
	int i, j;
	for (i = 1; i < n; ++i)
	{
		if (A[i] < A[i - 1])
		{
			int temp = A[i];
			for (j = i - 1; j>=0&&A[j]>temp;j--)
			{
				A[j + 1] = A[j];
			}
			A[j + 1] = temp;
		}
	}
}
//ð�����򣺴Ӻ���ǰ�����Ƚ�����Ԫ�ص�ֵ����Ϊ�����򽻻���
//ʱ�临�Ӷȣ�O(n^2),�ռ临�Ӷȣ�O(1),�ȶ�����
void BubbleSort(int A[], int n)
{
	int i,j;
	for (i = 0; i < n -1; ++i)
	{
		bool flag = false;
		for (j = n - 1; j>i; j--)
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
				flag = true;
			}				
		}
		if (!flag)
			return;
	}
}
//���������ڴ�������L[1...n]����ȡһ��Ԫ�أ�pivot��Ϊ��׼��ͨ��һ�����򽫴������л���Ϊ������L[1...k-1],L[k+1...n]��ʹ��ǰ���ֵ�Ԫ��С��pivot���󲿷ִ���pivot���ֱ�ݹ������֣�ÿ����ֻ��һ��Ԫ�ػ�Ϊ��ʱֹͣ
//ʱ�临�Ӷȣ�O(nlgn),�ռ临�Ӷȣ�O(lgn),���ȶ�����
int Partition(int A[], int low, int high)
{
	int pivot = A[high];
	int i = low - 1;
	for (int j = low; j < high; ++j)
	{
		if (A[j] <= pivot)
		{
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[high]);
	return i + 1;
}
int Partition1(int A[], int low, int high)
{
	int pivot = A[low];
	while (low < high)
	{
		while (low<high&&A[high]>=pivot)
			--high;
		A[low] = A[high];
		while (low < high&&A[low] <= pivot)
			++low;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
void QuickSort(int A[], int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(A, low, high);
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot + 1, high);
	}
}
//һ����������ҽ��д�д��ĸ��Сд��ĸ����дһ�������������ڵ���ĸ�������У���Сд�����д�д֮ǰ
void Partition(char a[], int low, int high)
{
	while (low<high)
	{
		while (low < high&&isupper(a[high]))
			--high;
		while (low < high&&islower(a[low]))
			++low;
		char temp = a[high];
		a[high] = a[low];
		a[low] = temp;
	}
}
//��������n��Ԫ�ص���������a,���а���0Ԫ�غͷ�0Ԫ�أ�����������1�����������0Ԫ����ǰ����0Ԫ���ں��ҷ�0Ԫ�����λ�ò��䣻2������ʹ�ö���洢�ռ�
void Partition2(int a[], int low, int high)
{
	int i = high + 1;
	for (int j = high; j >= low; --j)
	{
		if (a[j] != 0)
		{
			--i;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}