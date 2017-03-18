

#include "Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>

namespace wd
{

Socket::Socket(int sockfd)
	:sockfd_(sockfd)
{
}
    

void Socket::ready(const InetAddress & inetAddr)
{
 	 setReuseAddr(true);
	setReusePort(true);
	setKeepAlive(false);
	setTcpNoDelay(false);
	bindAddress(inetAddr);
	listen();
}

 Socket::~Socket()
{
	::close(sockfd_);
}
void Socket::bindAddress(const InetAddress &addr)
{
	
     if(::bind(sockfd_, (struct sockaddr*)addr.getSockAddrInet(), sizeof(addr)) == -1)
    {
         fprintf(stderr, "bind address error\n");
        exit(EXIT_FAILURE);
    }
}

void Socket::listen()
{
    if(::listen(sockfd_, SOMAXCONN) == -1)
    {
        fprintf(stderr, "listen address error\n");
        exit(EXIT_FAILURE);
    }
}

int Socket::accept()
{
    int fd = ::accept(sockfd_, NULL, NULL);
    if(fd == -1)
    {
        fprintf(stderr, "accept error\n");
        exit(EXIT_FAILURE);
    }
    return fd;
}

void Socket::shutdownWrite()
{
    if(::shutdown(sockfd_, SHUT_WR) == -1)
    {
        fprintf(stderr, "shutdown error\n");
        exit(EXIT_FAILURE);
    }
}

void Socket::setTcpNoDelay(bool on)
{
 	int optval =on?1:0;
	if(::setsockopt(sockfd_,
				IPPROTO_TCP,
				TCP_NODELAY,
				&optval,static_cast<socklen_t>(sizeof optval))==-1)
	{
		fprintf(stderr,"setTcpNoDelay error\n");
		exit(EXIT_FAILURE);
	}
}
void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;
    if(::setsockopt(sockfd_, 
                 SOL_SOCKET, 
                 SO_REUSEADDR,
                 &optval, 
                 static_cast<socklen_t>(sizeof optval)) == -1)
    {
        fprintf(stderr, "setReuseAddr error\n");
        exit(EXIT_FAILURE);
    }
}

void Socket::setReusePort(bool on)
{
#ifdef SO_REUSEPORT//该内容被定义则执行之后的内容，否则执行else的内容
     int optval = on ? 1 : 0;
    int ret = ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT,
                         &optval, static_cast<socklen_t>(sizeof optval));
    if (ret < 0)
    {
        fprintf(stderr, "setReusePort error\n");
        exit(EXIT_FAILURE);
    }
#else
    if (on)
    {
        fprintf(stderr, "SO_REUSEPORT is not supported.\n");
    }
#endif
}
void Socket::setKeepAlive(bool on)
{
	int optval =on?1:0;
	if(::setsockopt(sockfd_,
				SOL_SOCKET,
				SO_KEEPALIVE,
				&optval,
				static_cast<socklen_t>(sizeof optval))==-1)
	{
		fprintf(stderr,"setKeepAlive error\n");
		exit(EXIT_FAILURE);
	}
}

//static
InetAddress Socket::getLocalAddr(int sockfd)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof addr;
    if(::getsockname(sockfd, (struct sockaddr*)&addr, &len) == -1)
    {
         fprintf(stderr, "getLocalAddress\n");
        exit(EXIT_FAILURE);
    }
    return InetAddress(addr);
}

InetAddress Socket::getPeerAddr(int sockfd)
{
     struct sockaddr_in addr;
    socklen_t len = sizeof addr;//运算符运算对象的第二种形式,返回的是表达式结果类型的大小，并不实际计算运算对象值的大小
    if(::getpeername(sockfd, (struct sockaddr*)&addr, &len) == -1)
    {
         fprintf(stderr, "getPeerAddr ess\n");
        exit(EXIT_FAILURE);
    }
    return InetAddress(addr);
}

}//end namespace wd
