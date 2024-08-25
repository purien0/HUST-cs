#include "def.h"
void visit(VertexType V) {//访问结点函数 
	printf("        key：%d,others：%s\n",V.key,V.others);
}
void visit2(VertexType V) { 
	return;
}

status isRep(VertexType V[],int count)
{//检测是否有相同关键字 
    for(int i=0 ; i<count-1; i++)
    {
        for(int j=i+1;j<count-1;j++)
        {
            if(V[i].key==V[j].key)
            return TRUE;
        }
    }
    return FALSE;
}
status CreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。*/
{
	if(G.vexnum != 0)
	return INFEASIBLE;
	G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG;
    ArcNode *temp;
    int i,j; 
    while(V[G.vexnum].key!=-1)
    {
        if(G.vexnum == 20)
        return ERROR;
        G.vertices[G.vexnum].data.key = V[G.vexnum].key;
        strcpy(G.vertices[G.vexnum].data.others,V[G.vexnum].others);
        G.vertices[G.vexnum].firstarc = NULL;
        G.vexnum++;
    }
    if(G.vexnum == 0)//检查是否为空图
    return ERROR;
    if(isRep(V,G.vexnum)==TRUE)//检查关键字是否相同
    return ERROR;
    while(VR[G.arcnum][0] != -1)
    {
        temp = (ArcNode*)malloc(sizeof(ArcNode));
        for(i=0;i<G.vexnum;i++)//找到弧尾
        {
            if(G.vertices[i].data.key == VR[G.arcnum][0])
            break;
        }
        if(i==G.vexnum)//边信息错误（找不到结点）
        return ERROR;
        for(j=0;j<G.vexnum;j++)//找到弧头
        {
            if(G.vertices[j].data.key == VR[G.arcnum][1])
            break;
        }
        if(j==G.vexnum)//边信息错误（找不到结点）
        return ERROR;
        temp->adjvex = j;
        temp->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = temp;
        temp = (ArcNode*)malloc(sizeof(ArcNode));
        temp->adjvex = i;
        temp->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = temp;
        G.arcnum++;
    }
    return OK;
}

status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    if(!G.vexnum)
    return ERROR;
    ArcNode * temp;
    for(int i=0;i<G.vexnum;i++)
    {
        while((temp=G.vertices[i].firstarc)!=NULL)
        {
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
            free(temp);
        }
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
}

int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
	for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==u)
        return i;
    }
    return -1;
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果图不存在，返回INFEASIBLE 
//如果查找失败或关键字不唯一，返回ERROR
{
    if(!G.vexnum)
    return INFEASIBLE;
	int flag=0;
	int ui; 
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key == u)
        {
            ui=i;
			flag=1;
            continue;
        }
        if(G.vertices[i].data.key == value.key)//若关键字重复 
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
    	G.vertices[ui].data = value;
    	return OK;
	}
    else
    return ERROR;
}

int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key == u)
        {
            if(!G.vertices[i].firstarc)
            return -1;
            else
            return G.vertices[i].firstarc->adjvex;
        }
    }
    return -1;
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
	for(int i=0; i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key == v)
        {
            ArcNode * temp = G.vertices[i].firstarc; 
            while(temp)
            {
                if(G.vertices[temp->adjvex].data.key == w)
                {
                    if(temp->nextarc)
                    return temp->nextarc->adjvex;
                    else
                    return -1;
                }
                temp = temp->nextarc;
            }
            return -1;
        }
    }
    return -1;
}

status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    if(!G.vexnum)//若图不存在 
    return INFEASIBLE;
	if(G.vexnum==MAX_VERTEX_NUM)
    return ERROR;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v.key)
        return ERROR;
    }
    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++;
    return OK;
}

