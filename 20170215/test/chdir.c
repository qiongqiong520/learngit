///
/// @file    chdir.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-17 14:45:08
///

#include <unistd.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int ret;
	ret=chdir(argv[1]);	
	if(-1==ret)
	{
		perror("chdir");
		return -1;
	}
	printf("path: %s\n",getcwd(NULL,0));
	return 0;
}


