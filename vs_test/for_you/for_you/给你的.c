#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#define N 3
typedef struct Stu
{
	int num;
	char name[20];
	int s;
}stu;

void input(stu a[])
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d%s%d", &a[i].num, a[i].name, &a[i].s);
	}
}

void output(stu a[])
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("%d %s %d\n", a[i].num, a[i].name, a[i].s);
	}
}

void sort(stu a[])
{
	int i = 0;
	int j = 0;
	stu *b[N];
	stu *c;
	for (i = 0; i < N; i++)
	{
		b[i] = &(a[i]);
	}
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (b[i]->s > b[j]->s)
			{
				c = b[i];
				b[i] = b[j];
				b[j] = c;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%d %s %d\n", b[i]->num, b[i]->name, b[i]->s);
	}
}

int main()
{
	stu a[N];
	input(a);
	output(a);
	sort(a);
	system("pause");
	return 0;
}