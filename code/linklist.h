#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace  std;
struct node
{
	int data;
	node *next;
};
//��һ��ͷ�ڵ�ĵ�����һ��ָ��ָ��������м��һ���ڵ㣨�ǵ�һ���ڵ�Ҳ�����һ���ڵ㣩�������ڵ��������ɾ��
bool deleteNode(node *pCur)//���ýڵ����һ���ڵ��ֵ�����ýڵ㣬Ȼ��ɾ���ýڵ���һ���ڵ�
{
	if (pCur == nullptr || pCur->next == nullptr)
		return false;
	node * pNext = pCur->next;
	pCur->next = pNext->next;
	pCur->data = pNext->data;
	free(pNext);
	return true;
}
node *deleteNode(node *head, int value)
{
	node *p = head, *pre = nullptr;
	while (p&&p->data!=value)
	{
		pre = p;
		p = p->next;
	}
	if (p == nullptr)
		return head;
	if (pre == nullptr)
	{
		pre = p;
		p = p->next;
		free(pre);
		return p;
	}
	pre->next = p->next;
	free(p);
	return head;
}
//����ָ��ĸ����Ӧ��
//����ָ���еĿ���ָ�����ƶ��Ĳ������� ÿ����ǰ�ƶ��ٶȵĿ��������磬�����ÿ��ָ��ÿ����������ǰ�ƶ�2����ָ��ÿ����ǰ�ƶ�1
//�ж��Ƿ���ڻ�
bool isloop(node *head)
{
	node *slow = head,*fast=head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return true;
	}
	if (fast->next == nullptr)
		return false;
}
//Ѱ���������
node * FindBeginning(node *head)
{
	node *slow = head, *fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast)
			break;
	}
	if (fast->next == nullptr)
		return nullptr;
	slow = head;
	while (slow!=fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//��������е�����K���ڵ�
node *findKthtoTaol(node *head, int k)
{
	assert(head&&k >= 1);
	node *first = head, *second = head;
	for (int i = 0; i < k - 1; ++i)
	{
		first = first->next;
		if (first == nullptr)
			return nullptr;
	}
	while (first->next)
	{
		first = first->next;
		second = second->next;
	}
	return second;
}
