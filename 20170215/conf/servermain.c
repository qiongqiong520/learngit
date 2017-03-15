///
/// @file    servermain.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-26 16:51:32
///

#include"func.h"

int main(int argc,char* argv[])
{
	if(argc!=4)
	{
		printf("error args\n");
		exit(-1);
	}
	int count = atoi(argv[3]);//创建的进程数目
	pcdata p =(pcdata)calloc(count,sizeof(cdata));//为子进程结构体申请空间
	make_child(p,count);
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	set_init(sfd,argv[1],argv[2]);
	listen(sfd,count);
	int fd=0;
	char buf[512]={0};
	fd_set rdset;
	short iflags = fcntl(sfd,F_GETFL,0);
	fcntl(sfd,F_SETFL,O_NONBLOCK|iflags);

	int i;
	for(i =0;i<count;i++)
	{
		int iflags = fcntl(sfd,F_GETFL,0);
		fcntl(sfd,F_SETFL,O_NONBLOCK|iflags);
	}
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(sfd,&rdset);
		if(select(MAXCLIENT+1,&rdset,NULL,NULL,NULL)<0)
			continue;
		for(fd = 0;fd<MAXCLIENT;fd++)
		{
			if(FD_ISSET(fd,&rdset))
			{
				if(fd ==sfd)
				{
					int cfd = tcp_accept(sfd);
					FD_SET(cfd,&rdset);
				}else{
					bzero(buf,sizeof(buf));
					recv(fd,buf,sizeof(buf),0);
					puts(buf);
					send(fd,"java",5,0);//
					//FD_CLR(fd,&rdset);
					close(fd);
				}
			}
		}
	}
	close(sfd);
}



