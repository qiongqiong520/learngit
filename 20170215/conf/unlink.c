 ///
 /// @file    unlink.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 10:17:44
 ///
 
#include"func.h"

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int ret;
	ret= unlink(argv[1]);
	if(-1==ret)
	{
		perror("unlink");
		return -1;
	}
	return 0;
}
