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

int count = 0;

void InOrderleaf(Bitree root)
{
	if (root)
	{
		InOrderleaf(root->Lchild);
		if (!(root->Lchild == NULL && root->Rchild == NULL)) //如果是叶子节点，全局变量count++.
		{
			count++;
		}
		InOrderleaf(root->Rchild);
	}
}

int main()
{
	Bitree root;
	creatFirst(&root);
	InOrderleaf(root);
	printf("%d", count);
	system("pause");
	return 0;

}