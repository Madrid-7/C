#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 3

void classify();
struct film * create(void);
void findname(struct film * p);
void findyear(struct film * p);
void findregion(struct film * p);
void sort(struct film *p);
void del(struct film * p);
void insert(struct film * p);
void change(struct film * p);
void review(struct film*p);
void manage_app(struct meet *p);
void appointment(struct film *p);
void traversal(struct film * p);
void readdata();
void savedata(struct film *p);
void managemenu();
void usermenu();
void saveuser(char name[50], char password[10]);
void user_registration();
void welcome();
void member();
void user_login();

int main()
{
	welcome();
	member();
}

struct manage
{
	char managename[50];
	char managepassword[50];
};

struct user
{
	char username[50];
	char userpassword[50];
	char sex[10];
	long haoma;
};

struct meet
{
	char when[50];
	char address[60];
	struct meet *next;
};

struct film
{
	char name[50];
	char director[30];
	char actor[50];
	char region[50];
	int year;
	int box_office;
	struct film *next;
};

void classify()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("		-----------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("				1.影片名字查询\n");
	printf("				2.影片年份查询\n");
	printf("				3.影片地区查询\n");
	printf("				4.影片票房排序\n");
	printf("\n");
	printf("\n");
	printf("		-----------------------------------------------");
	printf("\n");
}

struct film * create(void)
{
	struct film * list;
	list = NULL;
	int len;
	int i;
	struct film *head, *pnew, *tail;
	head = (struct film*)malloc(sizeof(struct film));
	if (head == NULL)
	{
		printf("上传失败\n");
		exit(1);
	}

	tail = head;
	tail->next = NULL;

	printf("\n");
	printf("输入所要上传影片的数量：");
	scanf("%d", &len);
	printf("\n");

	printf("\t\t\t================================================================\n");
	printf("\t                                 |片名		导演		主演		地区		上映年份		票房|\n");
	printf("\t\t\t================================================================\n");

	for (i = 0; i < len; i++)
	{
		pnew = (struct film *)malloc(sizeof(struct film));
		if (pnew == NULL)
		{
			printf("内存分配失败");
			exit(1);
		}

		printf("\t\t\t                           ");
		scanf("%s%s%s%s%d%d", pnew->name, pnew->director, pnew->actor, pnew->region, &pnew->year, &pnew->box_office);

		tail->next = pnew;
		pnew->next = NULL;
		tail = pnew;
	}
	return head->next;
}

void findname(struct film * p)
{
	char name[50];
	readdata();
	struct film * m;
	m = NULL;
	printf("\t\t\t\t输入您所要查找的影片：");
	printf("\n\t\t\t\t\t\t   ----→  ");
	scanf("%s", name);

	while (m != NULL)
	{
		if (strcmp(m->name, name) == 0)
		{
			printf("%s	%s	%s	%s	%d	%d\n", m->name, m->director, m->actor, m->region, m->year, m->box_office);
			printf("\n");
			break;
		}
		else
			m = m->next;
	}
}

void findyear(struct film * p)
{
	struct film * f;
	f = (struct film *)malloc(sizeof(struct film));
	FILE * fp;
	int year;
	readdata();
	fp = fopen("影片内容.txt", "r");

	printf("\t\t输入您所要查找的影片的年份：");
	scanf("%d", &year);
	printf("\n");
	while (1)
	{
		//fscanf(fp, "%s	%s	%s	%s	%d	%d", f.name, f.director, f.actor, f.region, f.year, f.box_office);
		if (f->year == year)
		{
			printf("该年份有如下的影片：\n");
			printf("%d", f->year);
		}
		else
		{
			if (!feof(fp))
			{
				fscanf(fp, "		%s		%s	%s	%s	%d	%d", f->name, f->director, f->actor, f->region, &f->year, &f->box_office);
			}
		}
	}

}

void findregion(struct film * p)
{
	char region[50];
	printf("输入您所要查找的影片地区：");
	scanf("%s", region);
	while (p != NULL)
	{
		if (strcmp(p->region, region) == 0)
		{
			printf("%s	%s	%s	%s	%d	%d\n", p->name, p->director, p->actor, p->region, p->year, p->box_office);
			printf("\n");
			break;
		}
		else
			p = p->next;
	}

}

