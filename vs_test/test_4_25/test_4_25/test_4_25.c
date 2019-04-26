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
//	int random_num = rand() % 100 + 1;       //生成随机数
//	int input = 0;
//	while (1)
//	{
//		printf("输入猜的数字:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("猜大了\n");
//		}
//		else if (input < random_num)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));    //初始化随机数
//	do
//	{
//		menu();
//		printf("请选择:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("选择错误，重新输入！\n");
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
//		printf("输入密码(还有%d次机会)：", i);
//		scanf("%s", &input);
//		if (0 == strcmp(password, input))
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char ch;
//	printf("输入字母：");
//	while ((ch = getchar())!= EOF)
//	{
//		if (ch >= 'a'&&ch <= 'z')
//			printf("%c\n", ch - 32);
//		else if (ch >= 'A'&&ch <= 'Z')
//			printf("%c\n", ch + 32);
//		else
//			printf("输入错误");
////		fflush(stdin);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	return 0;
}