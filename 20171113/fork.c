 ///
 /// @file    fork.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-11-13 20:32:32
 ///
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	pid_t pid;
	pid= fork();
	if(pid<0)
	{
		fprintf(stderr,"Fork Failed");
		exit(-1);
	}
	else if(pid==0){
		execlp("/bin/ls","ls",NULL);
	}
	else{
		wait(NULL);
		printf("CHild create");
		exit(0);
	}
}
		
