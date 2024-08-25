#include<iostream>
#include<algorithm>
#include<climits>
typedef long long ll;
using namespace std;
const int maxn = 100002;
int n;
ll  m;
int x[maxn];
ll Greater(int mid) {//比a[i]+x大的个数 
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += n - (lower_bound(x, x+n,x[i] + mid) - x);//lower_bound返回第一个比a[i]+x大的元素地址 
    }
    return sum;
}
int main()
{
	int mid; 
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0 ; i < n; i++)
		{
			scanf("%d", &x[i]);
		}
		m = n*(n-1)/4;//差值的个数的一半 
		sort(x,x+n);//升序排序
		int l = 0, r = x[n - 1] - x[0];
		while(r > l + 1)
		{
			mid = (l+r)/2;
			if (Greater(mid)<=m)//在差值中比mid大的个数太小（mid太大） 
			r = mid;
            else l = mid;//mid太小 
		}
		mid = (l+r)/2;
		cout<<mid<<endl;
	}
	return 0;
}