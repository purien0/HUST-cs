#ifndef HEAD_H
#define HEAD_H

#define UNVISITED 0//标记结点状态
#define OPEN 1//在OPENLIST
#define CLOSED 2//在CLOSEDLIST
#define ANS 3//是最终答案路径上的结点
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
#include<ctime>
#include<windows.h>
using namespace std;
extern const int tar;//目标康托值
extern int open_num,closed_num;
extern int path_length;
extern int op;
extern unsigned char visit[362881];//标记各状态的结点的状态
extern char p[362881];
struct node
{
	int dis;//步骤数
	int f;//启发函数值 
	int now;//空格当前所处的位置 
	int state;//用康托值表示当前状态 
	bool operator<(const struct node b)const
	{
		return dis+f>b.dis+b.f;
	}
};
struct PATH
{
    int dis;//此时
    int f;//启发函数值
    int k;//下一个编号，编号为0则为终点
    int op;//操作类型
};
extern struct PATH Path[362881];//记录路径
extern priority_queue<struct node> q;
bool check(char*s,int now);//检查是否有答案 
int randomize(char*s);//
void solve(int op);
int Contor(char *a);
void incontor(char*res,int x);
void swap(int &a,int &b);
int linear_conflict(int contor);
int Mdis(int x,int y,int i); 
void reset();
void printTree();
#endif
