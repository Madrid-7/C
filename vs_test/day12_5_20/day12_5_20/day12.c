#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1.
//��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	int sum = 0;
//	int k = 0;
//	for (i = 0; i < 32; i++)
//	{
//		k = value >> i & 1;
//		sum += k << (31 - i);
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%u\n", reverse_bit(n));
//	system("pause");
//	return 0;
//}

//2.
//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//int ave_1(int x, int y)
//{
//	return y + ((x - y) >> 1);
//}
//int ave_2(int x, int y)
//{
//	return x & y + ((x ^ y) >> 1);
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d%d", &x, &y);
//	printf("ave_1 = %d\n", ave_1(x, y));
//	printf("ave_2 = %d\n", ave_2(x, y));
//	system("pause");
//	return 0;
//}

//3.
//���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//int main()
//{
//	int arr[] = { 1, 5, 5, 1, 7, 6, 7, 8, 8, 9, 9 };
//	int i = 0;
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 1; i < len; i++)
//	{
//		arr[0] = arr[0] ^ arr[i];                //��λ���ͬһ�������β���
//	}
//	printf("%d\n", arr[0]);
//	system("pause");
//	return 0;
//}

//4.
//��һ���ַ����������Ϊ:"student a am i",
//���㽫��������ݸ�Ϊ"i am a student".
//Ҫ��
//����ʹ�ÿ⺯����
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
int lenth(const char* str)
{
	int count = 0;
	//const char* p = str;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverve_swap(char* left, char* right)
{
	assert(left != NULL);       //���Բ��ǿ�ָ��
	assert(right != NULL);
	while (left < right)
	{
		char ret = *left;
		*left = *right;
		*right = ret;
		left++;
		right--;
	}
}
void reverve(char* str)
{
	int len = lenth(str);
	char* start = str;
	char* end = NULL;
	int i = 0;
	reverve_swap(str, str + len - 1);
	for (i = 0; i <= len; i++)
	{
		if (str[i] == '\0' || str[i] == ' ')
		{
			end = str + i - 1;
			reverve_swap(start, end);
			start = str + i + 1;
		}
	}
}
int main()
{
	char str[] = "student a am i";
	reverve(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}