status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    if(!G.vexnum)//若图不存在 
    return INFEASIBLE;
	ArcNode * temp;
    ArcNode * temp2;
    ArcNode * temp2_last=NULL;
    for(int i = 0;i < G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v)//找到关键字v对应节点
        {
            if(G.vexnum==1)
            return ERROR;
            temp = G.vertices[i].firstarc;
            while(temp)//依次消去弧
            {
                G.vertices[i].firstarc = temp->nextarc;
                temp2 = G.vertices[temp->adjvex].firstarc;
                while(temp2)//消去弧头结点的弧
                {
                    if(temp2->adjvex==i)
                    {
                        if(!temp2_last)//若为第一条弧
                        {
                            G.vertices[temp->adjvex].firstarc=temp2->nextarc;
                            free(temp2);
                        }else
                        {
                            temp2_last->nextarc = temp2->nextarc;
                            free(temp2);
                        }
                        temp2_last = NULL;
                        break;
                    }
                    temp2_last=temp2;
                    temp2 = temp2->nextarc;
                }
                free(temp);//消去弧尾结点的弧
                G.arcnum=G.arcnum-1;
                temp = G.vertices[i].firstarc;
            }
            for(int j=i;j<G.vexnum-1;j++)
            {
                G.vertices[j]=G.vertices[j+1];
            }
            G.vexnum--;
            for(int j=0;j<G.vexnum;j++)//调整其它弧
            {
                temp2 = G.vertices[j].firstarc;
                while(temp2)
                {
                    if(temp2->adjvex>i)
                    temp2->adjvex--;
                    temp2=temp2->nextarc;
                }
            }
            return OK;
        }
    }
    return ERROR;
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    if(!G.vexnum)//若图不存在 
    return INFEASIBLE;
	ArcNode *temp;
    int vi=-1,wi=-1;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key == v)
        vi=i;
        if(G.vertices[i].data.key == w)
        wi=i;
    }
    if(vi==-1||wi==-1)//检查顶点是否存在
    return ERROR;
    temp = G.vertices[vi].firstarc;
    while(temp)//检查顶点是否已有弧
    {
        if(temp->adjvex==wi)
        return ERROR;
        temp = temp->nextarc;
    }
    //在v处插入弧
    temp = (ArcNode*)malloc(sizeof(ArcNode));
    temp->adjvex = wi;
    temp->nextarc = G.vertices[vi].firstarc;
    G.vertices[vi].firstarc = temp;
    //在w处插入弧
    temp = (ArcNode*)malloc(sizeof(ArcNode));
    temp->adjvex = vi;
    temp->nextarc = G.vertices[wi].firstarc;
    G.vertices[wi].firstarc = temp;
    
    G.arcnum++;
    return OK;
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    if(!G.vexnum)//若图不存在 
    return INFEASIBLE;
	int i=0,j=0;//i,j分别存储v和w对应结点的序号
    for(i=0;i<G.vexnum;i++)//寻找到v对应结点
    {
        if(G.vertices[i].data.key==v)
        break;
    }
    if(i==G.vexnum)//若未寻找到v对应结点
    return ERROR;
    for(j=0;j<G.vexnum;j++)//寻找到w对应结点
    {
        if(G.vertices[j].data.key==w)
        break;
    }
    if(j==G.vexnum)//若未寻找到w对应结点
    return ERROR;
    ArcNode *temp1=G.vertices[i].firstarc;//存储v结点处弧的指针
    ArcNode *temp_last1=NULL;//存储v结点处弧的上一个弧的指针
    while(1)//寻找v结点处目标弧
    {
        if(!temp1)//若未找到该弧
        return ERROR;
        if(temp1->adjvex==j)//找到该弧
        break;
        temp_last1=temp1;
        temp1=temp1->nextarc;
    }
    ArcNode *temp2=G.vertices[j].firstarc;//存储w结点处弧的指针
    ArcNode *temp_last2=NULL;//存储w结点处弧的上一个弧的指针
    while(1)//寻找w结点处目标弧
    {
        if(!temp2)//若未找到该弧
        return ERROR;
        if(temp2->adjvex==i)//找到该弧
        break;
        temp_last2=temp2;
        temp2=temp2->nextarc;
    }
    //两个结点处目标弧均已找到，开始删除弧
    //删除v结点处弧
    if(!temp_last1)//若目标弧为第一条弧
    {
        G.vertices[i].firstarc=temp1->nextarc;
        free(temp1);
    }
    else
    {
        temp_last1->nextarc=temp1->nextarc;
        free(temp1);
    }
    //删除w结点处弧
    if(!temp_last2)//若目标弧为第一条弧
    {
        G.vertices[j].firstarc=temp2->nextarc;
        free(temp2);
    }
    else
    {
        temp_last2->nextarc=temp2->nextarc;
        free(temp2);
    }
    G.arcnum--;
    return OK;
}

