#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[3][3] = { 0 }, b[3][3] = { 0 }, c[3][3] = { 0 };
	int(*p)[3], (*pa)[3] = a, (*pb)[3] = b, (*pc)[3] = c;
	int *q;

	int i, j, k;
	printf("�����һ������:");
	for (p = a; p < a + 3; p++)
	{
		for (q = *p; q < *p + 3; q++)
		{
			scanf("%d", &*q);
		}
	}
	printf("����ڶ�������:");
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

	printf("���Ϊ:\n");
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

