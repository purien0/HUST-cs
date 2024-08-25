#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
int a[101][101];
int ans[101][101];
int m, n;
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
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			res = max(res, dfs(i, j));
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					printf("%d ", ans[i][j]);
				printf("\n");
			}
		}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}