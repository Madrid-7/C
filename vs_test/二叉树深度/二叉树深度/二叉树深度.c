#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	char data;
	struct Node* Lchild;
	struct Node* Rchild;
}BiTNode, *Bitree;

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

int Treedepth(Bitree root)
{
	int hl, hr;
	if (root == NULL)
		return 0;
	else
	{
		hl = Treedepth(root->Lchild);
		hr = Treedepth(root->Rchild);
		if (hl > hr)
			return hl + 1;
		else
			return hr + 1;
	}
}

int main()
{
	Bitree root;
	creatFirst(&root);
	printf("%d", Treedepth(root));
	system("pause");
	return 0;
}