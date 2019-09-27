#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* str[3] = { "stra","strb","strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s ", p++);
		i++;
	}
	system("pause");
	return 0;
}

//void del(struct node* head)
//{
//	int num;
//	struct node *p;
//	p = head->next;
//	printf("choose which one:");
//	scanf("%d", num);
//	while (p != NULL)
//	{
//		if (p->num == num)
//		{
//			head->next = p->next;
//			break;
//		}
//		head = p;
//		p = p->next;
//	}
//}