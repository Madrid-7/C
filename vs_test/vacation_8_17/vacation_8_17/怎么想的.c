#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	char a[20];
//	char* p1 = (char*)a;
//	char* p2 = (char*)(a + 5);
//	//int n = p2 - p1;
//	int n = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
//
//	printf("%d\n", n);
//	system("pause");
//	return 0;
//}

enum ENUM_A
{
	X1,
	Y1,
	Z1=5,
	A1,
	B1,
};
enum ENUM_A enumA = Y1; 
enum ENUM_A enumB = B1;

int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
 }
int  main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d, ", k);
	k = fun(j, m);
	printf("%d", k);
	system("pause");
	return 0;
}