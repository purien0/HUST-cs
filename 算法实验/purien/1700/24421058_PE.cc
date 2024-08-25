#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int nmax = 1001;
int num[nmax];
int main() 
{
	int t,n,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 0; i < n ; i++)
		scanf("%d",&num[i]);
		sort(num,num+n);
		ans = 0;
		//找到分界线,前后方案不同 
		int k=n;
		for(int i = n-1; i>1;i--)
		{
			if(num[0]+num[i]>2*num[1]&&num[0]+num[i-1]<=2*num[1])
			{
				k = i;
				break;
			}
		}
		k++;//k指向两个中最大的 
		if((n-1-k)%2)
		k++;
		for(int i = n-1;i>1;)
		{
			if(i>=k)
			{
			ans+=num[i]+2*num[1]+num[0];
			i-=2;	
			}
			else if(i<k)
			{
				ans+=num[i]+num[0];
				i--;
			}
		}
		if(n==1)
		ans+=num[0];
		else
		ans+=num[1];
		printf("%d\n\n",ans);
	}
	return 0;
 } 