#include "def.h"
void visit(BiTree T) {//访问结点所用函数 
	printf("        key：%d,others：%s\n",T->data.key,T->data.others);
}
status CreateBiTree(BiTree &T,TElemType definition[])
//根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK
//如果有相同的关键字，返回ERROR。
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
    while(definition[i].key!=-1)//检查有无重复关键字
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
            t->data.key=-1;//做标记，之后删除该结点 
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
//将二叉树设置成空，并删除所有结点，释放结点空间
//初始条件是二叉树T已存在；操作结果是销毁二叉树T
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
//将二叉树设置成空，并删除所有结点，释放结点空间
//初始条件是二叉树T存在；操作结果是将二叉树T清空
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
{//初始条件是二叉树T存在；操作结果是若T为空二叉树则返回TRUE，否则返回FALSE；
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
//求二叉树T的深度
//初始条件是二叉树T存在；操作结果是返回T的深度
{
	if(BiTreeEmpty(T))//若为空树 
	return 0;
	if(T)
    return (BiTreeDepth(T->lchild)+1)>(BiTreeDepth(T->rchild)+1)?(BiTreeDepth(T->lchild)+1):(BiTreeDepth(T->rchild)+1);
    else return 0;
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
//初始条件是二叉树T已存在，e是和T中结点关键字类型相同的给定值；
//操作结果是返回查找到的结点指针，如无关键字为e的结点，返回NULL；
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
{//检查二叉树中是否存在相同关键字的结点 
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
//结点赋值
//初始条件是二叉树T已存在，e是和T中结点关键字类型相同的给定值；
//操作结果是关键字为e的结点赋值为value；
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
//获得兄弟结点
//初始条件是二叉树T存在，e是和T中结点关键字类型相同的给定值；
//操作结果是返回关键字为e的结点的（左或右）兄弟结点指针。
//若关键字为e的结点无兄弟，则返回NULL；
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
//插入结点
//初始条件：T存在，e是和T中结点关键字类型相同的给定值，LR为0或1或-1 
// 结果：根据LR为0或者1或-1，插入结点c到T中，
//作为关键字为e的结点的左或右孩子结点，结点e的原有左子树或右子树则为结点c的右子树； 
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
//查找结点的父节点 
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
//删除结点
//初始条件是二叉树T存在，e是和T中结点关键字类型相同的给定值。操作结果是删除T中关键字为e的结点
{
    if(T)
    {
        int deg=0;
        BiTree temp,temp2;
        if(T->data.key==e)//当根结点为目标结点
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
                    while(temp2->rchild!=NULL)//找到目标节点左子树最右结点
                    temp2 = temp2->rchild;
                    temp2->rchild = T->rchild;
                    //将目标节点的右子树作为目标节点左子树最右结点的右子树
                    T=T->lchild;
                    free(temp);
                    return OK;
            }
        }
        BiTree Parent = LocateParentNode(T,e);
        BiTree Target;
        if(Parent == NULL)
        return ERROR;
        int flag=1;//标记目标结点是其父结点的左/右子节点，左结点为0，右结点为1
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
                if(!flag)//目标结点是其父结点的左儿子
                {
                    free(Target);
                    Parent->lchild = NULL;
                }
                else//目标结点是其父结点的右儿子
                {
                    free(Target);
                    Parent->rchild = NULL;
                }
                return OK;
            case 1:
                if(Target->lchild!=NULL)//目标结点有左儿子
                {
                    if(!flag)//目标结点是其父结点的左儿子
                    {
                    Parent->lchild = Target->lchild;
                    free(Target);
                    }
                    else//目标结点是其父结点的右儿子
                    {
                    Parent->rchild = Target->lchild;
                    free(Target);
                    }
                }
                else//目标结点有右儿子
                {
                    if(!flag)//目标结点是其父结点的左儿子
                    {
                    Parent->lchild = Target->rchild;
                    free(Target);
                    }
                    else//目标结点是其父结点的右儿子
                    {
                    Parent->rchild = Target->rchild;
                    free(Target);
                    }
                }
                return OK;
            case 2:
                if(!flag)//目标结点是其父结点的左儿子
                Parent->lchild = Target->lchild;
                else//目标结点是其父结点的右儿子
                Parent->rchild = Target->lchild;
                temp= Target->lchild;
                while(temp->rchild!=NULL)
                temp=temp->rchild;//找到目标节点最右结点
                temp->rchild = Target->rchild;
                free(Target);
                return OK;
        }
    }
    else return ERROR;
}
status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//前序遍历二叉树T（非递归）
//初始条件是二叉树T存在，Visit是一个函数指针的形参（可使用该函数对结点操作）；
//操作结果：先序遍历，对每个结点调用函数Visit一次且一次 
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
//中序遍历二叉树T
//初始条件是二叉树T存在，Visit是一个函数指针的形参（可使用该函数对结点操作）
//操作结果是中序遍历t，对每个结点调用函数Visit一次且一次
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
//后序遍历二叉树T
//初始条件是二叉树T存在，Visit是一个函数指针的形参（可使用该函数对结点操作）
//操作结果是中序遍历t，对每个结点调用函数Visit一次且一次
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
//按层遍历二叉树T
//始条件是二叉树T存在，Visit是对结点操作的应用函数；
//操作结果是层序遍历t，对每个结点调用函数Visit一次且一次
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
//将二叉树的结点数据写入到文件FileName中
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
//读入文件FileName的结点数据，创建二叉树
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
//检测输入的名称是否与Trees中已存在的二叉树名称相同，若相同返回TRUE，若不同返回FALSE 
{
	for(int i=0;i<Trees.length;i++)
	{
		if(!strcmp(name,Trees.elem[i].name))
		return TRUE;
	}
	return FALSE;
}
status AddTree(BITREES &Trees, char TreeName[])
// 只需要在Trees中增加一个名称为TreeName的二叉树 
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
// Trees中删除一个名称为TreeName的二叉树 
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
// 在Trees中查找一个名称为TreeName的二叉树，成功返回逻辑序号，否则返回0
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
// 如果Trees中有二叉树，依次显示二叉树序号和名称，每个二叉树占一行，返回OK；如果Trees为空，返回ERROR。
{
	int op;
	if(Trees.length==0)
	return ERROR;
	printf("选择遍历类型：\n前序/中序/后序/层序 分别输入1，2，3，4\n");
	scanf("%d",&op);
	if(op<1||op>4)
	{
		printf("输入序号有误，操作中断\n");
		return ERROR;
	}
	printf("已存在的二叉树如下所示：\n");
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
//重命名二叉树，若成功重命名，返回OK，若操作中断，返回ERROR 
{
	int state=1;
	int i=0;
	char *name = (char*)malloc(sizeof(char)*100);//动态分配空间 
	printf("输入您想要修改的二叉树的序号：[1-%d]\n",Trees.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Trees.length)
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
	if(isrep(Trees,name))//检查名称是否重复 
	{
		printf("输入名称重复\n");
		free(name);
		return ERROR; 
	}
	strcpy(Trees.elem[i-1].name,name);
	free(name);
	return i;			
}

int max(int a,int b)
//返回a和b的最大值 
{
	return a>b?a:b;
}
int maxPathSum(BiTree t,int sum)
 {//返回根节点到叶子结点的最大路径和的递归函数 
 	if(t==NULL)
 	return sum;
 	int lsum,rsum;
 	lsum=maxPathSum(t->lchild,sum+t->data.key);
 	rsum=maxPathSum(t->rchild,sum+t->data.key);
 	return max(lsum,rsum);
 }
int MaxPathSum(BiTree T)
{//返回根节点到叶子结点的最大路径和 
	if(T)
	return maxPathSum(T,0);//调用递归函数 
	else return ERROR;
}
 int vexDepth(BiTree T,KeyType e,int depth)
 {//返回关键词为e的结点深度，若结点不存在或二叉树不存在返回-1 
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
//最近公共祖先
//初始条件是二叉树T存在；操作结果是该二叉树中e1节点和e2节点的最近公共祖先
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
//翻转二叉树
//初始条件是图T已存在；操作结果是将T翻转，使其所有节点的左右节点互换
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
