 ///
 /// @file    0102_打印九九乘法表.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-05 19:47:43
 ///
#include<stdio.h>
#include<stdlib.h>

void mul(int n)
{
	int i,j;
	for(i =1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
			printf("%2d *%2d= %2d",i,j,i*j);
		printf("\n");
	}
}
int main(){
	int n;
	printf("请输入行数:");
	scanf("%d",&n);
	mul(n);
	return 0;
}

