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
//有一无头节点的单链表，一个指针指向此链表中间的一个节点（非第一个节点也非最后一个节点），将给节点从链表中删除
bool deleteNode(node *pCur)//将该节点的下一个节点的值赋给该节点，然后删除该节点下一个节点
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
//快慢指针的概念及其应用
//快慢指针中的快慢指的是移动的步长，即 每次向前移动速度的快慢，例如，可以让快的指针每次沿链表向前移动2，慢指针每次向前移动1
//判断是否存在环
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
//寻找链表环入口
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
//输出链表中倒数第K个节点
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
