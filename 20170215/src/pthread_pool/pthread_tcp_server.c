 ///
 /// @file    pthread_tcp_server.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 20:09:09
///
 
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<pthread.h>
#include<sys/socket.h>

#define DEFAULT_SVR_PORT 2828
#define FILE_MAX_LEN 64
char filename[FILE_MAX_LEN+1];

static void* handle_client(void * arg)
{
	int sock = (int)arg;
	char buff[1024];
	int len;
	printf("begin send\n");
	FILE* file=fopen(filename,"r");
	if(file ==NULL)
	{
		close(sock);
		exit;
	}
	//发文件名
	if(send(sock,filename,FILE_MAX_LEN,0)==-1)
	{
		perror("send file name\n");
		goto EXIT_THREAD;
	}

	printf("begin send file %s..\n",filename);

	//发文件名
	while(!feof(file))
	{
		len = fread(buff,1,sizeof(buff),file);
		printf("server read %s,len %d\n",filename,len);
		if(send(sock,buff,len,0)<0)
		{
			perror("send file");
			goto EXIT_THREAD;
		}
	}
EXIT_THREAD:
	if(file)
		fclose(file);
	close(sock);
}

int main(int argc,char* argv[])
{
	int sfd,new_fd;
	//定义两个ipv4地址
	struct sockaddr_in maddr,taddr;
	int sin_size,numbytes;
	pthread_t cli;
	unsigned short port;
	if(argc<2)
	{
		printf("need a filename without path\n");
		exit;
	}
	strncpy(filename,argv[1],FILE_MAX_LEN);
	port =DEFAULT_SVR_PORT;
if(argc>=3)
	{
		port = (unsigned short)atoi(argv[2]);//传输网络端口号转网络字节
	}
	//第一步，建立tcp套接字scoket
	//af_inet ip通讯
	//sock_stream   tcp
	if((sfd =socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	///第二步设置监听端口
	//初始化结构体，并绑定2828 端口
	memset(&maddr,0,sizeof(maddr));
	maddr.sin_family =AF_INET;
	maddr.sin_port = htons(port);
	maddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sfd,(struct sockaddr*)&maddr,sizeof(struct sockaddr))==-1)
	{
		perror("bind");
		goto EXIT_MAIN;
	}
	if(listen(sfd,10)==-1)
	{
		perror("listen");
		goto EXIT_MAIN;
	}
	printf("#@listen port%d\n",port);
	//第五步，循环与客户端通讯
	while(1)
	{
		sin_size = sizeof(struct sockaddr_in);
		printf("server waiting..\n");
		//如果有客户端链接，将产生一个权限的套接字
		if(new_fd=accept(sfd,(struct sockaddr*)&taddr,&sin_size)==-1)
		{
			perror("accept");
			goto EXIT_MAIN;
		}
		printf("--client(ip=%s:port= %d)request\n",inet_ntoa(taddr.sin_port));
		//生成一个线程来完成和客户端的会话，父进程继续监听
		pthread_create(&cli,NULL,handle_client,(void*)new_fd);
	}
	//第六部关闭socket
EXIT_MAIN:
	close(socket);
	return 0;
}

	
