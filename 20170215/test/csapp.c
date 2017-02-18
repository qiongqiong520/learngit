 ///
 /// @file    csapp.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 17:03:56
 ///
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
	struct stat stat;
	char *type ,*readok;

	Stat(argv[1],&stat);
	if(S_ISREG(stat.st_mode))
		type="regular";
	else if(S_ISDIR(stat.st_mode))
		type= "directory";
	else 
		type="other";
	if((stat.st_mode&S_IRUSR))
		readok ="yes";
	else
		readok ="np";
	printf("type:%s.read:%s\n",type,readok);
	exit(0);
}
