#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 20           //最大顶点个数
//#define INF 32767           //表示极大值 

typedef struct
{
	int arcs[MAXVEX][MAXVEX];      //边（或弧）信息
	char vex[MAXVEX];				//顶点信息
	int vexnum;						//顶点数目
	int arcnum;                     //边（或弧）的数目
}AdjMatrix;							//邻接矩阵

typedef struct                      //队列定义
{
	int elem[MAXVEX+1];
	int rear, front;
}Queue;
void InitQueue(Queue* Q)            //初始化队列
{
	Q->front = -1;
	Q->rear = -1;
}
void EnterQueue(Queue* Q, int v0)     //入队
{
	Q->rear++;
	Q->elem[Q->rear] = v0;
}
void DelQueue(Queue* Q, int* v)        //出队
{
	Q->front++;
	*v = Q->elem[Q->front];
}
int Empty(Queue* Q)                   //判断队空
{
	if (Q->rear == Q->front)
		return 1;
	return 0;
}

int LocateVex(AdjMatrix* G, char v)          //根据输入边的信息找到点的下标并返回
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
	printf("输入图中的顶点数和边数：\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);     //输入图中的顶点数和边数
	getchar();
	for (i = 0; i < G->vexnum; i++)           //对邻接矩阵初始化
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = 0;   //如果是网的话赋值INF
		}
	}
	printf("输入顶点的信息：\n");
	for (i = 0; i < G->vexnum; i++)
	{
		
		scanf("%c", &G->vex[i]);          //输入顶点的信息
	}
	printf("输入边的信息：\n");
	for (i = 0; i < G->arcnum; i++)
	{
		getchar();
		scanf("%c%c", &vex1, &vex2);         //输入边的信息

		j = LocateVex(G, vex1);             //根据输入边的信息找到点的下标并返回
		k = LocateVex(G, vex2);

		G->arcs[j][k] = 1;                //将对应的边加入邻接矩阵中，如果是网，赋予权值wight
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

int visited[MAXVEX] = { 0 };                //访问标识数组
int FirstAdjVex(AdjMatrix* G, int v0)       //返回图 g 中顶点 v0 的第一个邻接点，没有则返回 -1
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->arcs[v0][i] == 1)
			return i;
	}
	return -1;
}
int NextAdjVex(AdjMatrix* G, int v0, int w)  //在 w 这个点之后开始找，返回图 g 中顶点 v0 的下一个邻接点，没有则返回 -1 ，
{
	int i;
	for (i = w + 1; i < G->vexnum; i++)
	{
		if (G->arcs[v0][i] == 1)
			return i;
	}
	return -1;
}
//从 v0 出发递归地深度优先搜素遍历连通子图
void DFS(AdjMatrix* G, int v0)
{
	int w;
	printf("%c", G->vex[v0]);           //输出访问的点
	visited[v0] = 1;                    //访问过后标记为 1 ，表示为访问过
	w = FirstAdjVex(G, v0);             //找图 g 中顶点 v0 的第一个邻接点
	while (w != -1)
	{
		if (!visited[w])                //找到邻接点则从这个点开始递归遍历
			DFS(G,w);
		w = NextAdjVex(G, v0, w);       //递归遍历完上个点之后，找图 g 中顶点 v0 的下一个邻接点
	}
}
void TraverseG1(AdjMatrix* G)
{
	int v;
	for (v = 0; v < G->vexnum; v++)         //初始化访问标志数组
		visited[v] = 0;              
	for (v = 0; v < G->vexnum; v++)         //以每个没访问过的点开始访问
		if (!visited[v])
			DFS(G, v);
}

void BFS(AdjMatrix* G, int v0)
{
	int w;
	int v;
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	printf("%c", G->vex[v0]);                 //输出访问的点     
	visited[v0] = 1;                          //访问过后标记为 1 ，表示为访问过
	InitQueue(Q);                             
	EnterQueue(Q, v0);                        //访问后入队
	while (!Empty(Q))
	{
		DelQueue(Q, &v);
		w = FirstAdjVex(G, v);                 //找队列里第一个点的邻接点
		while (w != -1)
		{
			if (!(visited[w]))
			{
				printf("%c", G->vex[w]);
				visited[w] = 1;
				EnterQueue(Q, w);              //找到邻接点后将其入队
			}
			w = NextAdjVex(G, v, w);           //继续找队列里第一个点的下一个邻接点
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
	printf("出度、入度、度:\n");
	for (i = 0; i < G->vexnum; i++)
	{
		int OD = VexOD(G, i);
		int ID = VexID(G, i);
		
		printf("%c %d %d %d", G->vex[i], OD, ID, OD + ID);  //出度、入度、度
		printf("\n");
	}
	printf("深度优先遍历结果:\n");
	TraverseG1(G);
	printf("\n");
	printf("广度优先遍历结果:\n");
	TraverseG2(G);
	printf("\n");

	system("pause");
	return 0;
}