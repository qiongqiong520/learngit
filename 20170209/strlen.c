 ///
 /// @file    strlen.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-29 23:59:22
 ///
 
#include<stdio.h>
#include<assert.h>
int strlen(const char *str)
{
	assert(str!=NULL);
	int len =0;
	while((*str++)!='\0')
		len++;
	return len;
}

int main()
{
	int  n ;
	char y[10]="ntest";
	char *x =y;
	n =strlen(x);
	*x =x[n];
	x++;
	printf("x=%s\n",x);
	printf("y=%s\n",y);
return 0;
}
