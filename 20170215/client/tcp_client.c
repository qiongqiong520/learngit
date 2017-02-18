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

	memset(&ser,0,sizeof(ser));
	ser.sin_family =AF_INET;
	ser.sin_port = htons(atoi(argv[2]));
	ser.sin_addr.s_addr =inet_addr(argv[1]);
	int new_fd;
	 ret =connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	char buf[512]={0};
	ret=send(new_fd,"hello",6,0);
	if(-1==ret)
	{
		perror("send");
		return -1;
	}
	ret =recv(new_fd,buf,sizeof(buf),0);
	if(-1==ret)
	{
		perror("recv");
		return -1;
	}
	close(new_fd);
	close(sfd);
	return 0;
}
