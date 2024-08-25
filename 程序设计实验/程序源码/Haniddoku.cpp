//bug:3和4的操作计数器不同， 3可以一直操作，提示太少 
#include "Haniddoku.h"
#include "mySAT.h"
int transfer[11]= {0,0,5,11,18,26,35,43,50,56,61};
int bk_top=0;
int bk[1000];

Ansnode st[1000];
int pre_hole[61], holes = 15;
void st_push(int r,int c,int num,int flagg)
{
	for(int i=0; i<=999; i++)
	{
		if(st[i].mark==0)
		{
			st[i].col=c;
			st[i].row=r;
			st[i].ans=num;
			st[i].flag=flagg;
			st[i].mark=1;
			bk[bk_top++]=i;
			break;
		}
	}
	return ;
}
void AddHint(int x,int pos)
{
	int i;
	for(i = 10; i > 0; i--)
	{
		if(transfer[i] < x)
		break;
	}
	st[pos].row = i;
	st[pos].col = x-transfer[i];
	printf("%d\n%d\n",st[pos].row,st[pos].col);
}
void createHanidoku(int pre_hole[])//打开文件创造一开始的数独格局
{
	FILE *fp;
	fp=fopen("Hanidoku.txt","r");
	char s[100] = "HQV1G2634557426343651276581273434278951627394865587693463845745623";
	char c;
	for(int i=0; i<61; i++)
	{
		c = s[i+5];
		pre_hole[i]=c-'0';
	}
}

void createStartinggrid(int pre_hole[], int now_hole[], int holes)//开始挖洞，基于挖洞法生成数独游戏
{
	for (int i = 0; i < 61; i ++ ) now_hole[i] = pre_hole[i];

	int c[holes], cf;

	int flag = 0;

	for (int i = 0; i < holes; i ++ )//防止挖到相同的洞里面去
	{
		cf = rand() % 61; //生成0到60的随机数
		flag = 0;
		for (int m = 0; m < i; m ++ )
			if (cf == c[m])
				flag = 1;

		if (flag == 0)
		{
			now_hole[cf] = 0;
			c[i] = cf;
		}
		else i -- ;
	}
}

