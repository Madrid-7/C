#define _CRT_SECURE_NO_WARNINGS 1
#include"fxxk.h"

char* encode(char str[], int n) 
{
	char c;
	size_t i;  
	for (i = 0; i < strlen(str); ++i) 
	{        
		c=str[i];       
		if(c>='a' && c<='z')
		{  
			if(c+n%26<='z'){ 
				str[i]=(char)(c+n%26);
			}
			else
			{  
				str[i]=(char)(c+n%26-26);        
			}      
		}
		else if(c>='A' && c<='Z')
		{  
			if(c + n%26 <= 'Z')
			{  
				str[i]=(char)(c+n%26);        
			}
			else
			{  
				str[i]=(char)(c+n%26-26);    
			}       
		}
		else
		{ 
			str[i]=c;     
		}   
	}   
	return str;
}

char* decode(char str[], int n)
{
	char c;
	size_t i;
	for (i = 0; i < strlen(str); ++i)
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
		{
			if (c - n % 26 >= 'a')
			{
				str[i] = (char)(c - n % 26);
			}
			else
			{
				str[i] = (char)(c - n % 26 + 26);
			}
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (c - n % 26 >= 'A')
			{
				str[i] = (char)(c - n % 26);
			}
			else
			{
				str[i] = (char)(c - n % 26 + 26);
			}
		}
		else
		{
			str[i] = c;
		}
	}
	return str;
}

void DelStudio()
{
	FILE* fp;
	char name[100];
	studio* head = (studio*)malloc(sizeof(studio));
	studio* p, *q;
	studio* u;
	p = NULL;
	q = NULL;
	head = NULL;
	fp = fopen("studio_inf.txt", "r");
	if (fp == NULL || (fread(u = (studio*)malloc(sizeof(studio)), sizeof(studio), 1, fp)) == 0)
	{
		printf("δ���Ӱ����\n");
		return;
	}
	rewind(fp);
	printf("����Ҫɾ����Ӱ������");
	scanf("%s", name);
	while (fread(u = (studio*)malloc(sizeof(studio)), sizeof(studio), 1, fp))
	{
		if (head == NULL)
		{
			head = u;
			head->next = NULL;
			p = head;
		}
		else
		{
			u->next = NULL;
			p->next = u;
			p = u;
		}
	}
	p = head;
	while (p)
	{
		if (strcmp(name, p->name) == 0)
		{
			if (head == p)
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
			q = p;
			p = p->next;
		}
	}
	fp = fopen("studio_inf.txt", "w");
	while (head)
	{
		fwrite(head, sizeof(studio), 1, fp);
		p = head;
		head = head->next;
		free(p);
	}
	fclose(fp);
}

//void ChangeStudioSets()
//{
//
//}

void InitSets(char sets[ROW][COL], char str)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			sets[i][j] = str;
		}
	}
}

