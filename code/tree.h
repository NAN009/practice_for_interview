#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
//tree 树中一个结点的字结点个数为该节点的度
//tree的性质：
//1、树中的结点数等于所有结点的度数+1  n0+n1+n2+n3+n4=n1+2*n2+3n3+4n4+1   用于求叶子节点
//2、度为m的树中第i层至多有m^(i-1)个结点
//3、高度为h的m叉树至多有(m^h-1)/(m-1)个结点
//4、具有n个结点的叉树的最小高度为:向上取整（logm的（n(m-1)+1))

//二叉树与度为2的树的区别：
//度为2的树至少有3个结点，而二叉树可以为空
//度为2树的孩子节点是无序的，二叉树是有序的

//完全二叉树特点：
//1、若i<=n/2,则节点i为分支节点，否则为叶子节点
//2、叶子节点只可能出现在层次最大的两层。对于最大层次中的叶子节点，都依次排列在该层最左边位置上
//3、如果有度为1 的结点,只可以有一个，且该节点只有左孩子
//4、按层序编号后，一旦出现某节点i为叶子节点或只有左孩子，则编号大于i的节点均为叶子节点
//5、若n为奇数，则每个分支节点都有左孩子和右孩子；若为偶数，则最大编号的分支节点只有左孩子。
//度为1的节点要么为0，要么为1
//二叉树的性质
//1、非空二叉树上叶子结点数等于度为2的节点数+1；即：n0=n2+1
//2、非空二叉树上第K至多有2^(k-1)个节点
//3、高度为h的二叉树至多有2^h-1个节点
//4、n个节点的二叉树高度为 [log2(n+1)]向上取整

//二叉树后续非递归算法,思想：遍历顺序是先访问左子树，在访问右子树，最后访问跟节点。用栈来存储节点，必须分清返回根节点时，是从左子树返回还是右子树返回。所以用辅助指针r，其指向最近访问过的节点
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
//判断两颗二叉树是否相同,二叉树左右节点可以旋转
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
//求二叉树深度
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


