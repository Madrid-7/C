#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//void print(int n)
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= n; i++)
//	{
//
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d*%-2d=%-3d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("输入阶数:");
//	scanf("%d", &n);
//	print(n);
//	system("pause");
//	return 0;
//}
//void swop(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	printf("a = %d, b = %d\n", a, b);
//	swop(&a, &b);
//	printf("a = %d, b = %d\n", a, b);
//	system("pause");
//	return 0;
//}
//int leap_year(int year)
//{
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year;
//	printf("输入年份:");
//	scanf("%d", &year);
//	if (leap_year(year))
//		printf("%d是闰年\n", year);
//	else
//		printf("%d不是闰年\n", year);
//	system("pause");
//	return 0;
//}
//void init(int arr[], int sz)
//{
//	int i = 0, tmp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &tmp);
//		arr[i] = tmp;
//	}
//}
//void empty(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void reverse(int arr[], int sz)
//{
//	int i, tmp = 0;
//	for (i = 0; i < sz/2; i++)
//	{
//		tmp = arr[i];
//		arr[i] = arr[sz - i - 1];
//		arr[sz - i - 1] = tmp;
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = 0, i = 0;
//	sz = sizeof(arr) / sizeof(int);
//	init(arr, sz);      //初始化
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	reverse(arr, sz);          //逆置
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	empty(arr, sz);         //清空数组
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
int prime_number(int x)
{
	if (x <= 3)
		return 1;
	else
	{
		int i;
		for (i = 2; i <= sqrt(x); i++)
		{
			if (0 == x % i)
				return 0;
		}
		return 1;
	}
}
int main()
{
	int x;
	printf("输入一个大于1的正整数:");
	scanf("%d", &x);
	if (prime_number(x))
	{
		printf("%d是素数\n", x);
	}
	else
		printf("%d不是素数\n", x);
	system("pause");
	return 0;
}