#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int fib_num(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		int fib, i;
//		int a = 1, b = 1;
//		for (i = 3; i <= n; i++)
//		{
//			fib = a + b;
//			a = b;
//			b = fib;
//		}
//		return fib;
//	}
//}
//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d,%d", fib(n), fib_num(n));
//	system("pause");
//	return 0;
//}

//int num(int n, int k)
//{
//	if (0 == k)
//		return 1;
//	else
//		return n * num(n, k - 1);
//}
//int main()
//{
//	int n = 0, k = 0;
//	scanf("%d%d", &n, &k);
//	printf("%d", num(n, k));
//	system("pause");
//	return 0;
//}

//int DigitSum(int x)
//{
//	if (x > 0)
//	{
//		return x % 10 + DigitSum(x / 10);
//	}
//	return 0;
//}
//int main()
//{
//	printf("%d\n", DigitSum(1729));
//	system("pause");
//	return 0;
//}

//void reverse_string(char * string)
//{
//
//	if (*string != '\0')
//	{
//		reverse_string(++string);
//		printf("%c", *(string-1));
//	}
//}
//int main()
//{
//	char s[] = "abcdefgh";
//	reverse_string(s);
//	system("pause");
//	return 0;
//}

//int len_string(char s[])
//{
//	if (*(s++) != '\0')
//		return 1 + len_string(s);
//	return 0;
//}
//int main()
//{
//	char s[] = "abcdefgh";
//	printf("%d\n", len_string(s));
//	system("pause");
//	return 0;
//}
//int len_string(char s[])
//{
//	int i = 0;
//	while (s[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	char s[] = "abcdefgh";
//	printf("%d\n", len_string(s));
//	system("pause");
//	return 0;
//}

//int num(int n)
//{
//	if (n > 1)
//		return n * num(n - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", num(n));
//	system("pause");
//	return 0;
//}
//int num(int n)
//{
//	int i = 0, sum = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum = sum * i;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", num(n));
//	system("pause");
//	return 0;
//}

//void print_int(int n)
//{
//	if (n / 10 != 0)
//		print_int(n / 10);
//	printf("%d ", n % 10);
//
//}
//int main()
//{
//	int n = 2019;
//	print_int(n);
//	system("pause");
//	return 0;
//}