#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void m(float a, float b, float c)
{
	double x1, x2;
	x1 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
	x2 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	printf("������������ʵ����x1=%2.2f,x2=%2.2f\n", x1, x2);
}
void m1(float a, float b, float c)
{
	double x;	x = (-b) / 2 * a;
	printf("������һ��ʵ����x1=x2=%2.2f\n", x);
}
void main()
{
	float* a = (float*)malloc(3 * sizeof(float));
	double* sum = (double*)malloc(sizeof(double));
	printf("������a,b,cϵ����");
	scanf("%f%f%f", a, a + 1, a + 2);
	printf("����Ϊ��%2.2fx^2+%2.2fx+%2.2f=0\n", *a, *(a + 1), *(a + 2));
	*sum = (*(a + 1)) * (*(a + 1)) - 4 * (*a)*(*(a + 2));
	if (*sum > 0)		
		m(*a, *(a + 1), *(a + 2));
	else if (*sum == 0)		
		m1(*a, *(a + 1), *(a + 2));
	else printf("�����޽⣡����\n");
	system("pause");
}