void sort(struct film *p)
{
	char t1[50], t2[30], t3[50], t4[50];
	int t5, t6;
	struct film *l, *q;
	int select;
	q = p->next;

	printf("请选择升降序：\n");
	printf("升序 0\n");
	printf("降序 1\n");
	getchar();
	scanf("%d", &select);
	if (select == 0)
	{
		while (q != NULL)
		{
			l = q->next;
			while (l != NULL)
			{
				if (q->box_office < l->box_office)
				{
					strcpy(t1, q->name);
					strcpy(t2, q->actor);
					strcpy(t3, q->director);
					strcpy(t4, q->region);
					t5 = q->year;
					t6 = q->box_office;
					strcpy(q->name, l->name);
					strcpy(q->actor, l->actor);
					strcpy(q->director, l->director);
					strcpy(q->region, l->region);
					q->year = l->year;
					q->box_office = l->box_office;
					strcpy(l->name, t1);
					strcpy(l->director, t2);
					strcpy(l->actor, t3);
					strcpy(l->region, t4);
					l->year = t5;
					l->box_office = t6;
				}
				l = l->next;
			}
			printf("%s	", q->name);
			q = q->next;
		}
		printf("\n");
	}
	if (select == 1)
	{
		while (q != NULL)
		{
			l = q->next;
			while (l != NULL)
			{
				if (q->box_office > l->box_office)
				{
					strcpy(t1, q->name);
					strcpy(t2, q->actor);
					strcpy(t3, q->director);
					strcpy(t4, q->region);
					t5 = q->year;
					t6 = q->box_office;
					strcpy(q->name, l->name);
					strcpy(q->actor, l->actor);
					strcpy(q->director, l->director);
					strcpy(q->region, l->region);
					q->year = l->year;
					q->box_office = l->box_office;
					strcpy(l->name, t1);
					strcpy(l->director, t2);
					strcpy(l->actor, t3);
					strcpy(l->region, t4);
					l->year = t5;
					l->box_office = t6;
				}
				l = l->next;
			}
			printf("%s	", q->name);
			q = q->next;
		}
		printf("\n");
	}
}


void del(struct film * p)
{
	char answer;
	char name[50];
	struct film * prev;                   //所删除节点的前一个节点 
	readdata();
	printf("您想要删除哪一部影片？\n");
	scanf("%s", name);
	printf("\n");
	printf("您确定要删除这部吗？(Y/N)\n");
	fflush(stdin);
	answer = getchar();
	if (answer == 'Y' || answer == 'y')
	{
		while (p != NULL)
		{
			prev = p;
			p = p->next;
			if (strcmp(p->name, name) == 0)
			{
				prev->next = p->next;
				free(p);
				printf("删除成功！\n");
				printf("\n");
				if (p->next = NULL)
				{
					prev->next = NULL;
					free(p);
				}
				break;
			}
		}
	}
	else
	{
		printf("删除失败！\n");
		printf("\n");
	}
}

void insert(struct film * p)
{
	struct film * q = (struct film *)malloc(sizeof(struct film));//所要插入的新的节点 
	char name[50];
	printf("想要插到哪部之后:>\n");
	scanf("%s", name);
	printf("\n");
	printf("输入新添加的影片的内容:>\n");
	scanf("%s%s%s%s%d%d", q->name, q->director, q->actor, q->region, &q->year, &q->box_office);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			q->next = p->next;
			p->next = q;
			printf("添加成功！\n");
			printf("\n");
			break;
		}
		else
		{
			p = p->next;
		}
	}
}

void change(struct film * p)
{
	char name[50];
	printf("输入您所想要修改的影片名称：");
	scanf("%s", name);
	while (p != NULL)
	{
		p = p->next;
		if (strcmp(p->name, name) == 0)
		{
			printf("请输入所要修改的影片的内容：\n");
			scanf("%s%s%s%s%d%d", p->name, p->director, p->actor, p->region, &p->year, &p->box_office);
			break;
		}
	}
}

