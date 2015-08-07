#include <iostream>
using namespace std;
//直接插入排序：每次将一个待排序的关键字记录，按其关键字大小插入到前面已排子序列中
//时间复杂性O(n^2),空间复杂度O(1),稳定排序
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
//冒泡排序：从后往前两两比较相邻元素的值，若为逆序，则交换。
//时间复杂度：O(n^2),空间复杂度：O(1),稳定排序
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
//快速排序：在待排序列L[1...n]中任取一个元素，pivot作为基准，通过一趟排序将待排序列划分为两部分L[1...k-1],L[k+1...n]，使得前部分的元素小于pivot，后部分大于pivot，分别递归两部分，每部分只有一个元素或为空时停止
//时间复杂度：O(nlgn),空间复杂度：O(lgn),不稳定排序
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