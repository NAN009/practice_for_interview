#include <iostream>
#include <stack>
using namespace std;
//替换空格，把字符串中的每个空格替换为“%20”
void ReplaceBlank(char string[], int length)
{
	if (string == nullptr||length<0)
		return;
	int countBlank = 0,i=0,j,originLength=0;
	while (string[i]!='\0')
	{		
		if (string[i] == ' ')
			countBlank++;
		i++;
	}
	originLength = i;
	i = originLength - 1, j = originLength + 2 * countBlank - 1;
	if (j > length)
		return;
	while (i!=j)
	{
		if (string[i] != ' ')
			string[j--] = string[i];
		else
		{
			string[j] = '0';
			string[j - 1] = '2';
			string[j - 2] = '%';
			j = j - 3;
		}
		--i;
	}
}
//合并两个数组/字符串时，如果从前往后复制每个数组需要重复移动多次时，可以尝试从后往前复制。

struct ListNode
{
	int Value;
	ListNode* next;
};
//尾部添加value
void AddToTail(ListNode **pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->Value = value;
	pNew->next = nullptr;
	if (*pHead == nullptr)
		return;
	ListNode *pNode = *pHead;
	while (pNode->next)
		pNode = pNode->next;
	pNode->next = pNew;
}
//删除值为value的节点
void RemoveNode(ListNode *pHead, int value)
{
	if (pHead==nullptr)
		return;
	ListNode *pPre = nullptr,*pCur=pHead;
	while (pCur&&pCur->Value!=value)
	{
		pPre = pCur;
		pCur = pCur->next;
	}
	if (pCur = nullptr)
		return;
	if (pPre == nullptr)
	{
		pPre = pCur;
		pCur = pCur->next;
		delete pPre;
		return;
	}
	pPre->next = pCur->next;
	delete pCur;
}
//从尾到头打印链表
void PrintListReversingly(ListNode *head)
{
	stack<ListNode*>nodes;
	if (head == nullptr)
		return;
	ListNode *p = head;
	while (p)
	{
		nodes.push(p);
		p = p->next;
	}
	while (!nodes.empty())
	{
		cout << (nodes.top())->Value;
		nodes.pop();
	}
}
//递归版  可能栈溢出
void PrintListReversingly1(ListNode *head)
{
	if (head != nullptr)
	{
		if (head->next != nullptr)
			PrintListReversingly1(head);
		cout << head->Value;
	}
}

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};
//重建二叉树，给出前序 中序遍历结果(无重复数字)
BinaryTreeNode *ConsturctCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder)
{
	int rootValue = startPreOrder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->value = rootValue;
	root->left = root->right = nullptr;
	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder&&*startPreOrder == *startInOrder)
			return root;
		else
			throw std::exception("Invalid input!");
	}
	int *rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder&&*rootInOrder != rootValue)
		++rootInOrder;
	if (rootInOrder == endInOrder&&*rootInOrder == rootValue)
		throw std::exception("Invalid input!");
	int leftLength = rootInOrder - startInOrder;
	int *leftPreOrderEnd = startPreOrder + leftLength;
	if (leftLength > 0)
		root->left = ConsturctCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	if (leftLength < endPreOrder - startPreOrder)
		root->right = ConsturctCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	return root;
}
BinaryTreeNode *Consturct(int *preOrder, int *inOrder, int length)
{
	BinaryTreeNode *root=nullptr;
	if (preOrder == nullptr || inOrder == nullptr||length<=0)
		return root;	
}


