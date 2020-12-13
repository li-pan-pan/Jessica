#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("*********1.三子棋*************\n");
	printf("*********2.五子棋*************\n");
	printf("*********3.扫雷***************\n");
	printf("*********0.退出***************\n");
	printf("******************************\n");
}
void ThreeChess()
{
	//创建并且初始化棋盘
	char board[ROW][COL] = { 0 };
	BoardInit(board, ROW, COL);
	BoardShow(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		printf("玩家出手\n");

		BoardPlayer(board, ROW, COL);
		ret = IsWin(board, ROW, COL);

		if (ret != ' ')
		{
			break;
		}
		BoardComputer(board, ROW, COL);
		BoardShow(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
	}
	BoardShow(board, ROW, COL);
	if (ret == 'C')
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'M')
	{
		printf("你赢了\n");
	}
	if (ret == 'Q')
	{
	printf("平局\n");
	}
}
int main()
{
	int input;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ThreeChess();
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input != 0);
	return 0;
}
