#include "stu.h"
#include "def.h"
/* Graphs On Adjacency List */
int main()
{
    ALGRAPHS GRAPHS; //创建多图结构体 
	VertexType V[30];//用于临时储存顶点数据 
	KeyType VR[100][2];//用于临时储存边数据 
    int now = 1;//now为当前处理的图序号，默认为1 
    GRAPHS.elem[now-1].G.vexnum = 0;
    GRAPHS.elem[now-1].G.arcnum = 0;
    GRAPHS.elem[now-1].G.kind = UDG;//对图进行初始化 
    GRAPHS.length = 1;
    GRAPHS.size = 10;//对多图进行初始化 
    strcpy(GRAPHS.elem[0].name,"Untitled_Graphs_1");//将默认图1的名字改为未命名1 
    int e,e2,i,LR;//用于临时储存输入数据 
    VertexType c;//用于临时储存一个顶点数据 
    status returnvalue;//储存函数返回值 
    int op = 1;//单图操作序号 
    int OP = 1; //多图管理系统操作序号 
    char *name = (char*)malloc(100*sizeof(char));//用于临时储存字符串 
    normal://从多线性表系统到单线性表系统 
    while (op)
    {
		system("cls");//清屏幕 
        printf("Working Graphs%d:%s\n",now,GRAPHS.elem[now-1].name);
        printf("\n");
        printf("        Menu for Graphs On Adjacency List \n");
        printf("-------------------------------------------------\n");
        printf("    1. CreateGraph     10. DeleteArc\n");
        printf("    2. DestroyGraph    11. DFSTraverse\n");
        printf("    3. LocateVex       12. BFSTraverse\n");
        printf("    4. PutVex          13. VerticesSetLessThanK\n");
        printf("    5. FirstAdjVex     14. ShortestPathLength\n");
        printf("    6. NextAdjVex      15. ConnectedComponentsNums\n");
        printf("    7. InsertVex       16. SaveGraph\n");
        printf("    8. DeleteVex       17. LoadGraph\n");
        printf("    9. InsertArc       18. MulGraphsSys\n");
        printf("             0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("请选择你的操作[0~18]:");
        scanf("%d", &op);//输入操作序号 
        switch (op)
        {
        case 1://创建图
        	if(GRAPHS.elem[now-1].G.vexnum)
			{
				printf("图已存在！\n");
				break;
			}
			i=0; 
			printf("请输入图的顶点信息：\n"); 
			do {
    		scanf("%d%s",&V[i].key,V[i].others);
			} while(V[i++].key!=-1);
			i=0;
			printf("请输入图的边信息：\n"); 
			do {
    			scanf("%d%d",&VR[i][0],&VR[i][1]);
   			} while(VR[i++][0]!=-1);
			i=0;
			returnvalue = CreateGraph(GRAPHS.elem[now-1].G,V,VR);
            if (returnvalue == OK)
                printf("图创建成功！\n");
            else
            	printf("顶点或边信息有误！\n");
            getchar();
            break;
        case 2://销毁图
            if (DestroyGraph(GRAPHS.elem[now-1].G) == OK)
                printf("图销毁成功！\n");
            else
                printf("图不存在！\n");
            getchar();
            break;
        case 3://查找图中关键字为e的顶点 
            printf("输入您想查找的顶点关键字：");
            scanf("%d",&e);
            returnvalue = LocateVex(GRAPHS.elem[now-1].G,e);
            if(returnvalue == -1)
            printf("该元素不存在!\n");
            else
            {
            	printf("该元素位序为：%d\n",returnvalue);
            	printf("key:%d\nothers:%s\n",GRAPHS.elem[now-1].G.vertices[returnvalue].data.key,GRAPHS.elem[now-1].G.vertices[returnvalue].data.others);
			}
            getchar();
            break;
        case 4://查找图中关键字为e的顶点并赋值为value 
            printf("输入要查找顶点的关键字：\n");
            scanf("%d",&e);
            printf("输入要赋值的顶点信息：\nkey:");
            scanf("%d",&c.key);
            getchar();
            printf("others:");
            scanf("%s",c.others);
            returnvalue = PutVex (GRAPHS.elem[now-1].G,e,c);
            if( returnvalue== INFEASIBLE)
            printf("图不存在！\n");
            else if(returnvalue == ERROR)
            printf("顶点不存在！\n");
            else
            printf("赋值成功！\n");
            getchar();
            break;
        case 5:
        	//查找图中关键字为e的顶点并获得第一邻接点
            printf("输入您想查找顶点的关键字：");
            scanf("%d",&e);
            returnvalue = FirstAdjVex(GRAPHS.elem[now-1].G,e); 
            if(returnvalue == -1)
            printf("顶点不存在\n");
            else
            printf("第一邻接点的关键字为：%d\n第一邻接点的名称为：%s\n",GRAPHS.elem[now-1].G.vertices[returnvalue].data.key,GRAPHS.elem[now-1].G.vertices[returnvalue].data.others);
            getchar();
            break;
        case 6:
			//查找图中关键字为e的顶点并获得下一邻接点
			printf("输入您想查找顶点的关键字：");
            scanf("%d",&e);
            printf("输入您想查找顶点的邻接点的关键字：");
            scanf("%d",&e2);
            returnvalue = NextAdjVex(GRAPHS.elem[now-1].G,e,e2); 
            if(returnvalue == -1)
            printf("顶点不存在或不邻接或不存在下一个邻接点！\n");
            else
            printf("下一邻接点的关键字为：%d\n下一邻接点的名称为：%s\n",GRAPHS.elem[now-1].G.vertices[returnvalue].data.key,GRAPHS.elem[now-1].G.vertices[returnvalue].data.others);
            getchar();
            break;
        case 7:
        	//插入顶点 
            printf("输入您想插入的顶点：\n");
			printf("key:");
			scanf("%d",&c.key);
			getchar();
			printf("others:");
			scanf("%s",c.others);
			returnvalue = InsertVex(GRAPHS.elem[now-1].G,c);
			if(returnvalue == INFEASIBLE)
			printf("图不存在！\n");
            else if(returnvalue == ERROR)
            printf("插入失败！\n");
            else
            printf("插入成功！\n");
            getchar();
            break;
        case 8:
        	//删除顶点 
        	printf("输入您想删除的顶点的关键字：");
            scanf("%d",&e);
            returnvalue = DeleteVex(GRAPHS.elem[now-1].G,e);
            if(returnvalue == INFEASIBLE)
			printf("图不存在！\n");
			else if(returnvalue == ERROR)
            printf("删除失败！\n");
            else
            printf("删除成功！\n");
            getchar();
            break;
        case 9:
        	//插入弧 
            printf("输入您想插入的弧：\n");
			scanf("%d%d",&e,&e2);
			returnvalue = InsertArc(GRAPHS.elem[now-1].G,e,e2);
			if(returnvalue == INFEASIBLE)
			printf("图不存在！\n");
            else if(returnvalue == ERROR)
            printf("插入失败！\n");
            else
            printf("插入成功！\n");
            getchar();
            break;
        case 10:
        	//删除弧 
            printf("输入您想删除的弧：\n");
			scanf("%d%d",&e,&e2);
			returnvalue = DeleteArc(GRAPHS.elem[now-1].G,e,e2);
			if(returnvalue == INFEASIBLE)
			printf("图不存在！\n");
            else if(returnvalue == ERROR)
            printf("删除失败！\n");
            else
            printf("删除成功！\n");
            getchar();
            break; 
        case 11:
        	//深度优先搜索遍历 
        	if (DFSTraverse(GRAPHS.elem[now-1].G,visit) == INFEASIBLE)
            printf("图不存在！\n");
            getchar();
            break;
        case 12:
        	//广度优先搜索遍历 
            if (BFSTraverse(GRAPHS.elem[now-1].G,visit) == INFEASIBLE)
            printf("图不存在！\n");
            getchar();
            break;
        case 13:
        	//距离小于k的顶点集合 
        	printf("输入起始点的关键字：");
        	scanf("%d",&e);
        	printf("输入距离k："); 
        	scanf("%d",&i);
        	VerticesSetLessThanK(GRAPHS.elem[now-1].G,e,i);
            getchar(); 
            break; 
        case 14:
        	//顶点间最短路径和长度 
        	printf("输入起点的关键字：");
        	scanf("%d",&e);
        	printf("输入终点的关键字：");
        	scanf("%d",&e2);
        	returnvalue = ShortestPathLength(GRAPHS.elem[now-1].G,e,e2);
        	if(returnvalue == -1)
        	printf("图不存在或找不到顶点！\n");
        	else 
        	printf("顶点间最短路径的长度为：%d\n",returnvalue);
            getchar(); 
            break;
        case 15:
        	//图的连通分量
        	returnvalue=ConnectedComponentsNums(GRAPHS.elem[now-1].G);
        	if(returnvalue==ERROR)
        	printf("图不存在"); 
        	else
        	printf("图的连通分量数为：%d\n",returnvalue); 
        	break;
		case 16:
			//将图写入文件中 
			printf("请输入要存储的文件地址：");
			scanf("%s",name); 
			returnvalue = SaveGraph(GRAPHS.elem[now-1].G,name);
			if(returnvalue== OVERFLOW)
            printf("文件打开失败!\n");
            else if(returnvalue== ERROR)
            printf("图不存在!\n");
            else
            printf("图存储成功！\n"); 
            getchar();
        	break; 
        case 17:
        	//从文件中读入图 
			printf("请输入要读取的文件地址：");
			scanf("%s",name); 
			returnvalue = LoadGraph(GRAPHS.elem[now-1].G,name);
			if(returnvalue == ERROR)
            printf("图已存在!\n");
            else if(returnvalue == OVERFLOW)
            printf("文件读取失败!\n");
            else
            printf("图写入成功！\n"); 
            getchar();
        	break; 
		case 18://多图管理系统 
			printf("按enter进入多图管理系统");
			getchar(); 
			getchar(); 
			while(1)
			{
				system("cls");
       		printf("\n");
        	printf("   Menu for Multiple Graphss On Chain Structure \n");
       		printf("-------------------------------------------------\n");
        	printf("    1. AddGraphs        4. TraverseGraphs\n");
        	printf("    2. RemoveGraphs     5. RenameGraphs\n");
        	printf("    3. LocateGraphs           \n");
        	printf("    0. Exit\n");
        	printf("-------------------------------------------------\n");
        	printf("请选择你的操作[0~5]:");
        	scanf("%d", &OP);
        	switch (OP)
        	{
        		case 1://添加图 
        			printf("为新添加的图命名：");
					scanf("%s",name); 
        			returnvalue = AddGraph(GRAPHS,name);
        			if(returnvalue == OVERFLOW)
					printf("图数量已达上限！\n");
					if(returnvalue == ERROR)
					printf("图名称重复！\n"); 
        			if(returnvalue == OK)
        			printf("创建图成功！\n序号：%d\n名称：%s\n",GRAPHS.length,GRAPHS.elem[GRAPHS.length-1].name);
        			getchar();
        			break;
        		case 2://移除图 
        			printf("输入您想删除的图名称：");
					scanf("%s",name);
					returnvalue = RemoveGraph(GRAPHS,name);
					if(returnvalue == ERROR)
					printf("删除图失败！\n");
					if(returnvalue == OK)
					printf("删除图成功！\n剩余图数量：%d\n",GRAPHS.length); 
					getchar();
					break;
				case 3://按名称查找线性表 
					printf("输入您想查找的图名称：");
					scanf("%s",name);
					returnvalue = LocateGraph(GRAPHS,name);
					if(returnvalue == 0)
					printf("未查找到该图！\n");
					else
					printf("该图的编号为：%d\n",returnvalue);
					break;
				case 4://遍历各图 
					returnvalue = TraverseGraph(GRAPHS);
					if(returnvalue == ERROR)
					printf("不存在图！\n");
					break;
				case 5://图重命名 
					returnvalue = rename(GRAPHS);
					if(returnvalue==ERROR)
					printf("操作中断.\n");
					else
					printf("第%d个图的名称已成功修改为%s\n",returnvalue,GRAPHS.elem[returnvalue-1].name);
					break;
				case 0://退回单图管理系统
					if(!GRAPHS.length)
					{
						printf("多图管理系统中不存在图，请先创建一个图再回到单图管理系统\n");
						break; 
					 } 
					printf("输入您想管理的图编号[1-%d]：\n",GRAPHS.length);
					scanf("%d",&now);
					if(now > GRAPHS.length || now <=0)
					printf("编号非法！\n"); 
					else
					{
						printf("即将进入单图管理系统......");
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
    for(int j=0;j<GRAPHS.length;j++)
    DestroyGraph(GRAPHS.elem[j].G);
    printf("欢迎下次再使用本系统！\n");
    system("pause");
    return 0;
} // end of main()

