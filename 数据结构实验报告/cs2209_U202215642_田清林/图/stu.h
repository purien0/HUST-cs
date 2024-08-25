#include "def.h"
void visit(VertexType V) {//���ʽ�㺯�� 
	printf("        key��%d,others��%s\n",V.key,V.others);
}
void visit2(VertexType V) { 
	return;
}

status isRep(VertexType V[],int count)
{//����Ƿ�����ͬ�ؼ��� 
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
/*����V��VR����ͼT������OK�����V��VR����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR��*/
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
    if(G.vexnum == 0)//����Ƿ�Ϊ��ͼ
    return ERROR;
    if(isRep(V,G.vexnum)==TRUE)//���ؼ����Ƿ���ͬ
    return ERROR;
    while(VR[G.arcnum][0] != -1)
    {
        temp = (ArcNode*)malloc(sizeof(ArcNode));
        for(i=0;i<G.vexnum;i++)//�ҵ���β
        {
            if(G.vertices[i].data.key == VR[G.arcnum][0])
            break;
        }
        if(i==G.vexnum)//����Ϣ�����Ҳ�����㣩
        return ERROR;
        for(j=0;j<G.vexnum;j++)//�ҵ���ͷ
        {
            if(G.vertices[j].data.key == VR[G.arcnum][1])
            break;
        }
        if(j==G.vexnum)//����Ϣ�����Ҳ�����㣩
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
/*��������ͼG,ɾ��G��ȫ������ͱ�*/
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
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
{
	for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==u)
        return i;
    }
    return -1;
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//���ͼ�����ڣ�����INFEASIBLE 
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
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
        if(G.vertices[i].data.key == value.key)//���ؼ����ظ� 
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
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
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
//v��ӦG��һ������,w��Ӧv���ڽӶ��㣻��������Ƿ���v�ģ������w����һ���ڽӶ����λ�����w�����һ���ڽӶ��㣬��v��w��Ӧ���㲻���ڣ��򷵻�-1��
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
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
    if(!G.vexnum)//��ͼ������ 
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
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
{
    if(!G.vexnum)//��ͼ������ 
    return INFEASIBLE;
	ArcNode * temp;
    ArcNode * temp2;
    ArcNode * temp2_last=NULL;
    for(int i = 0;i < G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v)//�ҵ��ؼ���v��Ӧ�ڵ�
        {
            if(G.vexnum==1)
            return ERROR;
            temp = G.vertices[i].firstarc;
            while(temp)//������ȥ��
            {
                G.vertices[i].firstarc = temp->nextarc;
                temp2 = G.vertices[temp->adjvex].firstarc;
                while(temp2)//��ȥ��ͷ���Ļ�
                {
                    if(temp2->adjvex==i)
                    {
                        if(!temp2_last)//��Ϊ��һ����
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
                free(temp);//��ȥ��β���Ļ�
                G.arcnum=G.arcnum-1;
                temp = G.vertices[i].firstarc;
            }
            for(int j=i;j<G.vexnum-1;j++)
            {
                G.vertices[j]=G.vertices[j+1];
            }
            G.vexnum--;
            for(int j=0;j<G.vexnum;j++)//����������
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
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
    if(!G.vexnum)//��ͼ������ 
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
    if(vi==-1||wi==-1)//��鶥���Ƿ����
    return ERROR;
    temp = G.vertices[vi].firstarc;
    while(temp)//��鶥���Ƿ����л�
    {
        if(temp->adjvex==wi)
        return ERROR;
        temp = temp->nextarc;
    }
    //��v�����뻡
    temp = (ArcNode*)malloc(sizeof(ArcNode));
    temp->adjvex = wi;
    temp->nextarc = G.vertices[vi].firstarc;
    G.vertices[vi].firstarc = temp;
    //��w�����뻡
    temp = (ArcNode*)malloc(sizeof(ArcNode));
    temp->adjvex = vi;
    temp->nextarc = G.vertices[wi].firstarc;
    G.vertices[wi].firstarc = temp;
    
    G.arcnum++;
    return OK;
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
{
    if(!G.vexnum)//��ͼ������ 
    return INFEASIBLE;
	int i=0,j=0;//i,j�ֱ�洢v��w��Ӧ�������
    for(i=0;i<G.vexnum;i++)//Ѱ�ҵ�v��Ӧ���
    {
        if(G.vertices[i].data.key==v)
        break;
    }
    if(i==G.vexnum)//��δѰ�ҵ�v��Ӧ���
    return ERROR;
    for(j=0;j<G.vexnum;j++)//Ѱ�ҵ�w��Ӧ���
    {
        if(G.vertices[j].data.key==w)
        break;
    }
    if(j==G.vexnum)//��δѰ�ҵ�w��Ӧ���
    return ERROR;
    ArcNode *temp1=G.vertices[i].firstarc;//�洢v��㴦����ָ��
    ArcNode *temp_last1=NULL;//�洢v��㴦������һ������ָ��
    while(1)//Ѱ��v��㴦Ŀ�껡
    {
        if(!temp1)//��δ�ҵ��û�
        return ERROR;
        if(temp1->adjvex==j)//�ҵ��û�
        break;
        temp_last1=temp1;
        temp1=temp1->nextarc;
    }
    ArcNode *temp2=G.vertices[j].firstarc;//�洢w��㴦����ָ��
    ArcNode *temp_last2=NULL;//�洢w��㴦������һ������ָ��
    while(1)//Ѱ��w��㴦Ŀ�껡
    {
        if(!temp2)//��δ�ҵ��û�
        return ERROR;
        if(temp2->adjvex==i)//�ҵ��û�
        break;
        temp_last2=temp2;
        temp2=temp2->nextarc;
    }
    //������㴦Ŀ�껡�����ҵ�����ʼɾ����
    //ɾ��v��㴦��
    if(!temp_last1)//��Ŀ�껡Ϊ��һ����
    {
        G.vertices[i].firstarc=temp1->nextarc;
        free(temp1);
    }
    else
    {
        temp_last1->nextarc=temp1->nextarc;
        free(temp1);
    }
    //ɾ��w��㴦��
    if(!temp_last2)//��Ŀ�껡Ϊ��һ����
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
{//��������������õĵݹ麯�� 
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
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    if(!G.vexnum)//��ͼ������ 
    return INFEASIBLE;
    for(int i=0;i<G.vexnum;i++)
    visited[i]=0;//��ʼ�� 
	for(int i=0;i<G.vexnum;i++)
    DFS(G,i,visit);
    return OK;
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    if(!G.vexnum)//��ͼ������ 
    return INFEASIBLE;
	int queue[MAX_VERTEX_NUM];
    int top=0,tail=0;
    for(int i=0;i<G.vexnum;i++)
    visited[i]=0;//��ʼ�� 
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
//�������������Ƿ���Graphs���Ѵ��ڵ�ͼ������ͬ������ͬ����TRUE������ͬ����FALSE 
{
	for(int i=0;i<Graphs.length;i++)
	{
		if(!strcmp(name,Graphs.elem[i].name))
		return TRUE;
	}
	return FALSE;
}
status AddGraph(ALGRAPHS &Graphs, char GraphName[])
// ֻ��Ҫ��Graphs������һ������ΪGraphName��ͼ 
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
// Graphs��ɾ��һ������ΪGraphName��ͼ 
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
// ��Graphs�в���һ������ΪGraphName��ͼ���ɹ������߼���ţ����򷵻�0
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
// ���Graphs����ͼ��������ʾͼ��ź����ƣ�ÿ��ͼռһ�У�����OK�����GraphsΪ�գ�����ERROR��
{
	int op;
	if(Graphs.length==0)
	return ERROR;
	printf("ѡ��������ͣ�\n�����������/����������� �ֱ�����1��2\n");
	scanf("%d",&op);
	if(op<1||op>2)
	{
		printf("����������󣬲����ж�\n");
		return ERROR;
	}
	printf("�Ѵ��ڵ�ͼ������ʾ��\n");
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
//������ͼ�����ɹ�������������OK���������жϣ�����ERROR 
{
	int state=1;
	int i=0;
	char *name = (char*)malloc(sizeof(char)*100);//��̬����ռ� 
	printf("��������Ҫ�޸ĵı����ţ�[1-%d]\n",Graphs.length);
	scanf("%d",&i);
	getchar();
	if(i<=0 || i>Graphs.length)
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
	if(isrep(Graphs,name))//��������Ƿ��ظ� 
	{
		printf("���������ظ�\n");
		free(name);
		return ERROR; 
	}
	strcpy(Graphs.elem[i-1].name,name);
	free(name);
	return i;			
}

int mark[MAX_VERTEX_NUM+1];//��־��Щ���������붥��v����С��k�Ķ��㼯��

void dfs(ALGraph G,int num,int k)
{//�ҳ�����С��k�Ķ��㲢����mark 
	if(!k)//�������Ѵﵽ 
	return;
	if(mark[num])//���Ѵ��� 
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
//����С��k�Ķ��㼯��
//��ʼ������ͼG���ڣ���������Ƿ����붥��v����С��k�Ķ��㼯��
{
	if(k<=0)
	{
		printf("����Ƿ���\n");
		return;
	}
	for(int i=0;i<G.vexnum;i++)
	mark[i]=0;//��ʼ��
	int i;
	i = LocateVex(G,v);
	if(i==-1)
	{
		printf("�Ҳ������㣡\n");
		return;
	}
	mark[i]=1;
	ArcNode *temp=G.vertices[i].firstarc;
	while(temp)
	{
		dfs(G,temp->adjvex,k-1);
		temp=temp->nextarc;
	}
	printf("����С��k�Ķ��㼯��:\n");
	for(int i=0;i<G.vexnum;i++)
	if(mark[i])
	printf("%d %s ",G.vertices[i].data.key,G.vertices[i].data.others);
}
int ShortestPathLength(ALGraph G,KeyType v,KeyType w)
//��������·���ͳ���
//��ʼ������ͼG���ڣ���������Ƿ��ض���v�붥��w�����·���ĳ���
{
	for(int i=0;i<G.vexnum;i++)
	mark[i]=0;//��ʼ��
	int vi=LocateVex(G,v);
	int wi=LocateVex(G,w);
	ArcNode *temp; 
	if(vi==-1||wi==-1)//��ͼ���Ҳ������v/w 
	return -1;
	if(vi==wi)
	return 0;
	int k=2;
	temp=G.vertices[vi].firstarc;
	while(!mark[wi])
	{
		for(int i=0;i<G.vexnum;i++)
		mark[i]=0;//��ʼ��
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
//ͼ����ͨ����
//��ʼ������ͼG���ڣ���������Ƿ���ͼG��������ͨ�����ĸ���
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
//��ͼ������д�뵽�ļ�FileName��
{
    if(!G.vexnum)//��ͼ������ 
	return ERROR; 
	FILE* fp=fopen(FileName,"w");
    if(!fp)
    return OVERFLOW;
    KeyType arc[G.vexnum*(G.vexnum+1)/2][2];
    int count=0;
    ArcNode *temp;
    for(int i=0;i<G.vexnum;i++)
    {
        //�洢������Ϣ
        fprintf(fp,"%d %s ",G.vertices[i].data.key,G.vertices[i].data.others);
        temp=G.vertices[i].firstarc;
        while(temp)
        {
            if(!isRepeatArc(arc,G.vertices[i].data.key,G.vertices[temp->adjvex].data.key,count))//�������ظ��������Ž�arc����
            {
                arc[count][0]=G.vertices[i].data.key;
                arc[count][1]=G.vertices[temp->adjvex].data.key;
                count++;
            }
            temp=temp->nextarc;
        }
    }
    fprintf(fp,"-1 nil ");
    //�Ի���������
    KeyType t;//���ڽ���ֵ
    for(int i=0;i<count;i++)//��֤���ĵ�һ��ֵ���ڵڶ���ֵ
    {
        if(arc[i][0]>arc[i][1])
        {
            t=arc[i][0];
            arc[i][0]=arc[i][1];
            arc[i][1]=t;
        }
    }
    for(int i=0;i<count;i++)//��֤���ĵ�һ���ؼ��ִ��ڵڶ����ؼ���,���Ե�һ���ؼ���Ϊ�����ڶ����ؼ���Ϊ��������������
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
    for(int i=0;i<count;i++)//���������ļ�
    {
        fprintf(fp,"%d %d ",arc[i][0],arc[i][1]);
    }
    fprintf(fp,"-1 -1 ");
    fclose(fp);
    return OK;
}
status LoadGraph(ALGraph &G, char FileName[])
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
{
    if(G.vexnum)//��ͼ�Ѵ��� 
	return ERROR; 
	FILE*fp=fopen(FileName,"r");
	if(!fp)
	return OVERFLOW; 
    VertexType V[MAX_VERTEX_NUM+1];//�洢������Ϣ
    KeyType VR[MAX_VERTEX_NUM*(MAX_VERTEX_NUM+1)/2+1][2];//�洢����Ϣ
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

