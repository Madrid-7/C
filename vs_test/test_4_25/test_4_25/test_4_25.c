#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void menu()
//{
//	printf("************************\n");
//	printf("******** 1.play ********\n");
//	printf("******** 0.exit ********\n");
//	printf("************************\n");
//}
//void game()
//{
//	int random_num = rand() % 100 + 1;       //���������
//	int input = 0;
//	while (1)
//	{
//		printf("����µ�����:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("�´���\n");
//		}
//		else if (input < random_num)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));    //��ʼ�������
//	do
//	{
//		menu();
//		printf("��ѡ��:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("ѡ������������룡\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char password[] = "123456";
//	int i = 0;
//	char input[10] = { 0 };
//
//	for (i = 3; i > 0; i--)
//	{
//		printf("��������(����%d�λ���)��", i);
//		scanf("%s", &input);
//		if (0 == strcmp(password, input))
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char ch;
//	printf("������ĸ��");
//	while ((ch = getchar())!= EOF)
//	{
//		if (ch >= 'a'&&ch <= 'z')
//			printf("%c\n", ch - 32);
//		else if (ch >= 'A'&&ch <= 'Z')
//			printf("%c\n", ch + 32);
//		else
//			printf("�������");
////		fflush(stdin);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	return 0;
}