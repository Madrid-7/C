#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 20           //��󶥵����
//#define INF 32767           //��ʾ����ֵ 

typedef struct
{
	int arcs[MAXVEX][MAXVEX];      //�ߣ��򻡣���Ϣ
	char vex[MAXVEX];				//������Ϣ
	int vexnum;						//������Ŀ
	int arcnum;                     //�ߣ��򻡣�����Ŀ
}AdjMatrix;							//�ڽӾ���

typedef struct                      //���ж���
{
	int elem[MAXVEX+1];
	int rear, front;
}Queue;
void InitQueue(Queue* Q)            //��ʼ������
{
	Q->front = -1;
	Q->rear = -1;
}
void EnterQueue(Queue* Q, int v0)     //���
{
	Q->rear++;
	Q->elem[Q->rear] = v0;
}
void DelQueue(Queue* Q, int* v)        //����
{
	Q->front++;
	*v = Q->elem[Q->front];
}
int Empty(Queue* Q)                   //�ж϶ӿ�
{
	if (Q->rear == Q->front)
		return 1;
	return 0;
}

int LocateVex(AdjMatrix* G, char v)          //��������ߵ���Ϣ�ҵ�����±겢����
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
	printf("����ͼ�еĶ������ͱ�����\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);     //����ͼ�еĶ������ͱ���
	getchar();
	for (i = 0; i < G->vexnum; i++)           //���ڽӾ����ʼ��
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = 0;   //��������Ļ���ֵINF
		}
	}
	printf("���붥�����Ϣ��\n");
	for (i = 0; i < G->vexnum; i++)
	{
		
		scanf("%c", &G->vex[i]);          //���붥�����Ϣ
	}
	printf("����ߵ���Ϣ��\n");
	for (i = 0; i < G->arcnum; i++)
	{
		getchar();
		scanf("%c%c", &vex1, &vex2);         //����ߵ���Ϣ

		j = LocateVex(G, vex1);             //��������ߵ���Ϣ�ҵ�����±겢����
		k = LocateVex(G, vex2);

		G->arcs[j][k] = 1;                //����Ӧ�ı߼����ڽӾ����У��������������Ȩֵwight
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

int visited[MAXVEX] = { 0 };                //���ʱ�ʶ����
int FirstAdjVex(AdjMatrix* G, int v0)       //����ͼ g �ж��� v0 �ĵ�һ���ڽӵ㣬û���򷵻� -1
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->arcs[v0][i] == 1)
			return i;
	}
	return -1;
}
int NextAdjVex(AdjMatrix* G, int v0, int w)  //�� w �����֮��ʼ�ң�����ͼ g �ж��� v0 ����һ���ڽӵ㣬û���򷵻� -1 ��
{
	int i;
	for (i = w + 1; i < G->vexnum; i++)
	{
		if (G->arcs[v0][i] == 1)
			return i;
	}
	return -1;
}
//�� v0 �����ݹ������������ر�����ͨ��ͼ
void DFS(AdjMatrix* G, int v0)
{
	int w;
	printf("%c", G->vex[v0]);           //������ʵĵ�
	visited[v0] = 1;                    //���ʹ�����Ϊ 1 ����ʾΪ���ʹ�
	w = FirstAdjVex(G, v0);             //��ͼ g �ж��� v0 �ĵ�һ���ڽӵ�
	while (w != -1)
	{
		if (!visited[w])                //�ҵ��ڽӵ��������㿪ʼ�ݹ����
			DFS(G,w);
		w = NextAdjVex(G, v0, w);       //�ݹ�������ϸ���֮����ͼ g �ж��� v0 ����һ���ڽӵ�
	}
}
void TraverseG1(AdjMatrix* G)
{
	int v;
	for (v = 0; v < G->vexnum; v++)         //��ʼ�����ʱ�־����
		visited[v] = 0;              
	for (v = 0; v < G->vexnum; v++)         //��ÿ��û���ʹ��ĵ㿪ʼ����
		if (!visited[v])
			DFS(G, v);
}

void BFS(AdjMatrix* G, int v0)
{
	int w;
	int v;
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	printf("%c", G->vex[v0]);                 //������ʵĵ�     
	visited[v0] = 1;                          //���ʹ�����Ϊ 1 ����ʾΪ���ʹ�
	InitQueue(Q);                             
	EnterQueue(Q, v0);                        //���ʺ����
	while (!Empty(Q))
	{
		DelQueue(Q, &v);
		w = FirstAdjVex(G, v);                 //�Ҷ������һ������ڽӵ�
		while (w != -1)
		{
			if (!(visited[w]))
			{
				printf("%c", G->vex[w]);
				visited[w] = 1;
				EnterQueue(Q, w);              //�ҵ��ڽӵ�������
			}
			w = NextAdjVex(G, v, w);           //�����Ҷ������һ�������һ���ڽӵ�
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
	printf("���ȡ���ȡ���:\n");
	for (i = 0; i < G->vexnum; i++)
	{
		int OD = VexOD(G, i);
		int ID = VexID(G, i);
		
		printf("%c %d %d %d", G->vex[i], OD, ID, OD + ID);  //���ȡ���ȡ���
		printf("\n");
	}
	printf("������ȱ������:\n");
	TraverseG1(G);
	printf("\n");
	printf("������ȱ������:\n");
	TraverseG2(G);
	printf("\n");

	system("pause");
	return 0;
}