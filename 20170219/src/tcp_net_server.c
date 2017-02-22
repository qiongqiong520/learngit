 ///
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
	while(1)
	{
		int cfd = tcp_accept(sfd);
		char buf[512]={0};
		if(recv(cfd,buf,sizeof(buf),0)==-1)//从cfd客户端接受数据存于buf中
		{
			perror("recv");
			close(cfd);
			close(sfd);
			exit(-1);
		}
		puts(buf);
		if(send(cfd,"hello world",12,0)==-1)//从buf中取向客户端发送数据
		{
			perror("send");
			close(cfd);
			close(sfd);
			exit(-1);
		}
		close(cfd);
	}
	close(sfd);
}



