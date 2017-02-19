 ///
 /// @file    pthread_tcp_server.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 20:09:09
///
 
//tcp文件接受客户端
//

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
#include<fcntl.h>
#include<unistd.h>

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
		exit(0);
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
	int sfd,numbytes;
	char buf[1024],filename[FILE_MAX_LEN+1];
	char ip_addr[64];
	struct hosten *he;
	struct sockaddr_in taddr;
	int i = 0,len,total;
	unsigned short port;
	FILE *file = NULL;
	if(argc<2)
	{
		printf("need a server i\n");
		exit(0);
	}
	strncpy(ip_addr,argv[1],sizeof(ip_addr));
	port = DEFAULT_SVR_PORT;
	if(argc>=3)
	{
		port = (unsigned short)atoi(argv[2]);
	}
	//做域名解析（DNS）
	//he = gethostbyname(argv[1]);
	//第一步建立一个头层皮套接字
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket");
		return -1;
	}
	//第二步设置服务器地址和端口号2828
	//
	memset(&taddr,0,sizeof(taddr));
	taddr.sin_family = AF_INET;
	taddr.sin_port = htons(port);
	taddr.sin_addr.s_addr =inet_addr(ip_addr);
	//taddr.sin_addr =*((struct in_addr*)he->h_addr);
	printf("connect server %s:%d\n",ip_addr,port);
	//第三步：用connect和服务器建立链接，注意，这里没有使用本地端口，将由协议自动分配一个饿端口号
	if(connect(sfd,(struct sockaddr*)&taddr,sizeof(struct sockaddr))==-1)
	{
		perror("connect");
		return -1;
	}
	if(send(sfd,"hello",6,0)<0)
	{
		perror("send");
		return -1;
	}
	//接收文件名，为编成简单，假设前64 个字节固定是文件名，不足用0来填充
	total =0;
	while(total<FILE_MAX_LEN)
	{
		//接收buff长度，始终是未接受文件名剩下的长度
		len = recv(sfd,filename+total,(FILE_MAX_LEN-total),0);
		if(len<=0)
		{
			break;
		}
		total +=len;
	}
	//接收文件名出错
	if(total!=FILE_MAX_LEN)
	{
		perror("faileure file name");
		exit(3);
	}
	printf("recv file %s\n",filename);
	file = fopen(filename,"wb");
	if(file == NULL)
	{
		printf("create file %s failure ",filename);
		perror("fopen");
		exit(3);
	}
	//接收文件数据
	printf("recv begin\n");
	total =0;
	while(1)
	{
		len = recv(sfd,buf,sizeof(buf),0);
		if(len ==-1)
		{
			break;
		}
		total +=len;
		//写入本地文件
		fwrite(buf,1,len,file);
	}
	fclose(file);
	printf("recv file %s success total lenght %d\n",filename,total);
	//第六部关闭socket
	close(sfd);
	return 0;
}//备注读写大量文件时，通过下面的方法效率很高
/*
ssize_t readn(int fd,char *buf,int size)
//读大量内容
{
	char *pbuf=buf;
	int total ,nread;
	for(total = 0;total<size)
	{
		nread = read(fd,pbuf,size-total);
		if(nread==0)
			return total;
		if(nread == -1)
		{
			if(errno==EINTR)
				continue;
			else
				return -1;
		}
		total +=nread;
		pbuf += nread;
	}
	return total;
}
ssize_t writen(int fd,char *buf,int size)
{
	char *pbuf = buf;
	int total ,nwrite;
	for(total = 0;total<size;)
	{
		nwrite = write(fd,pbufmsize-total);
		if(nwrite<=0)
		{
			if(nwrite ==-1&&errno ==EINTR)
				continue;
			else
				return -1;
		}
		total+=nwrite;
		pbuf +=nwrite;
	}
	return total;
}
//3.调用fcntl将sockfd设置为非阻塞模式
//
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

	*/

