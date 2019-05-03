#define _CRT_SECURE_NO_WARNINGS 1
#define N 10
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double dis(double x1, double y1, double x2, double y2)
{
	double distance = 0.0;
	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return distance;
}
int main()
{
	double a[N][2] = { 0 };
	double c[N][N] = { 0 };
	int i, j;
	printf("输入十个点坐标(如:x,y):\n");
	for (i = 0; i < N; i++)
	{
		scanf("%lf,%lf", &a[i][0], &a[i][1]);
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			c[i][j] = dis(a[i][1], a[i][2], a[j][1], a[j][2]);
		}
	}
	printf("  dis    ");
	for (i = 0; i < N; i++)
	{
		printf("(%.0lf,%.0lf)  ", a[i][0], a[i][1]);
	}
	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("(%.0lf,%.0lf)  ", a[i][0], a[i][1]);
		for (j = 0; j <	N; j++)
		{
			printf("  %.1lf  ", c[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}