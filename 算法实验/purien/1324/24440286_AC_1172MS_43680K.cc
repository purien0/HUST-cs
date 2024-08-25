#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
 
int POW[7];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
struct Head
{
    int x, y;
};
struct snake
{
    Head head;
    short len;
    short body[7];
    int f, g, h;
}Holedox;
bool mp[25][25];
bool vis[25][25][16400];
short c[25][25][16400];
int f[25][25][16400];
int n, m, L, K;
 
struct cmp
{
    int operator () (const snake& a, const snake& b)
    {
        if (a.f == b.f)
            return a.g > b.g;
        return a.f > b.f;
    }
};
 
int GetH(const snake& now)
{
    return abs(now.head.x-1) + abs(now.head.y-1);
}
 
int GetS(const snake& now)
{
    int ret = 0;
    for (int i=0; i<now.len; i++)
        ret += now.body[i]*POW[i];
    return ret;
}
 
bool next(const snake& now, snake& New, int i)
{
    int newx = now.head.x+dx[i];
    int newy = now.head.y+dy[i];
    if (newx < 1 || newx > n || newy < 1 || newy > m)
        return false;
    if (!mp[newx][newy])
        return false;
    int nowx = now.head.x, nowy = now.head.y;
    for (int i=0; i<now.len; i++)
    {
        nowx += dx[now.body[i]]; nowy += dy[now.body[i]];
        if (nowx == newx && nowy == newy)
            return false;
    }
 
    New.head.x = newx; New.head.y = newy;
    New.body[0] = (i+2) % 4;
    for (int i=1; i<now.len; i++)
        New.body[i] = now.body[i-1];
    New.len = now.len;
    return true;
}
 
int Astar()
{
    memset(c,0,sizeof(c));
    priority_queue<snake, vector<snake>, cmp >Q;
 
    int s = GetS(Holedox);
    c[Holedox.head.x][Holedox.head.y][s] = 1;
    Holedox.f = Holedox.h = GetH(Holedox);
    f[Holedox.head.x][Holedox.head.y][s] = Holedox.f;
    Holedox.g = 0;
    Q.push(Holedox);
    while (!Q.empty())
    {
        snake now = Q.top();
        Q.pop();
 
        if (now.head.x == 1 && now.head.y == 1)
            return now.g;
 
        snake New;
        for (int i=0; i<4; i++)
            if (next(now,New,i))
        {
            s = GetS(New);
            New.g = now.g + 1;
            New.h = GetH(New);
            New.f = New.g + New.h;
 
            if (c[New.head.x][New.head.y][s] == 1)
            {
                if (New.f < f[New.head.x][New.head.y][s])
                {
                    f[New.head.x][New.head.y][s] = New.f;
                    Q.push(New);
                }
            }
            else if (c[New.head.x][New.head.y][s] == 2)
            {
                if (New.f < f[New.head.x][New.head.y][s])
                {
                    f[New.head.x][New.head.y][s] = New.f;
                    c[New.head.x][New.head.y][s] = 1;
                    Q.push(New);
                }
            }
            else
            {
                f[New.head.x][New.head.y][s] = New.f;
                c[New.head.x][New.head.y][s] = 1;
                Q.push(New);
            }
 
        }
        c[now.head.x][now.head.y][s] = 2;
    }
 
    return -1;
}
 
int main()
{
    int cnt = 0;
 
    POW[0] = 1;
    for (int i=1; i<7; i++)
        POW[i] = POW[i-1]*4;
 
    while (scanf("%d%d%d",&n,&m,&L))
    {
        if (n == 0 && m == 0 && L == 0)
            break;
 
        cnt++;
 
        Holedox.len = L-1;
        scanf("%d%d",&Holedox.head.x,&Holedox.head.y);
        int lastx = Holedox.head.x, lasty = Holedox.head.y;
        for (int i=0; i<L-1; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            switch (x-lastx)
            {
                case -1: Holedox.body[i] = 0; break;
                case 1 : Holedox.body[i] = 2; break;
                case 0 : Holedox.body[i] = y-lasty == -1 ? 3 : 1;
            }
            lastx = x; lasty = y;
        }
        memset(mp,true,sizeof(mp));
        scanf("%d",&K);
        for (int i=0; i<K; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            mp[x][y] = false;
        }
 
        int ans = Astar();
 
        printf("Case %d: %d\n",cnt, ans);
    }
 
    return 0;
}