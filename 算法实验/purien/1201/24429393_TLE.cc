#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
using namespace std;
#define max(a,b) ((a)<(b)?(b):(a)) 
struct node
{
	int from;
	int to;
	int w;
}edge[150005];
int d[50005];
int main()
{
	int n, m, r;
	scanf("%d",&n);
	int k = 0;
	int a = INT_MAX,b = 0;//最小与最大值 
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d",&edge[k].to,&edge[k].from,&edge[k].w);
		edge[k].to--;
		if(edge[k].to < a)
		a = edge[k].to;
		if(edge[k].from > b)
		b = edge[k].from;
		edge[k].w = -edge[k].w;
		k++;
	}
	for(int i = a; i < b; i++)
	{//加边 
		edge[k].from = i+1;
		edge[k].to = i;
		edge[k].w = 0;
		k++;
		edge[k].from = i;
		edge[k].to = i+1;
		edge[k++].w = 1;
	}
	for(int i = a; i <= b;i++)
	{
		for(int j = 0; j < k; j++)
		{
			if(d[edge[j].to]>d[edge[j].from]+edge[j].w)
			d[edge[j].to] = d[edge[j].from]+edge[j].w;
		}
	}
	/*for(int i = a;i<=b;i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<endl;
	cout<<a<<" "<<b<<endl;*/
	printf("%d",d[b]-d[a]); 
	return 0;
}