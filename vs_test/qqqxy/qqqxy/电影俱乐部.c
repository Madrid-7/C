#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
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
void managermenu();
void usermenu();
void saveuser(char name[50], char password[10]);
void user_registration();
void welcome();
void member();

main()
{
	struct film * list;
	welcome();
	member();
}

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




/*void userlogin()
{
	char
	FILE * fp;
	fp=fopen("�û�.txt","r");
	printf("�û�����");
	scanf("%s",)
}*/


void classify()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("		-----------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("				1.ӰƬ���ֲ�ѯ\n");
	printf("				2.ӰƬ��ݲ�ѯ\n");
	printf("				3.ӰƬ������ѯ\n");
	printf("				4.ӰƬƱ������\n");
	printf("\n");
	printf("\n");
	printf("		-----------------------------------------------");
	printf("\n");
}

struct film * create(void)
{
	FILE *fp;
	int len;
	int i;
	struct film *head, *pnew, *tail;
	head = (struct film*)malloc(sizeof(struct film));
	if (head == NULL)
	{
		printf("�ϴ�ʧ��\n");
		exit(1);
	}

	tail = head;
	tail->next = NULL;

	printf("\n");
	printf("������Ҫ�ϴ�ӰƬ��������");
	scanf("%d", &len);
	printf("\n");

	printf("|Ƭ��		����		����		��ӳ���		����		Ʊ��|\n");
	fp = fopen("ӰƬ����.txt", "w");
	if (fp == NULL)
	{
		printf("���ܴ򿪴��ļ�����������˳���");
		exit(1);
	}

	for (i = 0; i < len; i++)
	{
		pnew = (struct film *)malloc(sizeof(struct film));
		if (pnew == NULL)
		{
			printf("�ڴ����ʧ��");
			exit(1);
		}

		scanf("%s%s%s%s%d%d", pnew->name, pnew->director, pnew->actor, pnew->region, &pnew->year, &pnew->box_office);
		fprintf(fp, "%s	%s	%s	%s	%d	%d\n", pnew->name, pnew->director, pnew->actor, pnew->region, pnew->year, pnew->box_office);

		tail->next = pnew;
		pnew->next = NULL;
		tail = pnew;
	}
	fclose(fp);
}

void findname(struct film * p)
{
	char name[50];
	printf("��������Ҫ���ҵ�ӰƬ��");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			printf("%s	%s	%s	%s	%d	%d\n", p->name, p->director, p->actor, p->region, p->year, p->box_office);
			printf("\n");
			break;
		}
		else
			p = p->next;
	}
}

void findyear(struct film * p)
{
	int year;
	printf("��������Ҫ���ҵ�ӰƬ����ݣ�");
	scanf("%d", &year);
	printf("\n");
	printf("����������µ�ӰƬ��\n");
	while (p != NULL)
	{
		p = p->next;
		if (p->year == year)
			printf("%s	%s	%s	%s	%d	%d\n", p->name, p->director, p->actor, p->region, p->year, p->box_office);
	}
	printf("\n");
}

void findregion(struct film * p)
{
	char region[50];
	printf("��������Ҫ���ҵ�ӰƬ������");
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
	char name[50];
	char t1[50], t2[30], t3[50], t4[50];
	int t5, t6;
	struct film *l, *q;
	int select;
	q = p->next;

	printf("��ѡ��������\n");
	printf("���� 0\n");
	printf("���� 1\n");
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
	struct film * prev;                   //��ɾ���ڵ��ǰһ���ڵ� 
	printf("����Ҫɾ����һ��ӰƬ��\n");
	scanf("%s", name);
	printf("\n");
	printf("��ȷ��Ҫɾ���ⲿ��(Y/N)\n");
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
				printf("ɾ���ɹ���\n");
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
		printf("ɾ��ʧ�ܣ�\n");
		printf("\n");
	}
}

