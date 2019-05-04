#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROW][LINE], int row, int line)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			board[i][j] = ' ';
		}
	}
	//memset(&board[0][0], ' ', row*line * sizeof(board[0][0]));
}

void ChessBoard(int row, int line, char board[ROW][LINE])
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for ( j = 0; j < line; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < LINE - 1)
				printf("|");
			else
				printf("\n");
		}
		if (i < ROW - 1)
		{
			for (j = 0; j < line; j++)
			{
				printf("---");
				if (j < LINE - 1)
					printf("|");
				else
					printf("\n");
			}
		}
	}
}

void PlayerMove(int row, int line, char board[ROW][LINE])
{
	int x = 0, y = 0;
	printf("玩家走:>");
	while (1)
	{
		scanf("%d,%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= line)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("此位置已走,重新选择:>");
		}
		else
			printf("此位置不存在,重新选择:>");
	}
}

void ComputerMove(int row, int line, char board[ROW][LINE])
{
	int x = 0, y = 0;
	printf("电脑走:>");

	while (1)
	{
		x = rand() % ROW;
		y = rand() % LINE;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			printf("%d,%d\n", x + 1, y + 1);
			break;
		}
	}
}