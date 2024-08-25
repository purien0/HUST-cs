//�ı�ѡȡ���ԣ����ǵ���ͻ�������߲�ͳ�ͻ����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "mySAT.h"
int numVar;//������Ŀ 
int conflictnum;//���ֳ�ͻ����Ŀ 
int numCla;//�Ӿ���Ŀ 
int assigned[MAXVARNUM];
double posac[MAXVARNUM];//��������ԣ�����ѡ����߽ڵ㣩 
double negac[MAXVARNUM];//��������� 
Linklist *pos[MAXVARNUM];//�����������Ӿ��ָ�� 
Linklist *neg[MAXVARNUM];//�Ӹ��������Ӿ��ָ�� 
int ans[MAXVARNUM];//ÿ������ȡֵ 
int satclanum;//������Ӿ���Ŀ 
Snode stack[MAXVARNUM]; // �ŵ��Ӿ�
int back;// backָ����һ��λ��
int decLevel;//���߲���� 
int mark[MAXVARNUM];
int posconTimes[MAXVARNUM];
int negconTimes[MAXVARNUM];

void freeCla(Clause *ctemp) {
//�ͷ��Ӿ�Ŀռ� 
  Literal *ltemp, *lnext;
  ltemp = ctemp->first;
  while (ltemp) {
    lnext = ltemp->next;
    free(ltemp);
    ltemp = lnext;
  }
  free(ctemp);
}
void tot_free(Clause *head) {
//����������ռ��ͷ� 
  Clause *ctemp, *cnext;
  Literal *ltemp, *lnext;
  Linklist *temp, *next;
  ctemp = head->next;
  while (ctemp) {
    cnext = ctemp->next;
    freeCla(ctemp);
    ctemp = cnext;
  }
  for (int i = 1; i <= numVar; ++i) {
    temp = pos[i];
    while (temp) {
      next = temp->next;
      free(temp);
      temp = next;
    }
    temp = neg[i];
    while (temp) {
      next = temp->next;
      free(temp);
      temp = next;
    }
  }
  free(head);
}
int getNum(
FILE *fp) { // �������������ȡcnf�ļ�ʱ�õ����������Ӿ��������������
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
void findUnit(Clause *head) {
//�ҵ��Ӿ䲢����� 
  Clause *ctemp = head->next;
  Snode stemp;
  Literal * l;
  while (ctemp) {
    if (!ctemp->t && ctemp->count == ctemp->f + 1) {
      l = ctemp->first;
	  while(l)
	  {
	  	if(ans[abs(l->data)]==UNKNOWN)
	  	{
	  		stemp.var = l->data;
	  		break; 
		  }
		  l = l->next;
	  }
      stemp.cla = ctemp;
      stemp.decLevel = decLevel;
      stack[back++] = stemp;
    }
    ctemp = ctemp->next;
  }
}
void preprocess(Clause *head) {
//Ԥ���� 
  // �����ִ���
  for (int var = 1; var <= numVar; ++var) {
    if (!posac[var]) { // ȫ�Ǹ�����
      ans[var] = FALSE;
      delCla(neg[var]);
    } else if (!negac[var]) { // ȫ��������
      ans[var] = TRUE;
      delCla(pos[var]);
    }
  }
  // �ҵ��Ӿ�
  findUnit(head);
}
void Init() 
{//��ʼ�� 
	numVar = 0;
	conflictnum = 0;
	numCla = 0;
	memset(assigned,0,sizeof(int)*MAXVARNUM);
	memset(posac,0,sizeof(double)*MAXVARNUM);
	memset(negac,0,sizeof(double)*MAXVARNUM);
	memset(pos,0,sizeof(Linklist *)*MAXVARNUM);
	memset(neg,0,sizeof(Linklist *)*MAXVARNUM);
	memset(ans,0,sizeof(int)*MAXVARNUM);
	satclanum = 0;
	memset(stack,0,sizeof(Snode)*MAXVARNUM);
	back = 0;
	decLevel = 0;
	memset(mark,0,sizeof(int)*MAXVARNUM);
	memset(posconTimes,0,sizeof(int)*MAXVARNUM);
	memset(negconTimes,0,sizeof(int)*MAXVARNUM);
}
void readCNF(Clause *head, FILE *fp) {
//��ȡCNF�ļ� 
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
  numVar = getNum(fp); // ��ȡ������������ֵ��numVar
  numCla = getNum(fp); // ��ȡ�Ӿ���
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
        temp->next = pos[abs(var)];
        temp->clause = ctemp;
        pos[abs(var)] = temp;
        ++posac[abs(var)];
      } else {
        Linklist *temp = (Linklist *)malloc(sizeof(Linklist));
        temp->next = neg[abs(var)];
        temp->clause = ctemp;
        neg[abs(var)] = temp;
        ++negac[abs(var)];
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
  preprocess(head);
}
void addLit(Linklist *temp2) {
  // ����ÿ���Ӿ䣬��δ���㣬ȥ��һ��(ȡֵΪf)���֣��������㣬����
  while (temp2) { // ȥ��һ�����֣����Ӿ��Ѿ����������
    --temp2->clause->f;
    temp2 = temp2->next;
  }
}
void addCla(Linklist *temp2) {
  // ȥ��һ����true��
  // ����ÿ���������Ӿ䣨һ����������������ĿΪ1������ͳ�Ƹ�������Ŀ������������Ŀ����һ��ȥ��һ��������
  Literal *ltemp;
  int t;
  while (temp2) {
    --temp2->clause->t;
    if (!temp2->clause->t) // ����֮ǰ��ͳ����
      --satclanum;
    temp2 = temp2->next;
  }
}
void Add(int var) {
//addLit��addCla������һ�����/��װ 
  ans[abs(var)] = UNKNOWN;
  if (var > 0) {
    addLit(neg[abs(var)]);
    addCla(pos[abs(var)]);
  } else if (var < 0) {
    addLit(pos[abs(var)]);
    addCla(neg[abs(var)]);
  }
}
int delLit(Clause *head, Linklist *temp, Tnode *trail, int &top) {
  // ����һ��false
  Tnode ttemp;
  Snode stemp;
  int var;
  Literal *ltemp;
  int flag = 0;
  int isconflict = 0;
  while (temp) {
    ++temp->clause->f;
    if (!flag && !temp->clause->t &&
        temp->clause->count == temp->clause->f + 1) {
      // ɾ�ֺ�õ����Ӿ���ӣ���������ͻ���������Ϊ���ն�Ҫ����/����
      ltemp = temp->clause->first;
      while (ltemp) {
        if (ans[abs(ltemp->data)] ==
            UNKNOWN) // �ҵ���һ��δ�������������־��ǵ��Ӿ���Ψһ������
        {
          stemp.var = ltemp->data;
          stemp.cla = temp->clause;
          stemp.decLevel = decLevel;
          stack[back++] = stemp;
          break;
        }
        ltemp = ltemp->next;
      }
    }
    if (!flag&&temp->clause->count < temp->clause->f + 1) // ˵��������ͻ��
    {
      flag = 1; // ��ɱ���֮�����˳�
      ttemp.var = 0;
      ttemp.flag = CON;
      ttemp.reason = temp->clause;
      ttemp.decLevel = decLevel;
      trail[top++] = ttemp; // ��ͻ�Ӿ���ջ
    }
    temp = temp->next;
  } // ����delLit����Ӱ������ٻ���
  if (flag == 1) {
    isconflict = analyzeCon(head, trail, top);
  }
  return isconflict;
}
void delCla(Linklist *temp) {
  // ���Ӿ�δ���㣬��Ϊ�����㣻�������㣬������������Ŀ
  while (temp) {
    ++temp->clause->t;
    if (temp->clause->t == 1)
      ++satclanum;
    temp = temp->next;
  }
}
Tnode searchLast(Tnode *trail, int top) {
//�ҵ���һ�����߽�� 
  Tnode ttemp;
  ttemp.var = 0;
  while (top && trail[top - 1].flag != DEC)
    --top;
  if (!top)
    return ttemp;
  ttemp = trail[top - 1];
  return ttemp;
}
int DPLL(Clause *head) {
  Tnode trail[numVar + 10]; // ·��
  int top = 0;
  int var;
  int times = 0;
  int maxi;
  double dmax;
  int flag = 0;
  int isconflict = 0;
  Linklist *temp, *temp2;
  Literal *ltemp;
  Clause *ctemp;
  Tnode ttemp;
  Snode stemp;
  satclanum = 0;
  int assign;
  int i;
  while (satclanum < numCla) {
	while (back) { // ���Ӿ䴫��
      stemp = stack[--back];
      var = stemp.var;
      if (!var)
        continue;
      if (ans[abs(var)] != UNKNOWN)
        continue;
      ttemp.flag = DED;
      ttemp.var = var;
      ttemp.reason = stemp.cla;
      ttemp.decLevel = decLevel;
      trail[top++] = ttemp;
      if (var > 0) {
        ans[abs(var)] = TRUE;
        delCla(pos[abs(var)]);
        isconflict = delLit(head, neg[abs(var)], trail, top);
      } else {
        ans[abs(var)] = FALSE;
        delCla(neg[abs(var)]);
        isconflict = delLit(head, pos[abs(var)], trail, top);
      }
      if(isconflict == UNSAT)
    return UNSAT;
    }
    maxi = 0;
    dmax = 0.0;
      srand((unsigned)time(NULL));
    for (int i = 1; i <= numVar; ++i)
      if (ans[i] == UNKNOWN&&dmax <= posac[i]) {
        if(dmax==posac[i]&&(rand()%2))
		{
		maxi = i;
		}
		if(dmax < posac[i])
		{
			dmax = posac[i];
		maxi = i;
		}
      }
    for (int i = 1; i <= numVar; ++i)
      if (ans[i] == UNKNOWN&&dmax <= negac[i]) {
        if(dmax==negac[i]&&(rand()%2))
		{
			dmax = negac[i];
			maxi = -i;
		}
		else if(dmax<negac[i])
		{
			dmax = negac[i];
		maxi = -i;
		}
      }
    if(!maxi)
    return SAT;
    var = maxi;
    ++decLevel;
    ttemp.flag = DEC;
    ttemp.reason = NULL;
    ttemp.decLevel = decLevel;
    if (var>0) {
    	assigned[abs(var)]++;
      ans[abs(var)] = TRUE; // �ȼٶ�Ϊ��
      ttemp.var = var;
      trail[top++] = ttemp; // ָ��Ϊ��
      delCla(pos[abs(var)]);
      isconflict = delLit(head, neg[abs(var)], trail, top);
    } else {
    	assigned[abs(var)]++;
      ans[abs(var)] = FALSE; // �ȼٶ�Ϊ��
      ttemp.var = var;
      trail[top++] = ttemp;
      delCla(neg[abs(var)]);
      isconflict = delLit(head, pos[abs(var)], trail, top);
    }
    if(isconflict ==UNSAT)
    return UNSAT;
    times++;
  }
  return SAT;
}
Clause *resolve(Clause *c1, Clause *c2,
                int flag) { 
// ���ϲ�������flag==1ʱ�ͷ�c2
  if(!c1||!c2)
  return NULL; 
  int len = c1->count + c2->count;
  int num[len];
  int i = 0;
  Literal *l1;
  l1 = c1->first;
  while (l1) {
    num[i++] = l1->data;
    mark[abs(l1->data)] = l1->data;
    l1 = l1->next;
  }
  l1 = c2->first;
  while (l1) {
    num[i++] = l1->data;
    if (mark[abs(l1->data)] == -l1->data) { // �෴������
      mark[abs(l1->data)] = 0;
    } else if (!mark[abs(l1->data)]) // û���������
      mark[abs(l1->data)] = l1->data;
    // ��ͬ�ϲ��������ò���
    l1 = l1->next;
  }
  Clause *res = (Clause *)malloc(sizeof(Clause));
  int count = 0;
  Literal *l;
  Literal *llast;
  res->next = NULL;
  res->f = 0;
  res->t = 0;
  for (i = 0; i < len; ++i) {
    if (mark[abs(num[i])]==num[i]) {
      l = (Literal *)malloc(sizeof(Literal));
      l->data = num[i];
      l->next = NULL;
      ++count;
      if (count == 1) {
        res->first = llast = l;
      } else {
		llast->next = l;
        llast = llast->next;
      }
      mark[abs(num[i])] = 0;
    }
  }
  res->count = count;
  if (flag == 1)
    freeCla(c2);
  return res;
}
int isOnlyOne(Clause*res,int top,Tnode *trail)
{//������Ӿ����ж��ٵ�ǰ���߲�Ľ�㣬���ڳ�ͻ�Ӿ�ѧϰ����UIP��  
	Literal * ltemp = res->first;
	int i = 0;
	int count = 0;
	top--;
	while(ltemp)
	{
		for(i = 0;(top-i) && abs(trail[top-i].var)!=abs(ltemp->data);i++);
		//��trail���ҵ�
		if (trail[top-i].decLevel == decLevel)
      	count++;
      	if(count==2)
      	return 0;
      	ltemp = ltemp->next;
	}
	return 1;
}
int isIn(Clause*res,int var)
{//var �Ƿ���res����ڳ�ͻ�Ӿ�ѧϰ���ų��޹ص����� 
	Literal* l =res->first;
	while(l)
	{
		if(l->data==-var)
		return 1;
		l = l->next;
	}
	return 0;
}
Clause *learnCla(Clause*head,Tnode *trail, int top,
                 int &targetDecisionLevel,int &num) 
// ��trailѧϰ��ͻ�Ӿ�
{
  Tnode ttemp;
  int var;
  int level = trail[top-1].decLevel;
	Clause*res;
	int flag = 0;
	Clause *c;
	int begin = top-1; 
	int i = 0;
	flag=0;
  	res = trail[--top].reason;//��ͻ�Ӿ� 
  	while (1) {
  	if(!isIn(res,trail[top-1].var))
  	{//���޹� 
  		top--;
		continue; 
	}
	c = trail[--top].reason;
    if(trail[top].var>0)
    posconTimes[trail[top].var]++;
    else
    negconTimes[-trail[top].var]++;
    res = resolve(c, res, flag);
    if(!flag)
    flag=1;
    if(isOnlyOne(res,begin,trail))
    break;
  }
  top = begin;
  if(res->count !=1)//��res����һ���ҵ�����decLevel,���㱾�� 
{
	level = -1;
	Literal * ltemp = res->first;
	int i = 0;
	while(ltemp)
	{
		for(i = 1;(top-i) && abs(trail[top-i].var)!=abs(-ltemp->data);i++);
		//��trail���ҵ�
		if(ltemp->data>0)
		{
			negac[ltemp->data] = negac[ltemp->data]/2+(double)negconTimes[ltemp->data]/trail[top-i].decLevel;
		}
		else
		{
			posac[-ltemp->data] = posac[-ltemp->data]/2+(double)posconTimes[-ltemp->data]/trail[top-i].decLevel;
		}
		if(trail[top-i].decLevel==decLevel)
		{
			ltemp = ltemp->next;
			continue;
		}
		if (trail[top-i].decLevel > level)
      	level = trail[top-i].decLevel;
      	ltemp = ltemp->next;
	}
}
else level = 0;
	targetDecisionLevel = level+1;
	conflictnum++;
	memset(posconTimes,0,sizeof(int)*MAXVARNUM);
	memset(negconTimes,0,sizeof(int)*MAXVARNUM);
  return res;
}
void putClause(Clause *head, Clause *c) { 
// ������ѧϰ����Clause
  c->next = head->next;
  head->next = c;
  ++numCla;
  Literal *l;
  Linklist *temp;
  l = c->first;
  int var;
  while (l) {
    var = l->data;
    if(ans[abs(var)]==TRUE)
    {
    	if(var>0)
    	c->t++;
    	if(var<0)
    	c->f++;
	}
	if(ans[abs(var)]==FALSE)
    {
    	if(var<0)
    	c->t++;
    	if(var>0)
    	c->f++;
	}
	if (var > 0) {
      temp = (Linklist *)malloc(sizeof(Linklist));
      temp->next = pos[var];
      temp->clause = c;
      pos[abs(var)] = temp;
    } else if (var < 0) {
      temp = (Linklist *)malloc(sizeof(Linklist));
      temp->next = neg[abs(var)];
      temp->clause = c;
      neg[abs(var)] = temp;
    }
    l = l->next;
  }
}
int analyzeCon(Clause *head, Tnode *trail, int &top) {
	//������ͻԭ�� 
  Clause *c;
  int var;
  int targetDecisionLevel;
  int num;
  if(!decLevel)
  {
	  return UNSAT;
  }
  c = learnCla(head,trail, top, targetDecisionLevel,num);
  // ���������ݵ�decisionlevel = 0
  decLevel = targetDecisionLevel;
  while (top && trail[top - 1].decLevel >=
                          targetDecisionLevel) { // ���ݵ��Ӿ䴫�������е��� 
    var = trail[--top].var;
    Add(var);
  }
  putClause(head, c);
  if(decLevel)
  decLevel--;//
  // stack����
    back = 0;
  findUnit(head);
  return 1;
}
void PrintAnswer(int result, char filename[100],int duration) {
//����������ļ��Լ�����̨ 
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
	for(int i = 1; i <= numVar; i++)
	{
		if(ans[i] == TRUE)
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
  		for (int i = 1; i <= numVar; ++i) {
    	if(ans[i]==TRUE)
		printf("%d ", i);
		else
		printf("-%d ",i);
		}
	}
} 
void Sat() {
  Clause *chead = NULL;
  clock_t start, finish;
  int duration;
  int result;
  char filename[100];
  printf("Please input the file address:\n");
  scanf("%s", filename);
  chead = (Clause *)malloc(sizeof(Clause));
  chead->next = NULL;
  Init(); 
  FILE *fp;
  fp = fopen(filename, "r");
  if (!fp) {
    printf("Failed to open the file!\n");
    system("pause");
    return ;
  }
  readCNF(chead, fp);
  start = clock();
  result = DPLL(chead);
  finish = clock();
  duration = finish - start;
  if (result == SAT) {
    printf("Satisfiable!\n");
    PrintAnswer(1, filename,duration);
  } else
  {
  	printf("Unsatisfiable!\n");
	PrintAnswer(0, filename,duration);
  }
  tot_free(chead);
  system("pause");
  system("cls");
  return;
}
