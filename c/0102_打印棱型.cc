 ///
 /// @file    0102_打印棱型.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-05 22:51:36
 ///
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int head,current;
	int row;
	for(row =1;row<=5;row++)
	{
		for(head=5-row;head>0;head--)
		{
			printf(" ");
		}
		for(current =1;current<=row;current++)
			printf("*");
		printf("\n");
	}

	for(row=4;row>0;row--)
	{
		for(head=5-row;head>0;head--)
			printf(" ");
		for(current=1;current<=row;current++)
			printf("*");
		printf("\n");
	}
	return 0;
}
