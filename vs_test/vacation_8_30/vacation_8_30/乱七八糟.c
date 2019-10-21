#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int*)((int)a + 1);

	char* szX = "abc";
	char* szY = "abc";
	printf("%x\n", p1[0]);

	system("pause");
	return 0;
}