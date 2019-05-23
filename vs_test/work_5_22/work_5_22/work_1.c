//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#define N 10
//
//void arr_ranking(int* arr, int n)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < n - 1; i++)
//		for (j = i + 1; j < n; j++)
//			if (*(arr + i) > *(arr + j))
//			{
//				k = *(arr + i);
//				*(arr + i) = *(arr + j);
//				*(arr + j) = k;
//			}
//}
//int main()
//{
//	int i = 0;
//	int* arr = (int*)malloc(N * sizeof(int));
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	arr_ranking(arr, N);
//	for (i = 0; i < N; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	free(arr);
//	system("pause");
//	return 0;
//}