void review(struct film*p)
{
	char name[50];
	char user_review[500];
	FILE * fp;
	fp = fopen("影评.txt", "w");
	printf("Ah my friend！你想对评价哪一部影片呢？");
	scanf("%s", name);
	printf("\n");
	printf("-----------------------------------\n");
	printf("\n");
	printf("	期待你对这部影片的评价噢\n");
	printf("\n");
	printf("-----------------------------------\n");
	while (p != NULL)
	{
		if (strcmp(p->name, name))
		{
			printf("输入您对这部影片的评价鸭！");
			scanf("%s", user_review);
			fprintf(fp, "%s", user_review);
		}
		p = p->next;
	}
	fclose(fp);
}

void manage_app(struct meet *p)
{
	FILE * fm;
	int n;
	int m;
	struct meet *h, *t, *x;
	h = (struct meet*)malloc(sizeof(struct meet));
	t = h;
	t->next = NULL;
	printf("今年份几次聚会?");
	scanf("%d", &n);
	printf("输入聚会时间和地点：");
	fm = fopen("聚会.txt", "w");
	fprintf(fm, "%d", n);
	for (m = 0; m < n; m++)
	{
		x = (struct meet*)malloc(sizeof(struct meet));
		scanf("%s%s", x->when, x->address);
		fprintf(fm, "%s%s", x->when, x->address);

		t->next = x;
		x->next = NULL;
		t = x;
	}
	fclose(fm);
}

void appointment(struct film *p)
{
	int num;
	printf("请选择你想去的哪天聚会的序号");
	scanf("%d", &num);
	printf("预约成功！记住一定要去呀！");
}

void traversal(struct film * p)
{
	struct film * all = p->next;
	printf("观看全部内容\n");
	if (p == NULL)
	{
		printf("没有内容鸭！");
	}
	while (p != NULL)
	{
		printf("%s	%s	%s	%s	%d	%d\n", all->name, all->director, all->actor, all->region, all->year, all->box_office);
		all = all->next;
	}
	printf("\n");
}

void readdata()
{
	FILE * fp;
	struct film * m = (struct film*)malloc(sizeof(struct film));

	fp = fopen("影片内容.txt", "r");
	printf("\t\t\t   ================================================================\n");
	printf("\t\t\t\t   ^^^^^^^^^^^^^|好看的电影来啦|^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t   ================================================================\n");
	printf("\t\t片名	      导演	      主演	      地区	      上映年份	      票房\n");
	if (fp != NULL)
	{
		while (fread(m, sizeof(struct film), 1, fp))
		{
			printf("		%s		%s		%s		%s		%d		%d\n", m->name, m->director, m->actor, m->region, m->year, m->box_office);
		}
	}
}

/*void readdata()
{
	FILE *fp;
	struct film * m;
	struct film * n;
	struct film * h;
	fp = fopen("影片内容.txt", "r");
	h = (struct film*)malloc(sizeof(struct film));
	h->next = NULL;
	n = h;
	m = (struct film*)malloc(sizeof(struct film));
	m->next = n->next;
	while ((fread(m, sizeof(struct film), 1, fp)) == 1)
	{
		n->next = m;
		n = m;
		m = (struct film*)malloc(sizeof(struct film));
		m->next = n->next;
	}
	fclose(fp);
	g = h;
}
	/*if (fp == NULL)
	{
		printf("不存在该文件\n");
		exit(0);
	}
	int i = 0;
	while (!feof(fp))
	{
		char name[50];
		char director[30];
		char actor[50];
		char region[50];
		int year;
		int box_office;
		fscanf(fp, "%s%s%s%s%d%d", name, director, actor, region, &year, &box_office);
		i++;
	}
	fclose(fp);
}*/


void savedata(struct film *p)
{
	FILE * fp;
	struct film * h = p;
	if ((fp = fopen("影片内容.txt", "w")) == NULL)//以可写的方式打开
	{
		printf("不能打开此文件，按任意键退出\n");
		exit(1);
	}
	while (h != NULL)
	{
		fprintf(fp, "%s	%s	%s	%s	%d	%d\n", h->name, h->director, h->actor, h->region, h->year, h->box_office);
		h = h->next;
		printf("保存成功\n");
	}
	fclose(fp);
}

