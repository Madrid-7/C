#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 20
//#define INF 32767

typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;

typedef struct
{
	int elem[MAXVEX+1];
	int rear, front;
}Queue;
void InitQueue(Queue* Q)
{
	Q->front = -1;
	Q->rear = -1;
}
void EnterQueue(Queue* Q, int v0)
{
	Q->rear++;
	Q->elem[Q->rear] = v0;
}
void DelQueue(Queue* Q, int* v)
{
	Q->front++;
	*v = Q->elem[Q->front];
}
int Empty(Queue* Q)
{
	if (Q->rear == Q->front)
		return 1;
	return 0;
}

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
	scanf("%d%d", &G->vexnum, &G->arcnum);
	getchar();
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vex[i]);
	}
	for (i = 0; i < G->arcnum; i++)
	{
		getchar();
		scanf("%c%c", &vex1, &vex2);
		j = LocateVex(G, vex1);
		k = LocateVex(G, vex2);
		G->arcs[j][k] = 1;
	}

}

int VexOD(AdjMatrix* G, int vex)
{
	int count = 0;
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->arcs[vex][i] == 1)
			count++;
	}
	return count;
}
int VexID(AdjMatrix* G, int vex)
{
	int count = 0;
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->arcs[i][vex] == 1)
			count++;
	}
	return count;
}

int visited[MAXVEX] = { 0 };
int FirstAdjVex(AdjMatrix* G, int v0)
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->arcs[v0][i] == 1)
			return i;
	}
	return -1;
}
int NextAdjVex(AdjMatrix* G, int v0, int w)
{
	int i;
	for (i = w + 1; i < G->vexnum; i++)
	{
		if (G->arcs[v0][i] == 1)
			return i;
	}
	return -1;
}
void DFS(AdjMatrix* G, int v0)
{
	int w;
	printf("%c", G->vex[v0]);
	visited[v0] = 1;
	w = FirstAdjVex(G, v0);
	while (w != -1)
	{
		if (!visited[w])
			DFS(G,w);
		w = NextAdjVex(G, v0, w);
	}
}
void TraverseG(AdjMatrix* G)
{
	int v;
	for (v = 0; v < G->vexnum; v++)
		visited[v] = 0;
	for (v = 0; v < G->vexnum; v++)
		if (!visited[v])
			DFS(G, v);
}

void BFS(AdjMatrix* G, int v0)
{
	int w;
	int v;
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	printf("%c", G->vex[v0]);
	visited[v0] = 1;
	InitQueue(Q);
	EnterQueue(Q, v0);
	while (!Empty(Q))
	{
		DelQueue(Q, &v);
		w = FirstAdjVex(G, v);
		while (w != -1)
		{
			if (!(visited[w]))
			{
				printf("%c", G->vex[w]);
				visited[w] = 1;
				EnterQueue(Q, w);
			}
			w = NextAdjVex(G, v, w);
		}
	}
}
void TraverseG2(AdjMatrix* G)
{
	int v;
	for (v = 0; v < G->vexnum; v++)
		visited[v] = 0;
	for (v = 0; v < G->vexnum; v++)
		if (!visited[v])
			BFS(G, v);
}

int main()
{
	int i;
	AdjMatrix* G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	Create(G);
	for (i = 0; i < G->vexnum; i++)
	{
		int OD = VexOD(G, i);
		int ID = VexID(G, i);
		printf("%c %d %d %d", G->vex[i], OD, ID, OD + ID);
		printf("\n");
	}
	TraverseG(G);
	printf("\n");
	TraverseG2(G);
	printf("\n");

	system("pause");
	return 0;
}