#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//1. 
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	 //���� 1��λ�� 
//}
//int count_one_bits(unsigned int value)
//{
//	int  num = 0;
//	while (value)
//	{
//		if ((value & 1) == 1)
//			num++;
//		value >>= 1;//����
//	}
//	return num;
//}
//int main()
//{
//	int n = 0;
//	int num = 0;
//	printf("������һ��������");
//	scanf("%d", &n);
//	num = count_one_bits(n);
//	printf("num=%d\n", num);
//	system("pause");
//	return 0;
//}

//2.
//��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�
//int main()
//{
//	int num = 0;
//	int i = 0;
//	int tmp;
//	scanf_s("%d", &num);
//	printf("����λΪ��");
//	for (i = 31; i >= 0; i = i - 2)  //ÿ����������32λ����
//	{
//		tmp = (num >> i) & 1;  //��һ�������ƶ�31λ��ÿ�α仯2λ�����ɵõ�����λ���
//		printf("%d ", tmp);
//	}
//	printf("\n");
//	printf("ż��λΪ��");
//	for (i = 30; i >= 0; i = i - 2)  //�����ƶ�30λ��ÿ�α仯2λ�����ɵõ�ż��λ���
//	{
//		tmp = (num >> i) & 1;
//		printf("%d ", tmp);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//3.
//���һ��������ÿһλ��
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
//���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
int Differ_bits1(int m, int n)
{
	//��ÿһλ��λ��1���Ƚ��Ƿ���ͬ
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
	//����������������1�ĸ���
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