#define _CRT_SECURE_NO_WARNINGS 1
#define N 30
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct st_type
{
	char num[10];
	char name[21];
	char sex;
	float sub1;
	float sub2;
	float sub3;
	float sub4;
};
struct st_type input()
{
	struct st_type s0;
	printf("��������:");
	gets(s0.name);
	printf("����ѧ��,�Ա�,���ſεĳɼ�(�ո�ָ�):\n");
	scanf("%s %c %f %f %f %f", &s0.num, &s0.sex, &s0.sub1, &s0.sub2, &s0.sub3, &s0.sub4);
	while (getchar() != '\n')
	{
		;
	}
	return s0;
}
struct score_type      //����Ŀƽ��ֵ��������
{
	char name[5];
	float sum;                //���ڼ���ƽ��ֵ
	float aver;               //ƽ��ֵ
	float _sum;               //���ڼ��㷽��
	float _s;                 //����
};

int main()
{
	int i = 0, j = 0;
	struct st_type s[N];
	struct score_type sub[4] = { { "sub1",0,0,0,0 }, { "sub2",0,0,0,0 }, { "sub3",0,0,0,0 }, { "sub4",0,0,0,0 } };
	struct score_type tmp;
	for (i = 0; i < N; i++)
	{
		s[i] = input();
	}
	for (i = 0; i < N; i++)
	{
		sub[0].sum = sub[0].sum + s[i].sub1;
		sub[1].sum = sub[1].sum + s[i].sub2;
		sub[2].sum = sub[2].sum + s[i].sub3;
		sub[3].sum = sub[3].sum + s[i].sub4;
	}
	for (i = 0; i < 4; i++)
	{
		sub[i].aver = sub[i].sum / N;
	}
	for (i = 0; i < N; i++)
	{
		sub[0]._sum = sub[0]._sum + pow((s[i].sub1 - sub[0].aver), 2);
		sub[1]._sum = sub[1]._sum + pow((s[i].sub2 - sub[1].aver), 2);
		sub[2]._sum = sub[2]._sum + pow((s[i].sub3 - sub[2].aver), 2);
		sub[3]._sum = sub[3]._sum + pow((s[i].sub4 - sub[3].aver), 2);
	}
	for (i = 0; i < 4; i++)
	{
		sub[i]._s = sub[i]._sum / N;
	}
	for (i = 0; i <= 4; i++)
	{
		for (j = i + 1; j <= 4; j++)
		{
			if (sub[i].aver < sub[j].aver)
			{
				tmp = sub[i];
				sub[i] = sub[j];
				sub[j] = tmp;
			}
		}
	}
	printf("��Ŀ		ƽ���ɼ�	����\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s		%.2f		%.2f\n", sub[i].name, sub[i].aver, sub[i]._s);
	}
	system("pause");
	return 0;
}
