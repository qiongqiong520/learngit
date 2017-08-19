///
/// @file    findPrime.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-08-12 15:30:36
///
#include"stdio.h"
#include"math.h"
int main(void)
{
	int count,i,m,n,num;
	printf("请输入所求范围(正整数): ");
	scanf("%d",&num);
	count=0;//count记录素数的个数
	printf("%d以内的素数为:\n",num);
	for(m=2;m<=num;m++)
	{
		n=sqrt(m);
		for(i=2;i<=n;i++)
		{
			if(m%i==0)
				break;
		}
		if(i>n)//如果m是素数
		{
			printf("%6d",m);
			count++;
			if(count%10==0)//count为10的倍数时换行
				printf("\n");
		}
	}
	printf("\n");
	return 0;
}
