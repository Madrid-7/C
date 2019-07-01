#define _CRT_SECURE_NO_WARNINGS 1
#include"fxxk.h"

void cls()
{
	system("pause");
	system("cls");
}


void menu()
{
	printf("=======================================================================\n");
	printf("********************** Welcome to use the system **********************\n");
	printf("                     [1].上映厅管理（销售员）                     \n");
	printf("                     [2].电影信息管理（管理员）                   \n");
	printf("                     [3].查询上映电影界面                         \n");
	printf("                     [4].售票界面（销售员）                       \n");
	printf("                     [5].退票处理界面（销售员）                   \n");
	printf("                     [6].总销售额界面（经理）                     \n");
	printf("                     [7].用户管理（管理员）                       \n");
	printf("                     [0].退出                                     \n");
	printf("***********************************************************************\n");
	printf("=======================================================================\n");
}

int CheakUser(int input)
{
	FILE* fp;
	switch (input)
	{
	case 1:
		return 1;
	case 2:
		fp = fopen("user_saleman.txt", "r");
		user* saleman = (user*)malloc(sizeof(user));
		if (fp == NULL || (fread(saleman, sizeof(user), 1, fp)) == 0)
		{
			free(saleman);
			printf("未添加销售员账号信息，请登录管理员添加。\n");
		}
		else
		{
			char name[50] = { 0 };
			char password[20] = { 0 };
			rewind(fp);
			printf("输入姓名：");
			scanf("%s", name);
			printf("输入密码：");
			scanf("%s", password);
			if (saleman == NULL)
			{
				printf("err_malloc\n");
				return -1;
			}
			while (fread(saleman, sizeof(user), 1, fp))
			{
				if ((strcmp(name, saleman->name) == 0) && (strcmp(password, saleman->password) == 0))
				{
					printf("登陆成功。\n");
					free(saleman);
					return 2;
				}
			}
			printf("登陆失败，密码或账号名有错。\n");
			free(saleman);
			return 0;
		}
		break;
	case 3:
		fp = fopen("user_manager.txt", "r");
		user* manager = (user*)malloc(sizeof(user));
		if (fp == NULL || (fread(manager, sizeof(user), 1, fp)) == 0)
		{
			free(manager);
			printf("未添加经理账号信息，请登录管理员添加。\n");
		}
		else
		{
			char name[50] = { 0 };
			char password[20] = { 0 };
			rewind(fp);
			printf("输入姓名：");
			scanf("%s", name);
			printf("输入密码：");
			scanf("%s", password);
			if (manager == NULL)
			{
				printf("err_malloc\n");
				return -1;
			}
			while (fread(manager, sizeof(user), 1, fp))
			{
				if ((strcmp(name, manager->name) == 0) && (strcmp(password, manager->password) == 0))
				{
					printf("登陆成功。\n");
					free(manager);
					return 3;
				}
			}
			printf("登陆失败，密码或账号名有错。\n");
			free(manager);
			return 0;
		}
		break;
	case 9:
		fp = fopen("user_master.txt", "r");
		char name[50] = { 0 };
		char password[20] = { 0 };
		user* master = (user*)malloc(sizeof(user));
		printf("输入姓名：");
		scanf("%s", name);
		printf("输入密码：");
		scanf("%s", password);
		if (master == NULL)
		{
			printf("err_malloc\n");
			return -1;
		}
		fread(master, sizeof(user), 1, fp);
		if ((strcmp(name, master->name) == 0) && (strcmp(password, master->password) == 0))
		{
			printf("登陆成功。\n");
			free(master);
			return 9;
		}
		else
		{
			printf("登陆失败，密码或账号名有错。\n");
			free(master);
			return 0;
		}
		break;
	default:
		break;
	}
	return -1;
}

void CheakLogin(int n)
{
	switch (n)
	{
	case 0:
		break;
	case -1:
		break;
	case 1:
		Select_Fun(n);
		break;
	case 2:
		Select_Fun(n);
		break;
	case 3:
		Select_Fun(n);
		break;
	case 9:
		Select_Fun(n);
		break;
	default:
		break;
	}
}

