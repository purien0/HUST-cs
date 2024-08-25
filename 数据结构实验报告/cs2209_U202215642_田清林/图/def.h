#ifndef DEF_H
#define DEF_H
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define INFINITY INT_MAX

typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct {
    KeyType  key;
    char others[20];
} VertexType; //�������Ͷ���


typedef struct ArcNode {         //�������Ͷ���
   			int adjvex;              //����λ�ñ�� 
    	 struct ArcNode  *nextarc;	   //��һ������ָ��
} ArcNode;
typedef struct VNode{				//ͷ��㼰���������Ͷ���
   	VertexType data;       	//������Ϣ
    ArcNode *firstarc;      	 //ָ���һ����
} VNode,AdjList[MAX_VERTEX_NUM];
    	
typedef  struct {  //�ڽӱ�����Ͷ���
    AdjList vertices;     	 //ͷ�������
    int vexnum,arcnum;   	  //������������
    GraphKind  kind;        //ͼ������
} ALGraph;


typedef struct 
{//��ͼ����Ķ��� 
    struct
	{
		char name[30];
		ALGraph G;
	} elem[20];
	int length; //ͼ������ 
    int size;//ͼ�������Ŀ 
} ALGRAPHS; 
#endif
