#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//1.
//��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
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
//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
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
	printf("�Ҳ���.\n");
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	FindNum(arr, 7, 3, 3);
	system("pause");
	return 0;
}