#ifndef SAT_H
#define SAT_H

#define MAXVARNUM 10000
#define MAXCLAUSE 280000
#define NONE 3

#define TRUE 1
#define FALSE 2
#define UNKNOWN 0

#define UNSAT 2
#define SAT 1
typedef struct literal {
  int data;             // 该文字的值
  struct literal *next; // 下一个文字
} Literal;
typedef struct claus {
  Literal *first;     // 第一个文字
  struct claus *next; // 下一条子句
  int count;
  int t; // 真值数
  int f; // false
} Clause;
typedef struct linklist {
  Clause *clause;
  struct linklist *next;
} Linklist;
typedef struct answer{
	int ans[MAXVARNUM];
	int searched[MAXVARNUM];
	int numVar;
	int numCla;
}SatAns;
typedef struct {
	Linklist *pos[MAXVARNUM];
	Linklist *neg[MAXVARNUM];
	int satclanum;
	int posnum[MAXVARNUM];
	int negnum[MAXVARNUM];
	int queue[MAXVARNUM]; // 放单子句
	int front;            // back指向下一个位置
	int back;
}Extern_variable;
void tot_free(SatAns &ans,Extern_variable &ex_var,Clause *head);
int getNum(FILE *fp);
int abs(int a);
void preprocess(SatAns &ans,Extern_variable &ex_var,Clause *head);
void readCNF(SatAns &ans,Extern_variable &ex_var,Clause *head, FILE *fp);
void addLit(Linklist *temp2);
void addCla(Extern_variable &ex_var,Linklist *temp2);
void Add(SatAns &ans,Extern_variable &ex_var,int var);
void reset(SatAns &ans,Extern_variable &ex_var,int *stack1, int *stack2, int top1, int &top2);
int delLit(SatAns &ans,Extern_variable &ex_var,Linklist *temp, int *stack1, int *stack2, int &top1, int &top2);
void delCla(SatAns &ans,Extern_variable &ex_var,Linklist *temp);
void printans(SatAns &ans);
int opsit(SatAns &ans,Extern_variable &ex_var,int var, int *stack1, int *stack2, int &top1,int &top2);
int Del(SatAns &ans,Extern_variable &ex_var,int var,int *stack1,int*stack2,int & top1,int &top2,int flag);
int anal_con(SatAns &ans,Extern_variable &ex_var,int &isconflict,int *stack1,int *stack2,int &top1,int &top2);
int nextDecision(SatAns &ans,Extern_variable &ex_var);
int DPLL(SatAns &ans,Extern_variable &ex_var,Clause *head);
void init(SatAns &ans,Extern_variable &ex_var,Clause *&chead);
void Sat();

#endif
