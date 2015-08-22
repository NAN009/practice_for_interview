#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
//�滻�ո񣬰��ַ����е�ÿ���ո��滻Ϊ��%20��
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
//�ϲ���������/�ַ���ʱ�������ǰ������ÿ��������Ҫ�ظ��ƶ����ʱ�����Գ��ԴӺ���ǰ���ơ�

struct ListNode1
{
	int Value;
	ListNode1* next;
};
//β�����value
void AddToTail(ListNode1 **pHead, int value)
{
	ListNode1 *pNew = new ListNode1();
	pNew->Value = value;
	pNew->next = nullptr;
	if (*pHead == nullptr)
		return;
	ListNode1 *pNode = *pHead;
	while (pNode->next)
		pNode = pNode->next;
	pNode->next = pNew;
}
//ɾ��ֵΪvalue�Ľڵ�
void RemoveNode(ListNode1 *pHead, int value)
{
	if (pHead==nullptr)
		return;
	ListNode1 *pPre = nullptr,*pCur=pHead;
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
//��β��ͷ��ӡ����
void PrintListReversingly(ListNode1 *head)
{
	stack<ListNode1*>nodes;
	if (head == nullptr)
		return;
	ListNode1 *p = head;
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
//�ݹ��  ����ջ���
void PrintListReversingly1(ListNode1 *head)
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
//�ؽ�������������ǰ�� ����������(���ظ�����)
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
//������ջʵ�ֶ���
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
//쳲���������
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
//��������1�ĸ���
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
//��ֵ�������η�
bool g_InvalidInput = false;
bool equal(double x, double y)
{
	if (x - y<0.0000001&&x - y>-0.0000001)
		return true;
	return false;
}
double PowerWithUnsignedExp(double base, unsigned int exp)
{
	double result = 1.0;
	for (int i = 1; i < exp;++i)
	{
		result *= base;
	}
	return result;
}
double PowerWithUnsignedExp1(double base, unsigned int exp)
{
	if (0 == exp)
		return 1;
	if (1 == exp)
		return 1;
	double result = PowerWithUnsignedExp1(base, exp >> 1);
	result *= result;
	if (exp & 0x1 == 1)
		result *= base;
	return result;
}

double power(double base, int exp)
{
	g_InvalidInput = true;
	if (equal(base, 0.0) && exp < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExp = (unsigned int)(exp);
	if (exp < 0)
		absExp = (unsigned int)(-exp);
	double result = PowerWithUnsignedExp(base, absExp);
	if (exp < 0)
		result = 1.0 / result;
}
//��ӡ1�����nλ��
void PrintNumber(char *number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength;++i)
	{
		if (isBeginning0&&number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			cout << number[i];
	}
	cout << endl;
}
void Print1ToMaxofNDigitsRecursively(char *number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
		
	for (int i = 0; i < 10;++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxofNDigitsRecursively(number, length, index + 1);
	}
}
void Print1ToMaxofNDigits(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10;++i)
	{
		number[0] = i + '0';
		Print1ToMaxofNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//��������е�����k���ڵ�
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr||k==0)
		return nullptr;
	ListNode* first = pListHead,*second=nullptr;
	for (int i = 1; i < k;++i)
	{
		first = first->next;
		if (!first)
			return second;
	}
	second = pListHead;
	while (first->next)
	{
		first = first->next;
		second = second->next;
	}
	return second;
}
//��ת����
ListNode* ReverseList(ListNode* pHead)
{
	if (nullptr == pHead||nullptr==pHead->next)
		return pHead;
	ListNode *pre = nullptr, *cur = pHead, *next = pHead->next;
	while (next)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
//�ϲ��������������
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	
	ListNode *p =nullptr;
	if (pHead1->val < pHead2->val)
	{
		p = pHead1;
		p->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		p = pHead2;
		p->next = Merge(pHead1, pHead2->next);
	}
	return p;
}
//��̨��:һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж���������
int jumpFloor(int number) {
	int one = 1, two = 1, sum;
	if (number <= 0)
		return 0;
	if (1 == number)
		return 1;
	if (2 == number)
		return 1;
	for (int i = 2; i < number; ++i)
	{
		sum = one + two;
		one = two;
		two = sum;
	}
	return sum;
}
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж���������

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
//����������
void Mirror(TreeNode *pRoot) 
{
	if (pRoot == nullptr)
		return;
	TreeNode *temp;
	temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	if (pRoot->left)
		Mirror(pRoot->left);
	if (pRoot->right)
		Mirror(pRoot->right);
}
//����min������ջ
stack<int>sta1,sta2;
void push(int value) {
	sta1.push(value);
	if (sta2.empty())
		sta2.push(value);
	else
	{
		if (value < sta2.top())
			sta2.push(value);
		else
			sta2.push(sta2.top());
	}
}
void pop() {
	if (sta1.empty()||sta2.empty())
		return;
	sta1.pop();
	sta2.pop();
}
int top() {
	if(!sta1.empty())
		return sta1.top();
}
int min() {
	if (!sta2.empty())
		return sta2.top();
}
//ջ��ѹ�롢��������

//�������´�ӡ������
vector<int> PrintFromTopToBottom(TreeNode *root) 
{
	vector<int >vec;
	if (nullptr == root)
		return vec;
	deque<TreeNode*> que;
	que.push_back(root);
	while (!que.empty())
	{
		int len = que.size();
		for (int i = 0; i < len; ++i)
		{
			TreeNode *p = que.front();
			vec.push_back(p->val);
			if (p->left)
				que.push_back(p->left);
			if (p->right)
				que.push_back(p->right);
			que.pop_front();
		}
	}
	return vec;
	
}
//��ά�����еĲ���
bool Find(vector<vector<int>> array, int target)
{
	if (array.empty())
		return false;
	int cols=array[0].size(),rows=array.size(),col=cols-1,row=0;
	while (col>=0&&row<rows)
	{
		if (array[row][col] == target)
			return true;
		else if (array[row][col]>target)
			col--;
		else
			row++;

	}
	return false;

}
//�滻�ո�
void replaceSpace1(char *str, int length) {
	int count_blank = 0,originLength=0;
	while (*str!='\0')
	{
		if (*str==' ')
			count_blank++;
		originLength++;
		str++;
	}
	int first = originLength - 1, second = originLength + 2 * count_blank-1;
	if (second > length)
		return;
	while (first!=second)
	{
		if (str[first] == ' ')
		{
			str[second--] = '0';
			str[second--] = '2';
			str[second--] = '%';
		}
		else
			str[second--] = str[first];
		first--;
	}
}
//��β��ͷ��ӡ����
void printListFromTail(ListNode * head,vector<int> &vec)
{
	if (head != nullptr)
	{
		if (head->next != nullptr)
			printListFromTail(head->next, vec);			
		vec.push_back(head->val);			
	}		
}
vector<int> printListFromTailToHead1(ListNode* head) {
	vector<int>vec;
	if (nullptr == head)
		return vec;
	printListFromTail(head, vec);
	return vec;
}
//��ջʵ�ֶ���
class que
{
	stack<int> stack1;
	stack<int> stack2;
public:
	void push1(int node)
	{
		stack1.push(node);
	}
	int pop1()
	{
		if (!stack2.empty())
		{
			int temp = stack2.top();
			stack2.pop();
			return temp;
		}
		else
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int temp = stack2.top();
		stack2.pop();
		return temp;
	}
};
//��ת�������С����
//�����������ĺ����������
bool VerifySquenceOfBST1(vector<int> &sequence,int start,int end)
{
	int root = sequence[end],left=0,i;
	for (i = start; i < end;++i)
	{
		if (sequence[i]>root)
			break;
	}
	left = i;
	for (int j = i; j < end; ++j)
	{
		if (sequence[j] < root)
			return false;
	}
	bool left1 = true;
	if (i > 0)
		left1 = VerifySquenceOfBST1(sequence, start, left - 1);
	bool right= true;
	if (i<end)
		right = VerifySquenceOfBST1(sequence, left, end - 1);
	return left1&&right;
}
bool VerifySquenceOfBST(vector<int> sequence) 
{
	if (sequence.empty())
		return false;
	return VerifySquenceOfBST1(sequence, 0, sequence.size() - 1);

}
//�����ӽṹ
bool isSubtree(TreeNode* head1, TreeNode* head2)
{
	if (head2 == nullptr)
		return true;
	if (head1 == nullptr)
		return false;
	if (head1->val != head2->val)
		return false; 
	return isSubtree(head1->left, head2->left) && isSubtree(head1->right, head2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2->left) || HasSubtree(pRoot1->right, pRoot2->right);
}
//��ת����˳����
string ReverseSentence(string str)
{
	if (str.empty())
		return str;
	reverse(str.begin(), str.end());
	int begin = 0;
 	for (int k = 0; k <= str.size();++k)
	{
		if (str[k] == ' ' || str[k] == '\0')
		{
			reverse(str.begin() + begin, str.begin() + k);
			begin = ++k;
		}
	}
	return str;
}
//����ת�ַ�
string LeftRotateString(string str, int n) 
{
	if (str.empty())
		return str;
	if (n > str.size())
		n = n%str.size();
	reverse(str.begin(), str.end());
	reverse(str.begin(), str.end() - n);
	reverse(str.end() - n, str.end());
	return str;
}
//��Ϊs����������
vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	vector<int> vec;
	if (array.empty())
		return vec;
	vec.push_back(0);
	vec.push_back(0);
	int first=0, second = array.size() - 1,val=INT_MAX;
	while (first < second)
	{
		if (array[first] + array[second]>sum)
			--second;
		else if (array[first] + array[second] < sum)
			first++;
		else
		{
			if (array[first] * array[second]<val)
			{
				val = array[first] * array[second];
				vec[0] = array[first];
				vec[1] = array[second];
			}
			first++;
			second--;
		}
	}
	if (vec[0] == 0 && vec[1] == 0)
		return vector<int>();
	return vec;
}
//
char FirstNotRepeatingChar(char* pString)
{
	if (pString == nullptr)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;
	char *pHashKey = pString;
	while (*pHashKey != '\0')
		hashTable[*(pHashKey++)]++;
	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';
}
//��С��k����
int partation(vector<int> &vec, int begin, int end)
{
	int i = begin - 1,j,temp=vec[end];
	for (int j = begin; j < end;++j)
	{
		if (vec[j] < temp)
		{
			++i;
			if (i != j)
				swap(vec[i], vec[j]);
		}
	}
	++i;
	swap(vec[i], vec[end]);
	return i;
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int >vec;
	if (input.empty() || k<=0 || k>input.size())
		return vec;
	int begin=0,end = input.size()-1;
	int mid = partation(input, 0, end);
	while (mid!=k-1)
	{
		if (mid > k - 1)
		{
			end = mid - 1;
			mid = partation(input, begin, end);		
		}			
		else
		{
			begin = mid + 1;
			mid = partation(input, begin, end);
		}
	}
	for (int i = 0; i < k;i++)
	{
		vec.push_back(input[i]);
	}
	return vec;
}
//��ת�������С����
int minInOrder(vector<int> rotateArray, int begin, int end)
{
	int min = rotateArray[begin];
	for (int i = begin + 1; i <= end; ++i)
	{
		if (rotateArray[i] < min)
		{
			min = rotateArray[i];
		}
	}
	return min;
}
int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.empty())
		return 0;
	int begin = 0, end = rotateArray.size() - 1;
	int mid = begin;
	while (rotateArray[begin]>=rotateArray[end])
	{
		if (end - begin == 1)
		{
			mid = end;
			break;
		}
		mid = (begin + end) / 2;
		if (rotateArray[begin] == rotateArray[end] && rotateArray[mid] == rotateArray[begin] )
		{
			return minInOrder(rotateArray, begin, end);
		}
		if (rotateArray[mid]>=rotateArray[begin])
			begin = mid;
		else if (rotateArray[mid] <= rotateArray[end])
			end = mid;		
	}
	return rotateArray[mid];
}