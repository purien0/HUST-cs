#include "HEAD.H"
#include "waitingdia.h"
#include "ui_waitingdia.h"
int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};//康托展开用到的阶乘


bool check(char*s)//检查是否有答案
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
int randomize(char*s)
{
    int now;
    srand(time(0));
    for(int i = 0; i < 9; i++)
    s[i] = i;
    for(int i = 0; i < 9; i++)
    {
        swap(s[i],s[rand()%(9-i)+i]);
    }
    for(int i = 0; i < 9; i++)
    if(!s[i])
    now = i;
    while(!check(s))
    {
        swap(s[0],s[rand()%9]);
        for(int i = 0; i < 9; i++)
        if(!s[i])
        now = i;
    }
    return now;
}
priority_queue<struct node> q;
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
int linear_conflict(int contor)//返回某状态的linear_conflict数
{
        char state[9];
        incontor(state,contor);
        int count = 0;
        int c[3];
        for(int i = 0 ; i < 3;i++)
            c[i] = 0;
        for(int i = 0; i < 9; i++)
        {
            if(!state[i])
            continue;
            for(int j = i + 1;j/3==i/3;j++)
            {//现在是同一行
                if(!state[j])
                continue;
                if((state[i]-1)/3!=(state[j]-1)/3||(state[i]-1)/3!=i/3)
                continue;//目标是同一行，且现在和目标都在同一行
                if(state[i]>state[j])
                {
                    c[i%3]++;
                    c[j%3]++;//有线性冲突就让两者各加1
                }
            }
            if(i==2||i==5||i==8)
            {
            for(int i = 0 ; i < 3;i++)
            {//检查有没有2
                if(c[i]==2)//存在2则一定与另外两个都产生线性冲突
                {
                    count++;
                    for(int j = 0; j < 3; j++)
                        c[j]--;
                    c[i] = 0;//一步消解
                }
            }
            for(int i = 0 ; i < 3;i++)
            {//检查有没有1
                if(c[i]==1)//存在1
                {
                    count++;
                    break;
                }
            }
            for(int i = 0 ; i < 3;i++)
                c[i] = 0;
            }
        }
        for(int i = 0; i < 9; i+=3)
        {
            if(!state[i])
            continue;
            for(int j = i + 3;j<9;j+=3)
            {
                if(!state[j])
                continue;
                if((state[i]-1)%3!=(state[j]-1)%3||(state[i]-1)%3!=i%3)
                continue;//目标是同一列
                if(state[i]>state[j])
                {
                    c[i/3]++;
                    c[j/3]++;
                    break;
                }
            }
            if(i>=6&&i<=8)
            {
            for(int i = 0 ; i < 3;i++)
            {//检查有没有2
                if(c[i]==2)//存在2则一定与另外两个都产生线性冲突
                {
                    count++;
                    for(int j = 0; j < 3; j++)
                        c[j]--;
                    c[i] = 0;//一步消解冲突
                }
            }
            for(int i = 0 ; i < 3;i++)
            {//检查有没有1
                if(c[i]==1)//还存在1
                {
                    count++;
                    break;
                }
            }
            for(int i = 0 ; i < 3;i++)
                c[i] = 0;
            }
            if(i>=6&&i<=7)
            {
                i = i-5;
            }
        }
        return 2*count;
 }
