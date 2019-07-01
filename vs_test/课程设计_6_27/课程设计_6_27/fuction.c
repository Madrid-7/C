#define _CRT_SECURE_NO_WARNINGS 1
#include"fxxk.h"

void StudioManagement()         //上映厅管理
{
	printf("=======================================================================\n");
	printf("************************** Studio information *************************\n");
	printf("=======================================================================\n");
}

void MovieManagement()          //电影信息管理
{

}

void ShowMovieInf()             //显示上映电影
{

}

void SaleTicket()               //售票管理
{

}

void ReturnTicket()             //退票管理
{

}

void MoneyCount()               //总销售额界面
{

}

void DelUser(int chose)
{
	FILE* fp;
	char name[100];
	user* head = (user*)malloc(sizeof(user));
	user* p,*q;
	user* u;
	head = NULL;
	printf("输入要删除的用户名：");
	scanf("%s", name);
	if (chose == 1)
	{
		fp = fopen("user_saleman.txt", "r");
		if (fp == NULL)
		{
			printf("未添加销售员。\n");
			return;
		}
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
			}
			else
			{
				u->next = NULL;
				head->next = u;
			}
		}
		p = head;
		while (p)
		{
			q = p;
			if (strcmp(name, p->name) == 0)
			{
				if (q == p)
				{
					head = p->next;
				}
				else
				{
					q->next = p->next;
				}
				free(p);
				break;
			}
			else
			{
				p = p->next;
			}
		}
		fp = fopen("user_saleman.txt", "w");
		while (head)
		{
			fwrite(head, sizeof(user), 1, fp);
			head = head->next;
		}
		fclose(fp);
	}
	else
	{
		fp = fopen("user_manager.txt", "r");
		if (fp == NULL)
		{
			printf("未添加经理。\n");
			return;
		}
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
			}
			else
			{
				u->next = NULL;
				head->next = u;
			}
		}
		p = head;
		while (p)
		{
			q = p;
			if (strcmp(name, p->name) == 0)
			{
				if (q == p)
				{
					head = p->next;
				}
				else
				{
					q->next = p->next;
				}
				free(p);
				break;
			}
			else
			{
				p = p->next;
			}
		}
		fp = fopen("user_manager.txt", "w");
		while (head)
		{
			fwrite(head, sizeof(user), 1, fp);
			head = head->next;
		}
		fclose(fp);
	}
}

void ChangeUser(int chose)
{
	FILE* fp;
	char name[100];
	user* head = (user*)malloc(sizeof(user));
	user* p;
	user* u;
	head = NULL;
	printf("输入要修改的用户名：");
	scanf("%s", name);
	if (chose == 1)
	{
		fp = fopen("user_saleman.txt", "r");
		if (fp == NULL)
		{
			printf("未添加销售员。\n");
			return;
		}
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
			}
			else
			{
				u->next = NULL;
				head->next = u;
			}
		}
		p = head;
		while (p)
		{
			if (strcmp(name, p->name) == 0)
			{
				printf("输入新用户名：");
				scanf("%s", p->name);
				printf("输入新电话号码：");
				scanf("%s", p->tel_num);
				printf("输入新密码：");
				scanf("%s", p->password);
				break;
			}
			else
			{
				p = p->next;
			}
		}
		fp = fopen("user_saleman.txt", "w");
		while (head)
		{
			fwrite(head, sizeof(user), 1, fp);
			head = head->next;
		}
		fclose(fp);
	}
	else
	{
		fp = fopen("user_manager.txt", "r");
		if (fp == NULL)
		{
			printf("未添加经理。\n");
			return;
		}
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
			}
			else
			{
				u->next = NULL;
				head->next = u;
			}
		}
		p = head;
		while (p)
		{
			if (strcmp(name, p->name) == 0)
			{
				printf("输入新用户名：");
				scanf("%s", p->name);
				printf("输入新电话号码：");
				scanf("%s", p->tel_num);
				printf("输入新密码：");
				scanf("%s", p->password);
				break;
			}
			else
			{
				p = p->next;
			}
		}
		fp = fopen("user_manager.txt", "w");
		while (head)
		{
			fwrite(head, sizeof(user), 1, fp);
			head = head->next;
		}
		fclose(fp);
	}
}

