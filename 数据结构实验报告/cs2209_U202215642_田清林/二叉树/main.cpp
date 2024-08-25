#include "stu.h"
#include "def.h"
/* Binary Tree On Chain Structure */
int main()
{
    BITREES TREES; 
    int now = 1;//nowΪ��ǰ����Ķ�������ţ�Ĭ��Ϊ1 
    TREES.elem[now-1].T = NULL;
    TREES.length = 1;
    TREES.size = 10;//�Զ�������ṹ��TREES��ʼ�� 
    strcpy(TREES.elem[0].name,"Untitled_Tree_1");//��Ĭ�϶�����1�����ָ�Ϊδ����1 
    int e,e2,i,LR;//������ʱ������������ 
    TElemType c;//������ʱ����һ��������� 
    status returnvalue;//���溯������ֵ 
    BiTree returnpointer = NULL; //����ָ�뺯�����ص�ָ�� 
    int op = 1;//��������������� 
    int OP = 1; //�����������ϵͳ������� 
    char *name = (char*)malloc(100*sizeof(char));//������ʱ�����ַ��� 
    normal://�Ӷ����Ա�ϵͳ�������Ա�ϵͳ 
    while (op)
    {
		system("cls");//����Ļ 
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
        printf("    ��ѡ����Ĳ���[0~20]:");
        scanf("%d", &op);//���������� 
        switch (op)
        {
        case 1://����������
        	TElemType definition[100];
			i=0;
			printf("������������Ķ�����ǰ��������У�"); 
			do {
				scanf("%d%s",&definition[i].key,definition[i].others);
			} while (definition[i++].key!=-1);
            if (CreateBiTree(TREES.elem[now-1].T,definition) == OK)
                printf("�����������ɹ���\n");
            else
                printf("�������Ѵ��ڣ�\n");
            getchar();
            break;
        case 2://���ٶ�����
            if (DestroyBiTree(TREES.elem[now-1].T) == OK)
                printf("���������ٳɹ���\n");
            else
                printf("�����������ڣ�\n");
            getchar();
            break;
        case 3://��ն����� 
            if (ClearBiTree (TREES.elem[now-1].T) == OK)
                printf("��������ճɹ���\n");
            else
                printf("�����������ڣ�\n");
            getchar();
            break;
        case 4://���������Ƿ�Ϊ�� 
        	returnvalue =  BiTreeEmpty(TREES.elem[now-1].T);
            if (returnvalue == TRUE)
                printf("������Ϊ�գ�\n");
            else if (returnvalue == FALSE)
                printf("��������Ϊ�գ�\n");
            else
                printf("�����������ڣ�\n");
            getchar();
            break;
        case 5://���������� 
        	returnvalue = BiTreeDepth(TREES.elem[now-1].T); 
            if (returnvalue == INFEASIBLE)
                printf("�����������ڣ�\n");
            else
            printf("���������Ϊ%d\n",returnvalue);
            getchar();
            break;
        case 6://���Ҷ������йؼ���Ϊe�Ľ��ָ�� 
            printf("����������ҵ�Ԫ�أ�");
            scanf("%d",&e);
            returnpointer = LocateNode(TREES.elem[now-1].T,e);
            if(returnpointer == NULL)
            printf("��Ԫ�ز�����!\n");
            else
            printf("��Ԫ�ش��ڣ�\n");
            getchar();
            break;
        case 7://���Ҷ������йؼ���Ϊe�Ľ�㲢��ֵΪvalue 
            printf("����Ҫ���ҽ��Ĺؼ��֣�\n");
            scanf("%d",&e);
            printf("����Ҫ��ֵ�Ľ����Ϣ��\nkey:");
            scanf("%d",&c.key);
            getchar();
            printf("others:");
            scanf("%s",c.others);
            returnvalue = Assign(TREES.elem[now-1].T,e,c);
            if( returnvalue== INFEASIBLE)
            printf("�����������ڣ�\n");
            else if(returnvalue == ERROR)
            printf("��㲻���ڣ�\n");
            else
            printf("��ֵ�ɹ���\n");
            getchar();
            break;
        case 8:
        	//���Ҷ������йؼ���Ϊe�Ľ�㲢����ֵܽ�� 
            printf("����������ҽ��Ĺؼ��֣�");
            scanf("%d",&e);
            returnpointer = GetSibling(TREES.elem[now-1].T,e); 
            if(returnpointer == NULL)
            printf("�ֵܽ�㲻���ڣ�\n");
            else
            printf("�ֵܽ��Ĺؼ���Ϊ��%d\n�ֵܽ�������Ϊ��%s\n",returnpointer->data.key,returnpointer->data.others);
            getchar();
            break;
        case 9:
        	//���Ҷ������йؼ���Ϊe�Ľ�㲢������ 
            printf("�������������Ĺؼ��֣�\n");
            scanf("%d",&e);
            printf("�����������Ľ�㣺\n");
			printf("key:");
			scanf("%d",&c.key);
			getchar();
			printf("others:");
			scanf("%s",c.others);
			printf("����λ�ã�����/�Һ���/���ڵ��Ӧ0��1��-1\n");
			scanf("%d",&i);
			if(i>1||i<-1)
			{
				printf("����λ�����󣡲����ж�\n");
				break; 
			}
			returnvalue = InsertNode(TREES.elem[now-1].T,e,i,c);
            if(returnvalue == ERROR)
            printf("����ʧ�ܣ�\n");
            else
            printf("����ɹ���\n");
            getchar();
            break;
        case 10:
        	//ɾ����� 
        	printf("��������ɾ���Ľ��Ĺؼ��֣�");
            scanf("%d",&e);
            returnvalue = DeleteNode(TREES.elem[now-1].T,e);
            if(returnvalue == ERROR)
            printf("ɾ��ʧ�ܣ�\n");
            else
            printf("ɾ���ɹ���\n");
            getchar();
            break;
        case 11:
        	//ǰ����������� 
        	if (PreOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
            printf("�����������ڣ�\n");
            getchar();
            break;
        case 12:
        	//������������� 
            if (InOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
            printf("�����������ڣ�\n");
            getchar();
            break;
        case 13:
        	//������������� 
			if (PostOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
            printf("�����������ڣ�\n");
            getchar(); 
            break; 
        case 14:
        	//������������� 
        	if(LevelOrderTraverse(TREES.elem[now-1].T,visit) == ERROR)
        	printf("�����������ڣ�\n");
            getchar(); 
            break;
        case 15:
        	//���·����
        	returnvalue=MaxPathSum(TREES.elem[now-1].T);
        	if(returnvalue==ERROR)
        	printf("������������"); 
        	else
        	printf("�Ӹ���㵽Ҷ�ӽ������·����Ϊ��%d\n",returnvalue); 
        	break;
		case 16:
			//����������� 
			printf("�����һ�����ؼ��֣�");
			scanf("%d",&e);
			printf("����ڶ������ؼ��֣�");
			scanf("%d",&e2);
			returnpointer = LowestCommonAncestor(TREES.elem[now-1].T,e,e2);
			if(returnpointer==NULL)
			printf("����ʧ�ܣ�\n"); 
			else
			printf("��������Ϊ��\nkey:%d others:%s\n",returnpointer->data.key,returnpointer->data.others);
			break;
		case 17:
			//��ת������
			returnvalue = InvertTree(TREES.elem[now-1].T);
			if(returnvalue==ERROR)
			printf("��������תʧ�ܣ�\n");
			else
			printf("��������ת�ɹ���\n");
			break;
		case 18:
			//��������д���ļ��� 
			printf("������Ҫ�洢���ļ���ַ��");
			scanf("%s",name); 
			returnvalue = SaveBiTree(TREES.elem[now-1].T,name);
			if(returnvalue== OVERFLOW)
            printf("�ļ���ʧ��!\n");
            else if(returnvalue== ERROR)
            printf("������������!\n");
            else
            printf("�������洢�ɹ���\n"); 
            getchar();
        	break; 
        case 19:
        	//���ļ��ж�������� 
			printf("������Ҫ��ȡ���ļ���ַ��");
			scanf("%s",name); 
			returnvalue = LoadBiTree(TREES.elem[now-1].T,name);
			if(returnvalue == ERROR)
            printf("�������Ѵ���!\n");
            else if(returnvalue == OVERFLOW)
            printf("�ļ���ȡʧ��!\n");
            else
            printf("������д��ɹ���\n"); 
            getchar();
        	break; 
		case 20://�����������ϵͳ 
			printf("��enter��������������ϵͳ");
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
        	printf("    ��ѡ����Ĳ���[0~5]:");
        	scanf("%d", &OP);
        	switch (OP)
        	{
        		case 1://��Ӷ����� 
        			printf("Ϊ����ӵĶ�����������");
					scanf("%s",name); 
        			returnvalue = AddTree(TREES,name);
        			if(returnvalue == OVERFLOW)
					printf("�����������Ѵ����ޣ�\n");
					if(returnvalue == ERROR)
					printf("�����������ظ���\n"); 
        			if(returnvalue == OK)
        			printf("�����������ɹ���\n��ţ�%d\n���ƣ�%s\n",TREES.length,TREES.elem[TREES.length-1].name);
        			getchar();
        			break;
        		case 2://�Ƴ������� 
        			printf("��������ɾ���Ķ��������ƣ�");
					scanf("%s",name);
					returnvalue = RemoveTree(TREES,name);
					if(returnvalue == ERROR)
					printf("ɾ��������ʧ�ܣ�\n");
					if(returnvalue == OK)
					printf("ɾ���������ɹ���\nʣ�������������%d\n",TREES.length); 
					getchar();
					break;
				case 3://�����Ʋ������Ա� 
					printf("����������ҵĶ��������ƣ�");
					scanf("%s",name);
					returnvalue = LocateTree(TREES,name);
					if(returnvalue == 0)
					printf("δ���ҵ��ö�������\n");
					else
					printf("�ö������ı��Ϊ��%d\n",returnvalue);
					break;
				case 4://������������ 
					returnvalue = TraverseTree(TREES);
					if(returnvalue == ERROR)
					printf("�����ڶ�������\n");
					break;
				case 5://������������ 
					returnvalue = rename(TREES);
					if(returnvalue==ERROR)
					printf("�����ж�.\n");
					else
					printf("��%d���������������ѳɹ��޸�Ϊ%s\n",returnvalue,TREES.elem[returnvalue-1].name);
					break;
				case 0://�˻ص�����������ϵͳ 
					if(!TREES.length)
					{
						printf("�����������ϵͳ�в����ڶ����������ȴ���һ���������ٻص�������������ϵͳ\n");
						break; 
					 } 
					printf("�����������Ķ��������[1-%d]��\n",TREES.length);
					scanf("%d",&now);
					if(now > TREES.length || now <=0)
					printf("��ŷǷ���\n"); 
					else
					{
						printf("�������뵥����������ϵͳ......");
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
    for(int j=0;j<TREES.length;j++)
    DestroyBiTree(TREES.elem[j].T);
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
    system("pause");
    return 0;
} // end of main()

