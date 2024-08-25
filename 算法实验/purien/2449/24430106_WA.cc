#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int nmax = 1001;
const int mmax = 100005;
#define INF 0x3f3f3f3f
int m,n;
int dis[nmax];//存最短距离 
struct node
{
	int n;//编号
	int dis;
	int f;//估计值 
	bool operator<(const struct node b) const
	{
		return f>b.f;
	}
};
struct edgenode
{
	int to;
	int next;
	int w;
}edge[mmax],edge2[mmax];
int head[nmax],head2[nmax];
void dijkstra(int s)//源点 
{
	memset(dis,INF,sizeof(dis));
	dis[s] = 0;
	int min,mini;
	int mark[n+1];
	memset(mark,0,sizeof(mark));
	for(int i = 0; i < n; i++)
	{
		min = INF;
		mini = 1;
		for(int j = 1; j <= n; j++)
		{
			if(!mark[j]&&dis[j]<min)
			{
				min = dis[j];
				mini = j;
			}
		}
		mark[mini] = 1;
		for(int i = head2[mini];i;i = edge2[i].next)
		{
			if(dis[mini]+edge2[i].w< dis[edge2[i].to])
			dis[edge2[i].to] = dis[mini]+edge2[i].w;
		}
		/*for(int i = 1; i < n+1; i++)
		{
		cout<<dis[i]<<" ";
		}
		cout<<" "<<mini<<endl;*/ 
	 } 
}
int astar(int s,int t,int k)
{
	priority_queue<struct node> q;
	struct node temp = {s,0,0+dis[s]};//估计函数为起点到s的距离加上s到终点的最小距离
	q.push(temp);
	int j;
	int cnt[n+1];//记录出队的次数 
	memset(cnt,0,sizeof(cnt));
	//if(s==t) cnt[t]++;
	while(!q.empty())
	{
		temp = q.top();
		q.pop();
		j = temp.n;
		cnt[j]++;
		if(cnt[t]==k)
		{
			return temp.dis;
		}
		for(int i = head[j];i;i = edge[i].next)
		{
			if(cnt[edge[i].to] < k)
			q.push({edge[i].to,temp.dis+edge[i].w,temp.dis+edge[i].w+dis[edge[i].to]});
		}
	}
	return -1;
}
int main()
{
	int a,b,w,s,t,k;
	scanf("%d%d",&n,&m);
	int p = 1;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		edge[p].next = head[a];
		edge[p].to = b;
		edge[p].w = w;
		head[a] = p;
		edge2[p].next = head2[b];
		edge2[p].to = a;
		edge2[p].w = w;
		head2[b] = p;
		p++;//建立反边 
	}
	scanf("%d%d%d",&s,&t,&k);
	dijkstra(t);
	printf("%d",astar(s,t,k));
	return 0;
 } 