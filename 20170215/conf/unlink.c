///
/// @file    unlink.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-27 22:41:18
///
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int ret;
	ret=unlink(argv[1]);
	if(-1==ret)
	{
		perror("unlink");
		return -1;
	}
	return 0;
}
