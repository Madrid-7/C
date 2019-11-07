#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x;
	int i;
	int j;

	printf("请输入三角形的行数x:");
	scanf("%d", &x);

	for (i = 1; i < x; i++)
	{
		for (j = 0; j < x - i; j++)
		{
			printf(" ");
		}
		printf("*");
		for (j = 1; j < 2 * i - 2; j++)
		{
			printf(" ");
		}
		if (i != 1)
			printf("*");
		printf("\n");
	}

	for (i = 0; i < 2 * x - 1; i++)
	{
		printf("*");
	}
	printf("\n");

	system("pause");
	return 0;
}