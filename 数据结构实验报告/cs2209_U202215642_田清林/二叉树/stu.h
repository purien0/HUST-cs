#include "def.h"
void visit(BiTree T) {//���ʽ�����ú��� 
	printf("        key��%d,others��%s\n",T->data.key,T->data.others);
}
status CreateBiTree(BiTree &T,TElemType definition[])
//���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK
//�������ͬ�Ĺؼ��֣�����ERROR��
{
    if(definition[0].key==0)
    {
        T=NULL;
        return OK;
    }
    if(T)
    return ERROR;
    int i=0;
    T=(BiTree)malloc(sizeof(BiTNode));
    T->lchild = NULL;
    T->rchild = NULL;
    while(definition[i].key!=-1)//��������ظ��ؼ���
    {
        if(definition[i].key!=0)
        {
            for(int j=0;j<i;j++)
            {
                if(definition[j].key!=0)
                {
                    if(definition[i].key==definition[j].key)
                    return ERROR;

                }
            }
        }
        i++;
    }
    BiTree stack[100];
    stack[0] = T;
    int top;
    BiTree t,p;
    i=0;
    top=1;
    while(definition[i].key!=-1)
    {
        t=stack[--top];
        if(definition[i].key!=0)
        {
            t->data.key=definition[i].key;
            strcpy(t->data.others,definition[i].others);
            t->lchild=(BiTree)malloc(sizeof(BiTNode));
            t->rchild=(BiTree)malloc(sizeof(BiTNode));
            stack[top++]=t->rchild;
            stack[top++]=t->lchild;
        }
        else
        {
            t->data.key=-1;//����ǣ�֮��ɾ���ý�� 
        }
        i++;
    }
    top = 0;
    stack[top++] = T;
    while(top)
    {
        p = stack[--top];
        if(p->rchild!=NULL)
        {
        	if(p->rchild->data.key==-1)
        	{
        		free(p->rchild);
				p->rchild=NULL; 
			}
			else
			stack[top++]=p->rchild;
		}
        if(p->lchild!=NULL)
        {
        	if(p->lchild->data.key==-1)
        	{
        		free(p->lchild);
				p->lchild=NULL; 
			}
			else
			stack[top++]=p->lchild;
		}
    }
    return OK;
}

status DestroyBiTree(BiTree &T)
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
//��ʼ�����Ƕ�����T�Ѵ��ڣ�������������ٶ�����T
{
    if(T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
        T=NULL;
        return OK;
    }
    else
    return ERROR;
}

status ClearBiTree(BiTree &T)
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
//��ʼ�����Ƕ�����T���ڣ���������ǽ�������T���
{
    if(T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
		T=(BiTree)malloc(sizeof(BiTNode));
		T->lchild=NULL;
		T->rchild=NULL;
		T->data.key=0;
		strcpy(T->data.others,"#");
        return OK;
    }
    else
    return ERROR;
}
status BiTreeEmpty(BiTree T)
{//��ʼ�����Ƕ�����T���ڣ������������TΪ�ն������򷵻�TRUE�����򷵻�FALSE��
	if(T)
	{
		if(T->data.key==0&&strcmp(T->data.others,"#"))
		return TRUE;
		else
		return FALSE;
	}
	else
	return ERROR;
}
int BiTreeDepth(BiTree T)
//�������T�����
//��ʼ�����Ƕ�����T���ڣ���������Ƿ���T�����
{
	if(BiTreeEmpty(T))//��Ϊ���� 
	return 0;
	if(T)
    return (BiTreeDepth(T->lchild)+1)>(BiTreeDepth(T->rchild)+1)?(BiTreeDepth(T->lchild)+1):(BiTreeDepth(T->rchild)+1);
    else return 0;
}

BiTNode* LocateNode(BiTree T,KeyType e)
//���ҽ��
//��ʼ�����Ƕ�����T�Ѵ��ڣ�e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ��
//��������Ƿ��ز��ҵ��Ľ��ָ�룬���޹ؼ���Ϊe�Ľ�㣬����NULL��
{
    if(T)
    {
        if((T->data).key==e)
        return T;
        else{
            BiTree l = LocateNode(T->lchild,e);
            if(l!=NULL)
            return l;
            BiTree r = LocateNode(T->rchild,e);
            return r;
            if(r!=NULL)
            return r;
            return NULL;
        }
    }
    else
    return NULL;
}

