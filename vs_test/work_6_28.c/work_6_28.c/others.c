#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N sizeof(struct ballstar)
#define PT "姓名:%s,身高:%d",p1->name,p1->hight
struct ballstar
{
	char name[20];
	float hight;
	struct ballstar *next;
};
void print_menu(void)
{
	printf("**************************************************************");
	printf("******************欢迎使用NBA球星管理系统*********************");
	printf("**************************************************************");
	printf("***********************按1录入信息****************************");
	printf("**********************按2可删除球星信息***********************");
	printf("\t\t\t\t\t");
	printf("*********************其余功能正在开发中...********************");
	printf("************************敬请期待******************************");
}
struct ballstar *create()
{
	struct ballstar *p1, *p2, *head;
	head = p2 = (struct ballstar *)malloc(N);
	p1 = (struct ballstar*)malloc(N);
	printf("请录入信息：\n");
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
		if (p0->name == "库里")
		{
			head = p0->next;
		}
		head = p0;
		p0 = p0->next;
	}
	printf("删除完成\n");
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
		printf("信息录入完成");
		if (flag1 == '2')
		{
			m_delete(head);
			printf("删除完成");
		}
	}

	
}