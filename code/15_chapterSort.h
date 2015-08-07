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
void QuickSort(int A[], int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(A, low, high);
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot + 1, high);
	}
}