#define _CRT_SECURE_NO_WARNINGS 1
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
	double a[3][2] = { {1,1}, {2,1}, {3,1} };
	double c[3][3] = { 0 };
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c[i][j] = dis(a[i][1], a[i][2], a[j][1], a[j][2]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%.1lf  ", c[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}