status isRepeat(BiTree T ,KeyType e,BiTree Target)
{//�����������Ƿ������ͬ�ؼ��ֵĽ�� 
    if(T)
    {
        if(T->data.key==e && T!=Target)
        {
            return TRUE;
        }
        if(isRepeat(T->lchild,e,Target)==TRUE)
        return TRUE;
        if(isRepeat(T->rchild,e,Target)==TRUE)
        return TRUE;
        return FALSE;
    }
    else return FALSE;
}
status Assign(BiTree &T,KeyType e,TElemType value)
//��㸳ֵ
//��ʼ�����Ƕ�����T�Ѵ��ڣ�e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ��
//��������ǹؼ���Ϊe�Ľ�㸳ֵΪvalue��
{
    BiTree p = LocateNode(T,e);
    if(p==NULL)
    return ERROR;
    if(isRepeat(T,value.key,p)==TRUE)
    return ERROR;
    p->data = value;
    return OK;
}


BiTNode* GetSibling(BiTree T,KeyType e)
//����ֵܽ��
//��ʼ�����Ƕ�����T���ڣ�e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ��
//��������Ƿ��عؼ���Ϊe�Ľ��ģ�����ң��ֵܽ��ָ�롣
//���ؼ���Ϊe�Ľ�����ֵܣ��򷵻�NULL��
{
    if(T)
    {
        if(T->lchild!=NULL)
        if(T->lchild->data.key==e)
        return T->rchild;
        if(T->rchild!=NULL)
        if(T->rchild->data.key==e)
        return T->lchild;
        BiTNode* t = GetSibling(T->lchild,e);
        if(t!=NULL)
        return t;
        t = GetSibling(T->rchild,e);
        return t;
    }else
    return NULL;
}


