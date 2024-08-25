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

typedef int status;//״̬���� 
typedef int KeyType; //����Ԫ�����Ͷ���
typedef struct {
    KeyType  key;
    char others[20];
} TElemType; //������������Ͷ���


typedef struct BiTNode
{//����������Ķ���
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

typedef struct 
{//�����������Ķ��� 
    struct
	{
		char name[30];
		BiTree T;
	} elem[20];
	int length; 
    int size;
} BITREES; 
#endif