void SetUser()                  //用户信息管理
{
	FILE* fp;
	user* u = (user*)malloc(sizeof(user));
	int input = 0;
	do
	{
		int count = 0;
		int chose = 0;
		cls();
		fp = fopen("user_master.txt", "r");
		printf("=======================================================================\n");
		printf("******************************* Set user ******************************\n");
		printf("=======================================================================\n");
		printf("ID		User_Name		User_Phone_Num		User_Type        \n");
		while (fread(u, sizeof(user), 1, fp))
		{
			count++;
			printf("%d		%s			%s			master			 \n", count, u->name, u->tel_num);
		}
		fp = fopen("user_saleman.txt", "r");
		if (fp != NULL)
		{
			while (fread(u, sizeof(user), 1, fp))
			{
				count++;
				printf("%d		%s			%s			saleman			 \n", count, u->name, u->tel_num);
			}
		}
		fp = fopen("user_manager.txt", "r");
		if (fp != NULL)
		{
			while (fread(u, sizeof(user), 1, fp))
			{
				count++;
				printf("%d		%s			%s			manager			 \n", count, u->name, u->tel_num);
			}
		}
		printf("--- 总数：%d -----------------------------------------------------------\n", count);
		printf("=======================================================================\n");
		printf("                           [1].添加用户                                \n");
		printf("                           [2].删除用户                                \n");
		printf("                           [3].修改用户                                \n");
		printf("                           [0].退出                                    \n");
		printf("***********************************************************************\n");
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("1.添加销售员		2.添加经理		0.退出 \n");
			printf("输入你的选择：");
			scanf("%d", &chose);
			switch (chose)
			{
			case 1:
				fp = fopen("user_saleman.txt", "a");
				printf("请输入姓名：");
				scanf("%s", u->name);
				printf("请输入电话号码：");
				scanf("%s", u->tel_num);
				printf("请输入密码：");
				scanf("%s", u->password);
				fwrite(u, sizeof(user), 1, fp);
				fclose(fp);
				break;
			case 2:
				fp = fopen("user_manager.txt", "a");
				printf("请输入姓名：");
				scanf("%s", u->name);
				printf("请输入电话号码：");
				scanf("%s", u->tel_num);
				printf("请输入密码：");
				scanf("%s", u->password);
				fwrite(u, sizeof(user), 1, fp);
				fclose(fp);
				break;
			case 0:
				break;
			default:
				printf("输入错误，重新选择。\n");
				break;
			}
			break;
		case 2:
			printf("1.删除销售员		2.删除经理		0.退出 \n");
			printf("输入你的选择：");
			scanf("%d", &chose);
			switch (chose)
			{
			case 1:
				DelUser(chose);
				break;
			case 2:
				DelUser(chose);
				break;
			case 0:
				break;
			default:
				printf("输入错误，重新选择。\n");
				break;
			}
			break;
		case 3:
			printf("1.修改销售员		2.修改经理		0.退出 \n");
			printf("输入你的选择：");
			scanf("%d", &chose);
			switch (chose)
			{
			case 1:
				ChangeUser(chose);
				break;
			case 2:
				ChangeUser(chose);
				break;
			case 0:
				break;
			default:
				printf("输入错误，重新选择。\n");
				break;
			}
			break;
		case 0:
			break;
		default:
			printf("输入错误，重新选择。\n");
			break;
		}
	} while (input);
	free(u);
}

void Select_Fun(int n)      // n = 1,2,3,9
{
	int input = 0;
	do
	{
		cls();
		menu();
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			if (n != 2)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				StudioManagement();  //上映厅管理
			}
			break;
		case 2:
			if (n != 9)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				MovieManagement();  //电影信息管理
			}
			break;
		case 3:
			ShowMovieInf();     //显示上映电影
			break;
		case 4:
			if (n != 2)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				SaleTicket();    //售票管理
			}
			break;
		case 5:
			if (n != 2)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				ReturnTicket();  //退票管理
			}
			break;
		case 6:
			if (n != 3)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				MoneyCount();    //总销售额界面
			}
			break;
		case 7:
			if (n != 9)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				SetUser();    //用户信息管理
			}
			break;
		case 0:
			break;
		default:
			printf("输入错误，重新选择。\n");
			break;
		}
	} while (input);
}