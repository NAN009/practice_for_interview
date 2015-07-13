#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
//tree ����һ�������ֽ�����Ϊ�ýڵ�Ķ�
//tree�����ʣ�
//1�����еĽ�����������н��Ķ���+1  n0+n1+n2+n3+n4=n1+2*n2+3n3+4n4+1   ������Ҷ�ӽڵ�
//2����Ϊm�����е�i��������m^(i-1)�����
//3���߶�Ϊh��m����������(m^h-1)/(m-1)�����
//4������n�����Ĳ�������С�߶�Ϊ:����ȡ����logm�ģ�n(m-1)+1))

//���������Ϊ2����������
//��Ϊ2����������3����㣬������������Ϊ��
//��Ϊ2���ĺ��ӽڵ�������ģ��������������

//��ȫ�������ص㣺
//1����i<=n/2,��ڵ�iΪ��֧�ڵ㣬����ΪҶ�ӽڵ�
//2��Ҷ�ӽڵ�ֻ���ܳ����ڲ���������㡣����������е�Ҷ�ӽڵ㣬�����������ڸò������λ����
//3������ж�Ϊ1 �Ľ��,ֻ������һ�����Ҹýڵ�ֻ������
//4���������ź�һ������ĳ�ڵ�iΪҶ�ӽڵ��ֻ�����ӣ����Ŵ���i�Ľڵ��ΪҶ�ӽڵ�
//5����nΪ��������ÿ����֧�ڵ㶼�����Ӻ��Һ��ӣ���Ϊż����������ŵķ�֧�ڵ�ֻ�����ӡ�
//��Ϊ1�Ľڵ�ҪôΪ0��ҪôΪ1
//������������
//1���ǿն�������Ҷ�ӽ�������ڶ�Ϊ2�Ľڵ���+1������n0=n2+1
//2���ǿն������ϵ�K������2^(k-1)���ڵ�
//3���߶�Ϊh�Ķ�����������2^h-1���ڵ�
//4��n���ڵ�Ķ������߶�Ϊ [log2(n+1)]����ȡ��

//�����������ǵݹ��㷨,˼�룺����˳�����ȷ������������ڷ����������������ʸ��ڵ㡣��ջ���洢�ڵ㣬������巵�ظ��ڵ�ʱ���Ǵ����������ػ������������ء������ø���ָ��r����ָ��������ʹ��Ľڵ�
struct BiTreeNode
{
	int data;
	BiTreeNode *lchild;
	BiTreeNode *rchild;
};
void PostOrder(BiTreeNode *T)
{
	stack<BiTreeNode*>  s;
	BiTreeNode *p = T,*r=nullptr;
	while (p||!s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			if (p->rchild&&p->rchild!=r)
			{
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}
			else
			{
				p = s.top();
				s.pop();
				cout << p->data;
				r = p;
				p = nullptr;
			}
		}
	}
}
//�ж����Ŷ������Ƿ���ͬ,���������ҽڵ������ת
bool isEqual(BiTreeNode *node1, BiTreeNode *node2)
{
	if (node1 == nullptr&&node2 == nullptr)
		return 1;
	if (!node1 || !node2)
		return 0;
	if (node1->data == node2->data)
		return (isEqual(node1->lchild, node2->lchild) && isEqual(node1->rchild, node2->rchild)) || (isEqual(node1->lchild, node2->rchild) && isEqual(node1->rchild, node2->lchild));
	else
		return 0;

	/*if (node1->data == node2->data)
		return isEqual(node1->lchild, node2->lchild) && isEqual(node1->rchild, node2->rchild);
	else
		return 0;*/
}
//����������
int tree_height(BiTreeNode *root)
{
	if (nullptr == root)
		return 0;
	return max(tree_height(root->lchild), tree_height(root->rchild)) + 1;
}
int tree_height_BFS(BiTreeNode *root)
{
	if (nullptr == root)
		return 0;
	int res = 0;
	queue<BiTreeNode *>q;
	q.push(root);
	while (!q.empty())
	{
		++res;
		for (int i = 0, n = q.size(); i < n; ++i)
		{
			BiTreeNode *p = q.front();
			q.pop();
			if (p->lchild != nullptr)
				q.push(p->lchild);
			if (p->rchild != nullptr)
				q.push(p->rchild);
		}
	}
	return res;
}