status visited[MAX_VERTEX_NUM];
status DFS(ALGraph G,int i,void (*visit)(VertexType))
{//深度优先搜索所用的递归函数 
	if(!visited[i])
    {
        visit(G.vertices[i].data);
        visited[i]=TRUE;
        ArcNode *temp=G.vertices[i].firstarc;
        while(temp)
        {
            DFS(G,temp->adjvex,visit);
            temp=temp->nextarc;
        }
    }
}
status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    if(!G.vexnum)//若图不存在 
    return INFEASIBLE;
    for(int i=0;i<G.vexnum;i++)
    visited[i]=0;//初始化 
	for(int i=0;i<G.vexnum;i++)
    DFS(G,i,visit);
    return OK;
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    if(!G.vexnum)//若图不存在 
    return INFEASIBLE;
	int queue[MAX_VERTEX_NUM];
    int top=0,tail=0;
    for(int i=0;i<G.vexnum;i++)
    visited[i]=0;//初始化 
    ArcNode * temp;
    for(int i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            queue[tail++]=i;
            visited[i]=TRUE;
            temp=G.vertices[i].firstarc;
            while(temp)
            {
                if(!visited[temp->adjvex])
                {
                    queue[tail++]=temp->adjvex;
                    visited[temp->adjvex]=TRUE;
                }
                temp=temp->nextarc;
            }
        }
    }
    while(top!=tail)
    visit(G.vertices[queue[top++]].data);
    return OK;
}

int isrep(ALGRAPHS Graphs,char *name)
//检测输入的名称是否与Graphs中已存在的图名称相同，若相同返回TRUE，若不同返回FALSE 
{
	for(int i=0;i<Graphs.length;i++)
	{
		if(!strcmp(name,Graphs.elem[i].name))
		return TRUE;
	}
	return FALSE;
}
status AddGraph(ALGRAPHS &Graphs, char GraphName[])
// 只需要在Graphs中增加一个名称为GraphName的图 
{
    if(Graphs.length == Graphs.size)
    return OVERFLOW;
    if(isrep(Graphs,GraphName))
    return ERROR;
	strcpy(Graphs.elem[Graphs.length].name, GraphName);
    Graphs.elem[Graphs.length].G.vexnum = 0;
    Graphs.elem[Graphs.length].G.arcnum = 0;
    Graphs.elem[Graphs.length].G.kind = UDG;
    Graphs.length++;
    return OK;
}

status RemoveGraph(ALGRAPHS &Graphs, char GraphName[])
// Graphs中删除一个名称为GraphName的图 
{
    if(Graphs.length == 0)
    return ERROR;
    for (int i = 0; i < Graphs.length; i++)
    {
        if (strcmp(Graphs.elem[i].name, GraphName) == 0)
        {
            DestroyGraph(Graphs.elem[i].G);
			for (int j = i; j < Graphs.length - 1; j++)
            {
                Graphs.elem[j].G = Graphs.elem[j + 1].G;
                strcpy(Graphs.elem[j].name, Graphs.elem[j + 1].name);
            }
            Graphs.length--;
            return OK;
        }
    }
    return ERROR;
}

