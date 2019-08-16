#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* str_set(char* s)
{
	int len = strlen(s);
	int p1, p2;
	char* p = s;
	int count = 0;
	if (len < 0 || s == NULL)
		return NULL;
	while (*p)
	{
		if (*p == ' ')
		{
			count++;
		}
		p++;
	}
	p1 = len;
	p2 = 2 * count + len;
	while (p1 != p2 && p1 >= 0) 
	{ 
		if (s[p1] == ' ') 
		{
			s[p2--] = '0';
			s[p2--] = '2';
			s[p2--] = '%';
			p1--; 
		} 
		else 
		{ 
			s[p2--] = s[p1--]; 
		} 
	}
	return s;
}

int main()
{
	char str[30] = "abc defgx yz";
	str_set(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}