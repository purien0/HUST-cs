#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "SAT.h"
void tot_free(SatAns &ans,Extern_variable &ex_var,Clause *head) {//传入头指针，将空间完全清除 
  Clause *ctemp, *cnext;
  Literal *ltemp, *lnext;
  Linklist *temp, *next;
  ctemp = head->next;
  while (ctemp) {
    cnext = ctemp->next;
    ltemp = ctemp->first;
    while (ltemp) {
      lnext = ltemp->next;
      free(ltemp);
      ltemp = lnext;
    }
    free(ctemp);
    ctemp = cnext;
  }
  for (int i = 1; i < ans.numVar; ++i) {
    temp = ex_var.pos[i];
    while (temp) {
      next = temp->next;
      free(temp);
      temp = next;
    }
    temp = ex_var.neg[i];
    while (temp) {
      next = temp->next;
      free(temp);
      temp = next;
    }
  }
  free(head);
  head = NULL;
}
void findUnit(SatAns &ans,Extern_variable &ex_var,Clause *head) {
  Clause *ctemp = head->next;
	int var;
  Literal * l;
  while (ctemp) {
    if (!ctemp->t && ctemp->count == ctemp->f + 1) {
      l = ctemp->first;
	  while(l)
	  {
	  	if(ans.ans[abs(l->data)]==UNKNOWN)
	  	{
	  		var = l->data;
	  		break; 
		  }
		  l = l->next;
	  }
      ex_var.queue[ex_var.back++] = var;
    }
    ctemp = ctemp->next;
  }
}
int getNum(FILE *fp) { // 这个函数用来读取cnf文件时得到变量数、子句数、后面的内容
  char c;
  int sign = 1, num = 0; // num 用来得到文字的值,sign用来标记文字是正或者负
  fscanf(fp, "%c", &c);
  if (c == '-') {
    sign = -1; // sign变为-1，表示为负文字
    fscanf(fp, "%c", &c);
  } else if (c == '0') { // 表示该条子句结束
    fscanf(fp, "%c", &c);
    if (c == '\r') // 表示换行
      fscanf(fp, "%c", &c);
    return num;        //
  } else if (feof(fp)) // 如果是结束标记
    return 0;
  while (c != ' ' && c != '\n' && c != '\r') {
    num *= 10;
    num += c - '0'; // 得到文字的值
    fscanf(fp, "%c", &c);
  } // 快读
  if (c == '\r')
    fscanf(fp, "%c", &c);
  return sign * num; // 用来得到文字（包括正负和值）
}
int abs(int a) {
  if (a < 0)
    return -a;
  return a;
}
void preprocess(SatAns &ans,Extern_variable &ex_var,Clause *head)
{
	//纯文字处理 
	for(int var = 1; var <= ans.numVar; ++var)
	{
		if(!ex_var.posnum[var])
		{//全是负文字 
			ans.ans[var] = FALSE;
			ans.searched[var] = 1;
			delCla(ans,ex_var,ex_var.neg[var]);
		}else if(!ex_var.negnum[var])
		{//全是正文字 
			ans.ans[var] = TRUE;
			ans.searched[var] = 1;
			delCla(ans,ex_var,ex_var.pos[var]);
		}
	}
	//找单子句
	findUnit(ans,ex_var,head);
}
void readCNF(SatAns &ans,Extern_variable &ex_var,Clause *head, FILE *fp) {
  if (head != NULL)
    init(ans,ex_var,head);
  char c;
  Clause *ctemp, *clast;
  Literal *ltemp, *llast;
  int var = 0;
  int num = 0;
  fscanf(fp, "%c", &c);
  while (c == 'c') { // 忽略注释段
    while (c != '\n' && c != '\r')
      fscanf(fp, "%c", &c);
    fscanf(fp, "%c", &c);
    if (c == '\n')
      fscanf(fp, "%c", &c);
  }
  fscanf(fp, " cnf ");
  ans.numVar = getNum(fp); // 读取变量数，并赋值给numVar
  ans.numCla = getNum(fp); // 读取子句数
  var = getNum(fp);
  while (1) {
    num = 0;
    ctemp = (Clause *)malloc(sizeof(Clause)); // 为ctemp指针分配空间
    while (var) {
      ++num; // 统计每个子句的变元数目
      ltemp = (Literal *)malloc(sizeof(Literal));
      ltemp->data = var; // 文字的值域改成var，赋值
      ltemp->next = NULL;
      if (num == 1) { // 储存子句中首个变量
        ctemp->first = llast = ltemp;
      } else { // 储存子句中非首个变量
        llast->next = ltemp;
        llast = llast->next;
      }
      if (var > 0) {
        Linklist *temp = (Linklist *)malloc(sizeof(Linklist));
        temp->next = ex_var.pos[abs(var)];
        temp->clause = ctemp;
        ex_var.pos[abs(var)] = temp;
        ++ex_var.posnum[abs(var)];
      } else {
        Linklist *temp = (Linklist *)malloc(sizeof(Linklist));
        temp->next = ex_var.neg[abs(var)];
        temp->clause = ctemp;
        ex_var.neg[abs(var)] = temp;
        ++ex_var.negnum[abs(var)];
      }
      var = getNum(fp);
    }
    ctemp->next = head->next;
    ctemp->count = num;
    ctemp->t = 0;
    ctemp->f = 0;
    head->next = ctemp;
    var = getNum(fp);
    // 若到达文件尾，再执行一次z'z 读文件操作时，设置文件结束标志
    if (feof(fp))
      break;
  }
  preprocess(ans,ex_var,head);
}
void addLit(Linklist *temp2) {
  // 对于每个子句，若未满足，去掉一个(取值为f)文字，若已满足，忽略
  while (temp2) { // 去掉一个文字，若子句已经满足则忽略
    --temp2->clause->f;
    temp2 = temp2->next;
  }
}
void addCla(Extern_variable &ex_var,Linklist *temp2) {
  // 去掉一个（true）
  // 执行函数前要将searched数组置0，防止多统计一个文字
  // 对于每个已满足子句（一定），若正文字数目为1，重新统计负文字数目，若正文字数目大于一，去掉一个正文字
  Literal *ltemp;
  int t;
  while (temp2) {
    --temp2->clause->t;
    if (!temp2->clause->t) // 回溯之前别统计了
      --ex_var.satclanum;
    temp2 = temp2->next;
  }
}
void Add(SatAns &ans,Extern_variable &ex_var,int var) {
  ans.searched[abs(var)] = 0;
  ans.ans[abs(var)] = UNKNOWN;
  if (var > 0) {
    addLit(ex_var.neg[abs(var)]);
    addCla(ex_var,ex_var.pos[abs(var)]);
  } else if (var < 0) {
    addLit(ex_var.pos[abs(var)]);
    addCla(ex_var,ex_var.neg[abs(var)]);
  }
}
void reset(SatAns &ans,Extern_variable &ex_var,int *stack1, int *stack2, int top1, int &top2)
// 将stack2中元素不断出栈，直到stack2栈顶元素与stack1栈顶元素相同
// 函数执行后，stack1，stack2目标栈顶元素均未出栈
{
  int var;
  if (!top1) // 若stack1为空栈
    return;
  while (stack1[top1 - 1] != stack2[top2 - 1]) { // 回溯单子句传播过程中的字
    var = stack2[--top2];
    Add(ans,ex_var,var);
  }
}
int delLit(SatAns &ans,Extern_variable &ex_var,Linklist *temp, int *stack1, int *stack2, int &top1, int &top2)
 {
  // 加入一个false
  int var;
  Linklist temp2;
  Literal *ltemp;
  int flag = 0;
  while (temp) {
    ++temp->clause->f;
    if (!flag && !temp->clause->t &&
        temp->clause->count == temp->clause->f + 1) {
      // 删字后得到单子句入队，若发生冲突则不再入队因为最终都要回溯/出队
      ltemp = temp->clause->first;
      while (ltemp) {
        if (ans.ans[abs(ltemp->data)] ==
            UNKNOWN) // 找到第一个未被搜索过的文字就是单子句中唯一的文字
        {
          ex_var.queue[ex_var.back++] = ltemp->data;
          break;
        }
        ltemp = ltemp->next;
      }
    }
    if (temp->clause->count < temp->clause->f + 1) // 说明发生冲突了
    {
      flag = 1; // 完成遍历之后再退出
    }
    temp = temp->next;
  } // 先让delLit产生影响结束再回溯
  if (flag == 1) {
    reset(ans,ex_var,stack1, stack2, top1, top2);
    // 把因为不合理决策产生的备选单子句出队
    while ((ex_var.back - 1) && ex_var.queue[ex_var.back - 1]) // 找到最近的0
      --ex_var.back;
    --ex_var.back; // 去掉0，重新决策
    if (ex_var.front > ex_var.back)
      ex_var.front = ex_var.back;
    return 1;
  }
  return 0;
}
void delCla(SatAns &ans,Extern_variable &ex_var,Linklist *temp) {
  // 若子句未满足，改为已满足；若已满足，增加正文字数目
  while (temp) {
    ++(temp->clause->t);
    if (temp->clause->t == 1)
      ++ex_var.satclanum;
    temp = temp->next;
  }
}
void printans(SatAns &ans) {
  for (int i = 1; i <= ans.numVar; ++i) {
    if(ans.ans[i]==TRUE)
	printf("%d ", i);
	else
	printf("-%d ",i);
  }
  printf("\n");
}
void PrintAnswer(SatAns &ans,int result, char filename[100],int duration) {
    FILE *fp;
	int p = 0;
	while (filename[p] != 0) p++;
	while (filename[p] != '.') p--;
	p++;
	filename[p] = 'r';
	p++;
	filename[p] = 'e';
	p++;
	filename[p] = 's';
	p++;
	filename[p] = 0;
	fp = fopen(filename, "w");
	if(result == 1)
		fprintf(fp, "s 1\r\n");
	else
		fprintf(fp, "s 0\r\n");
	fprintf(fp, "v ");
	for(int i = 1; i <= ans.numVar; i++)
	{
		if(ans.ans[i] == TRUE)
			fprintf(fp, "%d ", i);
		else
			fprintf(fp, "-%d ", i);
	}
	fprintf(fp, "\r\n");
	fprintf(fp, "t %d\r\n",duration);
    fclose(fp);
    printf("The answer has been saved\n");
    printf("duration:%dms\n", duration);
    if(result)
    {
    	printf("One solution of SAT is:\n");
    	printans(ans);
	}
}
int opsit(SatAns &ans,Extern_variable &ex_var,int var, int *stack1, int *stack2, int &top1,
          int &top2) { // 当改变选择时使用，将+改为-，-改为+
  int isconflict = 0;
  Add(ans,ex_var,var);
  isconflict = Del(ans,ex_var,-var,stack1,stack2,top1,top2,1);
  ans.searched[abs(var)] = 2;
  return isconflict;
}
int Del(SatAns &ans,Extern_variable &ex_var,int var,int *stack1,int*stack2,int & top1,int &top2,int flag)
{
	int isconflict = 0;
	if (!var)
        return 0;
    if (ans.searched[abs(var)])
        return 0;
    if(flag)//flag==1时为自由变量 
    {
    	stack1[top1++] = var;
    	ex_var.queue[ex_var.back++] = 0;// 0为每次决策产生单子句的分隔点
	}
	stack2[top2++] = var;
    ans.searched[abs(var)] = 1;
    if (var > 0) {
    	ans.ans[abs(var)] = TRUE;
        delCla(ans,ex_var,ex_var.pos[abs(var)]);
        isconflict = delLit(ans,ex_var,ex_var.neg[abs(var)], stack1, stack2, top1, top2);
      } else {
        ans.ans[abs(var)] = FALSE;
        delCla(ans,ex_var,ex_var.neg[abs(var)]);
        isconflict = delLit(ans,ex_var,ex_var.pos[abs(var)], stack1, stack2, top1, top2);
      }
    return isconflict;
	
 } 
 int anal_con(SatAns &ans,Extern_variable &ex_var,int &isconflict,int *stack1,int *stack2,int &top1,int &top2)
 {
 	int var;
	 while (isconflict) {
        // 找到上一次决策的文字
        if (!top1)
          return UNSAT;
        var = stack1[--top1];
        --top2; // 决策结点同步出栈stack2
        if (ans.searched[abs(var)] == 1) {
          isconflict = opsit(ans,ex_var,var, stack1, stack2, top1, top2);
        } else if (ans.searched[abs(var)] == 2) {
          while (ans.searched[abs(var)] == 2) // 找到一个可以反转的
          {
            Add(ans,ex_var,var);
            if (!top1)
              return UNSAT;
            reset(ans,ex_var,stack1, stack2, top1, top2);
            --top2; // 决策结点出stack2
            // 把因为不合理决策产生的备选单子句出队
            while ((ex_var.back - 1) && ex_var.queue[ex_var.back - 1]) // 找到最近的0
              --ex_var.back;
            --ex_var.back; // 去掉0
            if (ex_var.front > ex_var.back)
              ex_var.front = ex_var.back;
            var = stack1[--top1];
          }
          isconflict = opsit(ans,ex_var,var, stack1, stack2, top1, top2);
        }
      }
 }
