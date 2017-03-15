 ///
 /// @file    tcp_net_client.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 17:44:44
 ///
 
#include"func.h"

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		exit(-1);
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket"); 
		exit(-1);
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));//port转网络字节
	ser.sin_addr.s_addr =inet_addr(argv[1]);//ip地址转网络字节序
	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("connect");
		exit(-1);
	}
	char buf[100]={0};
	int len;
	recv_n(sfd,buf,len);
	int fd;
	fd =open(buf,O_RDWR|O_CREAT,0666);
	if(-1==fd)
	{ 
	 	perror("open");
		exit(-1);
	}
	while(1)
	{
		recv_n(sfd,(char*)&len,4);
		memset(buf,0,sizeof(buf));
		if(len>0)
		{
			recv_n(sfd,buf,len);
	 		write(fd,buf,len);
		}else{
			break;
	 	}
	} 
	close(fd);
	close(sfd);
}
