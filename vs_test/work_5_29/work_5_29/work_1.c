#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

// ����

// ����ڵ�
typedef struct Type_new
{
	int date;
	struct Type_new* next;
}node;
// ����һ���ڵ�
node* create_node()
{
	node* p = (node*)malloc(sizeof(node));
	scanf("%d", &(p->date));
	p->next = NULL;
	return p;
}
// ��������
node* create_list()
{
	node* head = (node*)malloc(sizeof(node));
	node* p1, *p2;
	p1 = head;
	printf("����һ���½ڵ�?(y/n)\n");
	while (getchar() == 'y')
	{
		p2 = create_node();
		p1->next = p2;
		p1 = p2;
		while (getchar() == '\0');
		printf("����һ���½ڵ�?(y/n)\n");
	}
	return head;
}

int main()
{
	node* head = NULL;
	head = create_list();
	while (head->next != NULL) 
	{
		head = head->next;
		printf("%d  ", head->date);
	}
	system("pause");
	return 0;
}