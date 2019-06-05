#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//1.
//调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//void arr_fun(int* arr, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		int tmp = 0;
//		if (arr[left] % 2 == 1)
//		{
//			left++;
//			continue;
//		}
//		if (arr[right] % 2 == 0)
//		{
//			right--;
//			continue;
//		}
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	arr_fun(arr, len);
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

//2.
//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
void FindNum(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;
	while (x < row && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			printf("%d,%d\n", x, y);
			return;
		}
	}
	printf("找不到.\n");
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	FindNum(arr, 7, 3, 3);
	system("pause");
	return 0;
}