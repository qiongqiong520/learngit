#include "func.h"

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd =socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family =AF_INET;
	ser.sin_addr.s_addr =inet_addr(argv[2]);//port 转网络字节
	ser.sin_port = htons(atoi(argv[1]));//ip地址转网路字节
	int ret;
	ret= bind(sfd,(struct sockaddr*)&ser,sizeof(ser));//绑定IP地址和端口号
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	listen(sfd,10);
	struct sockaddr_in cli;
	memset(&cli,0,sizeof(cli));
	int new_fd;
	int addrlen =sizeof(cli);
	new_fd = accept(sfd,(struct sockaddr*)&cli,&addrlen);
	if(-1==new_fd)
	{
		perror("accpet");return -1;
	}
	printf("client i =%s,client port = %d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
	char buf[20]={0};
	ret =recv(new_fd,buf,sizeof(buf),0);
	if(-1==ret)
	{
	perror("recv");
	return -1;
	}
	printf("%s\n",buf);
	ret =send(new_fd,"i am server",11,0);
	if(-1==ret)
	{
		perror("send");
		return -1;
	}
	close(new_fd);
	close(sfd);
	return 0;
}
