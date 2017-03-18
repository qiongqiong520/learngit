 ///
 /// @file    TcpServer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-18 21:11:34
 //
 //
#include "TcpServer.h"
#include<stdlib.h>
namespace 
{
	int createSockerFd()
	{
		int fd=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(fd ==-1)
	{
		fprintf(stderr,"create socket fd errno\n");
		exit(EXIT_FAILURE);
	}
	return fd;
	}
}

namespace wd
{
	TcpServer::TcpServer(const string &ip,unsigned short port)
		:_addr(ip,port)
		 ,sockfd_(createSockerFd())
		 ,poller_(sockfd_.fd())
	{
	}