int nextDecision(SatAns &ans,Extern_variable &ex_var)
{
 	int max = 0;
    int maxi = 0;
    int  i;
    for (i = 1; i <= ans.numVar; ++i)
      if (ans.ans[i] == UNKNOWN&& max <= ex_var.posnum[i]) {
			max = ex_var.posnum[i];
			maxi = i;
      }
    for (i = 1; i <= ans.numVar; ++i)
      if (ans.ans[i] == UNKNOWN&& max <= ex_var.negnum[i]) {
			max = ex_var.negnum[i];
			maxi = -i;
		}
	return maxi;
 }
int DPLL(SatAns &ans,Extern_variable &ex_var,Clause *head) {
  int stack1[ans.numVar + 10]; // 用来回溯
  int stack2[ans.numVar + 10]; // 大
  int top1 = 0;
  int top2 = 0;
  int var;
  int isconflict = 0;
  Linklist *temp, *temp2;
  Literal *ltemp;
  Clause *ctemp;
  clock_t start, now;
  start = clock(); 
  while (ex_var.satclanum < ans.numCla) {
  	now = clock();
  	if(now-start>60000)//大于60s返回
	return UNSAT; 
    while (ex_var.front < ex_var.back) { // 单子句传播
      var = ex_var.queue[ex_var.front++];
      isconflict = Del(ans,ex_var,var,stack1,stack2,top1,top2,0);
      if(isconflict)
      {
      	if(anal_con(ans,ex_var,isconflict,stack1,stack2,top1,top2)==UNSAT)
      	return UNSAT;
	  }
    }
    var = nextDecision(ans,ex_var);//下一个 
    if (!var)
      return SAT; 
    isconflict = Del(ans,ex_var,var,stack1,stack2,top1,top2,1);
    if(isconflict)
	{
      	if(anal_con(ans,ex_var,isconflict,stack1,stack2,top1,top2)==UNSAT)
      	return UNSAT;
	}
  }
  return SAT;
}
void init(SatAns &ans,Extern_variable &ex_var,Clause *&head)
{
	head = (Clause *)malloc(sizeof(Clause));
  	head->next = NULL;
  	//初始化ans 
  	ans.numCla = 0;
  	ans.numVar = 0;
  	memset(ans.ans,0,MAXVARNUM*sizeof(int));
  	memset(ans.searched,0,MAXVARNUM*sizeof(int));
  	//初始化ex_var
  	ex_var.front = 0;
	ex_var.back = 0;
	 ex_var.satclanum = 0;
	memset(ex_var.pos,0,MAXVARNUM*sizeof(Linklist*));
	memset(ex_var.neg,0,MAXVARNUM*sizeof(Linklist*));
	memset(ex_var.posnum,0,MAXVARNUM*sizeof(int));
	memset(ex_var.negnum,0,MAXVARNUM*sizeof(int));
}
void Sat()
{
	Clause *head = NULL;
  clock_t start, finish;
  int duration;
  int result;
  char filename[100];
  printf("Please input the file address:\n");
  scanf("%s", filename);
  FILE *fp;
  fp = fopen(filename, "r");
  if (!fp) {
    printf("Failed to open the file\n");
    return;
  }
  Extern_variable ex_var;
	SatAns ans;
  init(ans,ex_var,head);
  readCNF(ans,ex_var,head, fp);
  fclose(fp);
  start = clock();
  result = DPLL(ans,ex_var,head);
  finish = clock();
  duration = finish - start;
  if(duration > 60000)
  {
  	printf("Time out\n");
  	printf("Your runtime is larger than 60s!\n");
  }
  else if (result == SAT) {
    printf("Satisfiable!\n");
    PrintAnswer(ans,1,filename,duration);
  } else
    {
    	printf("Unsatisfiable!\n");
		PrintAnswer(ans,0,filename,duration);
	}
  tot_free(ans,ex_var,head);
  system("pause");
  system("cls");
}
