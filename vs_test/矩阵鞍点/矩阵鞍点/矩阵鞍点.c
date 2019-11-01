#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m = 0;
	int n = 0;

	int i = 0;
	int j = 0;

	int flag = 0;
	int num = 0;

	int* min = (int *)malloc(n * sizeof(int));
	int* max = (int *)malloc(m * sizeof(int));

	scanf("%d%d", &m, &n);
	int **arr = (int**)malloc(m * sizeof(int *));
	for (i = 0; i < m; i++)
	{
		arr[i] = (int *)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < m; i++)
	{
		min[i] = arr[i][0];
		for (j = 1; j < n; j++)
		{
			if (arr[i][j] < min[i])
			{
				min[i] = arr[i][j];
			}
		}
	}

	for (j = 0; j < n; j++)
	{
		max[j] = arr[0][j];
		for (i = 1; i < m; i++)
		{
			if (arr[i][j] > max[j])
			{
				max[j] = arr[i][j];
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		if (flag == 1 && min[i] != num)
			continue;
		for (j = 0; j < n; j++)
		{
			if (min[i] == arr[i][j] && max[j] == arr[i][j])
			{
				if (flag == 0)
				{ 
					flag = 1;
					num = arr[i][j];
				}
				printf("(%d,%d,%d)", i + 1, j + 1, arr[i][j]);
			}
		}
	}

	if (flag == 0)
	{
		printf("NONE");
	}
	system("pause");
	return 0;
}