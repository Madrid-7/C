#define _CRT_SECURE_NO_WARNINGS 1
#include"fxxk.h"

void StudioManagement()         //��ӳ������
{
	printf("=======================================================================\n");
	printf("************************** Studio information *************************\n");
	printf("=======================================================================\n");
}

void MovieManagement()          //��Ӱ��Ϣ����
{

}

void ShowMovieInf()             //��ʾ��ӳ��Ӱ
{

}

void SaleTicket()               //��Ʊ����
{

}

void ReturnTicket()             //��Ʊ����
{

}

void MoneyCount()               //�����۶����
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
	printf("����Ҫɾ�����û�����");
	scanf("%s", name);
	if (chose == 1)
	{
		fp = fopen("user_saleman.txt", "r");
		if (fp == NULL)
		{
			printf("δ�������Ա��\n");
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
			printf("δ��Ӿ���\n");
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
	printf("����Ҫ�޸ĵ��û�����");
	scanf("%s", name);
	if (chose == 1)
	{
		fp = fopen("user_saleman.txt", "r");
		if (fp == NULL)
		{
			printf("δ�������Ա��\n");
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
				printf("�������û�����");
				scanf("%s", p->name);
				printf("�����µ绰���룺");
				scanf("%s", p->tel_num);
				printf("���������룺");
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
			printf("δ��Ӿ���\n");
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
				printf("�������û�����");
				scanf("%s", p->name);
				printf("�����µ绰���룺");
				scanf("%s", p->tel_num);
				printf("���������룺");
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

void SetUser()                  //�û���Ϣ����
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
		printf("--- ������%d -----------------------------------------------------------\n", count);
		printf("=======================================================================\n");
		printf("                           [1].����û�                                \n");
		printf("                           [2].ɾ���û�                                \n");
		printf("                           [3].�޸��û�                                \n");
		printf("                           [0].�˳�                                    \n");
		printf("***********************************************************************\n");
		printf("�������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("1.�������Ա		2.��Ӿ���		0.�˳� \n");
			printf("�������ѡ��");
			scanf("%d", &chose);
			switch (chose)
			{
			case 1:
				fp = fopen("user_saleman.txt", "a");
				printf("������������");
				scanf("%s", u->name);
				printf("������绰���룺");
				scanf("%s", u->tel_num);
				printf("���������룺");
				scanf("%s", u->password);
				fwrite(u, sizeof(user), 1, fp);
				fclose(fp);
				break;
			case 2:
				fp = fopen("user_manager.txt", "a");
				printf("������������");
				scanf("%s", u->name);
				printf("������绰���룺");
				scanf("%s", u->tel_num);
				printf("���������룺");
				scanf("%s", u->password);
				fwrite(u, sizeof(user), 1, fp);
				fclose(fp);
				break;
			case 0:
				break;
			default:
				printf("�����������ѡ��\n");
				break;
			}
			break;
		case 2:
			printf("1.ɾ������Ա		2.ɾ������		0.�˳� \n");
			printf("�������ѡ��");
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
				printf("�����������ѡ��\n");
				break;
			}
			break;
		case 3:
			printf("1.�޸�����Ա		2.�޸ľ���		0.�˳� \n");
			printf("�������ѡ��");
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
				printf("�����������ѡ��\n");
				break;
			}
			break;
		case 0:
			break;
		default:
			printf("�����������ѡ��\n");
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
		printf("�������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			if (n != 2)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				StudioManagement();  //��ӳ������
			}
			break;
		case 2:
			if (n != 9)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				MovieManagement();  //��Ӱ��Ϣ����
			}
			break;
		case 3:
			ShowMovieInf();     //��ʾ��ӳ��Ӱ
			break;
		case 4:
			if (n != 2)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				SaleTicket();    //��Ʊ����
			}
			break;
		case 5:
			if (n != 2)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				ReturnTicket();  //��Ʊ����
			}
			break;
		case 6:
			if (n != 3)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				MoneyCount();    //�����۶����
			}
			break;
		case 7:
			if (n != 9)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				SetUser();    //�û���Ϣ����
			}
			break;
		case 0:
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (input);
}