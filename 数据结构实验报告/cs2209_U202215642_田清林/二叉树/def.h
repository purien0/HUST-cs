#ifndef DEF_H
#define DEF_H
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h> 

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;//状态定义 
typedef int KeyType; //数据元素类型定义
typedef struct {
    KeyType  key;
    char others[20];
} TElemType; //二叉树结点类型定义


typedef struct BiTNode
{//二叉链表结点的定义
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

typedef struct 
{//多二叉树管理的定义 
    struct
	{
		char name[30];
		BiTree T;
	} elem[20];
	int length; 
    int size;
} BITREES; 
#endif
