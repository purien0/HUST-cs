#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
const int maxn=2e5+5;
const double inf=1e50;
struct Point {
    double x,y;
    int flag;
    bool operator<(const Point &a)const {
        if(x==a.x)
		return y < a.y; 
		return x < a.x;
    }//按x排序 
}p[maxn],q[maxn];
double Dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmpy(Point a,Point b){
	if(a.y ==b.y)
	return a.x < b.x; 
	return a.y < b.y;
}//按y优先 
double ClosestPointPair(int l,int r){
	if(l==r) 
	return inf;
	int cnt = 0;
	int mid = (l+r)/2;
	double ans = min(ClosestPointPair(l,mid),ClosestPointPair(mid+1,r));//左右最小值的最小值作为delta 
	for(int i = l; i <= r; i++)//取出所有点中位于+-delta范围内的点 
	if(fabs(p[i].x-p[mid].x) <= ans)
	q[cnt++]=p[i]; 
	sort(q,q+cnt,cmpy);
	for(int i = 0;i < cnt; i++){
		for(int j = i+1; j < cnt; j++){
			if(q[i].flag == q[j].flag) 
			continue; 
			if(q[j].y-q[i].y>ans) break;//之后的都超出范围 
			ans=min(ans,Dist(q[i],q[j]));
		}
	}
	return ans;
} 
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 0; i< 2 * n; i++){
			scanf("%lf%lf", &p[i].x, &p[i].y);
			if(i<n) p[i].flag = 0;
			else p[i].flag=1;
		} 
		sort(p,p+2*n);//x排序 
		printf("%.3f\n",ClosestPointPair(0,2*n-1));
	}
	return 0;
}