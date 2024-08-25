#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
struct node
{
	int dis;//步骤数
	int g;//不在正确位置的数量 
	int now;
	int state;//用康托值表示当前状态 
	vector<char> ans;
	bool operator<(const struct node b)const
	{
		return dis+g>b.dis+b.g;
	}
};
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
bool check(char*s,int now)//检查是否有答案 
{
	int x = now%2,cnt;
	for(int i = 0; i < 9; i++)
	{
		cnt = 0;
		for(int j = i; j < 9; j++)
		{
			if(s[i]>s[j])
			cnt++; 
		}
	 }
	if((x+cnt)%2)
	return false;
	return true;
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
            cnt --;// 如果当前不是0，就继续往后找
        }
    }
    return;// 返回答案
}
bool visit[362881];
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
	if(check(ori,now))
	{
		printf("unsolvable");
		return 0;
	}
	vector<char> t(1);
	t.resize(1);
	q.push({0,count,now,Contor(ori),t});
	solve(); 
	return 0;
}
void solve()
{
 	struct node temp;
 	char t;
 	int g,now;
 	int c;//contor 
 	vector<char> ans;
	while(!q.empty())
 	{
 		temp = q.top();
 		q.pop();
 		visit[temp.state] = true;
 		char state[9];
 		incontor(state,temp.state); 
		now = temp.now;
 		while(temp.now%3)//不在左边界,向左 
		{
			t = state[now-1];
			state[now-1] = state[now];
			state[now] = t;//交换位置
			c = Contor(state);
			t = state[now-1];
			state[now-1] = state[now];
			state[now] = t; //换回来 
			if(visit[c])
			break;
			g = temp.g;
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(1);//向左移动 
			if(state[now-1]==now)
			{
				g++;
			}else if(state[now-1]==now+1)
			{
				g--;
			}
			if(g==0)
			{
				for(int i = 0; i < ans.size();i++)
				{
					switch(ans[i])
					{
						case 1:
							printf("l");
							break;
						case 2:
							printf("r");
							break;
						case 3:
							printf("u");
							break;
						case 4:
							printf("d");
							break;
						default:
							break;
					}
				}
				return ;
			}
			q.push({temp.dis+1,g,now-1,c,ans});
			break;
		}
		while((temp.now-2)%3)//不在右边界
		{
			t = state[now+1];
			state[now+1] = state[now];
			state[now] = t;//交换位置
			c = Contor(state);
			t = state[now+1];
			state[now+1] = state[now];
			state[now] = t;
			if(visit[c])
			break;
			g = temp.g;
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(2);//向左移动
			if(state[now+1]==now+2)
			{
				g++;
			}else if(state[now+1]==now+1)
			{
				g--;
			}
			if(g==0)
			{
				for(int i = 0; i < ans.size();i++)
				{
					switch(ans[i])
					{
						case 1:
							printf("l");
							break;
						case 2:
							printf("r");
							break;
						case 3:
							printf("u");
							break;
						case 4:
							printf("d");
							break;
						default:
							break;
					}
				}
				return ;
			}
			q.push({temp.dis+1,g,now+1,c,ans});
			break;
		}
		while(temp.now > 2)//不在上边界
		{
			t = state[now-3];
			state[now-3] = state[now];
			state[now] = t;//交换位置
			c = Contor(state);
			t = state[now-3];
			state[now-3] = state[now];
			state[now] = t;
			if(visit[c])
			break;
			g = temp.g;
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(3);//向上移动
			if(state[now-3]==now-2)
			{
				g++;
			}else if(state[now-3]==now+1)
			{
				g--;
			}
			if(g==0)
			{
				for(int i = 0; i < ans.size();i++)
				{
					switch(ans[i])
					{
						case 1:
							printf("l");
							break;
						case 2:
							printf("r");
							break;
						case 3:
							printf("u");
							break;
						case 4:
							printf("d");
							break;
						default:
							break;
					}
				}
				return ;
			}
			q.push({temp.dis+1,g,now-3,c,ans});
			break;
		}
		while(temp.now < 6)//不在下边界
		{
			t = state[now+3];
			state[now+3] = state[now];
			state[now] = t;//交换位置
			c = Contor(state);
			t = state[now+3];
			state[now+3] = state[now];
			state[now] = t;
			if(visit[c])
			break;
			g = temp.g;
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(4);//向上移动
			if(state[now+3]==now+4)
			{
				g++;
			}else if(state[now+3]==now+1)
			{
				g--;
			}
			if(g==0)
			{
				for(int i = 0; i < ans.size();i++)
				{
					switch(ans[i])
					{
						case 1:
							printf("l");
							break;
						case 2:
							printf("r");
							break;
						case 3:
							printf("u");
							break;
						case 4:
							printf("d");
							break;
						default:
							break;
					}
				}
				return;
			}
			q.push({temp.dis+1,g,now+3,c,ans});
			break;
		}
	 }
	 printf("error");
	 return ;
}