#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//void InitSets(char** sets, char str, int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			sets[i][j] = str;
//		}
//	}
//}
//
//int main()
//{
//	int row = 0;
//	int col = 0;
//
//	int i = 0;
//	int j = 0;
//
//	printf("输入行：");
//	scanf("%d", &row);
//	printf("输入列：");
//	scanf("%d", &col);
//
//	char **sets = (char **)malloc(sizeof(char *) * row);
//	for (i = 0; i < row; ++i)
//	{
//		sets[i] = (char *)malloc(sizeof(char) * col);
//	}
//
//	InitSets(sets, 'y', row, col);
//
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", (sets)[i - 1][j - 1]);
//		}
//		printf("\n");
//	}
//
//	printf("输入new行：");
//	scanf("%d", &row);
//	printf("输入new列：");
//	scanf("%d", &col);
//
//	sets = (char **)realloc(sets, sizeof(char *) * row);
//	for (i = 0; i < row; ++i)
//	{
//		sets[i] = (char *)realloc(sets[i], sizeof(char) * col);
//	}
//
//	InitSets(sets, 'x', row, col);
//
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", (sets)[i - 1][j - 1]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

int main()
{

	int i = 0;
	do
	{
		b.managepassword[i] = _getch();
		if (b.managepassword[i] == '\r')
			break;
		if (b.managepassword[i] == '\b')
		{
			if (i == 0)
			{
				printf("\a");
				continue;
			}
			i = i - 1;
			printf("\b");
		}
		else
		{
			i = i + 1;
			printf("*");
		}
	} while (b.managepassword[i] != '\n' && i < 20);
	b.managepassword[i] = '\0';
	printf("\n");

}