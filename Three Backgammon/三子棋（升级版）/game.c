#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void PrintBroad(char broad[ROW][COL], int row, int col)
{
	system("cls");
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", broad[i][0], broad[i][1], broad[i][2]);
		if (i < row - 1)
		{
			printf("___|___|___\n");
		}
	}
}
int CheckBroad(char broad[ROW][COL], int col, int row)
{
	if (broad[row][col] == ' ')
		return 1;
	else
		return 0;
}
void Playermove(char broad[ROW][COL], int row, int col, char sz, int flag)
{
	int x = 0;
	int y = 0;
	printf("请玩家%d(%c)下棋(格式为：x,y)\n",(flag % 2) + 1,sz);
	while (1)
	{
		scanf("%d,%d", &x, &y);
		if (x > 0 && x <= 3 && y > 0 && y <= 3)
		{
			if (CheckBroad(broad, x - 1, y - 1) == 1)
			{
				broad[y - 1][x - 1] = sz;
				break;
			}
			else
				printf("请重新输入：");
		}
		else
			printf("请重新输入：");
	}
}

int CheckResult(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//检测横行
	for (i = 0; i < row; i++)
	{
		if (broad[i][0] == broad[i][1] && broad[i][0] == broad[i][2] && broad[i][0] != ' ')
		{
			if (broad[i][0] == 'X')
				return '0';
			else if (broad[i][0] == '0')
				return '1';
		}
	}
	//检测竖行
	for (i = 0; i < col; i++)
	{
		if (broad[0][i] == broad[1][i] && broad[1][i] == broad[2][i] && broad[1][i] != ' ')
		{
			if (broad[1][i] == 'X')
				return '0';
			else if (broad[1][i] == '0')
				return '1';
		}
	}
	//检测斜行
	if (broad[0][0] == broad[1][1] && broad[1][1] == broad[2][2] && broad[1][1] != ' ')
	{
		if (broad[1][1] == 'X')
			return '0';
		else if (broad[1][1] == '0')
			return '1';
	}
	if (broad[0][2] == broad[1][1] && broad[1][1] == broad[2][0] && broad[1][1] != ' ')
	{
		if (broad[1][1] == 'X')
			return '0';
		else if (broad[1][1] == '0')
			return '1';
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
				return 'c';
		}
	}
	return 'p';
}


