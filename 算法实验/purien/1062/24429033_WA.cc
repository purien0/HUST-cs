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
const int nmax = 101;
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
int dis[nmax]; 
int m,n;
int edge[nmax+1][nmax+1];//邻接矩阵 
void dijkstra();
int main()
{
	scanf("%d%d",&m,&n);
	int p,l,x,t,v;
	int s;//standard//酋长位置，直接忽略地位相差过大的边 
	scanf("%d%d%d",&p,&s,&x);//读入酋长的信息
	edge[0][1] = p;
	for(int j = 0; j < x;j++)
	{
		scanf("%d%d",&t,&v);
		edge[t][1] = v;
	}
	for(int i = 1; i < n ; i++)
	{
		scanf("%d%d%d",&p,&l,&x);
		if(l>=s-m)//地位足够高 
		{
			edge[0][i+1] = p;	
		}
		for(int j = 0; j < x;j++)
		{
		scanf("%d%d",&t,&v);
		edge[t][i+1] = v;
		}
	}
	dijkstra();
	printf("%d",dis[1]);
	return 0;
}
void dijkstra()
{//无堆优化 
	for(int i = 0; i < n+1; i++)
	{
		dis[i] = INT_MAX;
	}
	dis[0] = 0;//初始化 
	int mark[n+2];
	memset(mark,0,sizeof(mark));
	int min,mini;
	for(int i = 0; i < n+1; i++)
	{
		min = INT_MAX;
		mini = 0;
		for(int i = 0; i < n+1; i++)
		{
		if((!mark[i])&&(min>dis[i]))
		{
			min = dis[i];
			mini = i;
		}
		}//找到mini 
		mark[mini] = 1;
		for(int j = 0; j < n+1; j++)
		{
			if(j==mini)
			continue;
			if(!edge[mini][j])
			continue; 
			if(dis[j] > dis[mini]+edge[mini][j])//更新距离 
			dis[j] = dis[mini]+edge[mini][j];
		}
		/*for(int i = 0; i < n+1; i++)
		{
		cout<<dis[i]<<" ";
		}
		cout<<" "<<mini<<endl;*/
	}
}