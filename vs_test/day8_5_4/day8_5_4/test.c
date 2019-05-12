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
	ChessBoard(ROW, LINE, board);      //��ӡ����
	while (1)
	{
		PlayerMove(ROW, LINE, board);           //�����
		ChessBoard(ROW, LINE, board);               
		ret = CheakWin(ROW, LINE, board);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(ROW, LINE, board);                 //������
		ChessBoard(ROW, LINE, board);
		ret = CheakWin(ROW, LINE, board);
		if (ret != 'C')
		{
			break;
		}
	}
	if ('Q' == ret)
	{
		printf("ƽ��\n");
	}
	else if ('*' == ret)
	{
		printf("���Ӯ\n");
	}
	else if ('#' == ret)
	{
		printf("����Ӯ\n");
	}
}

void test()
{
	srand((unsigned)time(NULL));
	int n;
	do
	{
		menu();
		printf("���ѡ��:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����\n");
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