//Ӱ������
void StudioManagement()         
{
	FILE* fp;
	studio* inf = (studio*)malloc(sizeof(studio));
	int input = 0;
	do
	{
		int count = 0;
		cls();
		fp = fopen("studio_inf.txt", "r");
		printf("===============================================================================================================\n");
		printf("********************************************** Studio information *********************************************\n");
		printf("===============================================================================================================\n");
		printf("	ID			Name			Row		Col		Seats_count		   \n");
		if (fp != NULL)
		{
			while (fread(inf, sizeof(studio), 1, fp))
			{
				count++;
				printf("	%d			%s			%d		%d		%d\n", count, inf->name, ROW, COL, ROW*COL);
			}
		}
		printf("------------- ������%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].���Ӱ��                                \n");
		printf("                                               [2].ɾ��Ӱ��                                \n");
//		printf("                                               [3].�޸�Ӱ����λ�������δ������            \n");
		printf("                                               [0].�˳�                                    \n");
		printf("***************************************************************************************************************\n");
		printf("�������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			fp = fopen("studio_inf.txt", "a");
			printf("����Ӱ�����ƣ�");
			scanf("%s", inf->name);
			InitSets(inf->sets, '0');
			fwrite(inf, sizeof(studio), 1, fp);
			fclose(fp);
			break;
		case 2:
			DelStudio();
			break;
		//case 3:
		//	ChangeStudioSets();
		//	break;
		case 0:
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (input);
	free(inf);
}


studio SearchArea()
{
	FILE* fp;
	char name[100];
	studio* u = (studio*)malloc(sizeof(studio));
	scanf("%s", name);
	fp = fopen("studio_inf.txt", "r");
	if (fp == NULL || (fread(u, sizeof(studio), 1, fp)) == 0)
	{
		printf("δ���Ӱ����\n");
		strcpy(u->name, "��,�뼰ʱ�޸�");
		return *u;
	}
	rewind(fp);
	while (fread(u, sizeof(studio), 1, fp))
	{
		if (strcmp(name, u->name) == 0)
		{
			return *u;
		}
	}
	printf("δ�ҵ���Ӱ����\n");
	strcpy(u->name, "��,�뼰ʱ�޸�");
	return *u;
}

void DelMovie()
{
	FILE* fp;
	char name[100];
	char time[100];
	movie* head = (movie*)malloc(sizeof(movie));
	movie* p, *q;
	movie* u;
	p = NULL;
	q = NULL;
	head = NULL;
	fp = fopen("movie_inf.txt", "r");
	if (fp == NULL || (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp)) == 0)
	{
		printf("δ��ӵ�Ӱ��\n");
		return;
	}
	rewind(fp);
	printf("����Ҫɾ���ĵ�Ӱ��");
	scanf("%s", name);
	printf("�����Ӱ��ʱ��Σ�");
	scanf("%s", time);
	while (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp))
	{
		if (head == NULL)
		{
			head = u;
			head->next = NULL;
			p = head;
		}
		else
		{
			u->next = NULL;
			p->next = u;
			p = u;
		}
	}
	p = head;
	while (p)
	{
		if (strcmp(name, p->name) == 0 && strcmp(time, p->time) == 0)
		{
			if (head == p)
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
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			printf("δ�ҵ�ӰƬ��\n");
		}
	}
	fp = fopen("movie_inf.txt", "w");
	while (head)
	{
		fwrite(head, sizeof(movie), 1, fp);
		p = head;
		head = head->next;
		free(p);
	}
	fclose(fp);
}

void ChangeMovie()
{
	FILE* fp;
	char name[100];
	char time[100];
	movie* head = (movie*)malloc(sizeof(movie));
	movie* p;
	movie* u;
	head = NULL;
	p = NULL;
	fp = fopen("movie_inf.txt", "r");
	if (fp == NULL || (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp)) == 0)
	{
		printf("δ��ӵ�Ӱ��\n");
		return;
	}
	rewind(fp);
	printf("����Ҫ�޸ĵĵ�Ӱ��");
	scanf("%s", name);
	printf("�����Ӱ��ʱ��Σ�");
	scanf("%s", time);
	while (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp))
	{
		if (head == NULL)
		{
			head = u;
			head->next = NULL;
			p = head;
		}
		else
		{
			u->next = NULL;
			p->next = u;
			p = u;
		}
	}
	p = head;
	while (p)
	{
		if (strcmp(name, p->name) == 0 && strcmp(time, p->time) == 0)
		{
			printf("�����Ӱ���ƣ�");
			scanf("%s", p->name);
			printf("�����ӳ���أ�");
			p->area = SearchArea();
			printf("�����ӳʱ��Σ�");
			scanf("%s", p->time);
			printf("����Ʊ�ۣ�");
			scanf("%d", &(p->price));
			break;
		}
		else
		{
			p = p->next;
		}
		if (p == NULL)
		{
			printf("δ�ҵ�ӰƬ��\n");
		}
	}
	fp = fopen("movie_inf.txt", "w");
	while (head)
	{
		fwrite(head, sizeof(movie), 1, fp);
		p = head;
		head = head->next;
		free(p);
	}
	fclose(fp);
}

