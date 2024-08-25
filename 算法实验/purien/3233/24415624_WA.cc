#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
const int nmax = 30;
int n,m;
typedef struct matrix
{
	int num[nmax+2][nmax+2];
}Matrix;
Matrix mul(Matrix a,Matrix b)//求a与b的积
{
	Matrix ans;
	memset(ans.num,0,sizeof(ans.num));
	for(int i = 0 ;i < n; i++)
	{
		for(int j = 0 ; j < n;j++)
		{
			for(int k = 0 ;k < n;k++)
			ans.num[i][j] += ((a.num[i][k]*b.num[k][j])%m);
		}
	}
	return ans;
}
Matrix add(Matrix a,Matrix b)//求a与b的和 
{
	Matrix ans;
	for(int i = 0 ;i < n; i++)
	{
		for(int j = 0 ; j < n;j++)
		{
			ans.num[i][j] = (a.num[i][j]+b.num[i][j])%m;
		}
	}
	return ans;
} 
Matrix pow(Matrix a,int k)//求a的k次幂 
{
	Matrix ans;
	memset(ans.num,0,sizeof(ans.num));
	for(int i = 0 ;i < n; i++)
	{
		ans.num[i][i] =1;
	}//单位矩阵 
	while(k)
	{
		if(k%2)//如果k为奇数
		ans = mul(ans,a);
		a = mul(a,a);//升幂
		k/=2;//k除以2 
	} 
	return ans;
} 
Matrix sum(Matrix a,int k)
{//求 A加到k次幂的Matrix 
	if(k==1) return a;
	Matrix ans;
	Matrix s;
	s = sum(a,k/2); //二分的和，A加到k/2次幂 
	Matrix p;
	if(k%2)//k为奇数 
	{
		p = pow(a,k/2+1);
		ans = add(add(mul(p,s),s),p);
	}
	else //k为偶数 
	{
		p = pow(a,k/2);
		ans = add(mul(p,s),s);
	}
	return ans;
}
int main()
{
	int k;
	cin>>n>>k>>m;
	Matrix x;
	Matrix res; 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0 ; j < n; j++)
		{
			scanf("%d",&x.num[i][j]);
		}
	}
	res = sum(x,k);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0 ; j < n; j++)
		{
			if(j!=n-1)
			printf("%d ",res.num[i][j]);
			else
			printf("%d",res.num[i][j]);
		}
		printf("\n");
	}
	return 0;
}