void managemenu()
{
	struct meet * meeting;
	struct film * list;
	list = NULL;
	meeting = NULL;
	int b;
	int choice;
	printf("\n");
	printf("\n");
	printf("\t\t\t---------------------------------------------------------------------\n");
	printf("						欢迎来到管理员端ヽ(= ω = )\n");
	printf("							1.上传影片\n");
	printf("							2.查找影片\n");
	printf("							3.修改影片\n");
	printf("							4.删除影片\n");
	printf("							5.插入影片\n");
	printf("							6.聚会预定\n");
	printf("\t\t\t\t\t     请选择 | 1 | 2 | 3 | 4 | \n");
	printf("\n\t\t\t\t\t\t   ----→  ");
	scanf("%d", &b);
	system("cls");
	switch (b)
	{
	case 1:
		list = create();
		savedata(list);
		break;
	case 2:classify();
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:findname(list);
			break;
		case 2:findyear(list);
			break;
		case 3:findregion(list);
			break;
		case 4:sort(list);
			break;
		}
	}
	break;
	case 3:change(list); break;
	case 4:del(list); break;
	case 5:insert(list); break;
		//case 6:manage_app(meeting); break;
	}
	printf("\t\t\t按任意键返回上一级\n");
	getchar();
	system("cls");
	if (b = 0)
	{
		return member();
	}
	return managemenu();
}

void usermenu()
{
	struct film * list;
	list = NULL;
	int a;
	int choice;
	printf("\n");
	printf("\n");
	printf("\t\t\t---------------------------------------------------------------------\n");
	printf("					    欢迎来到用户端ヽ(= ω = )\n");
	printf("						1.查询影片\n");
	printf("						2.打卡咯\n");
	printf("						3.写影评\n");
	printf("						4.预约聚会噢\n");
	printf("\t\t\t\t     请选择 | 1 | 2 | 3 | 4 | \n");
	printf("\n\t\t\t\t\t   ----→  ");
	scanf("%d", &a);
	printf("\n");
	system("cls");
	switch (a)
	{
	case 1:classify();
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:findname(list);
			break;
		case 2:findyear(list);
			break;
		case 3:findregion(list);
			break;
		case 4:sort(list);
			break;
		}
	}
	break;
	//case 2:punch();break;
	case 3:review(list); break;
	case 4:appointment(list); break;
	default:printf("\t\t\t没有此功能\n");
	}
	printf("\t\t\t按任意键返回上一级\n");
	getchar();
	system("cls");
	usermenu();
}

void saveuser(char name[50], char password[10])
{
	FILE * fp;
	fp = fopen("用户.txt", "a");
	fprintf(fp, "%s %s\n", name, password);
	fclose(fp);
}

void user_registration()
{
	struct user a, b, again;
	FILE * fp;
	fp = fopen("用户.txt", "r");
	printf("\n\t\t\t       输入用户名：");
	scanf("%s", b.username);

	while (!feof(fp))
	{
		fscanf(fp, "%s %s\n", a.username, a.userpassword);
		if (strcmp(a.username, b.username) == 0)
		{
			printf("\t\t\t    该用户已存在！请重新输入\n");
			printf("\n\t\t\t       输入用户名：");
			scanf("%s", b.username);
			rewind(fp);
		}
	}
	printf("\t\t\t\t   用户名可用\n");
	printf("\t\t\t       请输入密码：");
	scanf("%s", b.userpassword);
	printf("\t\t\t       请再次输入：");
	scanf("%s", again.userpassword);
	while (1)
	{
		if (strcmp(b.userpassword, again.userpassword) == 0)
		{
			saveuser(b.username, b.userpassword);
			printf("\t\t\t     恭喜成为俱乐部的一员噢！\n");
			printf("\t\t\t\t   按任意键\n");
			Sleep(3000);
			system("cls");
			member();
		}
		else
		{
			printf("\t\t\t   两次密码不一样哈，再次输入一下\n");
			printf("\t\t\t\t   again:");
			scanf("%s", again.userpassword);
		}
	}
	fclose(fp);
}

