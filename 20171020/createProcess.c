 ///
 /// @file    createProcess.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-10-20 12:22:09
 ///
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

void main(int argc,char *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr,"Fork Failed");
		exit(-1);
	}
	else if(pid==0){
		execlp("/bin/ls",NULL);
	}
	else{
		wait(NULL);
		printf("Child Complete");
		exit(0);
	}
}
