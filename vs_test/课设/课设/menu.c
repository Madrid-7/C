#define _CRT_SECURE_NO_WARNINGS 1
#include"fxxk.h"

void menu()
{
	printf("===============================================================================================================\n");
	printf("****************************************** Welcome to use the system ******************************************\n");
	printf("                                         [1].Ӱ����������Ա��                       \n");          
	printf("                                         [2].��Ӱ��Ϣ��������Ա��                   \n");
	printf("                                         [3].��ѯ��ӳ��Ӱ����                         \n");
	printf("                                         [4].��Ʊ���棨����Ա��                       \n");
	printf("                                         [5].��Ʊ������棨����Ա��                   \n");
	printf("                                         [6].�����۶���棨����                     \n");
	printf("                                         [7].�û���������Ա��                       \n");
	printf("                                         [0].�˳�                                     \n");
	printf("***************************************************************************************************************\n");
	printf("===============================================================================================================\n");
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
			printf("δ�������Ա�˺���Ϣ�����¼����Ա��ӡ�\n");
		}
		else
		{
			int i = 0;
			char name[50] = { 0 };
			char password[20] = { 0 };
			rewind(fp);
			printf("����������");
			scanf("%s", name);
			printf("�������룺");
			do
			{
				password[i] = _getch();
				if (password[i] == '\r')
					break;
				if (password[i] == '\b')
				{
					if (i == 0)
					{
						printf("\a");
						continue;
					}
					i = i - 1;
					printf("\b");
				}
				else
				{
					i = i + 1;
					printf("*");
				}
			} while (password[i] != '\n' && i < 20);
			password[i] = '\0';
			printf("\n");
			//scanf("%s", password);
			if (saleman == NULL)
			{
				printf("err_malloc\n");
				return -1;
			}
			while (fread(saleman, sizeof(user), 1, fp))
			{
				if ((strcmp(name, saleman->name) == 0) && (strcmp(password, saleman->password) == 0))
				{
					printf("��½�ɹ���\n");
					free(saleman);
					return 2;
				}
			}
			printf("��½ʧ�ܣ�������˺����д�\n");
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
			printf("δ��Ӿ����˺���Ϣ�����¼����Ա��ӡ�\n");
		}
		else
		{
			int i = 0;
			char name[50] = { 0 };
			char password[20] = { 0 };
			rewind(fp);
			printf("����������");
			scanf("%s", name);
			printf("�������룺");
			do
			{
				password[i] = _getch();
				if (password[i] == '\r')
					break;
				if (password[i] == '\b')
				{
					if (i == 0)
					{
						printf("\a");
						continue;
					}
					i = i - 1;
					printf("\b");
				}
				else
				{
					i = i + 1;
					printf("*");
				}
			} while (password[i] != '\n' && i < 20);
			password[i] = '\0';
			printf("\n");
			//scanf("%s", password);
			if (manager == NULL)
			{
				printf("err_malloc\n");
				return -1;
			}
			while (fread(manager, sizeof(user), 1, fp))
			{
				if ((strcmp(name, manager->name) == 0) && (strcmp(password, manager->password) == 0))
				{
					printf("��½�ɹ���\n");
					free(manager);
					return 3;
				}
			}
			printf("��½ʧ�ܣ�������˺����д�\n");
			free(manager);
			return 0;
		}
		break;
	case 9:
		fp = fopen("user_master.txt", "r");
		int i = 0;
		char name[50] = { 0 };
		char password[20] = { 0 };
		user* master = (user*)malloc(sizeof(user));
		printf("����������");
		scanf("%s", name);
		printf("�������룺");
		do
		{
			password[i] = _getch();
			if (password[i] == '\r')
				break;
			if (password[i] == '\b')
			{
				if (i == 0)
				{
					printf("\a");
					continue;
				}
				i = i - 1;
				printf("\b");
			}
			else
			{
				i = i + 1;
				printf("*");
			}
		} while (password[i] != '\n' && i < 20);
		password[i] = '\0';
		printf("\n");
		//scanf("%s", password);
		if (master == NULL)
		{
			printf("err_malloc\n");
			return -1;
		}
		fread(master, sizeof(user), 1, fp);
		if ((strcmp(name, master->name) == 0) && (strcmp(password, master->password) == 0))
		{
			printf("��½�ɹ���\n");
			free(master);
			return 9;
		}
		else
		{
			printf("��½ʧ�ܣ�������˺����д�\n");
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

