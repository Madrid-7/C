#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5

void sort(char **p, int n)
{
	char **q, **s, *t;
	for (q = p; q < p + n - 1; q++)
	{
		for (s = q + 1; s < p + n; s++)
		{
			if (strcmp(*q, *s) > 0)
			{
				t = *q;
				*q = *s;
				*s = t;
			}
		}
	}
}
int main()
{
	char *a[N];
	char b[N][99];
	char **p;
	int i;
	for (i = 0; i < N; i++)
		a[i] = b[i];
	printf("ÇëÒÀ´ÎÊäÈë×Ö·û´®£º\n");
	for (i = 0; i < N; i++)
		scanf("%s", a[i]);
	p = a;
	sort(p, N);
	printf("ÅÅÐòºóÊä³öÎª£º\n");
	for (i = 0; i < N; i++)
	{
		printf("%s\n", a[i]);
	}
	system("pause");
	return 0;
}
