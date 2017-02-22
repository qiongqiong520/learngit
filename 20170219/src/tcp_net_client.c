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

	int sfd =tcp_connect(argv[1],atoi(argv[2]));//或int sfd =tcp_init("192,168.0.164",8888);
	char buf[512]={0};
	if(-1==send(sfd,"hello",6,0))//向sfd服务器端发送数据
	{
		perror("send");
		close(sfd);
		exit(-1);
	}
	if(-1== recv(sfd,buf,sizeof(buf),0))//从sfd服务端接收数据
	{
		perror("send");
		close(sfd);
		exit(-1);
	}
	puts(buf);
	close(sfd);
}
