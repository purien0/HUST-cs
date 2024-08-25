#include "stu.h"
#include "def.h"
int main()
{
    LISTS LIST;
    int now = 1;//now为当前处理的线性表序号，默认为1 
    LIST.elem[now-1].L.elem = NULL;
    LIST.length = 1;
    LIST.listsize = 10;
    strcpy(LIST.elem[0].name,"Untitled_List_1");//将默认线性表1的名字改为未命名1
    int e,e2,i;
    int returnvalue;//储存函数返回值
    int op = 1; //单线性表操作序号 
	int OP = 1;//多线性表管理系统操作序号 
    char *name = (char*)malloc(100*sizeof(char));
    normal://从多线性表系统到单线性表系统
    OP = 1 ; 
    while (op)
    {
		system("cls");//清屏幕 
        printf("Working List%d:%s\n",now,LIST.elem[now-1].name);
        printf("\n");
        printf("    Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    1. InitList       10. ListInsert\n");
        printf("    2. DestroyList    11. ListDelete\n");
        printf("    3. ClearList      12. ListTraverse\n");
        printf("    4. ListEmpty      13. MaxSubArray\n");
        printf("    5. ListLength     14. SubArrayNum\n");
        printf("    6. GetElem        15. SortList\n");
        printf("    7. LocateElem     16. SaveList\n");
        printf("    8. PriorElem      17. LoadList\n");
        printf("    9. NextElem       18. OnceInitList\n");
        printf("                      19. MulListSys\n");
        printf("             0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~19]:");
        scanf("%d", &op);//输入操作序号 
        switch (op)
        {
        case 1://创建线性表
            if (InitList(LIST.elem[now-1].L) == OK)
                printf("线性表创建成功！\n");
            else
                printf("线性表已存在！\n");
            getchar();
            break;
        case 2://销毁线性表 
            if (DestroyList(LIST.elem[now-1].L) == OK)
                printf("线性表销毁成功！\n");
            else
                printf("线性表不存在！\n");
            getchar();
            break;
        case 3://清空线性表
            if (ClearList(LIST.elem[now-1].L) == OK)
                printf("线性表清空成功！\n");
            else
                printf("线性表不存在！\n");
            getchar();
            break;
        case 4://检查线性表是否为空 
            if (ListEmpty(LIST.elem[now-1].L) == TRUE)
                printf("线性表为空！\n");
            else if (ListEmpty(LIST.elem[now-1].L) == FALSE)
                printf("线性表不为空！\n");
            else
                printf("线性表不存在！\n");
            getchar();
            break;
        case 5://输出线性表长度 
            if (ListLength(LIST.elem[now-1].L) == INFEASIBLE)
                printf("线性表不存在！\n");
            else
            printf("线性表长度为%d\n",ListLength(LIST.elem[now-1].L));
            getchar();
            break;
        case 6://查找线性表中输入元素序号的元素
            printf("输入元素序号：");
            scanf("%d",&i);
            returnvalue = GetElem(LIST.elem[now-1].L,i,e);
            if( returnvalue== INFEASIBLE)
            printf("线性表不存在!\n");
            else if(returnvalue == ERROR)
            printf("序号非法！\n");
            else
            printf("您选择的元素为：%d\n", e);
            getchar();
            break;
        case 7://查找线性表中输入元素的元素序号
            printf("输入您想查找的元素：");
            scanf("%d",&e);
            returnvalue = LocateElem(LIST.elem[now-1].L,e);
            if(returnvalue == INFEASIBLE)
            printf("线性表不存在!\n");
            if(returnvalue == 0)
            printf("元素不存在!\n");
            else
            printf("元素序号为：%d\n",returnvalue);
            getchar();
            break;
        case 8://查找线性表中输入元素的前驱
            printf("输入您想查找的元素：");
            scanf("%d",&e);
            returnvalue = PriorElem(LIST.elem[now-1].L,e,e2);
            if( returnvalue== INFEASIBLE)
            printf("线性表不存在!\n");
            else if(returnvalue == NEXIST)
            printf("该元素不存在前驱！\n");
            else if(returnvalue == ERROR)
            printf("该元素不存在于线性表中！\n");
            else
            printf("您选择的元素的前驱为：%d\n", e2);
            getchar();
            break;
        case 9://查找线性表中输入元素的后继
            printf("输入您想查找的元素：");
            scanf("%d",&e);
            returnvalue = NextElem(LIST.elem[now-1].L,e,e2);
            if( returnvalue== INFEASIBLE)
            printf("线性表不存在!\n");
            else if(returnvalue == ERROR)
            printf("该元素不存在于线性表中！\n");
            else if(returnvalue == NEXIST)
            printf("该元素不存在后继！\n");
            else
            printf("您选择的元素的后继为：%d\n", e2);
            getchar();
            break;
        case 10://在线性表中对应元素序号之前插入元素
        	printf("输入您想插入的元素：");
            scanf("%d",&e);
            printf("输入元素序号：[1-%d]\n",LIST.elem[now-1].L.length+1);
            scanf("%d",&i); 
            returnvalue = ListInsert(LIST.elem[now-1].L,i,e);
            if( returnvalue == INFEASIBLE)
            printf("线性表不存在!\n");
            else if(returnvalue == ERROR)
            printf("序号非法！\n");
            else
            printf("插入成功！\n");
            getchar();
            break;
        case 11:
        	//在线性表中删除对应元素序号的元素
            printf("输入元素序号：[1-%d]\n",max(LIST.elem[now-1].L.length,1));
            //提示合法的元素序号，防止用户输入错误
            scanf("%d",&i);
            returnvalue = ListDelete(LIST.elem[now-1].L,i,e);
            if( returnvalue== INFEASIBLE)
            printf("线性表不存在!\n");
            if(returnvalue == ERROR)
            printf("序号非法！\n");
            else
            printf("您删除的元素为：%d！\n",e);
            getchar();
            break;
        case 12://遍历线性表并输出每一个元素
            if (!ListTraverse(LIST.elem[now-1].L))
                printf("线性表是空表！\n");
            getchar();
            break;
        case 13://计算线性表中最大连续子数组和 
        	returnvalue = MaxSubArray(LIST.elem[now-1].L);
			if(returnvalue == -1)
				printf("线性表不存在或为空表！\n");
			else
				printf("最大连续子数组和为：%d\n",returnvalue);
			getchar();
			break;
		case 14://计算线性表中和为k的连续子数组个数 
			printf("输入子数组和k：\n"); 
			scanf("%d",&i); 
			returnvalue = SubArrayNum(LIST.elem[now-1].L,i);
			if(returnvalue == ERROR)
				printf("线性表不存在或为空表！\n");
			else
				printf("和为k的连续子数组数目为：%d\n",returnvalue);
			getchar();
			break;
		case 15:
			//将线性表升序排序 
			returnvalue = sortList(LIST.elem[now-1].L);
			if(returnvalue == INFEASIBLE)
				printf("线性表不存在或为空表！\n");
			else
				printf("线性表排序成功!\n");
			break;
		case 16:
			//将线性表写入文件中
			printf("请输入要存储的文件地址：");
			scanf("%s",name); 
			returnvalue = SaveList(LIST.elem[now-1].L,name);
			if(returnvalue== INFEASIBLE)
            printf("线性表不存在!\n");
            else if(returnvalue== ERROR)
            printf("文件写入失败!\n");
            else
            printf("线性表存储成功！\n"); 
            getchar();
        	break; 
        case 17:
        	//从文件中读入线性表
			printf("请输入要读取的文件地址：");
			scanf("%s",name); 
			returnvalue = LoadList(LIST.elem[now-1].L,name);
			if(returnvalue == INFEASIBLE)
            printf("线性表已存在!\n");
            else if(returnvalue == ERROR)
            printf("文件读取失败!\n");
            else
            printf("线性表写入成功！\n"); 
            getchar();
        	break; 
        case 18:
        	//一次性输入数据
			printf("请输入元素个数：\n");
			scanf("%d",&i);
			if(LIST.elem[now-1].L.elem)
			{
				ClearList(LIST.elem[now-1].L);
			}
			else
			{
				printf("线性表不存在！\n");
				break; 
			}
			printf("请输入数据：\n"); 
			for(int j=0;j < i;j++)
			{
				scanf("%d",&e);
				ListInsert(LIST.elem[now-1].L,j+1,e);
			}
			printf("输入结束\n");
			break;
		case 19://多线性表系统
			printf("按enter进入多线性表管理系统");
			getchar(); 
			getchar(); 
			while(1)
			{
				system("cls");
       		printf("\n");
        	printf("   Menu for Multiple Linear Tables On Sequence Structure \n");
       		printf("-------------------------------------------------\n");
        	printf("    1. AddList        4. TraverseList\n");
        	printf("    2. RemoveList     5. RenameList\n");
        	printf("    3. LocateList           \n");
        	printf("    0. Exit\n");
        	printf("-------------------------------------------------\n");
        	printf("    请选择你的操作[0~5]:");
        	scanf("%d", &OP);
        	switch (OP)
        	{
        		case 1://添加线性表 
        			printf("为新添加的线性表命名：");
					scanf("%s",name); 
        			returnvalue = AddList(LIST,name);
        			if(returnvalue == OVERFLOW)
					printf("线性表数量已达上限！\n");
					if(returnvalue == ERROR)
					printf("线性表名称重复！\n"); 
        			if(returnvalue == OK)
        			printf("创建线性表成功！\n序号：%d\n名称：%s\n",LIST.length,LIST.elem[LIST.length-1].name);
        			getchar();
        			break;
        		case 2://移除线性表 
        			printf("输入您想删除的线性表名称：");
					scanf("%s",name);
					returnvalue = RemoveList(LIST,name);
					if(returnvalue == UNDERFLOW)
					printf("线性表已空！\n");
					if(returnvalue == ERROR)
					printf("删除线性表失败！\n");
					if(returnvalue == OK)
					printf("删除线性表成功！\n剩余线性表数量：%d\n",LIST.length); 
					getchar();
					break;
				case 3://按名称查找线性表 
					printf("输入您想查找的线性表名称：");
					scanf("%s",name);
					returnvalue = LocateList(LIST,name);
					if(returnvalue == 0)
					printf("未查找到该线性表！\n");
					else
					printf("该线性表的编号为：%d\n",returnvalue);
					break;
				case 4://遍历各线性表 
					returnvalue = TraverseList(LIST);
					if(returnvalue == ERROR)
					printf("不存在线性表！\n");
					break;
				case 5://线性表重命名 
					returnvalue = rename(LIST);
					if(returnvalue==ERROR)
					printf("操作中断.\n");
					else
					printf("第%d个线性表的名称已成功修改为%s\n",returnvalue,LIST.elem[returnvalue-1].name);
					break;
				case 0://退回单线性表管理系统 
					printf("输入您想管理的线性表编号[1-%d]：\n",LIST.length);
					scanf("%d",&now);
					if(now > LIST.length || now <=0)
					printf("编号非法！\n"); 
					else
					{
						printf("即将进入单线性表管理系统......");
						system("pause");//暂停以显示结果
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
    for(int j=0;j<LIST.length;j++)
    DestroyList(LIST.elem[j].L);
    printf("欢迎下次再使用本系统！\n");
    system("pause");
    return 0;
} // end of main()

