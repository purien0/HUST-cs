#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int dis;//步骤数
	int g;//不在正确位置的数量 
	int now;
	char* state;//当前状态
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
bool visit[362881];
int main()
{
	char ch;
	char *ori = (char*)malloc(sizeof(char)*9);//用一个9元组表示棋盘状态 
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
	/*for(int i= 0; i < 9; i++)
	printf("%d ",ori[i]);
	cout<<endl;
	cout<<count<<endl;*/
	vector<char> t(1);
	t.resize(1);
	//for(int i= 0; i < t.capacity(); i++)
	//printf("%d ",t[i]);
	q.push({0,count,now,ori,t});
	//printf("%d",Contor(ori));
	solve(); 
	return 0;
}
void solve()
{
 	struct node temp;
 	char t;
 	int g,now;
 	vector<char> ans;
	while(!q.empty())
 	{
 		temp = q.top();
 		q.pop();
 		//printf("%d",Contor(temp.state));
 		visit[Contor(temp.state)] = true;
 		if(temp.now%3&&temp.ans.back()!=2)//不在左边界
		{
			g = temp.g;
			now = temp.now;
			char*state = (char*)malloc(sizeof(char)*9);
 			for(int i = 0; i < 9; i++)
 			state[i] = temp.state[i];
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(1);//向左移动 
			if(state[now-1]==now)
			{
				g++;
			}else if(state[now-1]==now+1)
			{
				g--;
			}
			t = state[now-1];
			state[now-1] = state[now];
			state[now] = t; 
			if(g==0)
			{
				for(int i = 0; i < ans.capacity();i++)
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
			if(!visit[Contor(state)])
			q.push({temp.dis+1,g,now-1,state,ans});
		}
		if((temp.now-2)%3&&temp.ans.back()!=1)//不在右边界
		{
			g = temp.g;
			now = temp.now;
			char*state = (char*)malloc(sizeof(char)*9);
 			for(int i = 0; i < 9; i++)
 			state[i] = temp.state[i];
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(2);//向左移动
			if(state[now+1]==now+2)
			{
				g++;
			}else if(state[now+1]==now+1)
			{
				g--;
			}
			t = state[now+1];
			state[now+1] = state[now];
			state[now] = t;
			if(g==0)
			{
				for(int i = 0; i < ans.capacity();i++)
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
			if(!visit[Contor(state)])
			q.push({temp.dis+1,g,now+1,state,ans});
		}
		if(temp.now > 2&&temp.ans.back()!=4)//不在上边界
		{
			g = temp.g;
			now = temp.now;
			char*state = (char*)malloc(sizeof(char)*9);
 			for(int i = 0; i < 9; i++)
 			state[i] = temp.state[i];
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(3);//向上移动
			if(state[now-3]==now-2)
			{
				g++;
			}else if(state[now-3]==now+1)
			{
				g--;
			}
			t = state[now-3];
			state[now-3] = state[now];
			state[now] = t;
			if(g==0)
			{
				for(int i = 0; i < ans.capacity();i++)
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
			if(!visit[Contor(state)])
			q.push({temp.dis+1,g,now-3,state,ans});
		}
		if(temp.now < 6&&temp.ans.back()!=3)//不在下边界
		{
			g = temp.g;
			now = temp.now;
			char*state = (char*)malloc(sizeof(char)*9);
 			for(int i = 0; i < 9; i++)
 			state[i] = temp.state[i];
 			ans.assign(temp.ans.begin(),temp.ans.end());
			ans.push_back(4);//向上移动
			if(state[now+3]==now+4)
			{
				g++;
			}else if(state[now+3]==now+1)
			{
				g--;
			}
			t = state[now+3];
			state[now+3] = state[now];
			state[now] = t;
			if(g==0)
			{
				for(int i = 0; i < ans.capacity();i++)
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
			if(!visit[Contor(state)])
			q.push({temp.dis+1,g,now+3,state,ans});
		}
	 }
	 printf("error");
	 return ;
}