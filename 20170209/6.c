 ///
 /// @file    6.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-29 22:23:38
 ///
 
#include<stdio.h>

int main()
{
	char *str[3] ={"stra","strb","strc"};
	char *p =str[0];
	int i=0;
	while(i<3)
	{
		printf("%s\n",p++);
		i++;
	}
	return 0;
}
