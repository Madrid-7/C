#define _CRT_SECURE_NO_WARNINGS 1
#include"fxxk.h"

void test()
{
	FILE* fp;
	fp = fopen("user_master.txt", "r");
	if (fp == NULL )                  //�ж��Ƿ������ļ�
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
		printf("��ϵͳ�״����У���ע�����Ա�����Ϣ��\n");
		printf("������������");
		scanf("%s", master->name);
		printf("������绰���룺");
		scanf("%s", master->tel_num);
		printf("���������룺");
		scanf("%s", master->password);
		fwrite(master, sizeof(user), 1, fp);
		free(master);
		fclose(fp);
		printf("��ϲ����Ϊ��ϵͳ�ĵ�һ������Ա��\n");
		cls();
	}
	int input = 0;
	do
	{
		printf("===============================================================================================================\n");
		printf("************************************************* User log in *************************************************\n");
		printf("===============================================================================================================\n");
		printf("===============================================================================================================\n");
		printf("  0.�˳�             1.����             2.����Ա             3.����                                 9.����Ա   \n");
		printf("�������ѡ��");
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
			printf("�����������ѡ��\n");
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