//��Ӱ��Ϣ����
void MovieManagement()          
{
	FILE* fp;
	movie* inf = (movie*)malloc(sizeof(movie));
	int input = 0;
	do
	{
		int count = 0;
		cls();
		fp = fopen("movie_inf.txt", "r");
		printf("===============================================================================================================\n");
		printf("************************************************** Movie list *************************************************\n");
		printf("===============================================================================================================\n");
		printf("	ID		Movie_name		Movie_area	Movie_time	Ticket_price   \n");
		if (fp != NULL)
		{
			while (fread(inf, sizeof(movie), 1, fp))
			{
				count++;
				printf("	%d		%s			%s		%s		%dԪ\n", count, inf->name, inf->area.name, inf->time, inf->price);
			}
		}
		printf("------------- ������%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].��ӵ�Ӱ                                \n");
		printf("                                               [2].ɾ����Ӱ                                \n");
		printf("                                               [3].�޸ĵ�Ӱ                                \n");
		printf("                                               [0].�˳�                                    \n");
		printf("***************************************************************************************************************\n");
		printf("�������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			fp = fopen("movie_inf.txt", "a");
			printf("�����Ӱ���ƣ�");
			scanf("%s", inf->name);
			printf("�����ӳ���أ�");
			inf->area = SearchArea();
			printf("�����ӳʱ��Σ�");
			scanf("%s", inf->time);
			printf("����Ʊ�ۣ�");
			scanf("%d", &(inf->price));
			fwrite(inf, sizeof(movie), 1, fp);
			fclose(fp);
			break;
		case 2:
			DelMovie();
			break;
		case 3:
			ChangeMovie();
		case 0:
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (input);
	free(inf);
}

int TicketsLeft(char name[100], char time[100])
{
	FILE* fp;
	movie* u = (movie*)malloc(sizeof(movie));
	fp = fopen("movie_inf.txt", "r");
	if (fp == NULL || (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp)) == 0)
	{
		return 0;
	}
	rewind(fp);
	while (fread(u, sizeof(movie), 1, fp))
	{
		if (strcmp(name, u->name) == 0 && strcmp(time, u->time) == 0)
		{
			int count = 0;
			int i, j;
			for (i = 0; i < ROW; i++)
			{
				for (j = 0; j < COL; j++)
				{
					if (u->area.sets[i][j] == '0')
						count++;
				}
			}
			return count;
		}
	}
	free(u);
	return 0;
}

void ShowSets()
{
	char name[100];
	char time[100];
	FILE* fp;
	movie* u = (movie*)malloc(sizeof(movie));
	fp = fopen("movie_inf.txt", "r");
	if (fp == NULL || (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp)) == 0)
	{
		printf("δ��ӵ�Ӱ��\n");
		return;
	}
	rewind(fp);
	printf("�����ѯ��Ӱ����");
	scanf("%s", name);
	printf("�����Ӱʱ��Σ�");
	scanf("%s", time);
	while (fread(u, sizeof(movie), 1, fp))
	{
		if (strcmp(name, u->name) == 0 && strcmp(time, u->time) == 0)
		{
			int i = 0;
			int j = 0;
			int row = 0;
			int col = 0;
			printf("\n");
			printf(" ");
			for (i = 0; i <= ROW + 3; i++)
			{
				printf("-");
			}
			printf("��Ļ");
			printf("\n\n");
			for (i = 0; i <= ROW; i++)
			{
				printf("%d ", i);
			}
			printf("\n");
			for (i = 1; i <= ROW; i++)
			{
				printf("%d ", i);
				for (j = 1; j <= COL; j++)
				{
					printf("%c ", (u->area.sets)[i - 1][j - 1]);
				}
				printf("\n");
			}
		}
	}
	free(u);
	return;
}

