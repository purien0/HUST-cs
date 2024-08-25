#include "def.h"
status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L==NULL)
    {
        L=(LinkList)malloc(sizeof(LNode));
        L->next = NULL;
        return OK;
    }
    else
    return INFEASIBLE;
}

status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(L)
    {
        DestroyList(L->next);
        free(L);
        L=NULL;
        return OK;
    }
    return INFEASIBLE;
}


status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(L)
    {
        if(L->next ==NULL)
        return OK ;
		LinkList now=L->next;
        LinkList Next=now->next;
        while(Next!=NULL)
        {
            free(now);
            now=Next;
            Next=Next->next;
        }
        free(now);
        L->next=NULL;
        return OK;
    }
    else
    return INFEASIBLE;
}


status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(L)
    {
        if(L->next)
        return FALSE;
        else return TRUE;
    }
    else return INFEASIBLE;
}


int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(L)
    {
        int length = 0;
        while(L->next!=NULL)
        {
        length++;
        L=L->next;
        }
        return length;
    }
    else return INFEASIBLE;
}


status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L)
    {
        if(i<=0)
        return ERROR;
        for(int j=0;j<i;j++)
        {
        L=L->next;
        if(L==NULL)
        return ERROR;
        }
        e=L->data;
        return OK;
    }
    else return INFEASIBLE;
}


status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if(L)
    {
        int i=0;
        L=L->next;
        while(L)
        {
            i++;
            if(L->data==e)
            return i;
            L=L->next;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L)
    {
        ElemType last;
        L=L->next;
        if(L==NULL)
        return ERROR;
        if(L->data==e)
        return ERROR;
        while(L)
        {
            if(L->data==e)
            {
                pre=last;
                return OK;
            }
            last=L->data;
            L=L->next;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L)
    {
        L=L->next;
        while(L)
        {
            if(L->data==e)
            {
                if(L->next==NULL)
                return ERROR;
                else
                {
                    next=L->next->data;
                    return OK;
                }
            }
            L=L->next;
        }
        return ERROR;
    }
    else return INFEASIBLE;
}


status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L)
    {
        LinkList L2 = L ;
        if(i<0)
        return ERROR;
        if(i==0&&L2->next)
        return ERROR;
        //查找元素 
        for(int j=0;j<i-1;j++)
        {
            L2 = L2->next;
            if(L2 == NULL)
            return ERROR;
        }
        //插入元素 
        LinkList temp = (LinkList) malloc (sizeof(LNode));
        temp->data=e;
        temp->next = L2->next;
        L2->next = temp;
        
        return OK;
    }
    else return INFEASIBLE;
}


status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L)
    {
        if(i<=0)
        return ERROR;
        LinkList L2 = L;
        //查找元素 
        for(int j = 0; j < i-1 ; j++)
        {
            L2 = L2->next;
            if(L2==NULL)
            return ERROR;
        }
        //删除元素 
        LinkList temp = L2->next;
        if(temp==NULL)
        return ERROR;
        L2->next = L2->next->next;
        e=temp->data;
        free(temp);
        return OK;
    }
    else return INFEASIBLE;
}

status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if(L)
    {
        printf("\n-----------all elements -----------------------\n");
		L = L->next;
        if(L == NULL)//若线性表为空表 
        {
        	printf("\n------------------ end ------------------------\n");
        	return OK;
		}
        while(L->next)
        {
            printf("%d ",L->data);
            L = L->next;
        }
        printf("%d",L->data);
        printf("\n------------------ end ------------------------\n");
        return OK;
    }
    else return INFEASIBLE;
}

status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if(L)
    {
        FILE* fp;
        fp = fopen(FileName,"w");
        if(!fp)//若打开失败 
        return ERROR;
        L = L->next;
        while(L)
        {
            fprintf(fp,"%d ",L->data);
            L = L->next;
        }//遍历线性表并写入文件 
        fclose(fp);
        return OK;
    }else return INFEASIBLE;
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if(!L)
    {
        L = (LinkList) malloc (sizeof(LNode));
        L->next = NULL;
        LinkList L2 = L;
        FILE* fp;
        fp = fopen(FileName,"r");
        if(!fp)//若打开失败 
        return ERROR;
        int num;
        while((fscanf(fp,"%d",&num))!=EOF)
        {
            LinkList temp = (LinkList) malloc (sizeof(LNode));
            temp->data = num;
            temp->next = NULL;
            L2->next = temp;
            L2 = L2->next;
        }//遍历文件并写入线性表 
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}

int isrep(LISTS Lists,char *name)
//检测输入的名称是否与Lists中已存在的线性表名称相同，若相同返回TRUE，若不同返回FALSE 
{
	for(int i=0;i<Lists.length;i++)
	{
		if(!strcmp(name,Lists.elem[i].name))
		return TRUE;
	}
	return FALSE;
}
status AddList(LISTS &Lists, char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表
{
    if(Lists.length == Lists.listsize)
    return OVERFLOW;
    if(isrep(Lists,ListName))
    return ERROR;
	strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length].L = NULL;
    Lists.length++;
    return OK;
}

