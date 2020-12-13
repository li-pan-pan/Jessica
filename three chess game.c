#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include<stdio.h>
//默认棋盘没落子每个位置是' '空格
//人下一个位置用'M'表示
//电脑下一个位置'C'表示
void BoardInit(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			board[i][j] = ' ';
		}
	}
}

void BoardShow(char board[ROW][COL], int row, int col)
{
	printf("|");
	for (int j = 0; j < col; ++j)
	{
		printf("---|");
	}
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		printf("|");
		for (int j = 0; j < col; ++j)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");

		printf("|");
		for (int j = 0; j < col; ++j)
		{
			printf("---|");
		}
		printf("\n");
	}
}

void BoardPlayer(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x, y;
		printf("请输入你要下的坐标：>");
		scanf("%d%d", &x, &y);

		if (x >= row || y >= col || row < 0 || col < 0)
		{
			printf("输入非法坐标，请重新输入\n");
			continue;
		}
		else
		{
			if (board[x][y] != ' ')
			{
				printf("此位置已落子，请重选择位置\n");
				continue;
			}
			else
			{
				board[x][y] = 'M';
				break;
			}
		}
	}
}
void BoardComputer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		srand((int)time(NULL));
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'C';
			break;
		}
	}
}


//int IsFull(char board[ROW][COL], int row, int col)
//{
//	/*int i = 0;
//	int j = 0;*/
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//			{
//				return 0;//没满
//			}
//		}
//	}
//	return 1;//满了
//}
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i= 0; i <row ; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}

		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横赢
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
