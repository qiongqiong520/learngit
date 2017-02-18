 ///
 /// @file    chdir.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 14:06:54
 ///
#include <unistd.h>
#include<stdio.h>
//当前工作目录改变成以参数path所指的目录
//
int main()
{
	chdir("~/leargit/20170215");
	printf("current working directory:%s\n",getcwd(NULL,0));
}
