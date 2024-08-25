#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int nmax = 101;
#define INF 0x3f3f3f3f
int d[nmax][nmax];
int main()
{
	int m,n,a,b;
	scanf("%d%d", &n,&m);
	memset(d,INF,sizeof(d));
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&a,&b);
		d[b][a] = 1;
	}
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n;i++)
		{
			if(d[i][k]==INF)
			continue;
			for(int j = 1; j <=n;j++)
			{
				if(d[k][j]==INF)
				continue;
				if(d[i][k]+d[k][j]<d[i][j])
				d[i][j] = d[i][k]+d[k][j];
			}
		}
	}
	int num = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		num=0;
		for(int j = 1; j<=n;j++)
		{
			if(i!=j&&d[i][j]!=INF) num++;
			if(i!=j&&d[j][i]!=INF) num++;
		}
		if(num==n-1) ans++;
	}
	printf("%d",ans);
	return 0;
 } 