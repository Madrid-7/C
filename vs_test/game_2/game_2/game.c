#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char str)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = str;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < EASY_MINE)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count++;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < row * col - EASY_MINE)
	{
		int x = 0;
		int y = 0;
		printf("��������:\n");
		scanf("%d%d", &x, &y);
		if (mine[x][y] != '1')
		{
			int sum = 0;
			sum += mine[x - 1][y - 1] - '0';
			sum += mine[x - 1][y] - '0';
			sum += mine[x - 1][y + 1] - '0';
			sum += mine[x][y + 1] - '0';
			sum += mine[x][y - 1] - '0';
			sum += mine[x + 1][y - 1] - '0';
			sum += mine[x + 1][y] - '0';
			sum += mine[x + 1][y + 1] - '0';
			if (sum == 0)
			{
				show[x][y] = ' ';
			}
			else
			{
				show[x][y] = sum + '0';
			}
			PrintBoard(show, ROW, COL);
			count++;

		}
		else
		{
			printf("��Ϸʧ��\n");
			PrintBoard(mine, ROW, COL);
			break;
		}
	}
	if (count == row * col - EASY_MINE)
	{
		printf("���׳ɹ�,��Ϸ����\n");
	}
}

