//求三角形面积
#include<stdio.h>
#include<math.h>
main(){
	float a,b,c,area,S;
	printf("输入三角形三个边长:");
	scanf("%f%f%f",&a,&b,&c);
	S=(a+b+c)*0.5;
	area=sqrt(S*(S-a)*(S-b)*(S-c));
	printf("三角形面积为：%g",area);
}
