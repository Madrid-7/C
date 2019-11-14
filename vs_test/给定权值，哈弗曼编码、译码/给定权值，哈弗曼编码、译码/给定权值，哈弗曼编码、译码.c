#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define N	 6
#define M    2 * N - 1

typedef char *Huffmancode[6];

typedef struct
{
	int weight;
	int parent, Lchild, Rchild;
}HTNode, HuffmanTree[M + 1];

//挑选哈夫曼书前n项中权值最小,且parent不为0的两个值的下标
void select(HuffmanTree ht, int n, int *s1, int *s2) 
{
	int c[30] = { 0 };
	int i, j, h; 
	int cut = 0; 
	for (i = 1; i <= n; i++)
	{ 
		if (ht[i].parent == 0)
		{
			c[cut] = ht[i].weight;
			cut++;
		} 
	}
	//冒泡排序	
	for (i = 0; i < cut; i++) 
	{							
		for (j = 0; j < cut - i - 1; j++) {
			if (c[j] > c[j + 1])
			{			
				h = c[j];		
				c[j] = c[j+1];	
				c[j+1] = h;		
			}		
		}	
	}
	for (i = 1; i <= n; i++)
	{
		if (c[0] == ht[i].weight)
			*s1 = i;
		if (c[1] == ht[i].weight)
			*s2 = i;
	}
}

//创建哈夫曼树
void CreatHuffmanTree(HuffmanTree ht, int w[], int n)
{					
	int m = 2 * n - 1;
	int s1,s2;
	int i; 
	for (i = 0; i <= n; i++)
	{		
		ht[i].weight = w[i];	
		ht[i].Lchild = 0;		
		ht[i].Rchild = 0; 	
		ht[i].parent = 0;	
	} 	
	for (i = n + 1; i <= m; i++)
	{		
		ht[i].weight = 0; 	
		ht[i].Lchild = 0; 		
		ht[i].Rchild = 0;		
		ht[i].parent = 0;
	} 	
	for (i = n + 1; i <= m; i++)
	{
		select(ht, i - 1, &s1, &s2);
		//Print(ht);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[i].Lchild = s1 ;	
		ht[i].Rchild = s2 ;	
		ht[s1].parent = i ;
		ht[s2].parent = i ;
	}
}

//哈夫曼树编码
void CrtHuffmanCodel(HuffmanTree ht, Huffmancode hc, int n) 
{
	char *cd;	
	int start;
	int i, c, p;
	cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++) 
	{ 
		start = n - 1;
		c = i;
		p = ht[i].parent;
		while (p != 0)
		{ 
			--start;
			if (ht[p].Lchild == c) 
			{ 
				cd[start] = '0';
			} 
			else
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}		
		hc[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]); 
	}	
	free(cd);
}

void print(Huffmancode hc) 
{						
	//输出哈夫曼树编码	
	int i;			
	for (i = 1; i <= 6; i++) 
	{ 
		switch (i) 
		{ 
		case 1:printf("A:%s", hc[1]); break;		
		case 2:printf("B:%s", hc[2]); break;		
		case 3:printf("C:%s", hc[3]); break;		
		case 4:printf("D:%s", hc[4]); break;		
		case 5:printf("E:%s", hc[5]); break;		
		case 6:printf("F:%s", hc[6]); break; 
		}		
		printf("\n");
	}
} 
void println(HuffmanTree ht, int p) 
{			
	//输出p为叶子节点时的译码信息		
	switch (p) 
	{ 
	case 1:printf("A"); break;	
	case 2:printf("B"); break;		
	case 3:printf("C"); break;		
	case 4:printf("D"); break;		
	case 5:printf("E"); break;	
	case 6:printf("F"); break; }
} 
void TransHuffmancodel(HuffmanTree ht, char *c)
{
	//哈弗满树译码	
	int i, p;
	p = M; 
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == '0')
		{
			p = ht[p].Lchild;
			if (ht[p].Lchild == 0 && ht[p].Rchild == 0)
			{
				println(ht, p);
				p = M;
			}
		}
		if (c[i] == '1')
		{
			p = ht[p].Rchild;
			if (ht[p].Lchild == 0 && ht[p].Rchild == 0) 
			{ 
				println(ht, p);				
				p = M;
			}
		}
	}
} 

int main()
{
	int i;
	HuffmanTree ht;
	int w[N + 1];
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &w[i]);
	}
	CreatHuffmanTree(ht, w, 6);
	Huffmancode hc;
	CrtHuffmanCodel(ht, hc, 6);
	char s[6], c[100];
	scanf("%s", s);
	scanf("\n%s", c);
	print(hc);
	for (i = 0; i < strlen(s); i++)
	{
		switch (s[i])
		{
		case 'A':printf("%s", hc[1]); break;
		case 'B':printf("%s", hc[2]); break;
		case 'C':printf("%s", hc[3]); break;
		case 'D':printf("%s", hc[4]); break;
		case 'E':printf("%s", hc[5]); break;
		case 'F':printf("%s", hc[6]); break;
		}
	}
	printf("\n");
	TransHuffmancodel(ht, c);
	printf("\n");
	system("pause");
	return 0;
}
