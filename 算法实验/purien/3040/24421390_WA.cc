#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<climits> 
using namespace std;
const int nmax = 1001;
int num[nmax];
struct node
{
	int v;
	int num;
};
bool cmp(struct node a,struct node b)
{
	return a.v < b.v;
}
int main() 
{
	int n,c,ans=0,a,b;
	cin>>n>>c;
	int num[n],count = 0;
	struct node N[n];
	int x;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d",&a,&b);
		if(a>=c)//大面值直接算到ans里 
		ans+=b;
		else
		{
			N[count].v = a;
			N[count++].num = b;
		}//小面值待组合
	}
	n = count;
	int combi[n];
	sort(N,N+n,cmp);
	//找到最优的小面值组合方案
	int flag=1;
	while(flag)
	{
	int now_c = c;
	memset(combi,0,sizeof(combi)); 
	for(int i = n-1;i>=0;i--)
	{
		if(N[i].num>=now_c/N[i].v)
		x = now_c/N[i].v;//用最大面值减去
		else
		x = N[i].num;
		now_c-=x*N[i].v;
		combi[i] = x;
		if(!now_c)
		break;
	}
	if(now_c)//如果无法刚好凑齐 
	{
		for(int i = 0; i<=n-1;i++)
		{//从小到大凑 
		if(N[i].num>=(combi[i]+1))
		{
			combi[i]+=1;
			now_c = 0;
		}
		}
		if(now_c)//已不能凑齐
		break; 
	 }
	 //凑齐后开始更新货币数,按照组合方式找到最多多少套(货币算得套数中的最小值） 
	 int min = INT_MAX;
	 for(int i = 0 ; i < n; i++)
	 {
	 	if(combi[i]&&min>N[i].num/combi[i])//若组合会用到
		min = N[i].num/combi[i];
	  }
	  ans+=min;
	  for(int i = 0; i < n; i++)
	  {
	  	N[i].num -=min*combi[i];//更新货币数目 
		}
	flag = 0;
	for(int i = 0; i < n; i++)
	{
		if(N[i].num) 
		flag=1;
	}
	}
	printf("%d",ans);
	return 0;
 } 