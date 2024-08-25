#include "stu.h"
#include "def.h"
int main()
{
    LISTS LIST;
    int now = 1;//nowΪ��ǰ��������Ա���ţ�Ĭ��Ϊ1 
    LIST.elem[now-1].L.elem = NULL;
    LIST.length = 1;
    LIST.listsize = 10;
    strcpy(LIST.elem[0].name,"Untitled_List_1");//��Ĭ�����Ա�1�����ָ�Ϊδ����1
    int e,e2,i;
    int returnvalue;//���溯������ֵ
    int op = 1; //�����Ա������� 
	int OP = 1;//�����Ա����ϵͳ������� 
    char *name = (char*)malloc(100*sizeof(char));
    normal://�Ӷ����Ա�ϵͳ�������Ա�ϵͳ
    OP = 1 ; 
    while (op)
    {
		system("cls");//����Ļ 
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
        printf("    ��ѡ����Ĳ���[0~19]:");
        scanf("%d", &op);//���������� 
        switch (op)
        {
        case 1://�������Ա�
            if (InitList(LIST.elem[now-1].L) == OK)
                printf("���Ա����ɹ���\n");
            else
                printf("���Ա��Ѵ��ڣ�\n");
            getchar();
            break;
        case 2://�������Ա� 
            if (DestroyList(LIST.elem[now-1].L) == OK)
                printf("���Ա����ٳɹ���\n");
            else
                printf("���Ա����ڣ�\n");
            getchar();
            break;
        case 3://������Ա�
            if (ClearList(LIST.elem[now-1].L) == OK)
                printf("���Ա���ճɹ���\n");
            else
                printf("���Ա����ڣ�\n");
            getchar();
            break;
        case 4://������Ա��Ƿ�Ϊ�� 
            if (ListEmpty(LIST.elem[now-1].L) == TRUE)
                printf("���Ա�Ϊ�գ�\n");
            else if (ListEmpty(LIST.elem[now-1].L) == FALSE)
                printf("���Ա�Ϊ�գ�\n");
            else
                printf("���Ա����ڣ�\n");
            getchar();
            break;
        case 5://������Ա��� 
            if (ListLength(LIST.elem[now-1].L) == INFEASIBLE)
                printf("���Ա����ڣ�\n");
            else
            printf("���Ա���Ϊ%d\n",ListLength(LIST.elem[now-1].L));
            getchar();
            break;
        case 6://�������Ա�������Ԫ����ŵ�Ԫ��
            printf("����Ԫ����ţ�");
            scanf("%d",&i);
            returnvalue = GetElem(LIST.elem[now-1].L,i,e);
            if( returnvalue== INFEASIBLE)
            printf("���Ա�����!\n");
            else if(returnvalue == ERROR)
            printf("��ŷǷ���\n");
            else
            printf("��ѡ���Ԫ��Ϊ��%d\n", e);
            getchar();
            break;
        case 7://�������Ա�������Ԫ�ص�Ԫ�����
            printf("����������ҵ�Ԫ�أ�");
            scanf("%d",&e);
            returnvalue = LocateElem(LIST.elem[now-1].L,e);
            if(returnvalue == INFEASIBLE)
            printf("���Ա�����!\n");
            if(returnvalue == 0)
            printf("Ԫ�ز�����!\n");
            else
            printf("Ԫ�����Ϊ��%d\n",returnvalue);
            getchar();
            break;
        case 8://�������Ա�������Ԫ�ص�ǰ��
            printf("����������ҵ�Ԫ�أ�");
            scanf("%d",&e);
            returnvalue = PriorElem(LIST.elem[now-1].L,e,e2);
            if( returnvalue== INFEASIBLE)
            printf("���Ա�����!\n");
            else if(returnvalue == NEXIST)
            printf("��Ԫ�ز�����ǰ����\n");
            else if(returnvalue == ERROR)
            printf("��Ԫ�ز����������Ա��У�\n");
            else
            printf("��ѡ���Ԫ�ص�ǰ��Ϊ��%d\n", e2);
            getchar();
            break;
        case 9://�������Ա�������Ԫ�صĺ��
            printf("����������ҵ�Ԫ�أ�");
            scanf("%d",&e);
            returnvalue = NextElem(LIST.elem[now-1].L,e,e2);
            if( returnvalue== INFEASIBLE)
            printf("���Ա�����!\n");
            else if(returnvalue == ERROR)
            printf("��Ԫ�ز����������Ա��У�\n");
            else if(returnvalue == NEXIST)
            printf("��Ԫ�ز����ں�̣�\n");
            else
            printf("��ѡ���Ԫ�صĺ��Ϊ��%d\n", e2);
            getchar();
            break;
        case 10://�����Ա��ж�ӦԪ�����֮ǰ����Ԫ��
        	printf("������������Ԫ�أ�");
            scanf("%d",&e);
            printf("����Ԫ����ţ�[1-%d]\n",LIST.elem[now-1].L.length+1);
            scanf("%d",&i); 
            returnvalue = ListInsert(LIST.elem[now-1].L,i,e);
            if( returnvalue == INFEASIBLE)
            printf("���Ա�����!\n");
            else if(returnvalue == ERROR)
            printf("��ŷǷ���\n");
            else
            printf("����ɹ���\n");
            getchar();
            break;
        case 11:
        	//�����Ա���ɾ����ӦԪ����ŵ�Ԫ��
            printf("����Ԫ����ţ�[1-%d]\n",max(LIST.elem[now-1].L.length,1));
            //��ʾ�Ϸ���Ԫ����ţ���ֹ�û��������
            scanf("%d",&i);
            returnvalue = ListDelete(LIST.elem[now-1].L,i,e);
            if( returnvalue== INFEASIBLE)
            printf("���Ա�����!\n");
            if(returnvalue == ERROR)
            printf("��ŷǷ���\n");
            else
            printf("��ɾ����Ԫ��Ϊ��%d��\n",e);
            getchar();
            break;
        case 12://�������Ա����ÿһ��Ԫ��
            if (!ListTraverse(LIST.elem[now-1].L))
                printf("���Ա��ǿձ�\n");
            getchar();
            break;
        case 13://�������Ա����������������� 
        	returnvalue = MaxSubArray(LIST.elem[now-1].L);
			if(returnvalue == -1)
				printf("���Ա����ڻ�Ϊ�ձ�\n");
			else
				printf("��������������Ϊ��%d\n",returnvalue);
			getchar();
			break;
		case 14://�������Ա��к�Ϊk��������������� 
			printf("�����������k��\n"); 
			scanf("%d",&i); 
			returnvalue = SubArrayNum(LIST.elem[now-1].L,i);
			if(returnvalue == ERROR)
				printf("���Ա����ڻ�Ϊ�ձ�\n");
			else
				printf("��Ϊk��������������ĿΪ��%d\n",returnvalue);
			getchar();
			break;
		case 15:
			//�����Ա��������� 
			returnvalue = sortList(LIST.elem[now-1].L);
			if(returnvalue == INFEASIBLE)
				printf("���Ա����ڻ�Ϊ�ձ�\n");
			else
				printf("���Ա�����ɹ�!\n");
			break;
		case 16:
			//�����Ա�д���ļ���
			printf("������Ҫ�洢���ļ���ַ��");
			scanf("%s",name); 
			returnvalue = SaveList(LIST.elem[now-1].L,name);
			if(returnvalue== INFEASIBLE)
            printf("���Ա�����!\n");
            else if(returnvalue== ERROR)
            printf("�ļ�д��ʧ��!\n");
            else
            printf("���Ա�洢�ɹ���\n"); 
            getchar();
        	break; 
        case 17:
        	//���ļ��ж������Ա�
			printf("������Ҫ��ȡ���ļ���ַ��");
			scanf("%s",name); 
			returnvalue = LoadList(LIST.elem[now-1].L,name);
			if(returnvalue == INFEASIBLE)
            printf("���Ա��Ѵ���!\n");
            else if(returnvalue == ERROR)
            printf("�ļ���ȡʧ��!\n");
            else
            printf("���Ա�д��ɹ���\n"); 
            getchar();
        	break; 
        case 18:
        	//һ������������
			printf("������Ԫ�ظ�����\n");
			scanf("%d",&i);
			if(LIST.elem[now-1].L.elem)
			{
				ClearList(LIST.elem[now-1].L);
			}
			else
			{
				printf("���Ա����ڣ�\n");
				break; 
			}
			printf("���������ݣ�\n"); 
			for(int j=0;j < i;j++)
			{
				scanf("%d",&e);
				ListInsert(LIST.elem[now-1].L,j+1,e);
			}
			printf("�������\n");
			break;
		case 19://�����Ա�ϵͳ
			printf("��enter��������Ա����ϵͳ");
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
        	printf("    ��ѡ����Ĳ���[0~5]:");
        	scanf("%d", &OP);
        	switch (OP)
        	{
        		case 1://������Ա� 
        			printf("Ϊ����ӵ����Ա�������");
					scanf("%s",name); 
        			returnvalue = AddList(LIST,name);
        			if(returnvalue == OVERFLOW)
					printf("���Ա������Ѵ����ޣ�\n");
					if(returnvalue == ERROR)
					printf("���Ա������ظ���\n"); 
        			if(returnvalue == OK)
        			printf("�������Ա�ɹ���\n��ţ�%d\n���ƣ�%s\n",LIST.length,LIST.elem[LIST.length-1].name);
        			getchar();
        			break;
        		case 2://�Ƴ����Ա� 
        			printf("��������ɾ�������Ա����ƣ�");
					scanf("%s",name);
					returnvalue = RemoveList(LIST,name);
					if(returnvalue == UNDERFLOW)
					printf("���Ա��ѿգ�\n");
					if(returnvalue == ERROR)
					printf("ɾ�����Ա�ʧ�ܣ�\n");
					if(returnvalue == OK)
					printf("ɾ�����Ա�ɹ���\nʣ�����Ա�������%d\n",LIST.length); 
					getchar();
					break;
				case 3://�����Ʋ������Ա� 
					printf("����������ҵ����Ա����ƣ�");
					scanf("%s",name);
					returnvalue = LocateList(LIST,name);
					if(returnvalue == 0)
					printf("δ���ҵ������Ա�\n");
					else
					printf("�����Ա�ı��Ϊ��%d\n",returnvalue);
					break;
				case 4://���������Ա� 
					returnvalue = TraverseList(LIST);
					if(returnvalue == ERROR)
					printf("���������Ա�\n");
					break;
				case 5://���Ա������� 
					returnvalue = rename(LIST);
					if(returnvalue==ERROR)
					printf("�����ж�.\n");
					else
					printf("��%d�����Ա�������ѳɹ��޸�Ϊ%s\n",returnvalue,LIST.elem[returnvalue-1].name);
					break;
				case 0://�˻ص����Ա����ϵͳ 
					printf("���������������Ա���[1-%d]��\n",LIST.length);
					scanf("%d",&now);
					if(now > LIST.length || now <=0)
					printf("��ŷǷ���\n"); 
					else
					{
						printf("�������뵥���Ա����ϵͳ......");
						system("pause");//��ͣ����ʾ���
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
    for(int j=0;j<LIST.length;j++)
    DestroyList(LIST.elem[j].L);
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
    system("pause");
    return 0;
} // end of main()