void print(const int pre_hole[])//输出数独格局
{
	printf("   1   2   3   4   5   6   7   8   9\n");
	printf("          / \\ / \\ / \\ / \\ / \\\n");
	printf("1        |");
	for (int i = 0; i < 5; i ++ )
		cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	printf("        / \\ / \\ / \\ / \\ / \\ / \\\n");
	printf("2      |");
	for (int i = 5; i < 11; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "      / \\ / \\ / \\ / \\ / \\ / \\ / \\\n";
	cout << "3    |";
	for (int i = 11; i < 18; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "    / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\\n";
	cout << "4  |";
	for (int i = 18; i < 26; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\\n";
	cout << "5|";
	for (int i = 26; i < 35; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "  \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /\n";
	cout << "6  |";
	for (int i = 35; i < 43; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "    \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /\n";
	cout << "7    |";
	for (int i = 43; i < 50; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "      \\ / \\ / \\ / \\ / \\ / \\ / \\ /\n";
	cout << "8      |";
	for (int i = 50; i < 56; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "        \\ / \\ / \\ / \\ / \\ / \\ /\n";
	cout << "9        |";
	for (int i = 56; i < 61; i ++ ) cout << ' ' << pre_hole[i] << " |";
	cout << endl;
	cout << "          \\ / \\ / \\ / \\ / \\ /\n";
}

//now_hole是待输出的数组，把pre_hole数组逆时针旋转了60度
//pre_hole是待输入的数组，把now_hole数组顺时针旋转了60度
void turnAnAngle(numNode pre_hole[][10], numNode now_hole[][10])
{
	now_hole[1][1] = pre_hole[1][5], now_hole[1][2] = pre_hole[2][6], now_hole[1][3] = pre_hole[3][7], now_hole[1][4] = pre_hole[4][8], now_hole[1][5] = pre_hole[5][9];
	now_hole[2][1] = pre_hole[1][4], now_hole[2][2] = pre_hole[2][5], now_hole[2][3] = pre_hole[3][6], now_hole[2][4] = pre_hole[4][7], now_hole[2][5] = pre_hole[5][8], now_hole[2][6] = pre_hole[6][8];//2
	now_hole[3][1] = pre_hole[1][3], now_hole[3][2] = pre_hole[2][4], now_hole[3][3] = pre_hole[3][5], now_hole[3][4] = pre_hole[4][6], now_hole[3][5] = pre_hole[5][7], now_hole[3][6] = pre_hole[6][7], now_hole[3][7] = pre_hole[7][7];//3
	now_hole[4][1] = pre_hole[1][2], now_hole[4][2] = pre_hole[2][3], now_hole[4][3] = pre_hole[3][4], now_hole[4][4] = pre_hole[4][5], now_hole[4][5] = pre_hole[5][6], now_hole[4][6] = pre_hole[6][6], now_hole[4][7] = pre_hole[7][6], now_hole[4][8] = pre_hole[8][6];
	now_hole[5][1] = pre_hole[1][1], now_hole[5][2] = pre_hole[2][2], now_hole[5][3] = pre_hole[3][3], now_hole[5][4] = pre_hole[4][4], now_hole[5][5] = pre_hole[5][5], now_hole[5][6] = pre_hole[6][5], now_hole[5][7] = pre_hole[7][5], now_hole[5][8] = pre_hole[8][5], now_hole[5][9] = pre_hole[9][5];
	now_hole[6][1] = pre_hole[2][1], now_hole[6][2] = pre_hole[3][2], now_hole[6][3] = pre_hole[4][3], now_hole[6][4] = pre_hole[5][4], now_hole[6][5] = pre_hole[6][4], now_hole[6][6] = pre_hole[7][4], now_hole[6][7] = pre_hole[8][4], now_hole[6][8] = pre_hole[9][4];
	now_hole[7][1] = pre_hole[3][1], now_hole[7][2] = pre_hole[4][2], now_hole[7][3] = pre_hole[5][3], now_hole[7][4] = pre_hole[6][3], now_hole[7][5] = pre_hole[7][3], now_hole[7][6] = pre_hole[8][3], now_hole[7][7] = pre_hole[9][3];
	now_hole[8][1] = pre_hole[4][1], now_hole[8][2] = pre_hole[5][2], now_hole[8][3] = pre_hole[6][2], now_hole[8][4] = pre_hole[7][2], now_hole[8][5] = pre_hole[8][2], now_hole[8][6] = pre_hole[9][2];
	now_hole[9][1] = pre_hole[5][1], now_hole[9][2] = pre_hole[6][1], now_hole[9][3] = pre_hole[7][1], now_hole[9][4] = pre_hole[8][1], now_hole[9][5] = pre_hole[9][1];
}

void createNode(numNode now_hole[][10])
{//创建结点 
	for (int i = 1; i <= 9; i ++ )
		for (int j = 1; j <= 9; j ++ )
		{
			now_hole[i][j].x = i;
			now_hole[i][j].y = j;
		}
}

//将语义编码转化为自然顺序编码
int TransLiteral(int x)
{
	int pre_hole[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
	int now_hole[10] = {0, 0, 5, 11, 18, 26, 35, 43, 50, 56};

	for (int i = 1; i <= 9; i ++ )
		for (int j = 1; j <= pre_hole[i]; j ++ )
			if (x >= 100 * i + 10 * j + 1 && x <= 100 * i + 10 * j + 9)
				return x - (100 * i + 10 * j) + 9 * (j - 1) + 9 * now_hole[i];

	return 0;
}

void def_TransLiteral(int x,int &row,int &col,int &con)
//将自然顺序码转换为语义编码
{
	int now_hole[10] = {0, 0, 5, 11, 18, 26, 35, 43, 50, 56};
	int order=x/9+1;//order代表身处61个中第几个格子
	con=x%9;//当前格子填的是几;
	col=0,row=0;
	for(int i=1; i<=9; i++)
	{
		if(order<now_hole[i])
		{
			row=i-1;
			break;
		}
	}
	col=order-now_hole[row];
	return ;
}


//行约束
void lineDis(FILE *fp, numNode now_hole[][10])
{
	//范式，1到9行的约束
	for (int p = 1; p <= 9; p ++ )
	{
		int cf = p;
		if (p >= 6 && p <= 9) cf = 10 - p;
		//必填数字
		for (int i = 5 - (cf - 1); i <= 5 + (cf - 1); i ++ )
		{
			for (int j = 1; j <= 5 + (cf - 1); j ++ )
				fprintf(fp,"%d ",TransLiteral(100 * now_hole[p][j].x + now_hole[p][j].y * 10 + i)) ;
			fprintf(fp,"0\n");
		}

		//约束方案的子句
		for (int i = 1; i <= 4 - (cf - 1); i ++ )
		{
			for (int j = 6 + (cf - 1); j < 6 + (cf - 1) + i; j ++ )
			{
				for (int k = 1; k <= 5 + (cf - 1); k ++ )
					fprintf(fp,"%d ",TransLiteral(100 * now_hole[p][k].x + 10 * now_hole[p][k].y + i));
				for (int k = 1; k <= 5 + (cf - 1); k ++ )
					fprintf(fp,"%d ",TransLiteral(100 * now_hole[p][k].x + 10 * now_hole[p][k].y + j));
				fprintf(fp,"0\n");
			}
		}

		//每两格的数字不能重复
		for (int i = 1; i <= 9; i ++ )
			for (int j = 1; j <= 5 + (cf - 1); j ++ )
				for (int k = j + 1; k <= 5 + (cf - 1); k ++ )
					fprintf(fp,"%d %d 0\n",- TransLiteral(100 * now_hole[p][j].x + now_hole[p][j].y * 10 + i),- TransLiteral(100 * now_hole[p][k].x + now_hole[p][k].y * 10 + i));
					
	}
}

//同一格只能填一个数字
void Singularity(FILE *fp)//文件写入
{
	for (int p = 1; p <= 9; p ++ )
	{
		int cf = p;
		if (p >= 6 && p <= 9) cf = 10 - p;

		for (int j = 1; j <= 5 + (cf - 1); j ++ )
		{
			for (int l = 1; l <= 9; l ++ ) fprintf(fp,"%d ",TransLiteral(100 * p + 10 * j + l));
			fprintf(fp,"0\n");
			for (int i = 1; i <= 9; i ++ )
			{
				for (int k = i + 1; k <= 9; k ++ )
					fprintf(fp,"%d %d 0\n",- TransLiteral(100 * p + 10 * j + i),- TransLiteral(100 * p + 10 * j + k));
			}
		}
	}
}
void turn(int *pre,int * now)
{//转60度 
	int clockwise[65]={27,19,12,6,1,36,28,20,13,7,2,44,37,29,21,14,8,3,51,45,38,30,22,15,9,4,57,52,46,39,31,23,16,10,5,58,53,47,40,32,24,17,11,59,54,48,41,33,25,18,60,55,49,42,34,26,61,56,50,43,35,0,0};
	for(int i = 0; i < 61;i++)
	{
		now[i] = pre[clockwise[i]-1];
	}
}
void ToCnf(int pre_hole[][9], int holes)
{//转化成CNF 
	FILE *fp;
	fp=fopen("sudoku.cnf","w");//定义输入文件
	if(fp==NULL)
		printf("无法打开文件！\n");
	fprintf(fp,"p cnf 549 %d \n",5211 + 61 - holes + 2257);

	//数独中所有的单子句
	for (int i = 0; i < 9; i ++ )
	{
		for (int j = 0; j < 9; j ++ )
			if (pre_hole[i][j] != -1 && pre_hole[i][j] != 0)
				fprintf(fp,"%d 0\n",TransLiteral((i + 1) * 100 + (j + 1) * 10 + pre_hole[i][j]));
	}
	numNode bp[10][10], now_hole[10][10],temp[10][10];
	createNode(now_hole);
	Singularity(fp); //单格数字约束
	
	//行约束
	lineDis(fp, now_hole);

	//右对角线约束
	turnAnAngle(now_hole, bp);
	lineDis(fp, bp);

	//左对角线约束
	turnAnAngle(now_hole, bp), turnAnAngle(bp, now_hole);
	lineDis(fp, now_hole);

	fclose(fp);
	return ;
}

void changeGrid(int hani[][9], int now_hole[])
{//
	for (int i = 0; i < 5; i ++ ) hani[0][i] = now_hole[i];
	for (int i = 5; i < 11; i ++ ) hani[1][i - 5] = now_hole[i];
	for (int i = 11; i < 18; i ++ ) hani[2][i - 11] = now_hole[i];
	for (int i = 18; i < 26; i ++ ) hani[3][i - 18] = now_hole[i];
	for (int i = 26; i < 35; i ++ ) hani[4][i - 26] = now_hole[i];
	for (int i = 35; i < 43; i ++ ) hani[5][i - 35] = now_hole[i];
	for (int i = 43; i < 50; i ++ ) hani[6][i - 43] = now_hole[i];
	for (int i = 50; i < 56; i ++ ) hani[7][i - 50] = now_hole[i];
	for (int i = 56; i < 61; i ++ ) hani[8][i - 56] = now_hole[i];
}
void Haniddoku()
{
	Clause *head = NULL;
  	int result;
    FILE *fp;
    char filename[100];
    int sudokuTable[9][9];
    int op = 1;
    int sj;
	int i;
	int xx;
    clock_t start, finish;
    double duration;
    srand((unsigned) time(NULL));
	//pre_hole是最初始的数组，now_hole是对应的挖了洞之后的数组，hani 则是代表第几行第几列是什么
	int pre_hole[61], now_hole[61], holes, hani[9][9];
	memset(hani, -1, sizeof hani);//-1代表出界的位置
	cout << "\nPlease choose the number of choices:\n" << endl;
	printf("1.easy   2：medium    3：hard\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: holes = 30+rand()%5;
				break;
		case 2: holes = 40+rand()%5;
				break;
		case 3: holes = 45+rand()%5;
				break;
	}
	do
	{
	if(head)
	{
		tot_free(head);
	}
	createHanidoku(pre_hole);
	createStartinggrid(pre_hole, now_hole, holes);
	cout << "initialize the sudoku!" << endl;
	changeGrid(hani, now_hole);
	ToCnf(hani, holes);
	strcpy(filename,"sudoku.cnf");
	fp = fopen(filename,"r");
	head = (Clause *)malloc(sizeof(Clause));
  	head->next = NULL;
  	Init();
  	readCNF(head, fp);
  	fclose(fp);
	}
	while(DPLL(head)==UNSAT);
	printf("sudoku is ready!\n");
	int temp[61];
	srand((unsigned)time(NULL));
	int times = rand()%6;
	for(i  = 0; i < times;i++)
	{
		if(i%2)//偶数次 
		{
			turn(temp,now_hole);
		}
		else
		{
			turn(now_hole, temp);
		}
	}
	 if(i%2)
	 {
	 	for(int j = 0; j <61 ; j++)
	 	{
	 			now_hole[j] = temp[j];
		 }
	 }
	 for(i  = 0; i < times;i++)
	{
		if(i%2)//偶数次 
		{
			turn(temp,pre_hole);
		}
		else
		{
			turn(pre_hole, temp);
		}
	}
	 if(i%2)
	 {
	 	for(int j = 0; j <61 ; j++)
	 	{
	 			pre_hole[j] = temp[j];
		 }
	 }
	print(now_hole);
	system("pause");
	system("cls");
	int now_holes = holes;
	int total_flag=0;
	while(1)
	{
		print(now_hole);
		printf("There are %d holes left!\n",now_holes);
		printf("Make your choice：\n");
		printf("1.fill   2：check    3：hint\n");
		printf("4：withdraw   5: withdraw(Only wrong)   6:give up  7：exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1://fill
					printf("row col ans:\n");
					int row_ans,col_ans,num_ans;
					scanf("%d %d %d",&row_ans,&col_ans,&num_ans);
					if(row_ans>9||row_ans<1||col_ans>9||col_ans<1||num_ans>9||num_ans<1)
					{
						printf("Invalid!\n");
						system("pause");
						break;
					}
					xx=transfer[row_ans]+col_ans;
					if(now_hole[xx-1])
					{
						printf("There is not Empty!");
						system("pause");
						break;
					}
					if(pre_hole[xx-1]==num_ans)//如果对了 
						st_push(row_ans,col_ans,num_ans,1);
					else
					{
						st_push(row_ans,col_ans,num_ans,0);
						total_flag=1;
					}
					now_hole[xx-1]=num_ans;
					system("cls");
					print(now_hole);
					now_holes--;
					if(!now_holes)
					break;
				break;
			case 2://check
				system("cls");
				print(now_hole);
				if(total_flag==1)
				{
					printf("Existing Wrong Answers:\n");
					for(int i=0; i<=999; i++)
						if(st[i].mark==1)
							if(st[i].flag==0)
								printf("row:%d col:%d\n",st[i].row,st[i].col);
				}
				else
				{
					printf("No Wrong Answers\n");
				}
				system("pause");
				break;
			case 3://hint
				srand((unsigned) time(NULL));
				sj=rand()%61;
				while(now_holes&&now_hole[sj]!=0)
				{
					sj=rand()%61;
				}
				if(!now_holes)
				break;
				for(i=0;i<=999;i++)
					if(st[i].mark==0)
					{
						st[i].mark=1;
						st[i].flag=1;
						AddHint(sj+1,i);
						st[i].ans = pre_hole[sj];
						bk[bk_top++]=i;
						now_holes--;
						break;
					}
				now_hole[sj]=pre_hole[sj];
				system("cls");
				print(now_hole);
				printf("Position:\n");
				printf("row:%d col:%d ans:%d\n",st[i].row,st[i].col,st[i].ans);
				system("pause");
				break;
			case 4://withdraw
				while(bk_top && !st[bk[bk_top-1]].mark)
				--bk_top;
				if(!bk_top)
				{
					printf("You can't withdraw now because there is no operation.\n");
					system("pause");
					break;
				}
				else
				{
					int temp=bk[--bk_top];
					st[temp].mark=0;
					int xx=transfer[st[temp].row]+st[temp].col;
					now_hole[xx-1]=0;
					system("cls");
					printf("complete！\n");	
					total_flag=0;
					for(int i=0;i<999;i++)
						if(st[i].mark)
							if(st[i].flag==0)
								total_flag=1;
					now_holes++;
				}
				print(now_hole);
				system("pause");
				break;
			case 5 ://withdraw(wrong)
				if(total_flag == 0)
				{
					printf("No Wrong Answers\n");
					system("pause");
					break;
				}
				for(int i=0; i<=999; i++)
						if(st[i].mark==1)
							if(st[i].flag==0)
							{
								st[i].mark=0;
								int xx=transfer[st[i].row]+st[i].col;
								now_hole[xx-1]=0;
								now_holes++;
							}
				system("cls");
				printf("After Withdrawing：\n");
				print(now_hole);
				system("pause");
				total_flag=0;
				break;
			case 6://give up
				int temp;
				printf("Are you serious to give up?\n");
				printf("1:Yes else:No\n");
				scanf("%d",&temp);
				if(temp==1)
				{
					system("cls");
					printf("The answers are as follows:\n");
					print(pre_hole);
					printf("Welcome to try again\n");
					system("pause");
					system("cls");
					return;
				}
				system("cls");
				break;
			case 7:
			system("cls");
			return ;
			default :
				printf("Invalid！\n");
				system("pause");
				break;
		}
		if(!now_holes)
		{
			printf("Game over\n");
			if(total_flag==0)
				printf("You won！\n");
			 else
			 	printf("You failed!\n");
			system("pause");
			system("cls");
			return;
		}
		system("cls");
	}
	return ;
}