status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//������
//��ʼ������T���ڣ�e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ��LRΪ0��1��-1 
// ���������LRΪ0����1��-1��������c��T�У�
//��Ϊ�ؼ���Ϊe�Ľ�������Һ��ӽ�㣬���e��ԭ������������������Ϊ���c���������� 
{
    if(T)
    {
        BiTree temp;
        temp = (BiTree)malloc(sizeof(BiTNode));
        temp->data = c;
        temp->lchild = NULL;
        BiTree target;
    switch(LR) 
    {
        case -1:
            temp->rchild = T;
            T = temp;
            return OK;
        case 0:
            if(isRepeat(T,c.key,NULL))
            return ERROR;
            target = LocateNode(T,e);
            if(target==NULL)
            return ERROR;
            temp->rchild = target->lchild;
            target->lchild = temp;
            return OK;
        case 1:
            if(isRepeat(T,c.key,NULL))
            return ERROR;
            target = LocateNode(T,e);
            if(target==NULL)
            return ERROR;
            temp->rchild = target->rchild;
            target->rchild = temp;
            return OK;
    }
    }
    else return ERROR;
}
BiTNode* LocateParentNode(BiTree T,KeyType e)
//���ҽ��ĸ��ڵ� 
{

    if(T)
    {
        if(T->lchild!=NULL&&T->lchild->data.key==e)
        return T;
        if(T->rchild!=NULL&&T->rchild->data.key==e)
        return T;
        BiTree t;
        t = LocateParentNode(T->lchild,e);
        if(t!=NULL)
        return t;
        t = LocateParentNode(T->rchild,e);
        return t;
    }
    else
    return NULL;
}
status DeleteNode(BiTree &T,KeyType e)
//ɾ�����
//��ʼ�����Ƕ�����T���ڣ�e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ�����������ɾ��T�йؼ���Ϊe�Ľ��
{
    if(T)
    {
        int deg=0;
        BiTree temp,temp2;
        if(T->data.key==e)//�������ΪĿ����
        {
            if(T->lchild!=NULL)
            deg++;
            if(T->rchild!=NULL)
            deg++;
            switch(deg)
            {
                case 0:
                    free(T);
                    T=NULL;
                    return OK;
                case 1:
                    temp = T;
                    if(T->lchild !=NULL)
                    T = T->lchild;
                    else T=T->rchild;
                    free(temp);
                    return OK;
                case 2:
                    temp = T;
                    temp2 =T->lchild;
                    while(temp2->rchild!=NULL)//�ҵ�Ŀ��ڵ����������ҽ��
                    temp2 = temp2->rchild;
                    temp2->rchild = T->rchild;
                    //��Ŀ��ڵ����������ΪĿ��ڵ����������ҽ���������
                    T=T->lchild;
                    free(temp);
                    return OK;
            }
        }
        BiTree Parent = LocateParentNode(T,e);
        BiTree Target;
        if(Parent == NULL)
        return ERROR;
        int flag=1;//���Ŀ�������丸������/���ӽڵ㣬����Ϊ0���ҽ��Ϊ1
        if(Parent->lchild!=NULL&&Parent->lchild->data.key==e)
        {
            Target = Parent->lchild;
            flag=0;
        }
        else Target = Parent->rchild;
        if(Target->lchild!=NULL)
        deg++;
        if(Target->rchild!=NULL)
        deg++;
        switch(deg)
        {
            case 0:
                if(!flag)//Ŀ�������丸���������
                {
                    free(Target);
                    Parent->lchild = NULL;
                }
                else//Ŀ�������丸�����Ҷ���
                {
                    free(Target);
                    Parent->rchild = NULL;
                }
                return OK;
            case 1:
                if(Target->lchild!=NULL)//Ŀ�����������
                {
                    if(!flag)//Ŀ�������丸���������
                    {
                    Parent->lchild = Target->lchild;
                    free(Target);
                    }
                    else//Ŀ�������丸�����Ҷ���
                    {
                    Parent->rchild = Target->lchild;
                    free(Target);
                    }
                }
                else//Ŀ�������Ҷ���
                {
                    if(!flag)//Ŀ�������丸���������
                    {
                    Parent->lchild = Target->rchild;
                    free(Target);
                    }
                    else//Ŀ�������丸�����Ҷ���
                    {
                    Parent->rchild = Target->rchild;
                    free(Target);
                    }
                }
                return OK;
            case 2:
                if(!flag)//Ŀ�������丸���������
                Parent->lchild = Target->lchild;
                else//Ŀ�������丸�����Ҷ���
                Parent->rchild = Target->lchild;
                temp= Target->lchild;
                while(temp->rchild!=NULL)
                temp=temp->rchild;//�ҵ�Ŀ��ڵ����ҽ��
                temp->rchild = Target->rchild;
                free(Target);
                return OK;
        }
    }
    else return ERROR;
}
status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//ǰ�����������T���ǵݹ飩
//��ʼ�����Ƕ�����T���ڣ�Visit��һ������ָ����βΣ���ʹ�øú����Խ���������
//��������������������ÿ�������ú���Visitһ����һ�� 
{
    if(T)
    {
    BiTree stack[100];
    int top = 0;
    stack[top++] = T;
    BiTree p;
    while(top)
    {
        p = stack[--top];
        visit(p);
        if(p->rchild!=NULL)
        stack[top++]=p->rchild;
        if(p->lchild!=NULL)
        stack[top++]=p->lchild;
    }
    return OK;
    }
    else return ERROR;
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
//��ʼ�����Ƕ�����T���ڣ�Visit��һ������ָ����βΣ���ʹ�øú����Խ�������
//����������������t����ÿ�������ú���Visitһ����һ��
{
    if(T)
    {
        InOrderTraverse(T->lchild,visit);
        visit(T);
        InOrderTraverse(T->rchild,visit);
        return OK;
    }
    else return ERROR;
}
status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
//��ʼ�����Ƕ�����T���ڣ�Visit��һ������ָ����βΣ���ʹ�øú����Խ�������
//����������������t����ÿ�������ú���Visitһ����һ��
{
    if(T)
    {
        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T);
        return OK;
    }
    else return ERROR;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
//ʼ�����Ƕ�����T���ڣ�Visit�ǶԽ�������Ӧ�ú�����
//��������ǲ������t����ÿ�������ú���Visitһ����һ��
{
    BiTree queue[100];
    int head = 0,tail = 0;
    if(T)
    queue[tail++]=T;
    else return ERROR;
    while(head!=tail)
    {
        visit(queue[head]);
        if(queue[head]->lchild!=NULL)
        queue[tail++]=queue[head]->lchild;
        if(queue[head]->rchild!=NULL)
        queue[tail++]=queue[head]->rchild;
        head++;
    }
    return OK;
}

status SaveBiTree(BiTree T, char FileName[])
//���������Ľ������д�뵽�ļ�FileName��
{
    if(T)
    {
    	FILE *fp;
    fp=fopen(FileName,"w");
    if(!fp)
    return OVERFLOW;
    BiTree stack[100];
    int top = 0;
    stack[top++] = T;
    BiTree p;
    while(top)
    {
        p = stack[--top];
        if(!p)
        {
            fprintf(fp,"0 null ");
            continue ;
        }
        fprintf(fp,"%d %s ",p->data.key,p->data.others);
        stack[top++]=p->rchild;
        stack[top++]=p->lchild;
    }
    fprintf(fp,"-1 nil ");
    fclose(fp);
    return OK;
	}
	else return ERROR;
}
status LoadBiTree(BiTree &T,  char FileName[])
//�����ļ�FileName�Ľ�����ݣ�����������
{
    if(!T)
	{
		FILE*fp;
    if(!(fp = fopen(FileName,"r")))
    return OVERFLOW;
    int pos,key;
    char name[100];
    TElemType temp[100];
    int count = 0;
    do
    {
        fscanf(fp,"%d%s",&key,name);
        temp[count].key = key;
        strcpy(temp[count++].others,name);
    }while(temp[count-1].key!=-1);
    CreateBiTree(T,temp);
    fclose(fp);
    return OK;
	} 
	else return ERROR;
}



int isrep(BITREES Trees,char *name)
//�������������Ƿ���Trees���Ѵ��ڵĶ�����������ͬ������ͬ����TRUE������ͬ����FALSE 
{
	for(int i=0;i<Trees.length;i++)
	{
		if(!strcmp(name,Trees.elem[i].name))
		return TRUE;
	}
	return FALSE;
}
status AddTree(BITREES &Trees, char TreeName[])
// ֻ��Ҫ��Trees������һ������ΪTreeName�Ķ����� 
{
    if(Trees.length == Trees.size)
    return OVERFLOW;
    if(isrep(Trees,TreeName))
    return ERROR;
	strcpy(Trees.elem[Trees.length].name, TreeName);
    Trees.elem[Trees.length].T = NULL;
    Trees.length++;
    return OK;
}

status RemoveTree(BITREES &Trees, char TreeName[])
// Trees��ɾ��һ������ΪTreeName�Ķ����� 
{
    if(Trees.length == 0)
    return ERROR;
    for (int i = 0; i < Trees.length; i++)
    {
        if (strcmp(Trees.elem[i].name, TreeName) == 0)
        {
            DestroyBiTree(Trees.elem[i].T);
			for (int j = i; j < Trees.length - 1; j++)
            {
                Trees.elem[j].T = Trees.elem[j + 1].T;
                strcpy(Trees.elem[j].name, Trees.elem[j + 1].name);
            }
            Trees.length--;
            return OK;
        }
    }
    return ERROR;
}

int LocateTree(BITREES Trees, char TreeName[])
// ��Trees�в���һ������ΪTreeName�Ķ��������ɹ������߼���ţ����򷵻�0
{
    for (int i = 0; i < Trees.length; i++)
    {
        if (strcmp(Trees.elem[i].name, TreeName) == 0)
        {
            return i + 1;
        }
    }
    return 0;
}
status TraverseTree(BITREES Trees)
// ���Trees���ж�������������ʾ��������ź����ƣ�ÿ��������ռһ�У�����OK�����TreesΪ�գ�����ERROR��
{
	int op;
	if(Trees.length==0)
	return ERROR;
	printf("ѡ��������ͣ�\nǰ��/����/����/���� �ֱ�����1��2��3��4\n");
	scanf("%d",&op);
	if(op<1||op>4)
	{
		printf("����������󣬲����ж�\n");
		return ERROR;
	}
	printf("�Ѵ��ڵĶ�����������ʾ��\n");
	for(int i=0;i<Trees.length;i++)
	{
		printf("Tree %d : %s\n",i+1,Trees.elem[i].name);
		switch(op)
		{
			case 1:
				PreOrderTraverse(Trees.elem[i].T,visit);
				break;
			case 2:
				InOrderTraverse(Trees.elem[i].T,visit);
				break;
			case 3:
				PostOrderTraverse(Trees.elem[i].T,visit);
				break;
			case 4:
				LevelOrderTraverse(Trees.elem[i].T,visit);
				break;
		}
	}
	return OK;
}

status rename(BITREES &Trees)
//�����������������ɹ�������������OK���������жϣ�����ERROR 
{
	int state=1;
	int i=0;
	char *name = (char*)malloc(sizeof(char)*100);//��̬����ռ� 
	printf("��������Ҫ�޸ĵĶ���������ţ�[1-%d]\n",Trees.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Trees.length)
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
	if(isrep(Trees,name))//��������Ƿ��ظ� 
	{
		printf("���������ظ�\n");
		free(name);
		return ERROR; 
	}
	strcpy(Trees.elem[i-1].name,name);
	free(name);
	return i;			
}

int max(int a,int b)
//����a��b�����ֵ 
{
	return a>b?a:b;
}
int maxPathSum(BiTree t,int sum)
 {//���ظ��ڵ㵽Ҷ�ӽ������·���͵ĵݹ麯�� 
 	if(t==NULL)
 	return sum;
 	int lsum,rsum;
 	lsum=maxPathSum(t->lchild,sum+t->data.key);
 	rsum=maxPathSum(t->rchild,sum+t->data.key);
 	return max(lsum,rsum);
 }
int MaxPathSum(BiTree T)
{//���ظ��ڵ㵽Ҷ�ӽ������·���� 
	if(T)
	return maxPathSum(T,0);//���õݹ麯�� 
	else return ERROR;
}
 int vexDepth(BiTree T,KeyType e,int depth)
 {//���عؼ���Ϊe�Ľ����ȣ�����㲻���ڻ�����������ڷ���-1 
 	if(T)
 	{
 		if(T->data.key==e)
 		return depth;
 		else
 		{
 			int ldepth = vexDepth(T->lchild,e,depth+1);
 			int rdepth = vexDepth(T->rchild,e,depth+1);
 			if(ldepth!=-1)
 			return ldepth;
 			if(rdepth!=-1)
 			return rdepth;
 			return -1;
	 	}
	}else return -1;
 }
BiTree LowestCommonAncestor(BiTree T,KeyType e1,KeyType e2)
//�����������
//��ʼ�����Ƕ�����T���ڣ���������Ǹö�������e1�ڵ��e2�ڵ�������������
{

	if(!T||e1==e2)
	return NULL;
	int depth1=vexDepth(T,e1,0);
	int depth2=vexDepth(T,e2,0);
	if(depth1==-1||depth2==-1)
	return NULL;
	BiTree parent1=LocateNode(T,e1);
	BiTree parent2=LocateNode(T,e2);
	if(depth1<depth2)
	{
		for(int i=0;i<depth2-depth1;i++)
		parent2=LocateParentNode(T,parent2->data.key);
	}
	else
	{
		for(int i=0;i<depth1-depth2;i++)
		parent1=LocateParentNode(T,parent1->data.key);
	}
	while(parent1!=parent2)
	{
		parent1=LocateParentNode(T,parent1->data.key);
		parent2=LocateParentNode(T,parent2->data.key);
	}
	return parent1;
}
status InvertTree(BiTree T)
//��ת������
//��ʼ������ͼT�Ѵ��ڣ���������ǽ�T��ת��ʹ�����нڵ�����ҽڵ㻥��
{
	if(!T)
	return ERROR;
	BiTree temp;
	temp=T->lchild;
	T->lchild = T->rchild;
	T->rchild = temp;
	InvertTree(T->lchild);
	InvertTree(T->rchild);
	return OK;
}
