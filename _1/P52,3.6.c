#include<stdio.h>
main(){
	int a,b,i;
	printf("输入一个数：");
	scanf("%d",&a);
	printf("它的个位，十位，百位依次为：\n"); 
	for(i=1;i<=3;i++){
		b=a%10;
		printf("%d\n",b);
		a=a/10;
	}
}
