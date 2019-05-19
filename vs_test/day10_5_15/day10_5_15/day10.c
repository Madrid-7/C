#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//1. 
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	 //返回 1的位数 
//}
//int count_one_bits(unsigned int value)
//{
//	int  num = 0;
//	while (value)
//	{
//		if ((value & 1) == 1)
//			num++;
//		value >>= 1;//右移
//	}
//	return num;
//}
//int main()
//{
//	int n = 0;
//	int num = 0;
//	printf("请输入一个正数：");
//	scanf("%d", &n);
//	num = count_one_bits(n);
//	printf("num=%d\n", num);
//	system("pause");
//	return 0;
//}

//2.
//获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
//int main()
//{
//	int num = 0;
//	int i = 0;
//	int tmp;
//	scanf_s("%d", &num);
//	printf("奇数位为：");
//	for (i = 31; i >= 0; i = i - 2)  //每个整型数按32位来算
//	{
//		tmp = (num >> i) & 1;  //第一次向右移动31位，每次变化2位，即可得到奇数位情况
//		printf("%d ", tmp);
//	}
//	printf("\n");
//	printf("偶数位为：");
//	for (i = 30; i >= 0; i = i - 2)  //向右移动30位，每次变化2位，即可得到偶数位情况
//	{
//		tmp = (num >> i) & 1;
//		printf("%d ", tmp);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//3.
//输出一个整数的每一位。
//void play(int x)
//{
//	if (x != 0)
//	{
//		printf("%d\n", x % 10);
//		play(x / 10);
//	}
//}
//
//int main()
//{
//	int k;
//	scanf("%d", &k);
//	play(k);
//	system("pause");
//	return 0;
//
//}

//4.
//编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
int Differ_bits1(int m, int n)
{
	//对每一位按位与1，比较是否相同
	int count = 0; 
	int i = 0; 
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
			count++;
	}
	return count;
}

int Differ_bits2(int m, int n)
{
	//两个数异或后，求其中1的个数
	int ret = m ^ n;
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((ret >> i) & 1))
			count++;
	}
	return count;
}

int main()
{
	int m = 0;
	int n = 0;
	int ret1 = 0;
	int ret2 = 0;
	scanf("%d%d", &m, &n);
	ret1 = Differ_bits1(m, n);
	ret2 = Differ_bits2(m, n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	system("pause");
	return 0;
}