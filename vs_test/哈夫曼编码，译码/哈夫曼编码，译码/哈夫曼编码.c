#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	char data;
	struct Node* Lchild;
	struct Node* Rchild;
}BiTNode, *Bitree;

typedef struct stack
{
	Bitree data[MAXSIZE];
	int top;
}Seqstack;

// ��ʼ��ջ
Seqstack* InitStack()
{
	Seqstack *s;
	s = (Seqstack *)malloc(sizeof(Seqstack));
	s->top = -1;
	return s;
}


//�ж�ջ�Ƿ�Ϊ��
int IsEmpty(Seqstack *s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}


//��ջ
int Push(Seqstack *s, Bitree root)
{
	if (s->top == MAXSIZE - 1)
		return 0;
	else
	{
		s->top++;
		s->data[s->top] = root;
		return 1;
	}
}

//��ջ
int Pop(Seqstack *s, Bitree *root)
{
	if (IsEmpty(s))
		return 0;
	else
	{
		*root = s->data[s->top];
		s->top--;
	}
	return 1;
}

//��ȡջ��Ԫ��
int Top(Seqstack*s, Bitree *root)
{
	if (IsEmpty(s))
		return 0;
	else
	{
		*root = s->data[s->top];
	}
	return 1;
}

void creatFirst(Bitree *T)
{
	char ch;
	ch = getchar();
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (Bitree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		creatFirst(&((*T)->Lchild));
		creatFirst(&((*T)->Rchild));
	}
}

//����
void PreOrder(Bitree root)
{
	if (root)
	{
		printf("%c", root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}

//����
void InOrder(Bitree root)
{
	if (root)
	{
		InOrder(root->Lchild);
		printf("%c", root->data);
		InOrder(root->Rchild);
	}
}

//����
void PostOrder(Bitree root)
{
	Seqstack *s;
	Bitree p, q;
	s = InitStack();
	p = root;
	q = NULL;
	while (p != NULL || !IsEmpty(s))
	{
		while (p != NULL)
		{
			Push(s, p);
			p = p->Lchild;
		}
		if (!IsEmpty(s))
		{
			Top(s, &p);
			if ((p->Rchild == NULL) || (p->Rchild == q))
			{
				Pop(s, &p);
				printf("%c", p->data);
				q = p;
				p = NULL;
			}
			else
				p = p->Rchild;
		}
	}
}

int main()
{
	Bitree root;
	creatFirst(&root);
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	system("pause");
	return 0;
}