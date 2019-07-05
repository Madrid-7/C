#define _CRT_SECURE_NO_WARNINGS 1
#include"fxxk.h"

void test()
{
	FILE* fp;
	fp = fopen("user_master.txt", "r");
	if (fp == NULL )                  //判断是否已有文件
	{
		user* master = (user*)malloc(sizeof(user));
		if (master == NULL)
		{
			printf("err_malloc\n");
			return;
		}
		fp = fopen("user_master.txt", "w");
		printf("===============================================================================================================\n");
		printf("****************************************** Welcome to use the system ******************************************\n");
		printf("\n");
		printf("该系统首次运行，请注册管理员相关信息。\n");
		printf("请输入姓名：");
		scanf("%s", master->name);
		printf("请输入电话号码：");
		scanf("%s", master->tel_num);
		printf("请输入密码：");
		scanf("%s", master->password);
		fwrite(master, sizeof(user), 1, fp);
		free(master);
		fclose(fp);
		printf("恭喜您成为该系统的第一个管理员。\n");
		cls();
	}
	int input = 0;
	do
	{
		printf("===============================================================================================================\n");
		printf("************************************************* User log in *************************************************\n");
		printf("===============================================================================================================\n");
		printf("===============================================================================================================\n");
		printf("  0.退出             1.其他             2.销售员             3.经理                                 9.管理员   \n");
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			CheakLogin(CheakUser(input));
			break;
		case 2:
			CheakLogin(CheakUser(input));
			break;
		case 3:
			CheakLogin(CheakUser(input));
			break;
		case 9:
			CheakLogin(CheakUser(input));
			break;
		default:
			printf("输入错误，重新选择。\n");
			break;
		}
		cls();
	} while (input);
}

int main()
{
	test();
	return 0;
}
