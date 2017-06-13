 ///
 /// @file    4.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-29 22:21:28
 ///
 
#include<stdio.h>
 int a(a)
{
	a ^=(1<<4)-1;
	return a;
}
int main()
{
	int b;
	b=a(10);
	printf("b=%d\n",b);
	return 0;
}
