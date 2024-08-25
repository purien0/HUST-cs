#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n=0,h=0,max=0,dsum=0,temp=0;
	int f[26],d[26],t[26],ans[26],temp_f[26],temp_ans[26]; 
	memset(ans,0,sizeof(ans));
	while((cin>>n)&&n)
	{
		cin>>h;
		for(int i = 0; i < n;i++)
		cin>>f[i];
		for(int i = 0; i < n;i++)
		cin>>d[i];
		for(int i = 0; i < n-1;i++)
		cin>>t[i];
		//考虑终点在第1个池塘到第n个池塘的情况
		dsum = 0;
		max = 0;
		for(int i = 0 ; i < n; i++)//终点为第i个池塘 
		{
			if(12*h <= dsum)
			break;
			memset(temp_ans,0,sizeof(temp_ans));
			temp = 0;
			for(int i = 0; i < n;i++)
			temp_f[i] = f[i];//temp_f初始化 
			for(int j = dsum + 1; j <= 12*h;j++)
			{
				int fmax = 0;
				int fmaxi = 0;
				for(int k = 0 ; k <= i; k++)//贪心
				{
					if(fmax < temp_f[k])
					{
						fmax = temp_f[k];
						fmaxi = k;
					}
				}
				temp+=temp_f[fmaxi];
				temp_ans[fmaxi]+=1;
				temp_f[fmaxi]-=d[fmaxi];
				if(temp_f[fmaxi]<0)
				temp_f[fmaxi] = 0;
			}
			if(max < temp||i==0)//更新最大值与答案 
			{
				max = temp;
				for(int i = 0; i < n;i++)
				{
				ans[i] = temp_ans[i];
				}
			}
			dsum+=t[i];
		}
		for(int i = 0 ; i < n; i++)
		{
			if(i!=n-1)
			cout<<ans[i]*5<<",";
			else
			cout<<ans[i]*5<<endl;
		}
		printf("Number of fish expected: %d \n\n",max); 
	}
	return 0;
 } 