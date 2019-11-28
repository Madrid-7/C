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
} Vex;

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
	for (i = 0; i < G->arcnum; i++)
	{
		getchar();
		scanf("(%c,%c,%d)", &vex1, &vex2, &weight);
		j = LocateVex(G, vex1);
		k = LocateVex(G, vex2);
		G->arcs[j][k] = weight;
		G->arcs[k][j] = weight;
	}
}

void MiniSpanTree_Kruskal(AdjMatrix *G)
{
	Vex edge[MAXVEX];
	int k = 0;
	int n, m;
	for (int i = 0; i < G->arcnum - 1; i++) {
		for (int j = i + 1; j < G->arcnum; j++) {
			if (G->arcs[i][j]) {
				edge[k].begin = i;
				edge[k].end = j;
				edge[k].weight = G->arcs[i][j];
				k++;
			}
		}
	}
	for(i = 0; i < G->vexnum)

}

int main()
{
	system("pause");
	return 0;
}