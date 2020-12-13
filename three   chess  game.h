#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//默认棋盘没落子每个位置是' '空格
//人下了一个位置用'M'表示
//电脑下了一个位置用'C'表示
void BoardInit(char board[ROW][COL], int row, int col);
void BoardShow(char board[ROW][COL], int row, int col);

void BoardPlayer(char board[ROW][COL], int row, int col);
void BoardComputer(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);
//电脑赢了 返回'C'   玩家赢了返回'M'返回'Q'代表平局
char IsWin(char board[ROW][COL], int row, int col);
