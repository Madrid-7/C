#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct user                 //�û���Ϣ
{
	char tel_num[15];
	char name[100];
	char password[20];
	struct user* next;
}user;

void menu();
void cls();                       //����
int CheakUser(int input);          //����˺�����
void CheakLogin(int n);             //����½���

void Select_Fun(int n);


