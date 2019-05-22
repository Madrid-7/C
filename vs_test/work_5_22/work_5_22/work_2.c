#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 5

new_strupr(char* str)
{
	int i = 0;
	while (*(str + i))
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int main()
{
	//char* str = (char*)malloc(N * sizeof(char));
	char str[] = "abcd";
	//str = "abcd";
	new_strupr(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}