///
 /// @file    tcp.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 19:59:26
 ///
 
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<pthread.h>


int  main(int argc,char* argv[])
{
	if(argc<3)
	{
		printf("usage:./servertcp ip port\n");
		return -1;
	}
	int sfd = tcp_init(argv[1],atoi(argv[2]));
	char buf[512] ={0};
	while(1)
	{
	int cfd = tcp_accept(sfd);
	if(fork()==0)
	{
	recv(cfd,buf,sizeof(buf),0);
	puts(buf);
	send(cfd,"hello",6,0);
	close(cfd);
	}
	else{
	close(cfd);
	}
	}
	close(sfd);
	}


