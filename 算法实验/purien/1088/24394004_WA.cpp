#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
using namespace std;
int a[101][101];
int ans[101][101];
int m, n;
struct node
{
	int i;
	int j;
	int num;
}NODE[10001];
bool cmp(node A,node B)
{
	return A.num < B.num;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int dfs(int i, int j)
{
	if (ans[i][j])
		return ans[i][j];
	if (i)
	{
		if (a[i][j] > a[i - 1][j])
		{
				ans[i][j] = max(ans[i][j], dfs(i - 1, j)+1);
		}
	}
	if (j)
	{
		if (a[i][j] > a[i ][j-1])
			ans[i][j] = max(ans[i][j], dfs(i, j-1)+1);
	}
	if (i != m-1)
	{
		if (a[i][j] > a[i + 1][j])
			ans[i][j] = max(ans[i][j], dfs(i +1, j) + 1);
	}
	if (j!=m-1)
	{
		if (a[i][j] > a[i][j + 1])
			ans[i][j] = max(ans[i][j], dfs(i, j + 1) + 1);
	}
	if (ans[i][j] == 0)
		ans[i][j] = 1;
	return ans[i][j];
}
int res;
int main()
{
	int num = 0;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
				NODE[num].i =i;
				NODE[num].j =j;
				NODE[num++].num =a[i][j];
			}
	sort(NODE,NODE+num,cmp);
	//printf("%d %d %d\n",NODE[0].i,NODE[0].j,NODE[0].num) ;
	for(int i = 0 ; i < num;i++)
	res = max(res, dfs(NODE[i].i, NODE[i].j)); 
	/*for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			res = max(res, dfs(i, j));
		}*/
	printf("%d",res);
	return 0;
}