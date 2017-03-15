 ///
 /// @file    printN.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 17:24:38
 ///
 
#include<stdio.h>

void printN(int N)
{
	int i;
	for(i=1;i<N;i++)
	{
		printf("%d\n",i);
	}
	return ;
}
int main(void)
{
	int N;
	scanf("%d",&N);
	printN(N);
	return 0;
	
}
	
		
