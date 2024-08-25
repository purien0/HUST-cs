#ifndef SAT_H
#define SAT_H

#define NONE 3
#define TRUE 1
#define FALSE 2
#define UNKNOWN 0

#define DEC 1//decision
#define DED 2//deduce
#define CON 3//conflict


#define UNSAT 2
#define SAT 1
#define MAXVARNUM 15000
#define MAXCLANUM 100000

typedef struct literal {//���ֽ�� 
  int data;             // �����ֵ�ֵ
  struct literal *next; // ��һ������
} Literal;

typedef struct clause {//�Ӿ��� 
  Literal *first;     // ��һ������
  struct clause *next; // ��һ���Ӿ�
  int count;
  int t; // ��ֵ��
  int f; // false
} Clause;

typedef struct linklist {//������ 
  Clause *clause;
  struct linklist *next;
} Linklist;

typedef struct trailnode {//���Ľ�� 
  int var;
  int flag;
  Clause *reason;
  int decLevel;
} Tnode;

typedef struct stacknode {//�������õ�ջ�Ľ�� 
  int var;
  Clause *cla;
  int decLevel;
} Snode;

// ��trailѧϰ��ͻ�Ӿ�
void Sat();
void Init();
int DPLL(Clause *head);
void readCNF(Clause *head, FILE *fp);
int getNum(FILE *fp);
void preprocess(Clause *head);
void findUnit(Clause *head);
int abs(int a);
void addLit(Linklist *temp2);
void addCla(Linklist *temp2);
void Add(int var);
int delLit(Clause *head, Linklist *temp, Tnode *trail, int &top);
void delCla(Linklist *temp);
int analyzeCon(Clause *head, Tnode *trail, int &top);
Clause *learnCla(Clause*head,Tnode *trail, int top,int &targetDecisionLevel,int &num);
Clause *resolve(Clause *c1, Clause *c2,int flag);
void putClause(Clause *head, Clause *c);
Tnode searchLast(Tnode *trail, int top);
int isOnlyOne(Clause*res,int top,Tnode *trail); 
int isIn(Clause*res,int var);
void freeCla(Clause *ctemp); 
void tot_free(Clause *head);
void PrintAnswer(int result, char filename[100],int duration);
#endif
