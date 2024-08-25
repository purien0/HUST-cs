#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int xm;
int ym;
int n;
struct node
{
	int x;
	int y;
}arr[10005];
bool cmp(struct node a,struct node b)
{
	if(a.x==b.x)
	return a.y<b.y;
	return a.x<b.x;
}
bool operator>(struct node a,struct node b)
{
	if(a.x==b.x)
	return a.y>b.y;
	return a.x>b.x;
}
bool operator==(struct node a,struct node b)
{
	return (a.x==b.x)&&(a.y==b.y);
}
int isRepeat(int x,int y,int xm,int ym)//检查牛舍的位置是否刚好在牛的位置
{
	/*if(x>y)
	return -1;
	int mid = (x+y)/2;
	struct node a = {xm,ym};
	if(arr[mid]==a)
	return mid;
	if(arr[mid]>a)
	return isRepeat(x,mid-1,xm,ym);
	return isRepeat(mid+1,y,xm,ym);*/
	struct node a = {xm,ym};
	for(int i = 0 ; i< n ; i++)
	{
		if(arr[i]==a)
		return i;
	}
	return -1;
} 
int dir[4][2] = {{1,0},{-1,0}, {0,1},{0,-1}};
int main()
{
	int pos;
	int ans = INT_MAX;
	int sum = 0,num; 
	cin>>n;
	int x[n],y[n];
	for(int i = 0; i < n; i++)
	{
		cin>>x[i]>>y[i];
		arr[i].x = x[i];
		arr[i].y = y[i];
	}
	sort(x,x+n);
	sort(y,y+n); 
	sort(arr,arr+n,cmp);
	if(n%2)//n为奇数 
	{
		xm = x[n/2];//直接找到中位数 
		ym = y[n/2];//直接找到中位数  
		pos = isRepeat(0,n-1,xm,ym);
		if(pos!=-1)//被占据,则相邻四个没被占据 
		{
		for(int k = 0; k < 4; k++)
		{//找四个位置 
			for(int i = 0; i < n; i++)
			{
			sum +=abs(x[i]-xm+dir[k][0])+abs(y[i]-ym+dir[k][1]);//找xm+1，ym 
			}
			if(sum<ans)
			{
			ans = sum;
			num = 1; 
			} 
			else if(sum==ans)
			num++;
			sum = 0; 
		}
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
			sum +=abs(x[i]-xm)+abs(y[i]-ym);//找xm+1，ym 
			}
			ans = sum;
			num = 1; 
		}
	}
	else
	{
		for(int i = x[n/2-1] ; i <= x[n/2]; i++ )
		{
			for(int j = y[n/2-1]; j <= y[n/2];j++)
			{
				pos = isRepeat(0,n-1,i,j);
				if(pos==-1)//没被占据 
				{
				sum = 0;
				for(int k = 0; k < n; k++)
				{
				sum +=abs(x[k]-i)+abs(y[k]-j);//找(i,j) 
				}
				if(sum<ans)
				{
				ans = sum;
				num = 1; 
				} 
				else if(sum==ans)
				num++;
				}
			}
		}
	}
	cout<<ans<<" "<<num;
	return 0;
}