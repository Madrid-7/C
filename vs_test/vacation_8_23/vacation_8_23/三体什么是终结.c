#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//
//
//	unsigned long u = 0;
//	printf("%lu", u);
//	system("pause");
//	return 0;
//
//}

//int main()
//{
//	int a = 4;
////	++(a++);     ±Ì¥Ô Ω¥ÌŒÛ
//
//	system("pause");
//	return 0;
//}

int x = 3;
void inc()
{
	static int x = 1;
	x *= (x + 1);
	printf("%d", x);
	return;
}
int main()
{
	int i;
	for (i = 1; i < x; i++)
	{
		inc();
	}
	system("pause");
	return 0;
}