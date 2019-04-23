#define _CRT_SECURE_NO_WARNINGS 1
//二分查找
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int left = 0, right = sizeof(arr) / sizeof(int) - 1, mid = 0;
	while (left <= right)
	{
		mid = left + (right - left);
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("下标为:%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("未找到\n");
	system("pause");
	return 0;
}