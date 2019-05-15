#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****      1.play       *****\n");
	printf("*****      0.exit       *****\n");
	printf("*****************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');       
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	PrintBoard(show, ROW, COL);
	//����
	SetMine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);
	//����
	FindMine(mine, show, ROW, COL);
	PrintBoard(mine, ROW, COL);
}

void test()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("���ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			break;
		default:
			break;
		}
	} while (input);
}

int main()
{

	test();

	system("pause");
	return 0;
}