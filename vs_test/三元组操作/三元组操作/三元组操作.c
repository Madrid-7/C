#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int row;
	int col;
	int x;
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];
	int rows;
	int cols;
	int nums;
}TSMatrix;

int main()
{
	TSMatrix a;
	TSMatrix b;
	scanf("%d%d%d", &a.rows, &a.cols, &a.nums);
	for (size_t i = 0; i < a.nums; i++)
	{
		scanf("(%d,%d,%d)", &a.data[i].row, &a.data[i].col, &a.data[i].x);
	}
	scanf("%d%d%d", &b.rows, &b.cols, &b.nums);
	for (size_t i = 0; i < a.nums; i++)
	{
		scanf("(%d,%d,%d)", &b.data[i].row, &b.data[i].col, &b.data[i].x);
	}
	system("pause");
	return 0;
}