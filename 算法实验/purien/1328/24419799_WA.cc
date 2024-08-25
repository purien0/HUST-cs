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
char mark[nmax];
bool cmp(struct node a,struct node b)
{
	if(a.x == b.x)
	return a.y<b.y;
	return a.x<b.x;
}
int maxpos(int x,int y)//找到某个点右边距离最远的位置
{
	return (int)(sqrt(d*d-y*y))+x;
}
int iscover(int x,int px,int py)//被覆盖 
{
	if(sqrt((px-x)*(px-x)+py*py)<(double)d)
	return 1;
	return 0;
}
int next(int n)//返回0到n-1 ,n说明全部覆盖 
{
	static int x = 0;
	for(int i = x;i < n; i++)
	{
		if(!mark[i])
		{
			x = i;
			return x;
		}
	}
	x = 0;
	return n;
}
int main()
{
	int n,ans;
	int case_i = 0;//case数 
	int now,x;
	while((cin>>n>>d)&&n&&d)
	{
		case_i++;
		ans = 0;
		now = 0;
		memset(mark,0,sizeof(mark));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		sort(p,p+n,cmp);
		while(now!=n)
		{
			x = maxpos(p[now].x,p[now].y);
			ans++;
			for(int i = now;i < n;i++)
			{
				if(((p[i].x-x)*(p[i].x-x)+p[i].y*p[i].y)<=d*d)
				mark[i] = 1;
				if(p[i].x>x+d)
				break; 
			}
			now = next(n);
		}
		printf("Case %d: %d\n",case_i,ans);
	}
	return 0;
 } 