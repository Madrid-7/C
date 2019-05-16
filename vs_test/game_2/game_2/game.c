#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//初始化棋盘
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
//打印棋盘
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
//埋雷
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
//返回周围雷的个数
int ChangeBoard(char mine[ROWS][COLS], char show[ROWS][COLS] ,int x, int y)
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
	return sum;
}
//实现展开函数
void Unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* p_count)
{
	int sum = ChangeBoard(mine, show, x, y);
	*p_count = *p_count + 1;
	if (sum == 0 && show[x - 1][y - 1] == '*' && x - 1 > 0 && y - 1 > 0)
	{
		Unfold(mine, show, x - 1, y - 1, &*p_count);
	}
	if (sum == 0 && show[x - 1][y] == '*' && x - 1 > 0)
	{
		Unfold(mine, show, x - 1, y, &*p_count);
	}
	if (sum == 0 && show[x - 1][y + 1] == '*' && x - 1 > 0 && y + 1 <= COL)
	{
		Unfold(mine, show, x - 1, y + 1, &*p_count);
	}
	if (sum == 0 && show[x][y - 1] == '*' && y - 1 > 0)
	{
		Unfold(mine, show, x, y - 1, &*p_count);
	}
	if (sum == 0 && show[x][y + 1] == '*' && x - 1 > 0 && y + 1 <= COL)
	{
		Unfold(mine, show, x, y + 1, &*p_count);
	}
	if (sum == 0 && show[x + 1][y - 1] == '*' && x + 1 <= ROW && y - 1 > 0)
	{
		Unfold(mine, show, x + 1, y - 1, &*p_count);
	}
	if (sum == 0 && show[x + 1][y] == '*' && x + 1 <= ROW)
	{
		Unfold(mine, show, x + 1, y, &*p_count);
	}
	if (sum == 0 && show[x + 1][y + 1] == '*' && x + 1 <= ROW && y + 1 <= COL)
	{
		Unfold(mine, show, x + 1, y + 1, &*p_count);
	}
}
//扫雷函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < row * col - EASY_MINE)
	{
		int x = 0;
		int y = 0;
		printf("输入坐标:\n");
		scanf("%d%d", &x, &y);
		if (mine[x][y] != '1')
		{
			Unfold(mine, show, x, y, &count);
			PrintBoard(show, ROW, COL);
		}
		else
		{
			//避免第一次被炸死
			if (count == 0)
			{
				while (count == 0)
				{
					int x1 = rand() % row + 1;
					int y1 = rand() % col + 1;
					if (mine[x1][y1] == '0' && x1 != x && y1 != y)
					{
						mine[x][y] = '0';
						mine[x1][y1] = '1';
						Unfold(mine, show, x, y, &count);
						PrintBoard(show, ROW, COL);
					}
				}
			}
			else
			{
				printf("游戏失败\n");
				break;
			}
		}
	}
	if (count == row * col - EASY_MINE)
	{
		printf("排雷成功,游戏结束\n");
	}
}
