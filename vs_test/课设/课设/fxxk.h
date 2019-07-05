#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define ROW 7
#define COL 7

typedef struct user                 //�û���Ϣ
{
	char tel_num[15];
	char name[100];
	char password[20];
	struct user* next;
}user;

char* encode(char str[]);
char* decode(char str[]);

void menu();
void cls();                       //����
int CheakUser(int input);          //����˺�����
void CheakLogin(int n);             //����½���

void Select_Fun(int n);

typedef struct studio               //Ӱ����Ϣ
{
	char name[100];
	char sets[ROW][COL];
	struct studio* next;
}studio;

typedef struct movie
{
	char name[100];
	studio area;
	char time[100];
	int price;
	struct movie* next;
}movie;
