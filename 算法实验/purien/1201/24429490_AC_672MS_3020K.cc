#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
#define max(a,b) ((a)<(b)?(b):(a)) 
struct node
{
	int to;
	int w;
	int next;
}edge[150005];
int d[50005];
bool visit[50005];
int head[50005];
int main()
{
	int n, m, r;
	scanf("%d",&n);
	int k = 1;
	int a = INT_MAX,b = 0;//最小与最大值
	int  to,from,w;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d",&to,&from,&w);
		edge[k].next = head[from];
		edge[k].to = to-1;
		edge[k].w = -w;
		head[from] = k;
		if(edge[k].to < a)
		a = edge[k].to;
		if(from > b)
		b =from;
		k++;
	}
	for(int i = a; i < b; i++)
	{//加边 
		edge[k].next = head[i+1];
		edge[k].to = i;
		edge[k].w = 0;
		head[i+1] = k;
		k++;
		edge[k].next = head[i];
		edge[k].to = i+1;
		edge[k].w = 1;
		head[i] = k;
		k++;
	}
	queue<int>q;
	for(int i = a; i <= b;i++)
	{
	q.push(i);
	visit[i] = true;	
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		visit[u] = false;
		for(int i = head[u];i;i = edge[i].next)
		{
			int v = edge[i].to;
			if(d[u]+edge[i].w < d[v]){//如果不满足三角形不等式
                d[v]=d[u]+edge[i].w;//更新答案
                if(!visit[v]){//如果终点不在队列
                    q.push(v);//入队
                    visit[v]=true;
                }
		}
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