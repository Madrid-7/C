//�����������
#include<stdio.h>
#include<math.h>
main(){
	float a,b,c,area,S;
	printf("���������������߳�:");
	scanf("%f%f%f",&a,&b,&c);
	S=(a+b+c)*0.5;
	area=sqrt(S*(S-a)*(S-b)*(S-c));
	printf("���������Ϊ��%g",area);
}
