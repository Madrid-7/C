#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void del(int arr[], int sz, int i, int k)
{
	if (i + k > sz)
	{
		int j = 0;
		for (j = i - 1; j < sz - 1; j++)
		{
			arr[j] = 0;
		}
	}
	else
	{
		for (; i + k < sz; i++)
			arr[i - 1] = arr[i + k - 1];
	}
}