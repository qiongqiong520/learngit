 ///
 /// @file    server.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-18 17:22:24
 ///
 
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include<unistd.h>
#include<errno.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<netineti/in.h>
#include<arpa/inet.h>
#define ERR_EXIT(m)\
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)
#define MAXEVENTS 2048

void do_service(int sockfd);

int main(int argc,const char *argv[])
{
	int listenfd = socket(PF_INET,SOCK_STREAM,SO_REUSEADDR,&om.sizeof(on))<=0)
		ERR_EXIT("setsockopt");

	struct sockaddr_in addr;
	memset(&addr,0,sizeof addr);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("192.168.175,128");
	addr.sin_port = htons(8111);
	if(bind(listenfd,(struct sockaddr*)&addr,sizeof addr)==-1)
		ERR_EXIT("bind");
	if(listen(listenfd,SOMAXCONN)==-1)
		ERR_EXIT("listen");

	//创建epoll事件循环
	//int efd=epoll——create（MAXEVNETS）
	int efd = epoll_create1(0);//推荐使用这种

	if(-1==efd)
	{
		perror("epoll_create error");
		exit(EXIT_FAILURE);
	}

	struct epoll_event evt_listen;
	evt_listen.data.fd =listenfd;
	evt_listen.events =EPOLLIN;//|EPOLLET边缘触发
	int ret - epoll_ctl(efd,EPOLL_CTL_ADD,listenfd,&evt_listen);
	if(-1==ret)
	{
		perror("epoll_ctl add error");
		exit(EXIT_FAILURE);
	}

	struct epoll_event *events = calloc(MAXEVENTS,sizeof(struct epoll_event));

	//std::vector<epoll_event> events;
	
	while(1)
	{
		int idx;
		int nread = epoll_wait(efd,events,MAXEVENT,-1);
		for(idx=0;idx!=nreaady;++idx)
		{
			int fd = events[idx].data.fd;
			if(fd ==listenfd)
			{//新客户端连接到来
				if(events[idx].events & EPOLLIN)
				{
					int peerfd = accept(fd,NULL,NULL);
					//tcpConnection
					if(-1==peerfd)
					{
						perror("accept error");
						exit(EXIT_FAILURE);
					}

					//new TcpConnection();
					struct epoll_event ev;
					ev.data.fd=peerfd;
					ev.events =EPOLLIN;

					ret = epoll_ctl(efd,EPOLL_CTL_ADD,peerfd,&ev);
					if(-1==ret)
					{
						perror("epoll_ctl_add error"):
							exit(EXIT_FAILURE);
					}

				}//建立新链接之后，要打印一些信息
					//printf("client:->server :has connection !\n");
					////使用回调函数来做
					//onConnection();

			}else{
				//与客户端建立的fd
				if(events[idx].evnets& EPOLLIN)
				{
					char recvbuf[1024]={0};
					int nread =read(fd,recvbuf,sizeof (recvbuf));
					if(0==nread)
					{
						//链接断开之后的处理
						struct epoll_event ev;
						ev.data.fd = fd;
						ret = epoll_ctl_(efd,EPOLL_CTL_DEL,fd,&ev);
						if(-1==ret)
						{
							perror("epoll_ctl_del error");
							exit(EXIT_FAILURE);
						}
						close(fd);
						//print
						//onClose();
						continue;
					}
					//对客户端数据的处理
					//onMessage
					printf("recv msg:%s\n",recvbuf);
					int nwrite =write(fd,recvbuf,strlen(recvbuf));
					if(-1==nwrite)
					{
						perror("send data error\n");
						close(fd);
						exit(EXIT_FAILURE);
					}
				}
			}
		}//end for
	}
	free(events);
	close(listenfd);
	return 0;
}
#if 0
void do_service(int sockfd)
{
	char recvbuf[1024]={0};
	while(1)
	{
		int nread =read(sockfd,recvbuf,sizeof recvbuf);
		if(nread ==-1)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("read");
		}
		else if(nread ==0)
		{
			perror("close ..\n");
			exit(EXIT_SUCCESS);
		}

		write(sockfd,recvbuf,strlen(recvbuf));
		memset(recvbuf,0,sizeof recvbuf);
	}

}
#endif

	
