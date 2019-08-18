#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>

//int main()
//{
//	int a = 5;
//	if (a = 0)
//	{
//		printf("%d\n", a - 10);
//	}
//	else
//	{
//		printf("%d\n", a++);
//	}
//	system("pause");
//	return 0;
//
//}

int fib(int n)
{
	if (n < 3 && n > 0)
	{
		return 1;
	}
	else if (n >= 3)
	{
		int p = 1;
		int q = 1;
		int fib = 0;
		int i = 0;
		for (i = 0; i < n - 2; i++)
		{
			fib = p + q;
			p = q;
			q = fib;
		}
		return fib;
	}
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	system("pause");
	return 0;
}