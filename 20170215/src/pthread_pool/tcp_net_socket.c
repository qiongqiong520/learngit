#include "tcp_net_socket.h"

int tcp_init(const char* ip,int port)
{
	int sfd =socket(AF_INET<SOCK_STREAM,0);
	if(sfd ==-1)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family =AF_INET:
		ser.sin_port = htons(atoi(argv[2]));
	ser.sin_addr.s_addr = inet_addr(argv[1]);
	int ret ;
	ret =bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("socket");
		return -1;
	}
	listen(sfd,10);
	return sfd;
}

int tcp_accept(int sfd)
{
	struct sockaddr_in cli;
	memset(&cli,0,sizeof(cli));
	int addrlen = sizeof(struct sockaddr);
	int new_fd = accept(sfd,(struct sockaddr*)&cli,&addrlen);
	if(new_fd==-1)
	{
		perror("accept");
		return -1;
	}
	printf("%s %d success connect..\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
	return new_fd;
}

in tcp_connect(const char* ip,int port)
{
int sfd = socket(AF_INET,SOCK_STREAM,0);
if(sfd == -1)
{
perror("socket");
return -1;
}
struct sockaddr_in ser;
memset(&ser,0,sizeof(struct sockaddr));
ser.sin_family = AF_INET;
ser.sin_port = htons(port);
ser.sin_addr.s_addr = inet_addr(ip);
if(connect(sfd,(struct sockaddr*)&ser,&addrlen)==-1)
{
	perror("connect");
	return -1;
}
