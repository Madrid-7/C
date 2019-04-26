#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//二分查找(函数)
//int binary_search(int arr[], int k, int left, int right)
//{
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > k)
//			right = mid - 1;
//		else if (arr[mid] < k)
//			left = mid + 1;
//		else
//			return mid;
//	}
//	if (left > right)
//		return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(int) - 1;
//	int ret = binary_search(arr, k, left, right);
//	if (ret)
//		printf("下标为%d\n", ret);
//	else
//		printf("未找到\n");
//	system("pause");
//	return 0;
//}
//酷壳
