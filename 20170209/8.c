 ///
 /// @file    8.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-29 22:47:04
 ///
 
#include<stdio.h>

int func(int a)
{
	a =(1<<5)-1;
	return a;
}

int main()
{
	printf("--%d\n",func(21));
return 0;
}

