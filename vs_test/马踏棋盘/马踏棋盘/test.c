#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 64

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int row[64];
	int col[64];
	int top;
}stack;

stack * InitStack()
{
	stack * s;
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;
	return s;
}

int Push(stack* s, int r, int c)
{
	if (s->top == MAXSIZE - 1)
		return 0;
	else
	{
		s->top++;
		s->row[s->top] = r;
		s->col[s->top] = c;
		return 1;
	}
}

int Pop(stack* s)
{
	s->top--;
	return 1;
}

void unfold(int r, int c, stack *s, int board[8][8])
{
	if ((r - 2 > -1) && (c + 1 < 8) && (board[r - 2][c + 1] == 0))
	{
		r = r - 2;
		c = c + 1;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if ((r - 1 > -1) && (c + 2 < 8) && (board[r - 1][c + 2] == 0))
	{
		r = r - 1;
		c = c + 2;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if ((r + 1 < 8) && (c + 2 < 8) && (board[r + 1][c + 2] == 0))
	{
		r = r + 1;
		c = c + 2;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if ((r + 2 < 8) && (c + 1 < 8) && (board[r + 2][c + 1] == 0))
	{
		r = r + 2;
		c = c + 1;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if ((r + 2 < 8) && (c - 1 > -1) && (board[r + 2][c - 1] == 0))
	{
		r = r + 2;
		c = c - 1;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if ((r + 1 < 8) && (c - 2 > -1) && (board[r + 1][c - 2] == 0))
	{
		r = r + 1;
		c = c - 2;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if ((r - 1 > -1) && (c - 2 > -1) && (board[r - 1][c - 2] == 0))
	{
		r = r - 1;
		c = c - 2;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if ((r - 2 > -1) && (c - 1 > -1) && (board[r - 2][c - 1] == 0))
	{
		r = r - 2;
		c = c - 1;
		Push(s, r, c);
		board[r][c] = s->top + 1;
		if (s->top != MAXSIZE - 1)
		{
			unfold(r, c, s, board);
			if (s->top == MAXSIZE - 1)
				return;
			board[r][c] = 0;
			Pop(s);
			r = s->row[s->top];
			c = s->col[s->top];
		}
	}
	if (s->top != MAXSIZE - 1)
		return;
}

int main()
{
	int i = 0;
	int j = 0;
	int board[8][8] = { 0 };
	stack *s;
	int r, c;
	scanf("%d%d", &r, &c);
	s = InitStack();
	r -= 1;
	c -= 1;
	Push(s, r, c);
	board[r][c] = s->top + 1;
	unfold(r, c, s, board);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%2d ", board[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}