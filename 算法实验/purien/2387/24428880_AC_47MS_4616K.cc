#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<climits>
#include<queue> 
inline int min(int a,int b)
{
	return a<b?a:b;
}

using namespace std;
const int nmax = 1001;
int num[nmax];
//dijkstra 
struct node
{
	int i;//编号
	int dis;//距离源点的距离 
	bool operator < (struct node b)
	{
		return dis<b.dis;
	}
}; 
//priority_queue<node> q;
int dis[1001]; 
int t,n;
int edge[nmax][nmax];//邻接矩阵 
void dijkstra();
int main()
{
	scanf("%d%d",&t,&n);
	int a,b,c;
	for(int i = 0; i < t ; i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(edge[a][b])
		{
		edge[a][b] = min(edge[a][b],c);
		edge[b][a] = min(edge[a][b],c);//无向图	
		}
		else
		{
		edge[a][b] = c;
		edge[b][a] = c;//无向图 	
		}
	}
	dijkstra();
	printf("%d",dis[n-1]);
	return 0;
}
void dijkstra()
{//无堆优化 
	for(int i = 0; i < n; i++)
	{
		dis[i] = INT_MAX;
	}
	dis[0] = 0;//初始化 
	int mark[n+1];
	memset(mark,0,sizeof(mark));
	int min,mini;
	for(int i = 0; i < n; i++)
	{
		min = INT_MAX;
		mini = 0;
		for(int i = 0; i < n; i++)
		{
		if((!mark[i])&&(min>dis[i]))
		{
			min = dis[i];
			mini = i;
		}
		}//找到mini 
		mark[mini] = 1;
		for(int j = 0; j < n; j++)
		{
			if(j==mini)
			continue;
			if(!edge[mini+1][j+1])
			continue; 
			if(dis[j] > dis[mini]+edge[mini+1][j+1])//更新距离 
			dis[j] = dis[mini]+edge[mini+1][j+1];
		}
		/*for(int i = 0; i < n; i++)
		{
		cout<<dis[i]<<" ";
		}
		cout<<" "<<mini<<endl;*/
	}
}