#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N sizeof(struct ballstar)
#define PT "����:%s,���:%d",p1->name,p1->hight
struct ballstar
{
	char name[20];
	float hight;
	struct ballstar *next;
};
void print_menu(void)
{
	printf("**************************************************************");
	printf("******************��ӭʹ��NBA���ǹ���ϵͳ*********************");
	printf("**************************************************************");
	printf("***********************��1¼����Ϣ****************************");
	printf("**********************��2��ɾ��������Ϣ***********************");
	printf("\t\t\t\t\t");
	printf("*********************���๦�����ڿ�����...********************");
	printf("************************�����ڴ�******************************");
}
struct ballstar *create()
{
	struct ballstar *p1, *p2, *head;
	head = p2 = (struct ballstar *)malloc(N);
	p1 = (struct ballstar*)malloc(N);
	printf("��¼����Ϣ��\n");
	scanf(PT);
	while (p1->hight != 0)
	{
		p2->next = p1;
		p2 = p1;
		scanf(PT);
	}
	p2->next = NULL;
	return head;
}

int m_delete(struct ballstar *head)
{
	struct ballstar *p0;
	p0 = head->next;
	if (p0 == NULL)
		return 0;
	while (p0 != NULL)
	{
		if (p0->name == "����")
		{
			head = p0->next;
		}
		head = p0;
		p0 = p0->next;
	}
	printf("ɾ�����\n");
	return 0;
}
main()
{
	print_menu();
	struct ballstar *head;
	char flag1;
	flag1 = getchar();
	if (flag1 == '1')
	{
		head = create();
		printf("��Ϣ¼�����");
		if (flag1 == '2')
		{
			m_delete(head);
			printf("ɾ�����");
		}
	}

	
}