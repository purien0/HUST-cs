#include "def.h"
status InitList(SqList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if (L.elem)
        return INFEASIBLE;
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!(L.elem))
        exit(INFEASIBLE);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if (L.elem)
    {
        free(L.elem);
        L.elem = NULL;
        L.listsize = 0;
        L.length = 0;
        return OK;
    }
    else
        return INFEASIBLE;
}

status ClearList(SqList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if (L.elem)
    {
        L.length = 0;
        return OK;
    }
    else
        return INFEASIBLE;
}

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem)
    {
        if (L.length == 0)
            return TRUE;
        else
            return FALSE;
    }
    else
        return INFEASIBLE;
}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if (L.elem)
    {
        return L.length;
    }
    else
        return INFEASIBLE;
}

status GetElem(SqList L, int i, ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem)
    {
        if (i >= L.length + 1 || i <= 0)
            return ERROR;
        e = L.elem[i - 1];
        return OK;
    }
    else
        return INFEASIBLE;
}

int LocateElem(SqList L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    if (L.elem)
    {
        for (int i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
                return i + 1;
        }
        return 0;
    }
    return INFEASIBLE;
}

status PriorElem(SqList L, ElemType e, ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem)
    {
        int i;
        if(L.elem[0] == e)
        return NEXIST;
        for (i = 1; i < L.length; i++)
        {
            if (L.elem[i] == e)
            {
                pre = L.elem[i - 1];
                return OK;
            }
        }
        return ERROR;
    }
    else
        return INFEASIBLE;
}

status NextElem(SqList L, ElemType e, ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem)
    {	
   		if(L.elem[L.length-1] == e)
        return NEXIST;
        for (int i = 0; i < L.length - 1; i++)
        {
            if (L.elem[i] == e)
            {
                next = L.elem[i + 1];
                return OK;
            }
        }
        return ERROR;
    }
    else
        return INFEASIBLE;
}

status ListInsert(SqList &L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem)
    {
        if (i <= 0 || i > L.length + 1)
            return ERROR;
        if (L.length == L.listsize)
        {
            SqList L2;
            L2.elem = (ElemType *)malloc((L.listsize + LISTINCREMENT) * sizeof(ElemType));
            for (int i = 0; i < L.length; i++)
                L2.elem[i] = L.elem[i];
            L2.length = L.length;
            L2.listsize = L.listsize + LISTINCREMENT;
            free(L.elem);
            L = L2;
        }
        for (int j = L.length - 1; j >= i - 1; j--)
        {
            L.elem[j + 1] = L.elem[j];
        }
        L.elem[i - 1] = e;
        L.length++;
        return OK;
    }
    else
        return INFEASIBLE;
}

status ListDelete(SqList &L, int i, ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem)
    {
        if (L.length == 0)
            return ERROR;
        if (i <= 0 || i > L.length)
            return ERROR;
        e = L.elem[i - 1];
        for (int j = i - 1; j < L.length - 1; j++)
        {
            L.elem[j] = L.elem[j + 1];
        }
        L.length--;
        return OK;
    }
    else
        return INFEASIBLE;
}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem)
    {
        printf("\n-----------all elements -----------------------\n");
        for (int i = 0; i < L.length; i++)
        {
            if (i == L.length - 1)
            {
                printf("%d", L.elem[i]);
                break;
            }
            printf("%d ", L.elem[i]);
        }
        printf("\n------------------ end ------------------------\n");
        return OK;
    }
    else
        return INFEASIBLE;
}

