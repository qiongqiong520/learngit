 ///
 /// @file    22.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-29 23:03:57
 ///
#include<stdio.h>

char *mystring()
{
	char buffer[6] ={0};
	char *s = "hello,world";
	for(int i=0;i<sizeof(buffer)-1;i++)
	{
		buffer[i]=*(s+i);
	}
	return buffer;
}
int main(int argc,char *argv[])
{
	printf("%s\n",mystring());
	return 0;
}
