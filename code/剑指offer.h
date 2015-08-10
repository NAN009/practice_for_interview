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
//用两个栈实现队列
//template<typename T>class CQueue
//{
//public:
//	CQueue(void);
//	~CQueue(void);
//	void appendTail(const T& node);
//	T deleteHead();
//private:
//	stack<T> stack1;
//	stack<T> stack2;
//
//};
//template<typename T> void CQueue<T>::appendTail(const T& node)
//{
//	stack1.push(node);
//}
//template<typename T> T CQueue::deleteHead()
//{
//	if (stack2.size() <= 0)
//	{
//		while (stack1.size()>0)
//		{
//			T& data = stack1.top();
//			stack2.push(data);
//			stack1.pop();
//		}
//	}
//	if (stack2.size() == 0)
//		throw new exception("queue is empty");
//	T head = stack2.top();
//	stack2.pop();
//	return head;
//}
//斐波那契数列
long fibonacci(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1||n==2)
		return 1;
	long first = 1, second = 1,fib=0;
	for (int i = 2; i <n; ++i)
	{
		fib = first + second;
		first = second;
		second = fib;
	}
	return fib;
}
//二进制中1的个数
int CountBinary(int x)
{
	int count = 0;
	while (x)
	{
		++count;
		x = x&(x - 1);
	}
	return count;
}