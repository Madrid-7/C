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
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("ÄãµÄÑ¡Ôñ:>");
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