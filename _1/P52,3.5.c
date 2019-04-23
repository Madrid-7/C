//输入四个数，求它们平均值
#include<stdio.h>
main(){
	float a,b,c,d,average;
	printf("输入四个数(空格分隔):");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	average=(a+b+c+d)/4;
	printf("average=%g",average);
}
