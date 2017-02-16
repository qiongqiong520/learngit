#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/types.h>

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		perror("error args\n");
		return -1;

	}
	int sfd;
	sfd =socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family =AF_INET;
	ser.sin_port = htons(atoi(argv[2]));//port转网络字节
			ser.sin_addr.s_addr =inet_addr(argv[1]);//IP地址转网络字节
			int ret ;
			ret = bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
			if(ret ==-1)
			{
			perror("bind");
			return -1;
			}
			listen(sfd,10);//监听网路信号
			//接受远程计算机请求
			struct sockaddr_in cli;
			memset(&cli,0,sizeof(cli));
			int addrlen = sizeof(struct sockaddr);
			int new_fd = accept(sfd,(struct sockaddr*)&cli,&addrlen);
			if(new_fd==-1)
			{
			perror("accept");
			return -1;
			}
			printf("%s %d success connect\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
			char buf[512]={0};
			ret = recv(new_fd,buf,sizeof(buf),0);
			if(-1==ret)
			{
				perror("recv");
				return -1;
			}
			puts(buf);
			ret =send(new_fd,"hello",6,0);
			if(-1==ret)
			{
				perror("send");
				return -1;
			}
			close(new_fd);
			close(sfd);
			return 0;
}