//��ʾ��ӳ��Ӱ
void ShowMovieInf()             
{
	FILE* fp;
	movie* inf = (movie*)malloc(sizeof(movie));
	int input = 0;
	do
	{
		int count = 0;
		cls();
		fp = fopen("movie_inf.txt", "r");
		printf("===============================================================================================================\n");
		printf("************************************************** Movie Inf **************************************************\n");
		printf("===============================================================================================================\n");
		printf("	ID		Movie_name		Movie_area	Movie_time	Ticket_price	Tickets_left\n");
		if (fp != NULL)
		{
			while (fread(inf, sizeof(movie), 1, fp))
			{
				count++;
				printf("	%d		%s			%s		%s		%dԪ		%d��\n", count, inf->name, inf->area.name, inf->time, inf->price, TicketsLeft(inf->name, inf->time));
			}
		}
		printf("------------- ������%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].ѡ�񳡴β鿴��λ���                    \n");
		printf("                                               [0].�˳�                                    \n");
		printf("***************************************************************************************************************\n");
		printf("�������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ShowSets();
			break;
		case 0:
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (input);
	free(inf);
}


void SaleSet()
{
	FILE* fp;
	char name[100];
	char time[100];
	movie* head = (movie*)malloc(sizeof(movie));
	movie* p;
	movie* u;
	head = NULL;
	p = NULL;
	fp = fopen("movie_inf.txt", "r");
	if (fp == NULL || (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp)) == 0)
	{
		printf("δ��ӵ�Ӱ��\n");
		return;
	}
	rewind(fp);
	printf("����ѡ���ĵ�Ӱ��");
	scanf("%s", name);
	printf("�����Ӱ��ʱ��Σ�");
	scanf("%s", time);
	while (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp))
	{
		if (head == NULL)
		{
			head = u;
			head->next = NULL;
			p = head;
		}
		else
		{
			u->next = NULL;
			p->next = u;
			p = u;
		}
	}
	p = head;
	while (p)
	{
		if (strcmp(name, p->name) == 0 && strcmp(time, p->time) == 0)
		{
			int i = 0;
			int j = 0;
			int row = 0;
			int col = 0;
			printf("\n");
			printf(" ");
			for (i = 0; i <= ROW+3; i++)
			{
				printf("-");
			}
			printf("��Ļ");
			printf("\n\n");
			for (i = 0; i <= ROW; i++)
			{
				printf("%d ", i);
			}
			printf("\n");
			for (i = 1; i <= ROW; i++)
			{
				printf("%d ", i);
				for (j = 1; j <= COL; j++)
				{
					printf("%c ", (p->area.sets)[i-1][j-1]);
				}
				printf("\n");
			}
			printf("\n");
			while (1)
			{
				printf("��ѡ���ż���:\n");
				scanf("%d%d", &row, &col);
				if ((p->area.sets)[row-1][col-1] == '0')
				{
					(p->area.sets)[row-1][col-1] = '1';
					printf("���۳ɹ���\n");
					break;
				}
				else
				{
					printf("��λ�����۳���\n");
				}
			}
			break;
		}
		else
		{
			p = p->next;
		}
		if (p == NULL)
		{
			printf("δ�ҵ�ӰƬ��\n");
		}
	}
	fp = fopen("movie_inf.txt", "w");
	while (head)
	{
		fwrite(head, sizeof(movie), 1, fp);
		p = head;
		head = head->next;
		free(p);
	}
	fclose(fp);
}

//��Ʊ����
void SaleTicket()               
{
	FILE* fp;
	movie* inf = (movie*)malloc(sizeof(movie));
	int input = 0;
	do
	{
		int count = 0;
		cls();
		fp = fopen("movie_inf.txt", "r");
		printf("===============================================================================================================\n");
		printf("************************************************* Sale Ticket *************************************************\n");
		printf("===============================================================================================================\n");
		printf("	ID		Movie_name		Movie_area	Movie_time	Ticket_price	\n");
		if (fp != NULL)
		{
			while (fread(inf, sizeof(movie), 1, fp))
			{
				count++;
				printf("	%d		%s			%s		%s		%dԪ\n", count, inf->name, inf->area.name, inf->time, inf->price);
			}
		}
		printf("------------- ������%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].ѡ�񳡴�                                \n");
		printf("                                               [0].�˳�                                    \n");
		printf("***************************************************************************************************************\n");
		printf("�������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			SaleSet();
			break;
		case 0:
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (input);
	free(inf);
}


void ReturnSet()
{
	FILE* fp;
	char name[100];
	char time[100];
	movie* head = (movie*)malloc(sizeof(movie));
	movie* p;
	movie* u;
	head = NULL;
	p = NULL;
	fp = fopen("movie_inf.txt", "r");
	if (fp == NULL || (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp)) == 0)
	{
		printf("δ��ӵ�Ӱ��\n");
		return;
	}
	rewind(fp);
	printf("�����˻صĵ�Ӱ��");
	scanf("%s", name);
	printf("�����Ӱ��ʱ��Σ�");
	scanf("%s", time);
	while (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp))
	{
		if (head == NULL)
		{
			head = u;
			head->next = NULL;
			p = head;
		}
		else
		{
			u->next = NULL;
			p->next = u;
			p = u;
		}
	}
	p = head;
	while (p)
	{
		if (strcmp(name, p->name) == 0 && strcmp(time, p->time) == 0)
		{
			int i = 0;
			int j = 0;
			int row = 0;
			int col = 0;
			printf("\n");
			printf(" ");
			for (i = 0; i <= ROW + 3; i++)
			{
				printf("-");
			}
			printf("��Ļ");
			printf("\n\n");
			for (i = 0; i <= ROW; i++)
			{
				printf("%d ", i);
			}
			printf("\n");
			for (i = 1; i <= ROW; i++)
			{
				printf("%d ", i);
				for (j = 1; j <= COL; j++)
				{
					printf("%c ", (p->area.sets)[i - 1][j - 1]);
				}
				printf("\n");
			}
			printf("\n");
			while (1)
			{
				printf("��ѡ���ż���:\n");
				scanf("%d%d", &row, &col);
				if ((p->area.sets)[row - 1][col - 1] == '1')
				{
					(p->area.sets)[row - 1][col - 1] = '0';
					printf("��Ʊ�ɹ���\n");
					break;
				}
				else
				{
					printf("��λ��δ�۳���\n");
				}
			}
			break;
		}
		else
		{
			p = p->next;
		}
		if (p == NULL)
		{
			printf("δ�ҵ�ӰƬ��\n");
		}
	}
	fp = fopen("movie_inf.txt", "w");
	while (head)
	{
		fwrite(head, sizeof(movie), 1, fp);
		p = head;
		head = head->next;
		free(p);
	}
	fclose(fp);
}