void manage_login()
{
	struct manage a, b;
	FILE *fp;
	fp = fopen("管理员.txt", "r");
	fscanf(fp, "%s %s\n", a.managename, a.managepassword);
	printf("\t\t======================================================\n");
	printf("\t\t-----------▲	    管理员名:");
	scanf("%s", b.managename);
	printf("\t\t-----------▲\n");
	printf("\t\t-----------▲	    密码:");
	scanf("%s", b.managepassword);

	while (1)
	{
		//fscanf(fp, "%s %s\n", a.username, a.userpassword);
		if (strcmp(a.managename, b.managename) == 0 && strcmp(a.managepassword, b.managepassword) == 0)
		{
			break;
		}
		else
		{
			if (!feof(fp))
			{
				fscanf(fp, "%s %s\n", a.managename, a.managepassword);
			}
			else
			{
				printf("\t\t\t   账号或者密码有误  |* ′Д｀|┛\n");
				printf("\n");
				printf("\t\t-----------▲	    管理员名:");
				scanf("%s", b.managename);
				printf("\t\t-----------▲\n");
				printf("\t\t-----------▲	    密码:");
				scanf("%s", b.managepassword);
				rewind(fp);
			}
		}
	}
	printf("\t\t-----------▲\n");
	printf("\t\t-----------▲    登录成功哦！(￣▽￣)~*\n");
	printf("\t\t======================================================\n");
	Sleep(6000);
	system("cls");
	return managemenu();
}

void user_login()
{
	struct user a, b;
	FILE *fp;
	fp = fopen("用户.txt", "r");
	fscanf(fp, "%s %s\n", a.username, a.userpassword);
	printf("\t\t======================================================\n");
	printf("\t\t-----------▲	    用户名:");
	scanf("%s", b.username);
	printf("\t\t-----------▲\n");
	printf("\t\t-----------▲	    密码:");
	scanf("%s", b.userpassword);
	while (1)
	{
		//fscanf(fp, "%s %s\n", a.username, a.userpassword);
		if (strcmp(a.username, b.username) == 0 && strcmp(a.userpassword, b.userpassword) == 0)
		{
			break;
		}
		else
		{
			if (!feof(fp))
			{
				fscanf(fp, "%s %s\n", a.username, a.userpassword);
			}
			else
			{
				printf("\t\t\t   账号或密码有误  |* ′Д｀|┛\n");
				printf("\n");
				printf("\n");
				printf("\t\t-----------▲	    用户名:");
				scanf("%s", b.username);
				printf("\t\t-----------▲\n");
				printf("\t\t-----------▲	    密码:");
				scanf("%s", b.userpassword);
				rewind(fp);
			}
		}
	}
	printf("\t\t-----------▲\n");
	printf("\t\t-----------▲    登录成功哦！(￣▽￣)~*\n");
	printf("\t\t======================================================\n");
	Sleep(6000);
	system("cls");
	return usermenu();
}

void welcome()
{
	printf("		*****************************************************\n");
	printf("		||						   ||\n");
	printf("		||						   ||\n");
	printf("		||						   ||\n");
	printf("		||	  Welcome  To  The  Movie  Club !	   ||\n");
	printf("		||		  My Dear Friend!		   ||\n");
	printf("		||		   ヽ(= ω = )		  	   ||\n");
	printf("		||						   ||\n");
	printf("		||					           ||\n");
	printf("		||						   ||\n");
	printf("		*****************************************************");
	printf("\n");
}

void member()
{
	int c;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("		======================================================");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("				      1.会员注册\n");
	printf("				      2.会员登陆\n");
	printf("				      3.管理员登陆\n");
	printf("				      4.退出\n");
	printf("\n");
	printf("\n");
	printf("		======================================================");
	printf("\n");
	printf("\t\t\t      请选择 | 1 | 2 | 3 | 4 | \n");
	printf("\n\t\t\t\t   ----→  ");
	scanf("%d", &c);
	printf("\n");
	switch (c)
	{
	case 1:user_registration(); break;
	case 2:user_login(); break;
	case 3:manage_login(); break;
	}
}
