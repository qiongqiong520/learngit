 ///
 /// @file    printN.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-06 14:27:15
 ///
#include<stdio.h>

void PrintN(int N)
{
	for(int i=1;i<=N;i++)
		printf("%d\n",i);
}

int main()
{
	int N;
	scanf("%d\n",&N);
	PrintN(N);

	return 0;
}

