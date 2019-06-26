#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[3][3] = { 0 }, b[3][3] = { 0 }, c[3][3] = { 0 };
	int(*p)[3], (*pa)[3] = a, (*pb)[3] = b, (*pc)[3] = c;
	int *q;

	int i, j, k;
	printf("输入第一个矩阵:");
	for (p = a; p < a + 3; p++)
	{
		for (q = *p; q < *p + 3; q++)
		{
			scanf("%d", &*q);
		}
	}
	printf("输入第二个矩阵:");
	for (p = b; p < b + 3; p++)
	{
		for (q = *p; q < *p + 3; q++)
		{
			scanf("%d", &*q);
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				*(*(pc + i) + j) += *(*(pa + i) + k) * *(*(pb + k) + j);
			}
		}
	}

	printf("结果为:\n");
	for (p = c; p < c + 3; p++)
	{
		for (q = *p; q < *p + 3; q++)
		{
			printf("%d", *q);
		}
		printf("\n");
	}
	system("pause");

	return 0;
}

