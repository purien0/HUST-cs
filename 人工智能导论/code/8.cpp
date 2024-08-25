#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
char dir[4] = {'l','r','u','d'};
struct node
{
	int dis;//������
	int g;//������ȷλ�õ����� 
	int now;
	int state;//�ÿ���ֵ��ʾ��ǰ״̬ 
	bool operator<(const struct node b)const
	{
		return dis+g>b.dis+b.g;
	}
};
struct path
{
	int op;//�涯��
	int k;//��һ����ţ����Ϊ0��Ϊ�յ� 
}path[362881];
priority_queue<struct node> q;
void solve();
int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};//����չ���õ��Ľ׳� 
int Contor(char *a) {//���㿵��ֵ 
  int sum=0,small=0;
  int n = 9;
  for(int i=0;i<n;i++) {
    small=0;
    for(int j=i+1;j<n;j++) {
      if(a[j]<a[i]) {    //�����iλ�ұ߱ȸ�����ҪС�����ĸ��� 
        small++;
      }
    }
    sum+=small*fac[n-i-1];
    //����12345��i=0ʱʵ���϶�Ӧ��5 
    //˳����iλʵ���϶�Ӧ�ŵ�n-iλ ����a[n-i]=small,����Ӧ����small* ((n-i)-1)!
    //����Ӧ����small*fac[n-i-1] 
  }
  return sum+1;
}
bool check(char*s,int now)//����Ƿ��д� 
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
    x--;// �õ���0��ʼ������
    int n = 9;// �������д�
    int cnt;
    bool st[10];// �������
    memset(st,0,sizeof st);
    for(int i = 0;i < n; ++i) {
        cnt = x/fac[n - i - 1];// ��a[i]С��û�г��ֹ������ĸ���
        x %= fac[n - i - 1];// ���� x
        for(int j = 1;j <= n; ++j) {// �ҵ�a[i]����1��ʼ�����
            if(st[j]) continue;// �������ǹ���������
            if(!cnt) {// ���cnt == 0˵����ǰ����a[i]
                st[j] = 1;//���
                res[i] = j-1;// ��iλ��j
                break;
            }
            cnt --;// �����ǰ����0���ͼ���������
        }
    }
    return;// ���ش�
}
bool visit[362881];
char p[362881];
int main()
{
	char ch;
	char ori[9];//��һ��9Ԫ���ʾ����״̬ 
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
		ori[i++] = 0; //0��ʾ�ո� 
		now = i-1;
		}
	}
	if(check(ori,now))
	{
		printf("unsolvable");
		return 0;
	}
	q.push({0,count,now,Contor(ori)});
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
	while(!q.empty())
 	{
 		temp = q.top();
 		q.pop();
 		visit[temp.state] = true;
 		char state[9];
 		incontor(state,temp.state); 
 		cc = temp.state;
		now = temp.now;
 		while(temp.now%3)//������߽�,���� 
		{
			t = state[now-1];
			state[now-1] = state[now];
			state[now] = t;//����λ��
			c = Contor(state);
			t = state[now-1];
			state[now-1] = state[now];
			state[now] = t; //������ 
			if(visit[c])
			break;
			g = temp.g;
			if(state[now-1]==now)
			{
				g++;
			}else if(state[now-1]==now+1)
			{
				g--;
			}
			path[c].op = 0;
			path[c].k = cc;//��һ�� 
			if(g==0)
			{
				int j = 0;
				for(int i = c;i;i = path[i].k)
				{
					p[j++] = dir[path[i].op];
				}
				for(int i = j-2; i >= 0; i--)
				{
					printf("%c", p[i]);
				}
				return ;
			}
			q.push({temp.dis+1,g,now-1,c});
			break;
		}
		while((temp.now-2)%3)//�����ұ߽�
		{
			t = state[now+1];
			state[now+1] = state[now];
			state[now] = t;//����λ��
			c = Contor(state);
			t = state[now+1];
			state[now+1] = state[now];
			state[now] = t;
			if(visit[c])
			break;
			g = temp.g;
			if(state[now+1]==now+2)
			{
				g++;
			}else if(state[now+1]==now+1)
			{
				g--;
			}
			path[c].op = 1;
			path[c].k = cc;
			if(g==0)
			{
				int j = 0;
				for(int i = c;i;i = path[i].k)
				{
					p[j++] = dir[path[i].op];
				}
				for(int i = j-2; i >= 0; i--)
				{
					printf("%c", p[i]);
				}
				return ;
			}
			q.push({temp.dis+1,g,now+1,c});
			break;
		}
		while(temp.now > 2)//�����ϱ߽�
		{
			t = state[now-3];
			state[now-3] = state[now];
			state[now] = t;//����λ��
			c = Contor(state);
			t = state[now-3];
			state[now-3] = state[now];
			state[now] = t;
			if(visit[c])
			break;
			g = temp.g;
			if(state[now-3]==now-2)
			{
				g++;
			}else if(state[now-3]==now+1)
			{
				g--;
			}
			path[c].op = 2;
			path[c].k = cc;
			if(g==0)
			{
				int j = 0;
				for(int i = c;i;i = path[i].k)
				{
					p[j++] = dir[path[i].op];
				}
				for(int i = j-2; i >= 0; i--)
				{
					printf("%c", p[i]);
				}
				return ;
			}
			q.push({temp.dis+1,g,now-3,c});
			break;
		}
		while(temp.now < 6)//�����±߽�
		{
			t = state[now+3];
			state[now+3] = state[now];
			state[now] = t;//����λ��
			c = Contor(state);
			t = state[now+3];
			state[now+3] = state[now];
			state[now] = t;
			if(visit[c])
			break;
			g = temp.g;
			if(state[now+3]==now+4)
			{
				g++;
			}else if(state[now+3]==now+1)
			{
				g--;
			}
			path[c].op = 3;
			path[c].k = cc;
			if(g==0)
			{
				int j = 0;
				for(int i = c;i;i = path[i].k)
				{
					p[j++] = dir[path[i].op];
				}
				for(int i = j-2; i >= 0; i--)
				{
					printf("%c", p[i]);
				}
				return ;
			}
			q.push({temp.dis+1,g,now+3,c});
			break;
		}
	 }
	 printf("unsolvable");
	 return ;
}
