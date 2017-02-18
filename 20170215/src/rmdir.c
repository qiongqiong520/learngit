///
/// @file    rmdir.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-17 15:49:32
///

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/dir.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int ret;
	ret=rmdir(argv[1]);
	if(-1==ret)
	{
		perror("rmdir");
		return -1;
	}
	return 0;
}