int Mdis(int x,int y,int i)
{
    return abs(x-i%3)+abs(y-i/3);
}
void reset()
{
    open_num = 1;
    closed_num  = 0;
    path_length = 0;
    memset(visit,0,sizeof(visit));
    while(!q.empty())
    {
        q.pop();
    }
    memset(p,0,sizeof(p));
    memset(Path,0,sizeof(Path));
}
void printTree()
{//利用dot语言将绘制树所需要的信息存入Tree.dot文件中并由graphviz绘制出

    waitingDia wdia;
    wdia.show();
    FILE*fp = fopen("Tree.dot","w");
    if(!fp)
    {printf("error");
        system("pause");
    return;}
    fprintf(fp,"digraph ExampleGraph {\n");
    fprintf(fp,"rankdir = LR\n");
    char state[9];
    for(int i= 0 ; i < 362881;i++)
    {
        if(visit[i]==CLOSED)
        {
            incontor(state,i);
            fprintf(fp,"num%d [shape = record,label = \"{%d|%d|%d}|{%d|%d|%d}|{%d|%d|%d}|{%d+%d}\"]\n",i,state[0],state[1],state[2],state[3],state[4],state[5],state[6],state[7],state[8],Path[i].dis,Path[i].f);
            if(Path[i].k&&(visit[Path[i].k]==CLOSED||visit[Path[i].k] == ANS))
                fprintf(fp,"num%d -> num%d\n",Path[i].k,i);
        }else if(visit[i]==ANS)
        {
            incontor(state,i);
            fprintf(fp,"num%d [shape = record,label = \"{%d|%d|%d}|{%d|%d|%d}|{%d|%d|%d}|{%d+%d}\"]\n",i,state[0],state[1],state[2],state[3],state[4],state[5],state[6],state[7],state[8],Path[i].dis,Path[i].f);
            if(Path[i].k&&(visit[Path[i].k]==CLOSED||visit[Path[i].k] == ANS))
            fprintf(fp,"num%d -> num%d [color=red]\n",Path[i].k,i);
        }
    }
    fprintf(fp,"}");
    fclose(fp);
    system(R"(Graphviz\bin\dot.exe -Tpng Tree.dot -o Tree.png)");
    wdia.close();
    return;
}
void solve(int op)
{
    struct node temp;
    int now;
    int c;//contor
    int cc;
    int x,y;
    int f;
    int d[4] = {-1,1,-3,3};
    char di[4] = {'l','r','u','d'};
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    const int tar = 46234;//目标康托值
    while(!q.empty())
    {
        temp = q.top();
        q.pop();
        if(visit[temp.state] != CLOSED)
        {//队列中同时存在OPEN，将open list内结点移入CLOSED list
            visit[temp.state] = CLOSED;
            closed_num++;
            open_num--;
        }else continue;
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
            if(visit[c]==CLOSED)//已经进入CLOSED则不再入队
            continue;
            switch(op)
            {//根据选用启发函数不同,更新启发函数的值
                case 1://不在正确位置的数量
                    if(state[now+d[i]]==now+d[i]+1)
                    f = temp.f+1;
                    else if(state[now+d[i]]==now+1)
                    f = temp.f-1;
                    else f = temp.f;
                    break;
                case 2://曼哈顿距离
                    f = temp.f - Mdis(x,y,state[now+d[i]]-1) + Mdis(now%3,now/3,state[now+d[i]]-1);
                    break;
                case 3://linear_conflict
                     f = temp.f - Mdis(x,y,state[now+d[i]]-1) + Mdis(now%3,now/3,state[now+d[i]]-1)-linear_conflict(cc)+linear_conflict(c);//dis更新
                     break;
                default:
                    printf("error!\n");
                    return;
            }
            if(!visit[c])//没有访问过
            {
                Path[c].dis = temp.dis+1;
                Path[c].f = f;
                Path[c].k = cc;//上一个
            }
            else
            {
                if(Path[c].dis>temp.dis+1)
                {
                    Path[c].dis = temp.dis+1;
                    Path[c].f = f;
                    Path[c].k = cc;//上一个
                }
            }
            if(c==tar)
            {
                int j = 0;
                for(int i = c;i;i = Path[i].k)
                {
                    visit[i]=ANS;
                    j++;
                }
                path_length = j-1;
                return ;
            }
            q.push({temp.dis+1,f,now+d[i],c});
            if(!visit[c])
            {
                visit[c]=OPEN;
                open_num++;
            }
        }
     }
     printf("error");
     return ;
}
