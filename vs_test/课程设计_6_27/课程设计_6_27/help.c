#define _CRT_SECURE_NO_WARNINGS 1
//void insert(struct film * p)
//{
//	struct film * q = (struct film *)malloc(sizeof(struct film));
//	char name[50];
//	printf("插到那部之后:>\n");
//	scnaf("%s", name);
//	printf("输入相关信息:>\n");
//	scanf("%s%s%s%d%d", q->name, q->director, q->actor, &q->year, &q->box_office);
//	while (p != NULL)
//	{
//		if (strcmp(p->name, name) == 0)
//		{
//			q->next = p->next;
//			p->next = q;
//			printf("succeed\n");
//			break;
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//}