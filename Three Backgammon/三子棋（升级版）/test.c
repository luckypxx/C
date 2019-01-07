#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("****1.play        0.exit****\n");
	printf("****************************\n");
}

int check()
{
	int input;
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			return input;
			break;
		case 0:
			system("cls");
			printf("���˳�\n");
			return 0;
			break;
		default:
			printf("���������룺");
			break;
		}
	} while (input);
}

int init(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			broad[i][j] = ' ';
	}
	return 0;
}

int main()
{
	char choose = 'k';
	char sz = 'X';
	int flag = 2;
	menu();
	printf("����������ѡ�");
	if (check() == 1)
	{
		char broad[ROW][COL] = { 0 };
		init(broad, ROW, COL);
		PrintBroad(broad, ROW, COL);
		while (1)
		{
			if (flag % 2 == 1)
				sz = 'X';
			else
				sz = '0';
			Playermove(broad, ROW, COL, sz, flag);
			PrintBroad(broad, ROW, COL);
			choose = (CheckResult(broad, ROW, COL));
			switch (choose)
			{
			case '0':
				printf("���2Ӯ�ˣ�\n");
				system("pause");
				return 0;
			case '1':
				printf("���1Ӯ�ˣ�\n");
				system("pause");
				return 0;
			case 'p':
				printf("ƽ��\n");
				system("pause");
				return 0;
			case 'c':
				break;
			default:
				printf("error\n");
			}
			flag++;
		}
	}

	system("pause");
	return 0;
}