void insert(struct film * p)
{
	struct film * q = (struct film *)malloc(sizeof(struct film));//��Ҫ������µĽڵ� 
	char name[50];
	printf("��Ҫ�嵽�Ĳ�֮��:>\n");
	scanf("%s", name);
	printf("\n");
	printf("��������ӵ�ӰƬ������:>\n");
	scanf("%s%s%s%s%d%d", q->name, q->director, q->actor, q->region, &q->year, &q->box_office);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			q->next = p->next;
			p->next = q;
			printf("��ӳɹ���\n");
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
	printf("����������Ҫ�޸ĵ�ӰƬ���ƣ�");
	scanf("%s", name);
	while (p != NULL)
	{
		p = p->next;
		if (strcmp(p->name, name) == 0)
		{
			printf("��������Ҫ�޸ĵ�ӰƬ�����ݣ�\n");
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
	fp = fopen("Ӱ��.txt", "w");
	printf("Ah my friend�������������һ��ӰƬ�أ�");
	scanf("%s", name);
	printf("\n");
	printf("-----------------------------------\n");
	printf("\n");
	printf("	�ڴ�����ⲿӰƬ��������\n");
	printf("\n");
	printf("-----------------------------------\n");
	while (p != NULL)
	{
		if (strcmp(p->name, name))
		{
			printf("���������ⲿӰƬ������Ѽ��");
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
	printf("����ݼ��ξۻ�?");
	scanf("%d", &n);
	printf("����ۻ�ʱ��͵ص㣺");
	fm = fopen("�ۻ�.txt", "w");
	fprintf(fm, "%d", &n);
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
	printf("��ѡ������ȥ������ۻ�����");
	scanf("%d", &num);
	printf("ԤԼ�ɹ�����סһ��Ҫȥѽ��");
}

void traversal(struct film * p)
{
	struct film * all = p->next;
	printf("�ۿ�ȫ������\n");
	if (p == NULL)
	{
		printf("û������Ѽ��");
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
	FILE *fp;
	fp = fopen("ӰƬ����.txt", "r");
	if (fp == NULL)
	{
		printf("�����ڸ��ļ�\n");
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
}


void savedata(struct film *p)
{
	FILE * fp;
	struct film * h = p->next;
	if ((fp = fopen("ӰƬ����.txt", "w")) == NULL)//�Կ�д�ķ�ʽ��
	{
		printf("���ܴ򿪴��ļ�����������˳�\n");
		exit(1);
	}
	while (h != NULL)
	{
		fprintf(fp, "%s	%s	%s	%s	%d	%d\n", h->name, h->director, h->actor, h->region, h->year, h->box_office);
		h = h->next;
		printf("����ɹ�\n");
	}
	fclose(fp);
}

void managermenu()
{
	struct meet * meeting;
	struct film * list;
	list = NULL;
	meeting = NULL;
	int b;
	int choice;
	printf("---------------------------------------------------------------------\n");
	printf("						��ӭ��������Ա�˩c(= �� = )\n");
	printf("							1.�ϴ�ӰƬ\n");
	printf("							2.����ӰƬ\n");
	printf("							3.�޸�ӰƬ\n");
	printf("							4.ɾ��ӰƬ\n");
	printf("							5.����ӰƬ\n");
	printf("							6.�ۻ�Ԥ��\n");
	printf("\t\t\t");
	scanf("%d", &b);
	system("cls");
	switch (b)
	{
	case 1:list = create(); break;
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
	case 6:manage_app(meeting); break;
	}
	printf("\t\t\t�������������һ��\n");
	getchar();
	system("cls");
	managermenu();
}

void usermenu()
{
	struct film * list;
	list = NULL;
	int a;
	int choice;
	printf("---------------------------------------------------------------------\n");
	printf("					��ӭ�����û��˩c(= �� = )\n");
	printf("							1.��ѯӰƬ\n");
	printf("							2.�򿨿�\n");
	printf("							3.дӰ��\n");
	printf("							4.ԤԼ�ۻ���\n");
	printf("\t\t\t");
	scanf("%d", &a);
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
	default:printf("\t\t\tû�д˹���\n");
	}
	printf("\t\t\t�������������һ��\n");
	getchar();
	system("cls");
	usermenu();
}

void saveuser(char name[50], char password[10])
{
	FILE * fp;
	fp = fopen("�û�.txt", "a");
	fprintf(fp, "%s %s\n", name, password);
}

void user_registration()
{
	struct user a, b, again;
	FILE * fp;
	int i;
	char reply;

	fp = fopen("�û�.txt", "r");
	printf("\n\t\t\t    �����û�����");
	scanf("%s", b.username);
	while (1)
	{
		fscanf(fp, "%s %s\n", a.username, a.userpassword);
		if (strcmp(a.username, b.username) == 0)
		{
			printf("\t\t\t���û��Ѵ��ڣ�����������\n");
			printf("\n\t\t\t    �����û�����");
			scanf("%s", b.username);
		}
		else
			break;
	}
	printf("\t\t\t\t�û�������\n");
	printf("\t\t\t    ���������룺");
	scanf("%s", b.userpassword);
	printf("\t\t\t    ���ٴ����룺");
	scanf("%s", again.userpassword);
	while (1)
	{
		if (strcmp(b.userpassword, again.userpassword) == 0)
		{
			saveuser(b.username, b.userpassword);
			printf("\t\t\t  ��ϲ��Ϊ���ֲ���һԱ�ޣ�\n");
			printf("\t\t\t\t�������\n");
			getchar();
			system("cls");
			usermenu();
		}
		else
		{
			printf("\t\t\t�������벻һ�������ٴ�����һ��\n");
			printf("\t\t\t   again:");
			scanf("%s", again.userpassword);
		}
	}
	fclose(fp);
}
void welcome()
{
	printf("		*****************************************************\n");
	printf("		||						   ||\n");
	printf("		||						   ||\n");
	printf("		||						   ||\n");
	printf("		||	  Welcome  To  The  Movie  Club !	   ||\n");
	printf("		||		  My Dear Friend!		   ||\n");
	printf("		||		   �c(= �� = )		  	   ||\n");
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
	printf("		===============================================");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("				1.��Աע��\n");
	printf("				2.��Ա��½\n");
	printf("				3.����Ա��½\n");
	printf("				4.�˳�\n");
	printf("\n");
	printf("\n");
	printf("		===============================================");
	printf("\n");
	printf("\t\t\t   ��ѡ�� | 1 | 2 | 3 | 4 | \n");
	printf("\n\t\t\t\t----��  ");
	scanf("%d", &c);
	switch (c)
	{
	case 1:user_registration(); break;
		//case 2 :user_login();break;
		//case 3 :manager_login();break;
	}
}


