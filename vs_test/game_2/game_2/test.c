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
	//雷区数组
	char mine[ROWS][COLS] = { 0 };
	//玩家界面
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');       
	InitBoard(show, ROWS, COLS, '*');
	//打印雷区
	PrintBoard(show, ROW, COL);
	//埋雷
	SetMine(mine, ROW, COL);
	//排雷
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
		printf("你的选择:>");
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