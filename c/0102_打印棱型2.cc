 ///
 /// @file    0102_打印棱型2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-05 23:09:20
 ///
#include<stdio.h>
#include<stdlib.h>

int main(){
	int row;
	int head ,mid;
	printf("    *    \n");
	for(row=2;row<=5;row++)
	{
		for(head=5-row;head>0;head--)
		{
			printf(" ");
		}
		printf("*");
		for(mid=0;mid<2*row-3;mid++)
			printf(" ");
		printf("*\n");
	}
	for(row=4;row>1;row--)
	{
	 	for(head=5-row;head>0;head--)
				printf(" ");
		printf("*");
		for(mid=0;mid<2*row-3;mid++)
				printf(" ");
		printf("\n");
	}
	printf("    *    \n");
		return 0;
	}
