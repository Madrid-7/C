#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a[3][3] = {0}, b[3][3] = { 0 }, c[3][3] = { 0 };
//	int i, j, k;
//	printf("输入第一个矩阵:");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	printf("输入第二个矩阵:");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%d", &b[i][j]);
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			for (k = 0; k < 3; k++)
//			{
//				c[i][j] += a[i][k] * b[k][j];
//			}
//		}
//	}
//	printf("结果为:\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", c[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	int i = 0, j = 0;
	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j < 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 13 - 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
