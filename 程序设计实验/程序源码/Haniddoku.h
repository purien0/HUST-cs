#ifndef  HANIDDOKU_H
#define  HANIDDOKU_H
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include <time.h>
typedef struct numNode   //为翻转提供准备
{
	int x;
	int y;
} numNode;
using namespace std;

typedef struct ansnode
{
	int col;
	int row;
	int ans;
	int flag;
	int mark;//0空1非空
} Ansnode;

void Haniddoku();
void st_push(int l,int r,int num,int flagg);
void createHanidoku(int pre_hole[]);
void createStartinggrid(int pre_hole[], int now_hole[], int holes);//开始挖洞，基于挖洞法生成数独游戏
void print(const int pre_hole[]);//输出数独格局
void turnAnAngle(numNode pre_hole[][10], numNode now_hole[][10]);
void createNode(numNode now_hole[][10]);
int TransLiteral(int x);
void def_TransLiteral(int x,int &line,int &row,int &con);
void lineDis(FILE *fp, numNode now_hole[][10]);
void Singularity(FILE *fp);
void ToCnf(int pre_hole[][9], int holes);
void changeGrid(int hani[][9], int now_hole[]);
#endif
