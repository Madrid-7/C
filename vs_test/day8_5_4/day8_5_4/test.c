#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
		printf("*************************************\n");
		printf("*********      1.play       *********\n");
		printf("*********      0.exit       *********\n");
		printf("*************************************\n");
}

void game()
{
	char board[ROW][LINE] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, LINE);
	ChessBoard(ROW, LINE, board);      //打印棋盘
	while (1)
	{
		PlayerMove(ROW, LINE, board);           //玩家走
		ChessBoard(ROW, LINE, board);               
		ret = CheakWin(ROW, LINE, board);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(ROW, LINE, board);                 //电脑走
		ChessBoard(ROW, LINE, board);
		ret = CheakWin(ROW, LINE, board);
		if (ret != 'C')
		{
			break;
		}
	}
	if ('Q' == ret)
	{
		printf("平局\n");
	}
	else if ('*' == ret)
	{
		printf("玩家赢\n");
	}
	else if ('#' == ret)
	{
		printf("电脑赢\n");
	}
}

void test()
{
	srand((unsigned)time(NULL));
	int n;
	do
	{
		menu();
		printf("你的选择:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (n);
}
int main()
{
	test();
	system("pause");
	return 0;
}





