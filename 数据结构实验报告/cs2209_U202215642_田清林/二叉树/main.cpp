#include "stu.h"
#include "def.h"
/* Binary Tree On Chain Structure */
int main()
{
    BITREES TREES; 
    int now = 1;//now为当前处理的二叉树序号，默认为1 
    TREES.elem[now-1].T = NULL;
    TREES.length = 1;
    TREES.size = 10;//对多二叉树结构体TREES初始化 
    strcpy(TREES.elem[0].name,"Untitled_Tree_1");//将默认二叉树1的名字改为未命名1 
    int e,e2,i,LR;//用于临时储存输入数据 
    TElemType c;//用于临时储存一个结点数据 
    status returnvalue;//储存函数返回值 
    BiTree returnpointer = NULL; //储存指针函数返回的指针 
    int op = 1;//单二叉树操作序号 
    int OP = 1; //多二叉树管理系统操作序号 
    char *name = (char*)malloc(100*sizeof(char));//用于临时储存字符串 
    normal://从多线性表系统到单线性表系统 
    while (op)
    {
		system("cls");//清屏幕 
        printf("Working Tree%d:%s\n",now,TREES.elem[now-1].name);
        printf("\n");
        printf("    Menu for Binary Tree On Chain Structure \n");
        printf("-------------------------------------------------\n");
        printf("    1. CreateBiTree     11. PreOrderTraverse\n");
        printf("    2. DestroyBiTree    12. InOrderTraverse\n");
        printf("    3. ClearBiTree      13. PostOrderTraverse\n");
        printf("    4. BiTreeEmpty      14. LevelOrderTraverse\n");
        printf("    5. BiTreeDepth      15. MaxPathSum\n");
        printf("    6. LocateNode       16. LowestCommonAncestor\n");
        printf("    7. Assign           17. InvertTree\n");
        printf("    8. GetSibling       18. SaveBiTree\n");
        printf("    9. InsertNode       19. LoadBiTree\n");
        printf("    10.DeleteNode       20. MulTreeSys\n");
        printf("             0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~20]:");
        scanf("%d", &op);//输入操作序号 
        switch (op)
        {
        case 1://创建二叉树
        	TElemType definition[100];
			i=0;
			printf("请输入空子树的二叉树前序遍历序列："); 
			do {
				scanf("%d%s",&definition[i].key,definition[i].others);
			} while (definition[i++].key!=-1);
            if (CreateBiTree(TREES.elem[now-1].T,definition) == OK)
                printf("二叉树创建成功！\n");
            else
                printf("二叉树已存在！\n");
            getchar();
            break;
        case 2://销毁二叉树
            if (DestroyBiTree(TREES.elem[now-1].T) == OK)
                printf("二叉树销毁成功！\n");
            else
                printf("二叉树不存在！\n");
            getchar();
            break;
        case 3://清空二叉树 
            if (ClearBiTree (TREES.elem[now-1].T) == OK)
                printf("二叉树清空成功！\n");
            else
                printf("二叉树不存在！\n");
            getchar();
            break;
        case 4://检查二叉树是否为空 
        	returnvalue =  BiTreeEmpty(TREES.elem[now-1].T);
            if (returnvalue == TRUE)
                printf("二叉树为空！\n");
            else if (returnvalue == FALSE)
                printf("二叉树不为空！\n");
            else
                printf("二叉树不存在！\n");
            getchar();
            break;
        case 5://求二叉树深度 
        	returnvalue = BiTreeDepth(TREES.elem[now-1].T); 
            if (returnvalue == INFEASIBLE)
                printf("二叉树不存在！\n");
            else
            printf("二叉树深度为%d\n",returnvalue);
            getchar();
            break;
        case 6://查找二叉树中关键字为e的结点指针 
            printf("输入您想查找的元素：");
            scanf("%d",&e);
            returnpointer = LocateNode(TREES.elem[now-1].T,e);
            if(returnpointer == NULL)
            printf("该元素不存在!\n");
            else
            printf("该元素存在！\n");
            getchar();
            break;
        case 7://查找二叉树中关键字为e的结点并赋值为value 
            printf("输入要查找结点的关键字：\n");
            scanf("%d",&e);
            printf("输入要赋值的结点信息：\nkey:");
            scanf("%d",&c.key);
            getchar();
            printf("others:");
            scanf("%s",c.others);
            returnvalue = Assign(TREES.elem[now-1].T,e,c);
            if( returnvalue== INFEASIBLE)
            printf("二叉树不存在！\n");
            else if(returnvalue == ERROR)
            printf("结点不存在！\n");
            else
            printf("赋值成功！\n");
            getchar();
            break;
        case 8:
        	//查找二叉树中关键字为e的结点并获得兄弟结点 
            printf("输入您想查找结点的关键字：");
            scanf("%d",&e);
            returnpointer = GetSibling(TREES.elem[now-1].T,e); 
            if(returnpointer == NULL)
            printf("兄弟结点不存在！\n");
            else
            printf("兄弟结点的关键字为：%d\n兄弟结点的名称为：%s\n",returnpointer->data.key,returnpointer->data.others);
            getchar();
            break;
        case 9:
        	//查找二叉树中关键字为e的结点并插入结点 
            printf("输入您想插入结点的关键字：\n");
            scanf("%d",&e);
            printf("输入您想插入的结点：\n");
			printf("key:");
			scanf("%d",&c.key);
			getchar();
			printf("others:");
			scanf("%s",c.others);
			printf("插入位置：左孩子/右孩子/根节点对应0，1，-1\n");
			scanf("%d",&i);
			if(i>1||i<-1)
			{
				printf("插入位置有误！操作中断\n");
				break; 
			}
			returnvalue = InsertNode(TREES.elem[now-1].T,e,i,c);
            if(returnvalue == ERROR)
            printf("插入失败！\n");
            else
            printf("插入成功！\n");
            getchar();
            break;
        case 10:
        	//删除结点 
        	printf("输入您想删除的结点的关键字：");
            scanf("%d",&e);
            returnvalue = DeleteNode(TREES.elem[now-1].T,e);
            if(returnvalue == ERROR)
            printf("删除失败！\n");
            else
            printf("删除成功！\n");
            getchar();
            break;
        case 11:
        	//前序遍历二叉树 
        	if (PreOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
            printf("二叉树不存在！\n");
            getchar();
            break;
        case 12:
        	//中序遍历二叉树 
            if (InOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
            printf("二叉树不存在！\n");
            getchar();
            break;
        case 13:
        	//后序遍历二叉树 
			if (PostOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
            printf("二叉树不存在！\n");
            getchar(); 
            break; 
        case 14:
        	//层序遍历二叉树 
        	if(LevelOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
        	printf("二叉树不存在！\n");
            getchar(); 
            break;
        case 15:
        	//最大路径和
        	returnvalue=MaxPathSum(TREES.elem[now-1].T);
        	if(returnvalue==ERROR)
        	printf("二叉树不存在"); 
        	else
        	printf("从根结点到叶子结点的最大路径和为：%d\n",returnvalue); 
        	break;
		case 16:
			//最近公共祖先 
			printf("输入第一个结点关键字：");
			scanf("%d",&e);
			printf("输入第二个结点关键字：");
			scanf("%d",&e2);
			returnpointer = LowestCommonAncestor(TREES.elem[now-1].T,e,e2);
			if(returnpointer==NULL)
			printf("操作失败！\n"); 
			else
			printf("公共祖先为：\nkey:%d others:%s\n",returnpointer->data.key,returnpointer->data.others);
			break;
		case 17:
			//翻转二叉树
			returnvalue = InvertTree(TREES.elem[now-1].T);
			if(returnvalue==ERROR)
			printf("二叉树翻转失败！\n");
			else
			printf("二叉树翻转成功！\n");
			break;
		case 18:
			//将二叉树写入文件中 
			printf("请输入要存储的文件地址：");
			scanf("%s",name); 
			returnvalue = SaveBiTree(TREES.elem[now-1].T,name);
			if(returnvalue== OVERFLOW)
            printf("文件打开失败!\n");
            else if(returnvalue== ERROR)
            printf("二叉树不存在!\n");
            else
            printf("二叉树存储成功！\n"); 
            getchar();
        	break; 
        case 19:
        	//从文件中读入二叉树 
			printf("请输入要读取的文件地址：");
			scanf("%s",name); 
			returnvalue = LoadBiTree(TREES.elem[now-1].T,name);
			if(returnvalue == ERROR)
            printf("二叉树已存在!\n");
            else if(returnvalue == OVERFLOW)
            printf("文件读取失败!\n");
            else
            printf("二叉树写入成功！\n"); 
            getchar();
        	break; 
		case 20://多二叉树管理系统 
			printf("按enter进入多二叉树管理系统");
			getchar(); 
			getchar(); 
			while(1)
			{
				system("cls");
       		printf("\n");
        	printf("   Menu for Multiple Trees On Chain Structure \n");
       		printf("-------------------------------------------------\n");
        	printf("    1. AddTree        4. TraverseTree\n");
        	printf("    2. RemoveTree     5. RenameTree\n");
        	printf("    3. LocateTree           \n");
        	printf("    0. Exit\n");
        	printf("-------------------------------------------------\n");
        	printf("    请选择你的操作[0~5]:");
        	scanf("%d", &OP);
        	switch (OP)
        	{
        		case 1://添加二叉树 
        			printf("为新添加的二叉树命名：");
					scanf("%s",name); 
        			returnvalue = AddTree(TREES,name);
        			if(returnvalue == OVERFLOW)
					printf("二叉树数量已达上限！\n");
					if(returnvalue == ERROR)
					printf("二叉树名称重复！\n"); 
        			if(returnvalue == OK)
        			printf("创建二叉树成功！\n序号：%d\n名称：%s\n",TREES.length,TREES.elem[TREES.length-1].name);
        			getchar();
        			break;
        		case 2://移除二叉树 
        			printf("输入您想删除的二叉树名称：");
					scanf("%s",name);
					returnvalue = RemoveTree(TREES,name);
					if(returnvalue == ERROR)
					printf("删除二叉树失败！\n");
					if(returnvalue == OK)
					printf("删除二叉树成功！\n剩余二叉树数量：%d\n",TREES.length); 
					getchar();
					break;
				case 3://按名称查找线性表 
					printf("输入您想查找的二叉树名称：");
					scanf("%s",name);
					returnvalue = LocateTree(TREES,name);
					if(returnvalue == 0)
					printf("未查找到该二叉树！\n");
					else
					printf("该二叉树的编号为：%d\n",returnvalue);
					break;
				case 4://遍历各二叉树 
					returnvalue = TraverseTree(TREES);
					if(returnvalue == ERROR)
					printf("不存在二叉树！\n");
					break;
				case 5://二叉树重命名 
					returnvalue = rename(TREES);
					if(returnvalue==ERROR)
					printf("操作中断.\n");
					else
					printf("第%d个二叉树的名称已成功修改为%s\n",returnvalue,TREES.elem[returnvalue-1].name);
					break;
				case 0://退回单二叉树管理系统 
					if(!TREES.length)
					{
						printf("多二叉树管理系统中不存在二叉树，请先创建一个二叉树再回到单二叉树管理系统\n");
						break; 
					 } 
					printf("输入您想管理的二叉树编号[1-%d]：\n",TREES.length);
					scanf("%d",&now);
					if(now > TREES.length || now <=0)
					printf("编号非法！\n"); 
					else
					{
						printf("即将进入单二叉树管理系统......");
						system("pause");
						goto normal;
					} 
					break;
				default :
        		printf("输入非法！请输入[0~5]中的序号\n");
        		break; 
			}
			system("pause");//暂停以显示结果
			}
        case 0:
            break;
        default :
        	printf("输入非法！请输入[0~19]中的序号\n");
        	break; 
        } // end of switch
        system("pause");//暂停以显示结果 
    }     // end of while
    free(name); 
    for(int j=0;j<TREES.length;j++)
    DestroyBiTree(TREES.elem[j].T);
    printf("欢迎下次再使用本系统！\n");
    system("pause");
    return 0;
} // end of main()

