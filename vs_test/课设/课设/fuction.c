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
		printf("未添加影厅。\n");
		return;
	}
	rewind(fp);
	printf("输入要删除的影厅名：");
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

//影厅管理
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
		printf("------------- 总数：%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].添加影厅                                \n");
		printf("                                               [2].删除影厅                                \n");
//		printf("                                               [3].修改影厅座位情况（暂未开发）            \n");
		printf("                                               [0].退出                                    \n");
		printf("***************************************************************************************************************\n");
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			fp = fopen("studio_inf.txt", "a");
			printf("输入影厅名称：");
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
			printf("输入错误，重新选择。\n");
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
		printf("未添加影厅。\n");
		strcpy(u->name, "无,请及时修改");
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
	printf("未找到该影厅。\n");
	strcpy(u->name, "无,请及时修改");
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
		printf("未添加电影。\n");
		return;
	}
	rewind(fp);
	printf("输入要删除的电影：");
	scanf("%s", name);
	printf("输入电影的时间段：");
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
			printf("未找到影片。\n");
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
		printf("未添加电影。\n");
		return;
	}
	rewind(fp);
	printf("输入要修改的电影：");
	scanf("%s", name);
	printf("输入电影的时间段：");
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
			printf("输入电影名称：");
			scanf("%s", p->name);
			printf("输入放映场地：");
			p->area = SearchArea();
			printf("输入放映时间段：");
			scanf("%s", p->time);
			printf("输入票价：");
			scanf("%d", &(p->price));
			break;
		}
		else
		{
			p = p->next;
		}
		if (p == NULL)
		{
			printf("未找到影片。\n");
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

//电影信息管理
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
				printf("	%d		%s			%s		%s		%d元\n", count, inf->name, inf->area.name, inf->time, inf->price);
			}
		}
		printf("------------- 总数：%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].添加电影                                \n");
		printf("                                               [2].删除电影                                \n");
		printf("                                               [3].修改电影                                \n");
		printf("                                               [0].退出                                    \n");
		printf("***************************************************************************************************************\n");
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			fp = fopen("movie_inf.txt", "a");
			printf("输入电影名称：");
			scanf("%s", inf->name);
			printf("输入放映场地：");
			inf->area = SearchArea();
			printf("输入放映时间段：");
			scanf("%s", inf->time);
			printf("输入票价：");
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
			printf("输入错误，重新选择。\n");
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
		printf("未添加电影。\n");
		return;
	}
	rewind(fp);
	printf("输入查询电影名：");
	scanf("%s", name);
	printf("输入电影时间段：");
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
			printf("屏幕");
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

//显示上映电影
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
				printf("	%d		%s			%s		%s		%d元		%d张\n", count, inf->name, inf->area.name, inf->time, inf->price, TicketsLeft(inf->name, inf->time));
			}
		}
		printf("------------- 总数：%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].选择场次查看座位情况                    \n");
		printf("                                               [0].退出                                    \n");
		printf("***************************************************************************************************************\n");
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ShowSets();
			break;
		case 0:
			break;
		default:
			printf("输入错误，重新选择。\n");
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
		printf("未添加电影。\n");
		return;
	}
	rewind(fp);
	printf("输入选购的电影：");
	scanf("%s", name);
	printf("输入电影的时间段：");
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
			printf("屏幕");
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
				printf("请选择几排几座:\n");
				scanf("%d%d", &row, &col);
				if ((p->area.sets)[row-1][col-1] == '0')
				{
					(p->area.sets)[row-1][col-1] = '1';
					printf("出售成功。\n");
					break;
				}
				else
				{
					printf("该位置已售出。\n");
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
			printf("未找到影片。\n");
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

//售票管理
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
				printf("	%d		%s			%s		%s		%d元\n", count, inf->name, inf->area.name, inf->time, inf->price);
			}
		}
		printf("------------- 总数：%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].选择场次                                \n");
		printf("                                               [0].退出                                    \n");
		printf("***************************************************************************************************************\n");
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			SaleSet();
			break;
		case 0:
			break;
		default:
			printf("输入错误，重新选择。\n");
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
		printf("未添加电影。\n");
		return;
	}
	rewind(fp);
	printf("输入退回的电影：");
	scanf("%s", name);
	printf("输入电影的时间段：");
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
			printf("屏幕");
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
				printf("请选择几排几座:\n");
				scanf("%d%d", &row, &col);
				if ((p->area.sets)[row - 1][col - 1] == '1')
				{
					(p->area.sets)[row - 1][col - 1] = '0';
					printf("退票成功。\n");
					break;
				}
				else
				{
					printf("该位置未售出。\n");
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
			printf("未找到影片。\n");
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

//退票管理
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
				printf("	%d		%s			%s		%s		%d元\n", count, inf->name, inf->area.name, inf->time, inf->price);
			}
		}
		printf("------------- 总数：%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].选择场次                                \n");
		printf("                                               [0].退出                                    \n");
		printf("***************************************************************************************************************\n");
		printf("输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ReturnSet();
			break;
		case 0:
			break;
		default:
			printf("输入错误，重新选择。\n");
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

//总销售额界面
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
			printf("	%d		%s			%s		%s		%d元		%d元\n", count, inf->name, inf->area.name, inf->time, inf->price, (inf->price)*Saleroom(inf->name, inf->time));
		}
	}
	printf("------------- 总数：%d -----------------------------------------------------------------------------------------\n", count);
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
			printf("未添加销售员。\n");
			return;
		}
		rewind(fp);
		printf("输入要删除的用户名：");
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
			printf("未添加经理。\n");
			return;
		}
		rewind(fp);
		printf("输入要删除的用户名：");
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
			printf("未添加销售员。\n");
			return;
		}
		rewind(fp);
		printf("输入要修改的用户名：");
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
			printf("未添加经理。\n");
			return;
		}
		rewind(fp);
		printf("输入要修改的用户名：");
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
			p = head;
			head = head->next;
			free(p);
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
		printf("------------- 总数：%d -----------------------------------------------------------------------------------------\n", count);
		printf("===============================================================================================================\n");
		printf("                                               [1].添加用户                                \n");
		printf("                                               [2].删除用户                                \n");
		printf("                                               [3].修改用户                                \n");
		printf("                                               [0].退出                                    \n");
		printf("***************************************************************************************************************\n");
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
			if (n != 2 && n != 9)
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
			if (n != 2 && n != 9)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				SaleTicket();    //售票管理
			}
			break;
		case 5:
			if (n != 2 && n != 9)
			{
				printf("当前账号无此权限。\n");
			}
			else
			{
				ReturnTicket();  //退票管理
			}
			break;
		case 6:
			if (n != 3 && n != 9)
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


