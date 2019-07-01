#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct user                 //用户信息
{
	char tel_num[15];
	char name[100];
	char password[20];
	struct user* next;
}user;

void menu();
void cls();                       //清屏
int CheakUser(int input);          //检测账号密码
void CheakLogin(int n);             //检测登陆情况

void Select_Fun(int n);


