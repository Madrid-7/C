#include<stdio.h>
main(){
	int a,b,i;
	printf("����һ������");
	scanf("%d",&a);
	printf("���ĸ�λ��ʮλ����λ����Ϊ��\n"); 
	for(i=1;i<=3;i++){
		b=a%10;
		printf("%d\n",b);
		a=a/10;
	}
}
