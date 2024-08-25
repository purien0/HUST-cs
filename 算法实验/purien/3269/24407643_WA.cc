#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int xm;
int ym;
struct node
{
	int x;
	int y;
}arr[100];
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
	if(x>y)
	return -1;
	int mid = (x+y)/2;
	struct node a = {xm,ym};
	if(arr[mid]==a)
	return mid;
	if(arr[mid]>a)
	return isRepeat(x,mid-1,xm,ym);
	return isRepeat(mid+1,y,xm,ym);
} 
int main()
{
	int n,pos;
	int ans = 0;
	int sum,num; 
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
	cout<<arr[0].x<<arr[0].y<<endl;
	if(n%2)//n为奇数 
	{
		xm = x[n/2];//直接找到中位数 
		ym = y[n/2];//直接找到中位数  
		pos = isRepeat(0,n-1,xm,ym);
		if(pos!=-1)//被占据,则相邻四个没被占据 
		{
		 for(int i = 0; i < n; i++)
		{
			sum +=abs(x[i]-xm-1)+abs(y[i]-ym);//找xm+1，ym 
		}
		ans = sum;
		num = 1; 
		sum = 0; 
		for(int i = 0; i < n; i++)
		{
			sum +=abs(x[i]-xm+1)+abs(y[i]-ym);
		}
		if(sum<ans)
		{
		ans = sum;
		num = 1; 
		} 
		else if(sum==ans)
		num++;
		sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum +=abs(x[i]-xm)+abs(y[i]-ym-1);
		}
		if(sum<ans)
		{
			ans = sum;
			num = 1;
		}
		else if(sum==ans)
		num++;
		sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum +=abs(x[i]-xm)+abs(y[i]-ym+1);
		}
		if(sum<ans)
		{
			ans = sum;
			num = 1;
		}
		else if(sum==ans)
		num++;
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
		/*xm1 = x[n/2];
		xm2 = x[n/2+1];
		ym1 = y[n/2];
		ym2 = y[n/2+1];*/
		ans = INT_MAX;
		for(int i = x[n/2-1] ; i <= x[n/2]; i++ )
		{
			for(int j = y[n/2-1]; j <= y[n/2];j++)
			{
				pos = isRepeat(0,n-1,i,j);
				cout<<i<<" "<<j<<" "<<pos<<endl;
				if(pos==-1)//没被占据 
				{
				sum = 0;
				for(int i = 0; i < n; i++)
				{
				sum +=abs(x[i]-xm)+abs(y[i]-ym);//找xm+1，ym 
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