#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int x = 3, y = 4, z;
//	z = y;
//	y = x;
//	x = z;
//	return 0;
//}
//int main()
//{
//	int x = 3, y = 4;
//	x = x + y;
//	y = x - y;
//	x = x - y;
//	return 0;
//}
//int main()
//{
//	int a[10] = { 21,31,23,43,54,2,36,87,90,12 };
//	int max = 0;
//	int i;
//
//	for (i = 0; i < 10; i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//		}
//	}
//	printf("%d", max);
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//int main()
//{
//	int a = 0, b = 0;
//	int i = 0;
//	scanf("%d%d", &a, &b);
//	if (a >= b)
//	{
//		for (i = b; i > 0; i--)
//		{
//			if ((a%i == 0) && (b%i == 0))
//			{
//				printf("%d\n",i);
//				break;
//			}
//		}
//	}
//	else
//	{
//		for (i = a; i > 0; i--)
//		{
//			if ((a%i == 0) && (b%i == 0))
//			{
//				printf("%d\n",i);
//				break;
//			}
//		}
//	}
//	return 0;
////}
//int main()
//{
//	int a[] = { 1, 3, 5, 7, 9 };
//	int b[] = { 3, 4, 5, 6 ,7 };
//	int c = 0, i = 0;
//	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		c = b[i];
//		b[i] = a[i];
//		a[i] = c;
//	}
//}
//int main()
//{
//	int i = 0, k = 1;
//	float sum = 0;
//
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + (1.0 / i)*k;
//		k = -k;
//	}
//	printf("%f", sum);
//	system("pause");
//	return 0;
//}
int main() {
	int i = 0;
	int k = 0;
	for (i = 1; i < 100; i++)
	{
		if (i % 10 == 9)
		{
			k++;
		}
		if (i / 10 == 9)
		{
			k++;
		}
	}
	printf("%d\n", k);
	system("pause");
	return 0;
}