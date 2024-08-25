#include "def.h"
status InitList(SqList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if (L.elem)
    {
        return L.length;
    }
    else
        return INFEASIBLE;
}

status GetElem(SqList L, int i, ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
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
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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
//�������������Ƿ���Lists���Ѵ��ڵ����Ա�������ͬ������ͬ����TRUE������ͬ����FALSE 
{
	for(int i=0;i<Lists.length;i++)
	{
		if(!strcmp(name,Lists.elem[i].name))
		return TRUE;
	}
	return FALSE;
}
status AddList(LISTS &Lists, char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա�
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
// Lists��ɾ��һ������ΪListName�����Ա�
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
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
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
// ���Lists�������Ա�������ʾ���Ա���ź����ƣ�ÿ�����Ա�ռһ�У�����OK��������Ա�ListsΪ�գ�����ERROR��
{
	if(Lists.length==0)
	return ERROR;
	printf("�Ѵ��ڵ����Ա�������ʾ��\n");
	for(int i=0;i<Lists.length;i++)
	{
		printf("List %d : %s\n",i+1,Lists.elem[i].name);
		ListTraverse(Lists.elem[i].L); 
	}
	return OK;
}

status rename(LISTS &Lists)
//���������Ա����ɹ�������������OK���������жϣ�����ERROR 
{
	int state=1;
	int i=0;
	char *name = (char*)malloc(sizeof(char)*100);
	printf("��������Ҫ�޸ĵı����ţ�[1-%d]\n",Lists.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Lists.length)//�����������Ա�����Ƿ�Ϸ� 
	{
		printf("������ŷǷ�\n");
		free(name); 
		return ERROR;
	}
	printf("���뽫�����޸�Ϊ��");
	scanf("%s",name);
	if(strlen(name)>=30)//����������Ƴ����Ƿ�Ϸ� 
	{
		printf("�������ƹ���\n");
		free(name);
		return ERROR;
	}
	if(isrep(Lists,name))//������������Ƿ��ظ� 
	{
		printf("���������ظ�\n");
		return ERROR;
	}
	strcpy(Lists.elem[i-1].name,name);
	return i;			
}
int MaxSubArray(SqList L)
//������Ա�L�Ѵ����ҷǿգ��ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������ͣ��������ڻ�Ϊ�ձ�����-1 
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
{//������Ա�L�Ѵ����ҷǿգ��ҳ���ΪK�������飨���������ٰ���һ��Ԫ�أ��������������������Ϊ�ձ�����-1 
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
//�����Ѵ��ڵ����Ա�����Ԫ�ؽ��������������ɹ����򣬷���OK�������Ա����ڣ�����INFEASIBLE 
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
//����a��b�����ֵ 
{
	return a>b?a:b;
}
