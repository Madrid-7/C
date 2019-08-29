#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//int main()
//{
//
//	char a = 1;
//	int b = 1;
//	float c = 1;
//	double d = 1;
//
//	int x;
////	x = a + b + c + d;             ֵΪdouble
//	system("pause");
//	return 0;
//}

int main()
{
	//unsigned long ulA = 0x11000000;
	//printf("%x\n", *(unsigned char *)&ulA);

	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s));
	system("pause");
	return 0;
}