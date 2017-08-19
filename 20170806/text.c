 ///
 /// @file    text.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-06 16:05:42
 ///
#include<stdio.h>
int main()
{
	for(int i=20;i>0;i--)
	if(100*i*i < (2<<i))
		printf("%d",i);
	return 0;
}
	
