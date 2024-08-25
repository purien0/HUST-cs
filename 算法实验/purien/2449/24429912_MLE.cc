#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int nmax = 1001;
#define INF 0x3f3f3f3f
int ed[nmax][nmax];
int m,n;
int dis[nmax];//存最短距离 
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
		for(int j = 1; j <= n; j++)
		{
			if(mini==j) continue;
			if(ed[mini][j]==INF)
			continue;
			if(dis[mini]+ed[mini][j] < dis[j])
			dis[j] = dis[mini] + ed[mini][j];
		}
		/*for(int i = 1; i < n+1; i++)
		{
		cout<<dis[i]<<" ";
		}
		cout<<" "<<mini<<endl;*/
	 } 
}
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
int astar(int s,int t,int k)
{
	priority_queue<struct node> q;
	struct node temp = {s,0,0+dis[s]};//估计函数为起点到s的距离加上s到终点的最小距离
	q.push(temp);
	int j;
	int cnt[n+1];//记录出队的次数 
	memset(cnt,0,sizeof(cnt));
	if(s==t) cnt[t]++;
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
		for(int i = 1; i <= n;i++)
		{
			if(i==j)continue;
			if(ed[j][i] == INF) continue;
			if(cnt[i] < k)
			q.push({i,temp.dis+ed[j][i],temp.dis+ed[j][i]+dis[i]});
		}
	}
	return -1;
}
int main()
{
	int a,b,w,s,t,k;
	scanf("%d%d",&n,&m);
	memset(ed,INF,sizeof(ed));
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		ed[a][b] = w;
	}
	scanf("%d%d%d",&s,&t,&k);
	dijkstra(s);
	printf("%d",astar(s,t,k));
	return 0;
 } 