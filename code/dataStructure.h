//编程实现一个单链表的建立，测长，打印
#include<iostream>
#include <stdio.h>
using namespace std;
typedef struct student
{
	int data;
	struct student *next;
}node;
node *creat()
{
	node *head, *p, *s;
	int x, cycle = 1;
	head = new node();
	p = head;
	while (cycle)
	{
		cout << "please input the data:";
		cin >> x;
		if (x != 0)//尾插法
		{
			s = new node();
			s->data = x;
			cout << s->data;
			p->next = s;
			p = s;
		}
		else
			cycle = 0;
	}
	head = head->next;
	p->next = nullptr;
	cout << head->data;
	return head;
}
int length(node *head)
{
	int n = 0;
	node *p;
	p = head;
	while (p)
	{
		p = p->next;
		n++;
	}
	return n;
}
void print(node *head)
{
	node *p;
	int n;
	n = length(head);
	p = head;
	if (head)
	while (p)
	{
		cout << p->data;
		p = p->next;
	}
}
//删除单链表节点
node *del(node *head, int num)
{
	node *p, *pre;
	p = head;
	while (num!=p->data&&p->next)
	{
		pre = p;
		p = p->next;
	}
	if (num == p->data)
	{
		if (p == head)
		{
			head = p->next;
			free(p);
		}
		else
			cout << "no found!";
	}
	return head;
}
//插入
node *insert(node *head, int num)
{
	node *p0, *p1, *p2;
	p1 = head;
	p0 = new node();
	p0->data = num;
	while (p0->data>p1->data&&p1->next)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->data <= p1->data)
	{
		if (head == p1)
		{
			p0->next = p1;
			head = p0;
		}
		else
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	else
	{
		p1->next = p0;
		p0->next = nullptr;
	}
	return head;
}
//sort
node *sort(node *head)
{
	node *p, *p2, *p3;
	int n,temp;
	n = length(head);
	if (head == nullptr || head->next == nullptr)
		return head;
	p = head;
	for (int j = 1; j < n; ++j)
	{
		p = head;
		for (int i = 0; i < n - j; ++i)
		{
			if (p->data>p->next->data)
			{
				temp=p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
	return head;
}
//链表逆置
node *reverse(node *head)//书中代码........water......
{
	node *p1, *p2, *p3;
	if (head == nullptr || head->next == nullptr)
		return head;
	p1 = head, p2 = head->next;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = nullptr;
	head = p1;
	return head;
}
