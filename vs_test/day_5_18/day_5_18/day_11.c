#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//不考虑重序
//int main()
//{
//	int a, b, c, d, e;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1)
//							&& ((b == 2) + (e == 4) == 1)
//							&& ((c == 1) + (d == 2) == 1)
//							&& ((c == 5) + (d == 3) == 1)
//							&& ((e == 4) + (a == 1) == 1))
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
//							}
//						}
//						//int num = 0;
//						//num |= (1 << (a - 1));//a=3
//						//num |= (1 << (b - 1));
//						//num |= (1 << (c - 1));
//						//num |= (1 << (d - 1));
//						//num |= (1 << (e - 1));
//						//while (num)  //有可能有并列，但是绝不可能有第一名第三名，没有第二名
//						//{
//						//	if (num % 2 == 0)
//						//		break;
//						//	num = num / 2;
//						//}
//						//if (num == 0)
//						//{
//						//	printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//						//}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//2.
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//int main()
//{
//	int a, b, c, d;
//	for (a = 0; a <= 1; a++)
//	{
//		for (b = 0; b <= 1; b++)
//		{
//			for (c = 0; c <= 1; c++)
//			{
//				for (d = 0; d <= 1; d++)
//				{
//					if ((a == 0) + (c == 1) + (d == 1) + (d == 0) == 3)
//					{
//						if (a + b + c + d == 1)
//						{
//							printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//3.
//在屏幕上打印杨辉三角。
//   1
//  1 1
// 1 2 1
//1 3 3 1
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int arr[30][30] = { 0 };
	arr[0][0] = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("%d ", arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}