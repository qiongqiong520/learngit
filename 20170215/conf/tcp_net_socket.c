 ///
 /// @file    tcp_net_socket.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 17:25:09
 ///
 

#include"tcp_net_socket.h"

int tcp_init(const char* ip,int port)
{
	//用于初始化操作
	int sfd=socket(AF_INET,SOCK_STREAM,0);//首先创建一个socket，详向系统申请
	if(sfd==-1)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family =AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip);//或inaddr——any
	if(bind(sfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1)
	{
		perror("bind");
		close(sfd);
		exit(-1);
	}
	if(listen(sfd,10)==-1)//监听并设置允许的最大连接数为10
	{
		perror("listen");
		close(sfd);
		exit(-1);
	}
	return sfd;
}

int tcp_accept(int sfd)
{
	//用于服务器端的接收
	struct sockaddr_in clientaddr;
	memset(&clientaddr,0,sizeof(clientaddr));
	int addrlen =sizeof(clientaddr);
	int new_fd = accept(sfd,(struct sockaddr*)&clientaddr,(unsigned int*)&addrlen);
	if(-1==new_fd)
	{
		perror("accept");
		close(sfd);
		exit(-1);
	}
	printf("%s %d success connect..\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
	return new_fd;
}
int tcp_connect(const char* ip,int port)//用于客户端连接
{
	int sfd =socket(AF_INET,SOCK_STREAM,0);//向系统注册申请新的soxket
	if(sfd==-1)
	{
		perror("socket");
		close(sfd);
		exit(-1);
	}
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family =AF_INET;
	serveraddr.sin_port =htons(port);
	serveraddr.sin_addr.s_addr =inet_addr(ip);
	if(connect(sfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1)
	{
		perror("connect");
		close(sfd);
		exit(-1);
	}
	close(sfd);
	return sfd;
}

void signalhandler(void)//用于信号处理，让服务器端在按下ctrl+c或ctrl+|的时候不会退出
{
	sigset_t sigSet;
	sigemptyset(&sigSet);
	sigaddset(&sigSet,SIGINT);
	sigaddset(&sigSet,SIGQUIT);
	sigprocmask(SIG_BLOCK,&sigSet,NULL);
}
	
