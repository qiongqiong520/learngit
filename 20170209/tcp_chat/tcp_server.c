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
	ser.sin_addr.s_addr =inet_addr(argv[1]);//port 转网络字节
	ser.sin_port = htons(atoi(argv[2]));//ip地址转网路字节
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
	char buf[50]={0};
	fd_set rdset,tmpset;
	int new_fd=-1;
	FD_ZERO(&tmpset);
	FD_SET(STDIN_FILENO,&tmpset);
	FD_SET(sfd,&tmpset);
	while(1)
	{
		FD_ZERO(&rdset);//青空集合
		memcpy(&rdset,&tmpset,sizeof(fd_set));
		ret = select(13,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(STDIN_FILENO,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret = read(0,buf,sizeof(buf));
				if(ret<=0)
				{
					printf("byebye\n");
					break;
				}
				ret = send(sfd,buf,strlen(buf)-1,0);
				if(-1==ret)
				{
					perror("send");
					return -1;
				}
			}
			if(FD_ISSET(sfd,&rdset)){
				memset(buf,0,sizeof(buf));
				ret = recv(sfd,buf,sizeof(buf),0);
				if(-1==ret)
				{
					perror("recv");
					return -1;
					}else if(0==ret)
					{
					printf("byebye\n");
					 break;
					}
					printf("%s\n",buf);
					}
		}
	
}		
	close(sfd);
	return 0;
}