//��Ʊ����
void ReturnTicket()             
{
	FILE* fp;
	movie* inf = (movie*)malloc(sizeof(movie));
	int input = 0;
	do
	{
		int count = 0;
		cls();
		fp = fopen("movie_inf.txt", "r");
		printf("===============================================================================================================\n");
		printf("************************************************ Return Ticket ************************************************\n");
		printf("===============================================================================================================\n");
		printf("	ID		Movie_name		Movie_area	Movie_time	Ticket_price	\n");
		if (fp != NULL)
		{
			while (fread(inf, sizeof(movie), 1, fp))
			{
				count++;
				printf("	%d		%s			%s		%s		%dԪ\n", count, inf->name, inf->area.name, inf->time, inf->price);
			}
		}
		printf("------------- ������%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].ѡ�񳡴�                                \n");
		printf("                                               [0].�˳�                                    \n");
		printf("***************************************************************************************************************\n");
		printf("�������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ReturnSet();
			break;
		case 0:
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (input);
	free(inf);
}

int Saleroom(char name[100], char time[100])
{
	FILE* fp;
	movie* u = (movie*)malloc(sizeof(movie));
	fp = fopen("movie_inf.txt", "r");
	if (fp == NULL || (fread(u = (movie*)malloc(sizeof(movie)), sizeof(movie), 1, fp)) == 0)
	{
		return 0;
	}
	rewind(fp);
	while (fread(u, sizeof(movie), 1, fp))
	{
		if (strcmp(name, u->name) == 0 && strcmp(time, u->time) == 0)
		{
			int count = 0;
			int i, j;
			for (i = 0; i < ROW; i++)
			{
				for (j = 0; j < COL; j++)
				{
					if (u->area.sets[i][j] == '1')
						count++;
				}
			}
			return count;
		}
	}
	free(u);
	return 0;
}

//�����۶����
void MoneyCount()               
{
	FILE* fp;
	movie* inf = (movie*)malloc(sizeof(movie));
	int count = 0;
	cls();
	fp = fopen("movie_inf.txt", "r");
	printf("===============================================================================================================\n");
	printf("************************************************** Sale room **************************************************\n");
	printf("===============================================================================================================\n");
	printf("	ID		Movie_name		Movie_area	Movie_time	Ticket_price	Saleroom\n");
	if (fp != NULL)
	{
		while (fread(inf, sizeof(movie), 1, fp))
		{
			count++;
			printf("	%d		%s			%s		%s		%dԪ		%dԪ\n", count, inf->name, inf->area.name, inf->time, inf->price, (inf->price)*Saleroom(inf->name, inf->time));
		}
	}
	printf("------------- ������%d -----------------------------------------------------------------------------------------\n", count);
	free(inf);
}


void DelUser(int chose)
{
	FILE* fp;
	char name[100];
	user* head = (user*)malloc(sizeof(user));
	user* p,*q;
	user* u;
	head = NULL;
	p = NULL;
	q = NULL;
	if (chose == 1)
	{
		fp = fopen("user_saleman.txt", "r");
		if (fp == NULL || (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp)) == 0)
		{
			printf("δ�������Ա��\n");
			return;
		}
		rewind(fp);
		printf("����Ҫɾ�����û�����");
		scanf("%s", name);
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
				p = head;
			}
			else
			{
				u->next = NULL;
				p->next = u;
				p = u;
			}
		}
		p = head;
		while (p)
		{
			if (strcmp(name, p->name) == 0)
			{
				if (head == p)
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
				q = p;
				p = p->next;
			}
		}
		fp = fopen("user_saleman.txt", "w");
		while (head)
		{
			fwrite(head, sizeof(user), 1, fp);
			p = head;
			head = head->next;
			free(p);
		}
		fclose(fp);
	}
	else
	{
		fp = fopen("user_manager.txt", "r");
		if (fp == NULL || (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp)) == 0)
		{
			printf("δ��Ӿ���\n");
			return;
		}
		rewind(fp);
		printf("����Ҫɾ�����û�����");
		scanf("%s", name);
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
				p = head;
			}
			else
			{
				u->next = NULL;
				p->next = u;
				p = u;
			}
		}
		p = head;
		while (p)
		{
			if (strcmp(name, p->name) == 0)
			{
				if (head == p)
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
				q = p;
				p = p->next;
			}
		}
		fp = fopen("user_manager.txt", "w");
		while (head)
		{
			fwrite(head, sizeof(user), 1, fp);
			p = head;
			head = head->next;
			free(p);
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
	p = NULL;
	if (chose == 1)
	{
		fp = fopen("user_saleman.txt", "r");
		if (fp == NULL || (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp)) == 0)
		{
			printf("δ�������Ա��\n");
			return;
		}
		rewind(fp);
		printf("����Ҫ�޸ĵ��û�����");
		scanf("%s", name);
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
				p = head;
			}
			else
			{
				u->next = NULL;
				p->next = u;
				p = u;
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
			p = head;
			head = head->next;
			free(p);
		}
		fclose(fp);
	}
	else
	{
		fp = fopen("user_manager.txt", "r");
		if (fp == NULL || (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp)) == 0)
		{
			printf("δ��Ӿ���\n");
			return;
		}
		rewind(fp);
		printf("����Ҫ�޸ĵ��û�����");
		scanf("%s", name);
		while (fread(u = (user*)malloc(sizeof(user)), sizeof(user), 1, fp))
		{
			if (head == NULL)
			{
				head = u;
				head->next = NULL;
				p = head;
			}
			else
			{
				u->next = NULL;
				p->next = u;
				p = u;
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
			p = head;
			head = head->next;
			free(p);
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
		printf("===============================================================================================================\n");
		printf("*************************************************** Set user **************************************************\n");
		printf("===============================================================================================================\n");
		printf("	ID			User_Name			User_Phone_Num			User_Type        \n");
		while (fread(u, sizeof(user), 1, fp))
		{
			count++;
			printf("	%d			%s				%s				master			 \n", count, u->name, u->tel_num);
		}
		fp = fopen("user_saleman.txt", "r");
		if (fp != NULL)
		{
			while (fread(u, sizeof(user), 1, fp))
			{
				count++;
				printf("	%d			%s				%s				saleman			 \n", count, u->name, u->tel_num);
			}
		}
		fp = fopen("user_manager.txt", "r");
		if (fp != NULL)
		{
			while (fread(u, sizeof(user), 1, fp))
			{
				count++;
				printf("	%d			%s				%s				manager			 \n", count, u->name, u->tel_num);
			}
		}
		printf("------------- ������%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].����û�                                \n");
		printf("                                               [2].ɾ���û�                                \n");
		printf("                                               [3].�޸��û�                                \n");
		printf("                                               [0].�˳�                                    \n");
		printf("***************************************************************************************************************\n");
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
			if (n != 2 && n != 9)
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
			if (n != 2 && n != 9)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				SaleTicket();    //��Ʊ����
			}
			break;
		case 5:
			if (n != 2 && n != 9)
			{
				printf("��ǰ�˺��޴�Ȩ�ޡ�\n");
			}
			else
			{
				ReturnTicket();  //��Ʊ����
			}
			break;
		case 6:
			if (n != 3 && n != 9)
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


