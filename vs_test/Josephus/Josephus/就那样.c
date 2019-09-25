#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int id;
	int password;
	struct node* next;
}node;

node* create_list(int n)
{
	node *p, *q, *head;
	int count = 1;
	int i = 0;
	head = q = p = (node*)malloc(sizeof(node));
	p->id = count++;
	scanf("%d", &p->password);
	for (i = 1; i < n; i++)
	{
		p = (node*)malloc(sizeof(node));
		p->id = count++;
		scanf("%d", &p->password);
		q->next = p;
		q = p;
	}
	p->next = head;
	return p;
}

void print_list(node* first, node* last, int n, int m)
{
	int i = 0;
	m = m % n;
	for (i = 1; i < m; i++)
	{
		last = first;
		first = first->next;
	}
	printf("%d ", first->id);
	m = first->password;
	last->next = first->next;
	free(first);
	first = last->next;
	n--;
	if (n > 1)
	{
		print_list(first, last, n, m);
	}
	else if (n == 1)
	{
		printf("%d", first->id);
	}
}

int main()
{
	int n, m;
	node *last;
	scanf("%d%d", &n, &m);
	last = create_list(n);
	print_list(last->next, last, n, m);
	system("pause");
	return 0;
}