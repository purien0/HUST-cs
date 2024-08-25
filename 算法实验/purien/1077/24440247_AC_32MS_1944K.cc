#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;
int d[4] = {-1,1,-3,3};
char di[4] = {'l','r','u','d'};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
const int tar = 46234;//目标康托值
struct node
{
	int dis;//步骤数
	int g;//不在正确位置的数量
	int f;//启发函数值 
	int now;//空格当前所处的位置 
	int state;//用康托值表示当前状态 
	bool operator<(const struct node b)const
	{
		return dis+f>b.dis+b.f;
	}
};
bool check(char*s,int now)//检查是否有答案 
{
	int cnt = 0;
	for(int i = 0; i < 9; i++)
	{
		if(!s[i])
		continue;
		for(int j = i+1; j < 9; j++)
		{
			if(!s[j])
			continue;
			if(s[i]>s[j])
			cnt++; 
		}
	 }
	if(cnt%2)
	return false;
	return true;
}
struct path
{
	int op;//存动作
	int k;//下一个编号，编号为0则为终点 
}path[362881];
priority_queue<struct node> q;
void solve();
int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};//康托展开用到的阶乘 
int Contor(char *a) {//计算康托值 
  int sum=0,small=0;
  int n = 9;
  for(int i=0;i<n;i++) {
    small=0;
    for(int j=i+1;j<n;j++) {
      if(a[j]<a[i]) {    //计算第i位右边比该数还要小的数的个数 
        small++;
      }
    }
    sum+=small*fac[n-i-1];
    //例如12345，i=0时实际上对应着5 
    //顺数第i位实际上对应着第n-i位 ，即a[n-i]=small,所以应该是small* ((n-i)-1)!
    //所以应该是small*fac[n-i-1] 
  }
  return sum+1;
}
void incontor(char*res,int x) {
    x--;// 得到以0开始的排名
    int n = 9;// 保存数列答案
    int cnt;
    bool st[10];// 标记数组
    memset(st,0,sizeof st);
    for(int i = 0;i < n; ++i) {
        cnt = x/fac[n - i - 1];// 比a[i]小且没有出现过的数的个数
        x %= fac[n - i - 1];// 更新 x
        for(int j = 1;j <= n; ++j) {// 找到a[i]，从1开始向后找
            if(st[j]) continue;// 如果被标记过，就跳过
            if(!cnt) {// 如果cnt == 0说明当前数是a[i]
                st[j] = 1;//标记
                res[i] = j-1;// 第i位是j
                break;
            }
            cnt--;// 如果当前不是0，就继续往后找
        }
    }
    return;// 返回答案
} 
void swap(int &a,int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
 int linear_conflict(int contor)
{
	char state[9];
	incontor(state,contor);
	int count = 0;
	for(int i = 0; i < 9; i++)
	{
		if(!state[i])
		continue;
		for(int j = i + 1;j/3==i/3;j++)
		{//现在是同一行 
			if(!state[j])
			continue;
			if((state[i]-1)/3!=(state[j]-1)/3)
			continue;//目标是同一行 
			if(state[i]>state[j])
			count++;
		}
	}
	for(int i = 0; i < 9; i++)
	{
		if(!state[i])
		continue;
		for(int j = i + 3;j<9;j+=3)
		{
			if(!state[j])
			continue;
			if((state[i]-1)%3!=(state[j]-1)%3)
			continue;//目标是同一列 
			if(state[i]>state[j])
			count++;
		}
	}
	return 2*count; 
 } 
bool visit[362881];
char p[362881];
int Mdis(int x,int y,int i)
{
	return abs(x-i%3)+abs(y-i/3);
}
int main()
{
	char ch;
	char ori[9];//用一个9元组表示棋盘状态 
	int count = 0;
	int now;
	for(int i = 0; i < 9;)
	{
		scanf("%c",&ch);
		if(ch<'9'&&ch>'0')
		{
			ori[i++] = ch-'0';
			if(ori[i-1]!=i)
			count++;
		}
		else if(ch=='x')
		{
		ori[i++] = 0; //0表示空格 
		now = i-1;
		}
	}
	if(!check(ori,now))
	{
		printf("unsolvable");
		return 0;
	}
	int dis = 0;
	for(int i = 0; i < 9;i++)
	{
		if(ori[i])
		dis += Mdis(i%3,i/3,ori[i]-1);
	}//算出最初的曼哈顿距离
	dis+=linear_conflict(Contor(ori));
	q.push({0,count,dis,now,Contor(ori)});
	solve(); 
	return 0;
}
void solve()
{
 	struct node temp;
 	char t;
 	int g,now;
 	int c;//contor
 	int cc;
 	int x,y; 
 	int dis; 
	while(!q.empty())
 	{
 		temp = q.top();
 		q.pop(); 
 		visit[temp.state] = true;
 		char state[9];
 		incontor(state,temp.state);
 		cc = temp.state;
		now = temp.now;
		for(int i = 0; i < 4; i++)//四个方向左，右 
		{
			x=now%3+dir[i][0];
			y=now/3+dir[i][1];
			if(x<0||x>2||y<0||y>2)
			continue;//越界
			swap(state[now+d[i]],state[now]);//交换位置
			c = Contor(state);//记录康托值 
			swap(state[now+d[i]],state[now]);//换回来
			if(visit[c])
			continue;
			dis = temp.f-Mdis(x,y,state[now+d[i]]-1)+Mdis(now%3,now/3,state[now+d[i]]-1)-linear_conflict(cc)+linear_conflict(c);//dis更新 
			g = temp.g;
			if(state[now+d[i]]==now+d[i]+1)
			{
				g++;
			}else if(state[now+d[i]]==now+1)
			{
				g--;
			}
			path[c].op = i;
			path[c].k = cc;//上一个
			if(c==tar)
			{
				int j = 0;
				for(int i = c;i;i = path[i].k)
				{
					p[j++] = di[path[i].op];
				}
				for(int i = j-2; i >= 0; i--)
				{
					printf("%c", p[i]);
				}
				return ;
			}
			q.push({temp.dis+1,g,dis,now+d[i],c});
		}
	 }
	 printf("error");
	 return ;
}