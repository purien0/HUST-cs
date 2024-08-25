#include "def.h"
status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L)
    {
        LinkList L2 = L ;
        if(i<0)
        return ERROR;
        if(i==0&&L2->next)
        return ERROR;
        //����Ԫ�� 
        for(int j=0;j<i-1;j++)
        {
            L2 = L2->next;
            if(L2 == NULL)
            return ERROR;
        }
        //����Ԫ�� 
        LinkList temp = (LinkList) malloc (sizeof(LNode));
        temp->data=e;
        temp->next = L2->next;
        L2->next = temp;
        
        return OK;
    }
    else return INFEASIBLE;
}


status ListDelete(LinkList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L)
    {
        if(i<=0)
        return ERROR;
        LinkList L2 = L;
        //����Ԫ�� 
        for(int j = 0; j < i-1 ; j++)
        {
            L2 = L2->next;
            if(L2==NULL)
            return ERROR;
        }
        //ɾ��Ԫ�� 
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L)
    {
        printf("\n-----------all elements -----------------------\n");
		L = L->next;
        if(L == NULL)//�����Ա�Ϊ�ձ� 
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    if(L)
    {
        FILE* fp;
        fp = fopen(FileName,"w");
        if(!fp)//����ʧ�� 
        return ERROR;
        L = L->next;
        while(L)
        {
            fprintf(fp,"%d ",L->data);
            L = L->next;
        }//�������Ա�д���ļ� 
        fclose(fp);
        return OK;
    }else return INFEASIBLE;
}

status LoadList(LinkList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if(!L)
    {
        L = (LinkList) malloc (sizeof(LNode));
        L->next = NULL;
        LinkList L2 = L;
        FILE* fp;
        fp = fopen(FileName,"r");
        if(!fp)//����ʧ�� 
        return ERROR;
        int num;
        while((fscanf(fp,"%d",&num))!=EOF)
        {
            LinkList temp = (LinkList) malloc (sizeof(LNode));
            temp->data = num;
            temp->next = NULL;
            L2->next = temp;
            L2 = L2->next;
        }//�����ļ���д�����Ա� 
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
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
    Lists.elem[Lists.length].L = NULL;
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
	char *name = (char*)malloc(sizeof(char)*100);//��̬����ռ� 
	printf("��������Ҫ�޸ĵı����ţ�[1-%d]\n",Lists.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Lists.length)
	{
		printf("������ŷǷ�\n");
		free(name);
		return ERROR;
	}
	printf("���뽫�����޸�Ϊ��");
	scanf("%s",name);
	if(strlen(name)>=30)//��������Ƿ���� 
	{
		printf("�������ƹ���\n");
		free(name);
		return ERROR;
	}
	if(isrep(Lists,name))//��������Ƿ��ظ� 
	{
		printf("���������ظ�\n");
		free(name);
		return ERROR; 
	}
	strcpy(Lists.elem[i-1].name,name);
	free(name);
	return i;			
}

status reverseList(LinkList & L)
{//��ת������ʼ���������Ա�L�Ѵ��ڣ���������ǽ�L��ת��������OK�����������ڣ�����INFEASIBLE�� 
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
{//��ʼ���������Ա�L�Ѵ����ҷǿ�, �������ڷ���INFEASIBLE,��n�Ϸ���ɾ��������n����㲢���ؽ���ֵ�������Ϸ�����ERROR, 
	if(L)
	{
		int length = ListLength(L);//��ȡ���Ա��� 
		if(n>length ||n<=0)
		return ERROR;
		ElemType e;
		ListDelete(L,length-n+1,e);//ɾ��������n����� 
		return e;
	}
	else return INFEASIBLE;
}

status sortList(LinkList &L)
{//��ʼ���������Ա��Ѵ��ڣ��������ڷ���INFEASIBLE�����ɹ����򣬷���OK�� 
	if(L)
	{
		int length = ListLength(L) ;
		LinkList pt = L->next;
		LinkList newL = NULL;//���´����������Ա� 
		InitList(newL);
		ElemType temp[length] ;//��һ�����鴢�����Ա��ڵ����� 
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
		}//�����Ա���Ԫ������ 
		ListInsert(newL,0,temp[length-1]);
		for(i=length-2;i>=0;i--)
		{
			ListInsert(newL,1,temp[i]);
		}//��������Ԫ�ز��뵽�����Ա� 
		DestroyList(L);//����ԭ���Ա� 
		L=newL;//���������Ա� 
		return OK;
	}
	else return INFEASIBLE;
}
int max(int a,int b)
//����a��b�����ֵ 
{
	return a>b?a:b;
}