int LocateGraph(ALGRAPHS Graphs, char GraphName[])
// 在Graphs中查找一个名称为GraphName的图，成功返回逻辑序号，否则返回0
{
    for (int i = 0; i < Graphs.length; i++)
    {
        if (strcmp(Graphs.elem[i].name, GraphName) == 0)
        {
            return i + 1;
        }
    }
    return 0;
}
status TraverseGraph(ALGRAPHS Graphs)
// 如果Graphs中有图，依次显示图序号和名称，每个图占一行，返回OK；如果Graphs为空，返回ERROR。
{
	int op;
	if(Graphs.length==0)
	return ERROR;
	printf("选择遍历类型：\n深度优先搜索/广度优先搜索 分别输入1，2\n");
	scanf("%d",&op);
	if(op<1||op>2)
	{
		printf("输入序号有误，操作中断\n");
		return ERROR;
	}
	printf("已存在的图如下所示：\n");
	for(int i=0;i<Graphs.length;i++)
	{
		printf("Graph %d : %s\n",i+1,Graphs.elem[i].name);
		switch(op)
		{
			case 1:
				DFSTraverse(Graphs.elem[i].G,visit); 
				break;
			case 2:
				BFSTraverse(Graphs.elem[i].G,visit);
				break;
		}
	}
	return OK;
}

status rename(ALGRAPHS &Graphs)
//重命名图，若成功重命名，返回OK，若操作中断，返回ERROR 
{
	int state=1;
	int i=0;
	char *name = (char*)malloc(sizeof(char)*100);//动态分配空间 
	printf("输入您想要修改的表的序号：[1-%d]\n",Graphs.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Graphs.length)
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
	if(isrep(Graphs,name))//检查名称是否重复 
	{
		printf("输入名称重复\n");
		free(name);
		return ERROR; 
	}
	strcpy(Graphs.elem[i-1].name,name);
	free(name);
	return i;			
}

int mark[MAX_VERTEX_NUM+1];//标志哪些顶点属于与顶点v距离小于k的顶点集合

void dfs(ALGraph G,int num,int k)
{//找出距离小于k的顶点并更新mark 
	if(!k)//若距离已达到 
	return;
	if(mark[num])//若已处理 
	return;
	mark[num]=1;
	ArcNode *temp=G.vertices[num].firstarc;
	while(temp)
	{
		dfs(G,temp->adjvex,k-1);
		temp=temp->nextarc;
	}
}

void VerticesSetLessThanK(ALGraph G,KeyType v,int k)
//距离小于k的顶点集合
//初始条件是图G存在；操作结果是返回与顶点v距离小于k的顶点集合
{
	if(k<=0)
	{
		printf("输入非法！\n");
		return;
	}
	for(int i=0;i<G.vexnum;i++)
	mark[i]=0;//初始化
	int i;
	i = LocateVex(G,v);
	if(i==-1)
	{
		printf("找不到顶点！\n");
		return;
	}
	mark[i]=1;
	ArcNode *temp=G.vertices[i].firstarc;
	while(temp)
	{
		dfs(G,temp->adjvex,k-1);
		temp=temp->nextarc;
	}
	printf("距离小于k的顶点集合:\n");
	for(int i=0;i<G.vexnum;i++)
	if(mark[i])
	printf("%d %s ",G.vertices[i].data.key,G.vertices[i].data.others);
}
int ShortestPathLength(ALGraph G,KeyType v,KeyType w)
//顶点间最短路径和长度
//初始条件是图G存在；操作结果是返回顶点v与顶点w的最短路径的长度
{
	for(int i=0;i<G.vexnum;i++)
	mark[i]=0;//初始化
	int vi=LocateVex(G,v);
	int wi=LocateVex(G,w);
	ArcNode *temp; 
	if(vi==-1||wi==-1)//在图内找不到结点v/w 
	return -1;
	if(vi==wi)
	return 0;
	int k=2;
	temp=G.vertices[vi].firstarc;
	while(!mark[wi])
	{
		for(int i=0;i<G.vexnum;i++)
		mark[i]=0;//初始化
		mark[vi]=1;
		temp=G.vertices[vi].firstarc;
		while(temp)
		{
		dfs(G,temp->adjvex,k-1);
		temp=temp->nextarc;
		}
		k++;
		if(k>2*G.vexnum)
		return INFINITY;
	}
	return k-2;
}
int ConnectedComponentsNums(ALGraph G)
//图的连通分量
//初始条件是图G存在；操作结果是返回图G的所有连通分量的个数
{
	int count=0; 
	for(int i=0;i<G.vexnum;i++)
	visited[i]=0;
	for(int i=0;i<G.vexnum;i++)
	{
		if(visited[i]==0)
		{
			count++;
			DFS(G,i,visit2);
		}
	}
    return count;
}
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);
status isRepeatArc(KeyType arc[][2],KeyType v,KeyType w,int count)
{
    for(int i=0;i<count;i++)
    {
        if((arc[i][0]==v&&arc[i][1]==w)||(arc[i][0]==w&&arc[i][1]==v))
        return TRUE;
    }
    return FALSE;
}

