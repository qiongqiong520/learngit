 ///
 /// @file    server.conf.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 11:31:50
 ///
 
 //服务器端实现
 
#include "func.h"
void change_noblock(int fd)
{
	int status;
	status =fcntl(fd,F_GETFL);
	status = status(O_NONBLOCK);
	int ret = fcntl(fd,F_SETFL,status);
	if(-1==ret)
	{
		perror("fcntl");
		return ;
	}
}

int main(int argc ,char* argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;//文件描述符
	sfd =socket(AF_INET,SOCK_STREAM，0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));//结构体初始化，需要取地址符
	ser.sin_family =AF_INET;
	ser.sin_port = htons(atoi(argv[2]));//port端口转啊网络字节序
	ser.sin_addr.s_addr = inet_addr(argv[1]);//ip地址转网络端口号
	int ret ;
	ret =bind(sfd,(struct sockaddr*)&ser,sizeof(ser));//绑定网络端口号he ip
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	listen(sfd,10);
	int epfd = epoll_create(1);
	struct epoll_event event,evs[3];
	memset(&event,0.sizeof(event));
	event.events=EPOLLIN;//描述符是否可读
	event.data.fd = sfd;
	ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	if(-1==ret)
	{
		perror("epoll_ctl");
		return -1;
	}
	struct sockaddr_in cli;
	memset(&cli,0,sizeof(cli));
	char buf[5]={0};
	int new_fd =-1;
	int i;
	while(1)
	{
		memset(evs,0,sizeof(cli));
		char buf[50]={0};
		if(ret>0)
		{
				for(i=0;i<ret;i++)
				{
					if(evs[i].data.fd ==sfd)
					{
						int addrlen =sizeof(cli);
						new_fd = accept(sfd,(struct sockaddr*)&cli,&addrlen);
						if(-1==new_fd)
						{
							perror("accept");
							return -1;
						}
						printf("client ip=%s,client port = %d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
						change_noblock(new_fd);
						memset(&event,0,sizeof(event));
						event.events=EPOLLIN|EPOLLET;//描述符是否可读
						event.data.fd = new_fd;
						ret = epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&event);
					}
					if(evs[i].data.fd ==new_fd)
					{
						while(1)
						{
							memset(buf,0,sizeof(buf));
							ret =recv(new_fd,buf,sizeof(buf),0);
							if(-1==ret&&errno==EAGAIN)
							{
								break;//读空缓冲区
							}
							else if(0==ret)
							{
								printf("byebye");
								close(new_fd);
								memset(&event,0,sizeof(event));
								event.events =EPOLLIN;//描述符是否可读
								event.data.fd = new_fd;
								ret =epoll_ctl(epfd,EPOLL_CTL_DEL,new_fd,&event);
								break;
							}
							printf("%s\n",buf);
						}
						if(evs[i].events ==EPOLLIN&&evs[i].data.fd ==0)
							{
								memset(buf,0,sizeof(buf));
								ret = read(STDIN_FILENO,buf,sizeof(buf));
								if(ret <=0)
								{
									printf("byebye");
									close(new_fd);
									memset(&event,0,sizeof(event));
									event.events =EPOLLIN;//描述符是否可读
									event.data.fd = new_fd;
									ret =epoll_ctl(epfd,EPOLL_CTL_DEL,new_fd,&event);
									continue;
								}
								ret =send(new_fd.buf,strlen(buf)-1.0);
								if(-1==ret)
								{
									perror("send");
									return -1;
								}

							}
						}

				}
		}
		close(sfd);
		return 0;
				}

							

