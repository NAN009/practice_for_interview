#include <iostream>
#include <vector>
using namespace std;
//È«ÅÅÁÐ
const int N = 13;
int d[N], v[N],n;
void dfs(int depth)
{
	if (depth >= n)
	{
		for (int i = 0; i != n; ++i)
			cout << d[i];
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] == 0)
		{
			v[i] = 1;
			d[depth] = i;
			dfs(depth + 1);
			v[i] = 0;
		}
	}
}