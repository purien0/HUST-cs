#include "stu.h"
#include "def.h"
/* Graphs On Adjacency List */
int main()
{
    ALGRAPHS GRAPHS; //������ͼ�ṹ�� 
	VertexType V[30];//������ʱ���涥������ 
	KeyType VR[100][2];//������ʱ��������� 
    int now = 1;//nowΪ��ǰ�����ͼ��ţ�Ĭ��Ϊ1 
    GRAPHS.elem[now-1].G.vexnum = 0;
    GRAPHS.elem[now-1].G.arcnum = 0;
    GRAPHS.elem[now-1].G.kind = UDG;//��ͼ���г�ʼ�� 
    GRAPHS.length = 1;
    GRAPHS.size = 10;//�Զ�ͼ���г�ʼ�� 
    strcpy(GRAPHS.elem[0].name,"Untitled_Graphs_1");//��Ĭ��ͼ1�����ָ�Ϊδ����1 
    int e,e2,i,LR;//������ʱ������������ 
    VertexType c;//������ʱ����һ���������� 
    status returnvalue;//���溯������ֵ 
    int op = 1;//��ͼ������� 
    int OP = 1; //��ͼ����ϵͳ������� 
    char *name = (char*)malloc(100*sizeof(char));//������ʱ�����ַ��� 
    normal://�Ӷ����Ա�ϵͳ�������Ա�ϵͳ 
    while (op)
    {
		system("cls");//����Ļ 
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
        printf("��ѡ����Ĳ���[0~18]:");
        scanf("%d", &op);//���������� 
        switch (op)
        {
        case 1://����ͼ
        	if(GRAPHS.elem[now-1].G.vexnum)
			{
				printf("ͼ�Ѵ��ڣ�\n");
				break;
			}
			i=0; 
			printf("������ͼ�Ķ�����Ϣ��\n"); 
			do {
    		scanf("%d%s",&V[i].key,V[i].others);
			} while(V[i++].key!=-1);
			i=0;
			printf("������ͼ�ı���Ϣ��\n"); 
			do {
    			scanf("%d%d",&VR[i][0],&VR[i][1]);
   			} while(VR[i++][0]!=-1);
			i=0;
			returnvalue = CreateGraph(GRAPHS.elem[now-1].G,V,VR);
            if (returnvalue == OK)
                printf("ͼ�����ɹ���\n");
            else
            	printf("��������Ϣ����\n");
            getchar();
            break;
        case 2://����ͼ
            if (DestroyGraph(GRAPHS.elem[now-1].G) == OK)
                printf("ͼ���ٳɹ���\n");
            else
                printf("ͼ�����ڣ�\n");
            getchar();
            break;
        case 3://����ͼ�йؼ���Ϊe�Ķ��� 
            printf("����������ҵĶ���ؼ��֣�");
            scanf("%d",&e);
            returnvalue = LocateVex(GRAPHS.elem[now-1].G,e);
            if(returnvalue == -1)
            printf("��Ԫ�ز�����!\n");
            else
            {
            	printf("��Ԫ��λ��Ϊ��%d\n",returnvalue);
            	printf("key:%d\nothers:%s\n",GRAPHS.elem[now-1].G.vertices[returnvalue].data.key,GRAPHS.elem[now-1].G.vertices[returnvalue].data.others);
			}
            getchar();
            break;
        case 4://����ͼ�йؼ���Ϊe�Ķ��㲢��ֵΪvalue 
            printf("����Ҫ���Ҷ���Ĺؼ��֣�\n");
            scanf("%d",&e);
            printf("����Ҫ��ֵ�Ķ�����Ϣ��\nkey:");
            scanf("%d",&c.key);
            getchar();
            printf("others:");
            scanf("%s",c.others);
            returnvalue = PutVex (GRAPHS.elem[now-1].G,e,c);
            if( returnvalue== INFEASIBLE)
            printf("ͼ�����ڣ�\n");
            else if(returnvalue == ERROR)
            printf("���㲻���ڣ�\n");
            else
            printf("��ֵ�ɹ���\n");
            getchar();
            break;
        case 5:
        	//����ͼ�йؼ���Ϊe�Ķ��㲢��õ�һ�ڽӵ�
            printf("����������Ҷ���Ĺؼ��֣�");
            scanf("%d",&e);
            returnvalue = FirstAdjVex(GRAPHS.elem[now-1].G,e); 
            if(returnvalue == -1)
            printf("���㲻����\n");
            else
            printf("��һ�ڽӵ�Ĺؼ���Ϊ��%d\n��һ�ڽӵ������Ϊ��%s\n",GRAPHS.elem[now-1].G.vertices[returnvalue].data.key,GRAPHS.elem[now-1].G.vertices[returnvalue].data.others);
            getchar();
            break;
        case 6:
			//����ͼ�йؼ���Ϊe�Ķ��㲢�����һ�ڽӵ�
			printf("����������Ҷ���Ĺؼ��֣�");
            scanf("%d",&e);
            printf("����������Ҷ�����ڽӵ�Ĺؼ��֣�");
            scanf("%d",&e2);
            returnvalue = NextAdjVex(GRAPHS.elem[now-1].G,e,e2); 
            if(returnvalue == -1)
            printf("���㲻���ڻ��ڽӻ򲻴�����һ���ڽӵ㣡\n");
            else
            printf("��һ�ڽӵ�Ĺؼ���Ϊ��%d\n��һ�ڽӵ������Ϊ��%s\n",GRAPHS.elem[now-1].G.vertices[returnvalue].data.key,GRAPHS.elem[now-1].G.vertices[returnvalue].data.others);
            getchar();
            break;
        case 7:
        	//���붥�� 
            printf("�����������Ķ��㣺\n");
			printf("key:");
			scanf("%d",&c.key);
			getchar();
			printf("others:");
			scanf("%s",c.others);
			returnvalue = InsertVex(GRAPHS.elem[now-1].G,c);
			if(returnvalue == INFEASIBLE)
			printf("ͼ�����ڣ�\n");
            else if(returnvalue == ERROR)
            printf("����ʧ�ܣ�\n");
            else
            printf("����ɹ���\n");
            getchar();
            break;
        case 8:
        	//ɾ������ 
        	printf("��������ɾ���Ķ���Ĺؼ��֣�");
            scanf("%d",&e);
            returnvalue = DeleteVex(GRAPHS.elem[now-1].G,e);
            if(returnvalue == INFEASIBLE)
			printf("ͼ�����ڣ�\n");
			else if(returnvalue == ERROR)
            printf("ɾ��ʧ�ܣ�\n");
            else
            printf("ɾ���ɹ���\n");
            getchar();
            break;
        case 9:
        	//���뻡 
            printf("�����������Ļ���\n");
			scanf("%d%d",&e,&e2);
			returnvalue = InsertArc(GRAPHS.elem[now-1].G,e,e2);
			if(returnvalue == INFEASIBLE)
			printf("ͼ�����ڣ�\n");
            else if(returnvalue == ERROR)
            printf("����ʧ�ܣ�\n");
            else
            printf("����ɹ���\n");
            getchar();
            break;
        case 10:
        	//ɾ���� 
            printf("��������ɾ���Ļ���\n");
			scanf("%d%d",&e,&e2);
			returnvalue = DeleteArc(GRAPHS.elem[now-1].G,e,e2);
			if(returnvalue == INFEASIBLE)
			printf("ͼ�����ڣ�\n");
            else if(returnvalue == ERROR)
            printf("ɾ��ʧ�ܣ�\n");
            else
            printf("ɾ���ɹ���\n");
            getchar();
            break; 
        case 11:
        	//��������������� 
        	if (DFSTraverse(GRAPHS.elem[now-1].G,visit) == INFEASIBLE)
            printf("ͼ�����ڣ�\n");
            getchar();
            break;
        case 12:
        	//��������������� 
            if (BFSTraverse(GRAPHS.elem[now-1].G,visit) == INFEASIBLE)
            printf("ͼ�����ڣ�\n");
            getchar();
            break;
        case 13:
        	//����С��k�Ķ��㼯�� 
        	printf("������ʼ��Ĺؼ��֣�");
        	scanf("%d",&e);
        	printf("�������k��"); 
        	scanf("%d",&i);
        	VerticesSetLessThanK(GRAPHS.elem[now-1].G,e,i);
            getchar(); 
            break; 
        case 14:
        	//��������·���ͳ��� 
        	printf("�������Ĺؼ��֣�");
        	scanf("%d",&e);
        	printf("�����յ�Ĺؼ��֣�");
        	scanf("%d",&e2);
        	returnvalue = ShortestPathLength(GRAPHS.elem[now-1].G,e,e2);
        	if(returnvalue == -1)
        	printf("ͼ�����ڻ��Ҳ������㣡\n");
        	else 
        	printf("��������·���ĳ���Ϊ��%d\n",returnvalue);
            getchar(); 
            break;
        case 15:
        	//ͼ����ͨ����
        	returnvalue=ConnectedComponentsNums(GRAPHS.elem[now-1].G);
        	if(returnvalue==ERROR)
        	printf("ͼ������"); 
        	else
        	printf("ͼ����ͨ������Ϊ��%d\n",returnvalue); 
        	break;
		case 16:
			//��ͼд���ļ��� 
			printf("������Ҫ�洢���ļ���ַ��");
			scanf("%s",name); 
			returnvalue = SaveGraph(GRAPHS.elem[now-1].G,name);
			if(returnvalue== OVERFLOW)
            printf("�ļ���ʧ��!\n");
            else if(returnvalue== ERROR)
            printf("ͼ������!\n");
            else
            printf("ͼ�洢�ɹ���\n"); 
            getchar();
        	break; 
        case 17:
        	//���ļ��ж���ͼ 
			printf("������Ҫ��ȡ���ļ���ַ��");
			scanf("%s",name); 
			returnvalue = LoadGraph(GRAPHS.elem[now-1].G,name);
			if(returnvalue == ERROR)
            printf("ͼ�Ѵ���!\n");
            else if(returnvalue == OVERFLOW)
            printf("�ļ���ȡʧ��!\n");
            else
            printf("ͼд��ɹ���\n"); 
            getchar();
        	break; 
		case 18://��ͼ����ϵͳ 
			printf("��enter�����ͼ����ϵͳ");
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
        	printf("��ѡ����Ĳ���[0~5]:");
        	scanf("%d", &OP);
        	switch (OP)
        	{
        		case 1://���ͼ 
        			printf("Ϊ����ӵ�ͼ������");
					scanf("%s",name); 
        			returnvalue = AddGraph(GRAPHS,name);
        			if(returnvalue == OVERFLOW)
					printf("ͼ�����Ѵ����ޣ�\n");
					if(returnvalue == ERROR)
					printf("ͼ�����ظ���\n"); 
        			if(returnvalue == OK)
        			printf("����ͼ�ɹ���\n��ţ�%d\n���ƣ�%s\n",GRAPHS.length,GRAPHS.elem[GRAPHS.length-1].name);
        			getchar();
        			break;
        		case 2://�Ƴ�ͼ 
        			printf("��������ɾ����ͼ���ƣ�");
					scanf("%s",name);
					returnvalue = RemoveGraph(GRAPHS,name);
					if(returnvalue == ERROR)
					printf("ɾ��ͼʧ�ܣ�\n");
					if(returnvalue == OK)
					printf("ɾ��ͼ�ɹ���\nʣ��ͼ������%d\n",GRAPHS.length); 
					getchar();
					break;
				case 3://�����Ʋ������Ա� 
					printf("����������ҵ�ͼ���ƣ�");
					scanf("%s",name);
					returnvalue = LocateGraph(GRAPHS,name);
					if(returnvalue == 0)
					printf("δ���ҵ���ͼ��\n");
					else
					printf("��ͼ�ı��Ϊ��%d\n",returnvalue);
					break;
				case 4://������ͼ 
					returnvalue = TraverseGraph(GRAPHS);
					if(returnvalue == ERROR)
					printf("������ͼ��\n");
					break;
				case 5://ͼ������ 
					returnvalue = rename(GRAPHS);
					if(returnvalue==ERROR)
					printf("�����ж�.\n");
					else
					printf("��%d��ͼ�������ѳɹ��޸�Ϊ%s\n",returnvalue,GRAPHS.elem[returnvalue-1].name);
					break;
				case 0://�˻ص�ͼ����ϵͳ
					if(!GRAPHS.length)
					{
						printf("��ͼ����ϵͳ�в�����ͼ�����ȴ���һ��ͼ�ٻص���ͼ����ϵͳ\n");
						break; 
					 } 
					printf("������������ͼ���[1-%d]��\n",GRAPHS.length);
					scanf("%d",&now);
					if(now > GRAPHS.length || now <=0)
					printf("��ŷǷ���\n"); 
					else
					{
						printf("�������뵥ͼ����ϵͳ......");
						system("pause");
						goto normal;
					} 
					break;
				default :
        		printf("����Ƿ���������[0~5]�е����\n");
        		break; 
			}
			system("pause");//��ͣ����ʾ���
			}
        case 0:
            break;
        default :
        	printf("����Ƿ���������[0~19]�е����\n");
        	break; 
        } // end of switch
        system("pause");//��ͣ����ʾ��� 
    }     // end of while
    free(name); 
    for(int j=0;j<GRAPHS.length;j++)
    DestroyGraph(GRAPHS.elem[j].G);
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
    system("pause");
    return 0;
} // end of main()

