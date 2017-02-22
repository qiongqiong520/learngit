//
/// @file    tcp_net_client.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-19 17:44:44
///

#include"tcp_net_socket.h"

int main(int argc,char* argv[])
{
	if(argc<3)
	{
		printf("usage:./serveretcp ip port\n");
		exit(-1);
	}
	signalhandler();
	int sfd =tcp_init(argv[1],atoi(argv[2]));//或int sfd =tcp_init("192,168.0.164",8888);
	int fd =0;
	char buf[512]={0};
	fd_set rdset;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(sfd,&rdset);
		if(select(MAXCLIENT+1,&rdset,NULL,NULL,NULL)<0)
			continue;
		for(fd =0;fd<MAXCLIENT;fd++)
		{
			if(FD_ISSET(fd,&rdset))
			{
				if(fd ==sfd)
				{

					int cfd = tcp_accept(sfd);
					printf("-->accept %d\n", cfd);
					send(cfd, "welcome", 8, 0);
					FD_SET(cfd,&rdset);
				}else{
					bzero(buf,sizeof(buf));
					if(recv(fd,buf,sizeof(buf),0)==-1)//从cfd客户端接受数据存于buf中
					{
						perror("recv");
						close(fd);
						close(sfd);
						exit(-1);
					}
					puts(buf);
					if(send(fd,"hello world",12,0)==-1)//从buf中取向客户端发送数据
					{
						perror("send");
						close(fd);
						close(sfd);
						exit(-1);
					}
					//FD_CLR(fd,&rdset);
				}
			}
		}
	}
		
			close(sfd);
}