status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    if(!G.vexnum)//若图不存在 
	return ERROR; 
	FILE* fp=fopen(FileName,"w");
    if(!fp)
    return OVERFLOW;
    KeyType arc[G.vexnum*(G.vexnum+1)/2][2];
    int count=0;
    ArcNode *temp;
    for(int i=0;i<G.vexnum;i++)
    {
        //存储顶点信息
        fprintf(fp,"%d %s ",G.vertices[i].data.key,G.vertices[i].data.others);
        temp=G.vertices[i].firstarc;
        while(temp)
        {
            if(!isRepeatArc(arc,G.vertices[i].data.key,G.vertices[temp->adjvex].data.key,count))//若弧不重复，将弧放进arc数组
            {
                arc[count][0]=G.vertices[i].data.key;
                arc[count][1]=G.vertices[temp->adjvex].data.key;
                count++;
            }
            temp=temp->nextarc;
        }
    }
    fprintf(fp,"-1 nil ");
    //对弧数组排序
    KeyType t;//用于交换值
    for(int i=0;i<count;i++)//保证弧的第一个值大于第二个值
    {
        if(arc[i][0]>arc[i][1])
        {
            t=arc[i][0];
            arc[i][0]=arc[i][1];
            arc[i][1]=t;
        }
    }
    for(int i=0;i<count;i++)//保证弧的第一个关键字大于第二个关键字,并以第一个关键字为主，第二个关键字为副进行升序排序
    {
        for(int j=0;j<count-1;j++)
        {
            if(arc[j][0]>arc[j+1][0])
        {
            t=arc[j][0];
            arc[j][0]=arc[j+1][0];
            arc[j+1][0]=t;
            t=arc[j][1];
            arc[j][1]=arc[j+1][1];
            arc[j+1][1]=t;
        }
        if(arc[j][0]==arc[j+1][0]&&arc[j][1]>arc[j+1][1])
        {
            t=arc[j][1];
            arc[j][1]=arc[j+1][1];
            arc[j+1][1]=t;
        }
        }
    }
    for(int i=0;i<count;i++)//将弧存入文件
    {
        fprintf(fp,"%d %d ",arc[i][0],arc[i][1]);
    }
    fprintf(fp,"-1 -1 ");
    fclose(fp);
    return OK;
}
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    if(G.vexnum)//若图已存在 
	return ERROR; 
	FILE*fp=fopen(FileName,"r");
	if(!fp)
	return OVERFLOW; 
    VertexType V[MAX_VERTEX_NUM+1];//存储顶点信息
    KeyType VR[MAX_VERTEX_NUM*(MAX_VERTEX_NUM+1)/2+1][2];//存储弧信息
    int vexnum=0,arcnum=0;
    do
    {
        fscanf(fp,"%d%s",&V[vexnum].key,V[vexnum].others);
        vexnum++;
    }while(V[vexnum-1].key!=-1);
    do
    {
        fscanf(fp,"%d%d",&VR[arcnum][0],&VR[arcnum][1]);
        arcnum++;
    }while(VR[arcnum-1][0]!=-1);
    fclose(fp);
    CreateGraph(G,V,VR);
    return OK;
}

