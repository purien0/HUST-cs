#ifndef DEF_H
#define DEF_H
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define UNDERFLOW 2
#define NEXIST -3

typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{ // 顺序表（顺序结构）的定义
	ElemType *elem;
	int length;
	int listsize;
} SqList;
typedef struct
{ // 线性表的管理表定义
	struct
	{
		char name[30];
		SqList L;
	} elem[10];
	int length;
	int listsize;
} LISTS;
#endif
