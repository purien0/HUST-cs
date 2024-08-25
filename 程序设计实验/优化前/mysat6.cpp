#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "SAT.h"
void tot_free(SatAns &ans,Extern_variable &ex_var,Clause *head) {//����ͷָ�룬���ռ���ȫ��� 
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
int getNum(FILE *fp) { // �������������ȡcnf�ļ�ʱ�õ����������Ӿ��������������
  char c;
  int sign = 1, num = 0; // num �����õ����ֵ�ֵ,sign������������������߸�
  fscanf(fp, "%c", &c);
  if (c == '-') {
    sign = -1; // sign��Ϊ-1����ʾΪ������
    fscanf(fp, "%c", &c);
  } else if (c == '0') { // ��ʾ�����Ӿ����
    fscanf(fp, "%c", &c);
    if (c == '\r') // ��ʾ����
      fscanf(fp, "%c", &c);
    return num;        //
  } else if (feof(fp)) // ����ǽ������
    return 0;
  while (c != ' ' && c != '\n' && c != '\r') {
    num *= 10;
    num += c - '0'; // �õ����ֵ�ֵ
    fscanf(fp, "%c", &c);
  } // ���
  if (c == '\r')
    fscanf(fp, "%c", &c);
  return sign * num; // �����õ����֣�����������ֵ��
}
int abs(int a) {
  if (a < 0)
    return -a;
  return a;
}
void preprocess(SatAns &ans,Extern_variable &ex_var,Clause *head)
{
	//�����ִ��� 
	for(int var = 1; var <= ans.numVar; ++var)
	{
		if(!ex_var.posnum[var])
		{//ȫ�Ǹ����� 
			ans.ans[var] = FALSE;
			ans.searched[var] = 1;
			delCla(ans,ex_var,ex_var.neg[var]);
		}else if(!ex_var.negnum[var])
		{//ȫ�������� 
			ans.ans[var] = TRUE;
			ans.searched[var] = 1;
			delCla(ans,ex_var,ex_var.pos[var]);
		}
	}
	//�ҵ��Ӿ�
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
  while (c == 'c') { // ����ע�Ͷ�
    while (c != '\n' && c != '\r')
      fscanf(fp, "%c", &c);
    fscanf(fp, "%c", &c);
    if (c == '\n')
      fscanf(fp, "%c", &c);
  }
  fscanf(fp, " cnf ");
  ans.numVar = getNum(fp); // ��ȡ������������ֵ��numVar
  ans.numCla = getNum(fp); // ��ȡ�Ӿ���
  var = getNum(fp);
  while (1) {
    num = 0;
    ctemp = (Clause *)malloc(sizeof(Clause)); // Ϊctempָ�����ռ�
    while (var) {
      ++num; // ͳ��ÿ���Ӿ�ı�Ԫ��Ŀ
      ltemp = (Literal *)malloc(sizeof(Literal));
      ltemp->data = var; // ���ֵ�ֵ��ĳ�var����ֵ
      ltemp->next = NULL;
      if (num == 1) { // �����Ӿ����׸�����
        ctemp->first = llast = ltemp;
      } else { // �����Ӿ��з��׸�����
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
    // �������ļ�β����ִ��һ��z'z ���ļ�����ʱ�������ļ�������־
    if (feof(fp))
      break;
  }
  preprocess(ans,ex_var,head);
}
void addLit(Linklist *temp2) {
  // ����ÿ���Ӿ䣬��δ���㣬ȥ��һ��(ȡֵΪf)���֣��������㣬����
  while (temp2) { // ȥ��һ�����֣����Ӿ��Ѿ����������
    --temp2->clause->f;
    temp2 = temp2->next;
  }
}
void addCla(Extern_variable &ex_var,Linklist *temp2) {
  // ȥ��һ����true��
  // ִ�к���ǰҪ��searched������0����ֹ��ͳ��һ������
  // ����ÿ���������Ӿ䣨һ����������������ĿΪ1������ͳ�Ƹ�������Ŀ������������Ŀ����һ��ȥ��һ��������
  Literal *ltemp;
  int t;
  while (temp2) {
    --temp2->clause->t;
    if (!temp2->clause->t) // ����֮ǰ��ͳ����
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
// ��stack2��Ԫ�ز��ϳ�ջ��ֱ��stack2ջ��Ԫ����stack1ջ��Ԫ����ͬ
// ����ִ�к�stack1��stack2Ŀ��ջ��Ԫ�ؾ�δ��ջ
{
  int var;
  if (!top1) // ��stack1Ϊ��ջ
    return;
  while (stack1[top1 - 1] != stack2[top2 - 1]) { // ���ݵ��Ӿ䴫�������е���
    var = stack2[--top2];
    Add(ans,ex_var,var);
  }
}
int delLit(SatAns &ans,Extern_variable &ex_var,Linklist *temp, int *stack1, int *stack2, int &top1, int &top2)
 {
  // ����һ��false
  int var;
  Linklist temp2;
  Literal *ltemp;
  int flag = 0;
  while (temp) {
    ++temp->clause->f;
    if (!flag && !temp->clause->t &&
        temp->clause->count == temp->clause->f + 1) {
      // ɾ�ֺ�õ����Ӿ���ӣ���������ͻ���������Ϊ���ն�Ҫ����/����
      ltemp = temp->clause->first;
      while (ltemp) {
        if (ans.ans[abs(ltemp->data)] ==
            UNKNOWN) // �ҵ���һ��δ�������������־��ǵ��Ӿ���Ψһ������
        {
          ex_var.queue[ex_var.back++] = ltemp->data;
          break;
        }
        ltemp = ltemp->next;
      }
    }
    if (temp->clause->count < temp->clause->f + 1) // ˵��������ͻ��
    {
      flag = 1; // ��ɱ���֮�����˳�
    }
    temp = temp->next;
  } // ����delLit����Ӱ������ٻ���
  if (flag == 1) {
    reset(ans,ex_var,stack1, stack2, top1, top2);
    // ����Ϊ��������߲����ı�ѡ���Ӿ����
    while ((ex_var.back - 1) && ex_var.queue[ex_var.back - 1]) // �ҵ������0
      --ex_var.back;
    --ex_var.back; // ȥ��0�����¾���
    if (ex_var.front > ex_var.back)
      ex_var.front = ex_var.back;
    return 1;
  }
  return 0;
}
void delCla(SatAns &ans,Extern_variable &ex_var,Linklist *temp) {
  // ���Ӿ�δ���㣬��Ϊ�����㣻�������㣬������������Ŀ
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
          int &top2) { // ���ı�ѡ��ʱʹ�ã���+��Ϊ-��-��Ϊ+
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
    if(flag)//flag==1ʱΪ���ɱ��� 
    {
    	stack1[top1++] = var;
    	ex_var.queue[ex_var.back++] = 0;// 0Ϊÿ�ξ��߲������Ӿ�ķָ���
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
        // �ҵ���һ�ξ��ߵ�����
        if (!top1)
          return UNSAT;
        var = stack1[--top1];
        --top2; // ���߽��ͬ����ջstack2
        if (ans.searched[abs(var)] == 1) {
          isconflict = opsit(ans,ex_var,var, stack1, stack2, top1, top2);
        } else if (ans.searched[abs(var)] == 2) {
          while (ans.searched[abs(var)] == 2) // �ҵ�һ�����Է�ת��
          {
            Add(ans,ex_var,var);
            if (!top1)
              return UNSAT;
            reset(ans,ex_var,stack1, stack2, top1, top2);
            --top2; // ���߽���stack2
            // ����Ϊ��������߲����ı�ѡ���Ӿ����
            while ((ex_var.back - 1) && ex_var.queue[ex_var.back - 1]) // �ҵ������0
              --ex_var.back;
            --ex_var.back; // ȥ��0
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
  int stack1[ans.numVar + 10]; // ��������
  int stack2[ans.numVar + 10]; // ��
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
  	if(now-start>60000)//����60s����
	return UNSAT; 
    while (ex_var.front < ex_var.back) { // ���Ӿ䴫��
      var = ex_var.queue[ex_var.front++];
      isconflict = Del(ans,ex_var,var,stack1,stack2,top1,top2,0);
      if(isconflict)
      {
      	if(anal_con(ans,ex_var,isconflict,stack1,stack2,top1,top2)==UNSAT)
      	return UNSAT;
	  }
    }
    var = nextDecision(ans,ex_var);//��һ�� 
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
  	//��ʼ��ans 
  	ans.numCla = 0;
  	ans.numVar = 0;
  	memset(ans.ans,0,MAXVARNUM*sizeof(int));
  	memset(ans.searched,0,MAXVARNUM*sizeof(int));
  	//��ʼ��ex_var
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
