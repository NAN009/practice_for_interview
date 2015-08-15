#include<iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
//#include "5Chapter.h"
//#include "6Chapter.h"
//#include "7Chapter.h"
//#include "8Chapter.h"
//#include "9Chapter.h"
//#include "10Chapter.h"
#include "operator1.h"
#include "11Chapter.h"
#include "Cstrings.h"
#include "preprocessing.h"
#include "function.h "
#include "15_chapterSort.h"
#include "½£Ö¸offer.h"
#include "graph.h"
using namespace std;
#define NORM2(x,y) ((x)*(x)+(y)*(y))

int main(void)
{
	char matrix[3][3] = { { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' } };
	int a[] = {8,0,0,9,1,0,7,2,0};
	char c[30] = "we  are happy";

	vector<int> vec = {7,0,5};
	ListNode *head = new ListNode(6),*temp=head;
	for (int i = 0; i < vec.size(); ++i)
	{
		temp->next = new struct ListNode(vec[i]);
		temp = temp->next;
	}

	que qu;
	qu.push1(1);
	qu.push1(2);
	qu.push1(3);
	qu.pop1();
	qu.pop1();
	qu.push1(4);
	qu.pop1();
	qu.push1(5);
	qu.pop1();
	qu.pop1();
	system("pause");
	return 0;
}

