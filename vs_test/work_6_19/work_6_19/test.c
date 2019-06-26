#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * pFile;
	pFile = fopen("myfile.txt", "w");
	if (pFile != NULL)
	{
		fputs("fopen example", pFile);
		fclose(pFile);
	}
	system("pause");
	return 0;
}