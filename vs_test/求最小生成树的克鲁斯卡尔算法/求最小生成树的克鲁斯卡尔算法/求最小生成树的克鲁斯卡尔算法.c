#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 20
#define INF 32767

typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;

typedef struct {
	int begin;
	int end;
	int weight;
	int isUsed;
} Edge;

int LocateVex(AdjMatrix* G, char v)
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->vex[i] == v)
			return i;
	}
	return 0;
}
void Create(AdjMatrix *G)
{
	int i, j, k;
	char vex1, vex2;
	int weight;
	scanf("%d%d", &G->vexnum, &G->arcnum);
	getchar();
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = INF;
		}
	}
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vex[i]);
	}
	getchar();
	for (i = 0; i < G->arcnum; i++)
	{
		scanf("(%c,%c,%d)", &vex1, &vex2, &weight);
		j = LocateVex(G, vex1);
		k = LocateVex(G, vex2);
		G->arcs[j][k] = weight;
		G->arcs[k][j] = weight;
	}
}

int Find(int *parent, int f)
{
	//从下标f开始寻找parent数组中元素为0的下标
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}
void Kruskal(AdjMatrix *G)
{
	int parent[MAXVEX] = { 0 };
	Edge edge[MAXVEX];
	int i, j;
	int k = 0;
	int n, m;
	for (i = 0; i < G->vexnum- 1; i++) {
		for (j = i + 1; j < G->vexnum; j++) {
			if (G->arcs[i][j] != INF) {
				edge[k].begin = i;
				edge[k].end = j;
				edge[k].weight = G->arcs[i][j];
				edge[k].isUsed = 0;
				k++;
			}
		}
	}
	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				Edge tmp = edge[i];
				edge[i] = edge[j];
				edge[j] = tmp;
			}
		}
	}
	for (int i = 0; i < G->arcnum; i++)
	{
		n = Find(parent, edge[i].begin);
		m = Find(parent, edge[i].end);
		if (n != m)//m=n说明有环
		{
			parent[n] = m;
			edge[i].isUsed = 1;
		}
		printf("(%c,%c,%d,%d)", G->vex[edge[i].begin], G->vex[edge[i].end], edge[i].weight, edge[i].isUsed);
	}
}

int main()
{
	AdjMatrix* G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	Create(G);
	Kruskal(G);
	system("pause");
	return 0;
}