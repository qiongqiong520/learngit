 ///
 /// @file    sizeof.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 11:55:55
 ///
#include<stdio.h>
#include<stdlib.h>

struct A{
 	long a1;
	short a2;
	int a3;
	int *a4;
};
int main()
{
	printf("%d",sizeof(struct A));
	return 0;
}
