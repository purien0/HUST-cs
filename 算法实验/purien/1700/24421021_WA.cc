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
		if(n==1)
		ans = num[0];
		else if(n==2)
		ans = num[0]+num[1];
		else
		ans = num[0]+num[1]+num[n-1];
		for(int i = 2; i < n-1;i++)
		{
			if(num[0]+num[i]>2*num[1])
			ans+=2*num[1];
			else
			ans+=num[0]+num[i];
		}
		printf("%d",ans);
	}
	return 0;
 } 