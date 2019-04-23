//大写字母转化为小写字母
#include<stdio.h>
main(){
	int letter;
	printf("输入大写字母：");
	scanf("%c",&letter);
	letter=letter+32;
	printf("小写字母为：%c",letter);
} 