status SaveList(SqList L, char * FileName)
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if (!L.elem)
    return INFEASIBLE;
    else
    {
        FILE *fp;
        fp = fopen(FileName, "w");
        if (!fp)
            return ERROR;
        for (int i = 0; i < L.length; i++)
        {
            fprintf(fp, "%d ", L.elem[i]);
        }
        fclose(fp);
        return OK;
    }
}
status LoadList(SqList &L, char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if (!L.elem)
    {
        FILE *fp;
        int num;
        fp = fopen(FileName, "r");
        if (!fp)
            return ERROR;
        L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        L.listsize = LIST_INIT_SIZE;
        L.length = 0;
        while ((fscanf(fp, "%d", &num)) != EOF)
        {
            if (L.listsize == L.length)
            {
                SqList tem;
                tem.elem = (ElemType *)malloc((L.listsize + LISTINCREMENT) * sizeof(ElemType));
                tem.listsize = L.listsize + LISTINCREMENT;
                tem.length = L.listsize;
                for (int i = 0; i < L.listsize; i++)
                    tem.elem[i] = L.elem[i];
                L = tem;
            }
            L.elem[L.length++] = num;
        }
        fclose(fp);
        return OK;
    }
    else
        return INFEASIBLE;
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
    Lists.elem[Lists.length].L.elem = NULL;
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
            for (int j = i; j < Lists.length - 1; j++)
            {
                for (int k = 0; k < Lists.elem[j + 1].L.length; k++)
                    Lists.elem[j].L.elem[k] = Lists.elem[j + 1].L.elem[k];
                Lists.elem[j].L.length = Lists.elem[j + 1].L.length;
                Lists.elem[j].L.listsize = Lists.elem[j + 1].L.listsize;
                strcpy(Lists.elem[j].name, Lists.elem[j + 1].name);
            }
            DestroyList(Lists.elem[Lists.length - 1].L);
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
	char *name = (char*)malloc(sizeof(char)*100);
	printf("输入您想要修改的表的序号：[1-%d]\n",Lists.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Lists.length)//检测输入的线性表序号是否合法 
	{
		printf("输入序号非法\n");
		free(name); 
		return ERROR;
	}
	printf("您想将名称修改为：");
	scanf("%s",name);
	if(strlen(name)>=30)//检测输入名称长度是否合法 
	{
		printf("输入名称过长\n");
		free(name);
		return ERROR;
	}
	if(isrep(Lists,name))//检测输入名称是否重复 
	{
		printf("输入名称重复\n");
		return ERROR;
	}
	strcpy(Lists.elem[i-1].name,name);
	return i;			
}
int MaxSubArray(SqList L)
//如果线性表L已存在且非空，找出一个具有最大和的连续子数组（子数组最少包含一个元素）并返回其最大和，若不存在或为空表，返回-1 
{
	if(L.elem&&!(ListEmpty(L)))
	{
		int max=L.elem[0],sum=0;
	for(int i=0;i<L.length;++i)
	{
		sum=0;
		for(int j=i;j<L.length;++j)
		{
			sum+=L.elem[j];
			if(sum<=0)
			{
				i=j;
				break;
			}
			if(max<sum)
			max=sum;
		}
	}
	return max;
	}
	else return -1;
}
int SubArrayNum(SqList L,ElemType k)
{//如果线性表L已存在且非空，找出和为K的子数组（子数组最少包含一个元素）并返回子数组个数，若为空表，返回-1 
	if(L.elem)
	{
		ElemType presum[L.length+1];
		int count = 0;
		presum[0] = 0;
		for(int i=1;i<L.length + 1;i++)
		{
			presum[i] = presum[i-1] + L.elem[i-1];
		}
		for(int i = 0;i<L.length + 1 ; i++)
		{
			for(int j=i; j<L.length + 1;j++)
			if(presum[i] + k == presum[j])
			count++;
		}
	return count;
	}
	else return ERROR;
}
status sortList(SqList &L)
//对于已存在的线性表，对其元素进行升序排序，若成功排序，返回OK，若线性表不存在，返回INFEASIBLE 
{
	if(L.elem&&!(ListEmpty(L)))
	{
		ElemType temp;
		for(int i=0 ;i < L.length; i++)
		{
			for(int j = i;j<L.length-1; j++)
			{
				if(L.elem[j]>L.elem[j+1])
				{
					temp = L.elem [j];
					L.elem[j]= L.elem [j+1];
					L.elem[j+1] = temp;
				}
			}
		}
		return  OK;
	}else return INFEASIBLE;
}
int max(int a,int b)
//返回a和b的最大值 
{
	return a>b?a:b;
}
