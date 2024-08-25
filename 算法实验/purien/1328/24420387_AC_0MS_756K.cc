#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int nmax = 1001;
int d; 
struct node{
	int x;
	int y;
}p[nmax];
struct Node{
	double l;
	double r;
}q[nmax];
char mark[nmax];
bool cmp(struct Node a,struct Node b)
{
	if(a.l == b.l)
	return a.r>b.r;
	return a.l<b.l;
	//return a.l<b.l;
}
inline double rpos(int x,int y)//找到某个点右边距离最远的位置
{
	return (sqrt(d*d-y*y))+(double)x;
}
inline double lpos(int x,int y)
{
	return -(sqrt(d*d-y*y))+(double)x;
}
int main()
{
	int n,ans;
	int case_i = 0;//case数 
	int now,x;
	int flag=0;
	while((cin>>n>>d)&&n)
	{
		case_i++;
		ans = 0;
		now = 0;
		if(d<=0)
		{
			flag=1;
		}
		memset(mark,0,sizeof(mark));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			if(p[i].y<0)
			{
				i--;
				n--;
			}
			if(p[i].y>d)
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			flag=0;
			printf("Case %d: %d\n",case_i,-1);
			continue;
		}
		for(int i = 0 ; i < n; i++)
		{
			q[i].l = lpos(p[i].x,p[i].y);
			q[i].r = rpos(p[i].x,p[i].y);
		}
		sort(q,q+n,cmp);
		double r = q[0].r;
		ans=1;
		for(int i = 1; i < n;i++)
		{
			if(q[i].l>r)
			{
				r = q[i].r;
				ans++;
			}else if(q[i].r<r)
			{
				r = q[i].r;
			}
		}
		printf("Case %d: %d\n",case_i,ans);
	}
	return 0;
 } 