#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int ans = 0;
	cin>>n;
	int x[n],y[n];
	for(int i = 0; i < n; i++)
	{
		cin>>x[i]>>y[i];
	}
	sort(x,x+n);
	for(int i = 0; i < n; i++)
	{
		x[i]-=i;
	}
	sort(y,y+n); 
		int xm = x[n/2];
		int ym = y[n/2];
		for(int i = 0; i < n; i++)
		{
			ans +=abs(x[i]-xm)+abs(y[i]-ym);
		}
	cout<<ans;
	return 0;
}