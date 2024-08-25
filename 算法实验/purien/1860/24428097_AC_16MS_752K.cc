#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<climits> 
using namespace std;
const int nmax = 101;
int num[nmax];
struct node
{
	int from;
	int to;
	double r;
	double c;	
}edge[210];
double d[nmax];
int main() 
{
	int n,m,s,a,b;//n为货币数（顶点数），m为货币（边数） 
	double v;
	cin>>n>>m>>s>>v;
	int k = 0; 
	for(int i=0; i < m; i++)
	{
		scanf("%d%d",&a,&b);
		edge[k].from = a;
		edge[k].to = b;
		k++;
		edge[k].from = b;
		edge[k].to = a;
		scanf("%lf%lf%lf%lf",&edge[k-1].r,&edge[k-1].c,&edge[k].r,&edge[k].c);\
		k++;
	}
	node temp;
	d[s] = v;
	for(int i = 0; i < n;i++)//n次松弛 
	{
		for(int j = 0; j < k; j++)
		{
			temp = edge[j];
			if((d[temp.from]-temp.c)*temp.r>d[temp.to])
			{
				d[temp.to] = (d[temp.from]-temp.c)*temp.r;
				if(i==n-1)
				{
					printf("YES");
					return 0;
				}
			}
		}
	}
	printf("NO");
	return 0;
 } 