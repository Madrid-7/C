#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>

typedef struct Stack
{
	int row;
	int col;
	int dir;
	struct Stack* next;
	struct Stack* top;
}stack;

stack* InitStack()
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->next = NULL;
	s->top = NULL;
	return s;
}

void Input(stack** s, int r, int c, int d)
{
	stack* n = (stack*)malloc(sizeof(stack));
	n->next = NULL;
	n->row = r;
	n->col = c;
	n->dir = d;
	n->top = *s;
	(*s)->next = n;
	(*s) = n;
}

void Output(stack** s)
{
	if ((*s)->top == NULL)
	{
		printf("??");
		system("pause");
		exit(0);
	}
	stack* p = (*s);
	(*s) = (*s)->top;
	(*s)->next = NULL;
	free(p);
}

void FindWay(stack** s, char** board, int r, int c, int m, int n)
{
	if ((c + 1 < n) && (board[r][c + 1] == '0'))
	{
		(*s)->dir = 1;
		c = c + 1;
		board[r][c] = '*';
		Input(s, r, c, 0);
		if (((*s)->row == m - 1) && ((*s)->col == n - 1))
			return;
		else
		{
			FindWay(s, board, r, c, m, n);
			if (((*s)->row == m - 1) && ((*s)->col == n - 1))
				return;
			Output(s);
			r = (*s)->row;
			c = (*s)->col;
		}
	}
	if ((r + 1 < m) && (board[r + 1][c] == '0'))
	{
		(*s)->dir = 2;
		r = r + 1;
		board[r][c] = '*';
		Input(s, r, c, 0);
		if (((*s)->row == m - 1) && ((*s)->col == n - 1))
			return;
		else
		{
			FindWay(s, board, r, c, m, n);
			if (((*s)->row == m - 1) && ((*s)->col == n - 1))
				return;
			Output(s);
			r = (*s)->row;
			c = (*s)->col;
		}
	}
	if ((c - 1 > -1) && (board[r][c - 1] == '0'))
	{
		(*s)->dir = 3;
		c = c - 1;
		board[r][c] = '*';
		Input(s, r, c, 0);
		if (((*s)->row == m - 1) && ((*s)->col == n - 1))
			return;
		else
		{
			FindWay(s, board, r, c, m, n);
			if (((*s)->row == m - 1) && ((*s)->col == n - 1))
				return;
			Output(s);
			r = (*s)->row;
			c = (*s)->col;
		}
	}
	if ((r - 1 > -1) && (board[r - 1][c] == '0'))
	{
		(*s)->dir = 4;
		r = r - 1;
		board[r][c] = '*';
		Input(s, r, c, 0);
		if (((*s)->row == m - 1) && ((*s)->col == n - 1))
			return;
		else
		{
			FindWay(s, board, r, c, m, n);
			if (((*s)->row == m - 1) && ((*s)->col == n - 1))
				return;
			Output(s);
			r = (*s)->row;
			c = (*s)->col;
		}
	}
}

int main()
{
	stack* s;
	stack* head;

	int m = 0;
	int n = 0;

	int i = 0;

	int r = 0;
	int c = 0;

	scanf("%d%d", &m, &n);
	char **board = (char**)malloc(m * sizeof(char*));
	for (i = 0; i < m; i++)
	{
		board[i] = (char*)malloc(n * sizeof(char));
		scanf("%s", board[i]);
	}
	board[0][0] = '*';

	s = InitStack();
	head = s;
	Input(&s, 0, 0, 0);
	FindWay(&s, board, r, c, m, n);

	head = head->next;
	while (head != NULL)
	{
		printf("(%d,%d,%d)", head->row + 1, head->col + 1, head->dir);
		head = head->next;
	}

	system("pause");
	return 0;
}