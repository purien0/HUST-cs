#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
using namespace std;
const int nmax = 101;
const int mmax = 10;
int n,m;
int dp[nmax][1<<mmax-1][1<<mmax-1];//填充第i行，前两列对 
int ori[nmax+2];//第i行的初始状态
int ac[nmax];
int Count(int x)  
{  
    int cons = 0;  
    while(x)  
    {  
        if(x & 1)cons++;  
        x >>= 1;  
    }  
    return cons;  
}  
int main()
{
	int ans = 0;
	char ch;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%c",&ch);
			if(ch!='H'&&ch!='P')
			{
				j--;
				continue;
			}
			if(ch=='H')
			ori[i+2] += (1<<j);//第i行的初始状态设置，把j处设置为1,意为不能放置,前两行设置为0 
		}
	}
	int count = 0;
	for(int i = 0; i < 1<<m; i++)//一行内的可行解
	{
		if(i&(i<<1))//隔一个不能放 
		continue;
		if(i&(i<<2))//隔两个不能放 
		continue;
		ac[count++] = i;
	}
	for(int i = 0; i < n; i++)//第i行 
	for(int aci = 0; aci < count; aci++)//枚举可行解
	{
		if(ac[aci]&ori[i+2])//和初始格局有没有冲突，有就去掉
		continue;
		for(int ac1 = 0; ac1 < count; ac1++)//检查下一行间有没有冲突 
		{
			if(ac[ac1]&ori[i+1])continue; 
			if(ac[aci]&ac[ac1])
			continue;
			for(int ac2 = 0; ac2 < count; ac2++)
			{
				if(ac[ac2]&ori[i]) continue;
				if(ac[aci]&ac[ac2]) continue;
				if(ac[ac1]&ac[ac2]) continue; 
				//都通过则为可行解
				dp[i+1][ac[aci]][ac[ac1]] = max(dp[i+1][ac[aci]][ac[ac1]],dp[i][ac[ac1]][ac[ac2]]);
			}
			dp[i+1][ac[aci]][ac[ac1]]+=Count(ac[aci]);
		}
	}
	 for(int i = (1<<m)-1; i >= 0; i--)  
    {  
        for(int j = (1<<m)-1; j >= 0; j--)  
        {  
            ans = max(ans,dp[n][i][j]);  
            //取最大的方案数  
        }  
    }  
    printf("%d\n", ans); 
    return 0;
	
}