status RemoveList(LISTS &Lists, char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    if(Lists.length == 0)
    return ERROR;
    for (int i = 0; i < Lists.length; i++)
    {
        if (strcmp(Lists.elem[i].name, ListName) == 0)
        {
            DestroyList(Lists.elem[i].L);
			for (int j = i; j < Lists.length - 1; j++)
            {
                Lists.elem[j].L = Lists.elem[j + 1].L;
                strcpy(Lists.elem[j].name, Lists.elem[j + 1].name);
            }
            Lists.length--;
            return OK;
        }
    }
    return ERROR;
}

int LocateList(LISTS Lists, char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    for (int i = 0; i < Lists.length; i++)
    {
        if (strcmp(Lists.elem[i].name, ListName) == 0)
        {
            return i + 1;
        }
    }
    return 0;
}
status TraverseList(LISTS Lists)
// 如果Lists中有线性表，依次显示线性表序号和名称，每个线性表占一行，返回OK；如果线性表Lists为空，返回ERROR。
{
	if(Lists.length==0)
	return ERROR;
	printf("已存在的线性表如下所示：\n");
	for(int i=0;i<Lists.length;i++)
	{
		printf("List %d : %s\n",i+1,Lists.elem[i].name);
		ListTraverse(Lists.elem[i].L); 
	}
	return OK;
}

status rename(LISTS &Lists)
//重命名线性表，若成功重命名，返回OK，若操作中断，返回ERROR 
{
	int state=1;
	int i=0;
	char *name = (char*)malloc(sizeof(char)*100);//动态分配空间 
	printf("输入您想要修改的表的序号：[1-%d]\n",Lists.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Lists.length)
	{
		printf("输入序号非法\n");
		free(name);
		return ERROR;
	}
	printf("您想将名称修改为：");
	scanf("%s",name);
	if(strlen(name)>=30)//检查名称是否过长 
	{
		printf("输入名称过长\n");
		free(name);
		return ERROR;
	}
	if(isrep(Lists,name))//检查名称是否重复 
	{
		printf("输入名称重复\n");
		free(name);
		return ERROR; 
	}
	strcpy(Lists.elem[i-1].name,name);
	free(name);
	return i;			
}

status reverseList(LinkList & L)
{//翻转链表，初始条件是线性表L已存在；操作结果是将L翻转，并返回OK；若链表不存在，返回INFEASIBLE； 
	if(L)
	{
		if(!(L->next&&L->next->next))
		return OK; 
		LinkList pre = NULL,p = L->next,nex = p->next;
		while(nex)
		{
			p->next = pre;
			pre = p;
			p = nex;
			nex = nex->next;
		}
		p->next = pre;
		L->next = p;
		return OK;
	}
	else
	return INFEASIBLE;
}

ElemType RemoveNthFromEnd(LinkList &L,int n)
{//初始条件是线性表L已存在且非空, 若不存在返回INFEASIBLE,若n合法，删除倒数第n个结点并返回结点的值，若不合法返回ERROR, 
	if(L)
	{
		int length = ListLength(L);//获取线性表长度 
		if(n>length ||n<=0)
		return ERROR;
		ElemType e;
		ListDelete(L,length-n+1,e);//删除倒数第n个结点 
		return e;
	}
	else return INFEASIBLE;
}

status sortList(LinkList &L)
{//初始条件是线性表已存在，若不存在返回INFEASIBLE，若成功排序，返回OK。 
	if(L)
	{
		int length = ListLength(L) ;
		LinkList pt = L->next;
		LinkList newL = NULL;//重新创建个新线性表 
		InitList(newL);
		ElemType temp[length] ;//用一个数组储存线性表内的数据 
		ElemType tem;
		int i;
		for(i=0; i<length;i++)
		{
			temp[i] = pt->data;
			pt = pt->next ;
		}
		for(i=0;i<length-1 ;i++)
		{
			for(int j = 0; j<length -i-1;j++)
			{
				if(temp[j]>temp[j+1])
				{
					tem = temp[j];
					temp[j] = temp[j+1];
					temp[j+1] = tem ;
				}
			}
		}//对线性表内元素排序 
		ListInsert(newL,0,temp[length-1]);
		for(i=length-2;i>=0;i--)
		{
			ListInsert(newL,1,temp[i]);
		}//将排序后的元素插入到新线性表 
		DestroyList(L);//销毁原线性表 
		L=newL;//返回新线性表 
		return OK;
	}
	else return INFEASIBLE;
}
int max(int a,int b)
//返回a和b的最大值 
{
	return a>b?a:b;
}
