#include "EpollPoller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/eventfd.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

namespace
{
int createEpollFd()
{
    int epollfd = ::epoll_create1(0);
    if(epollfd == -1)
    {
        perror("create epoll fd error");
        exit(EXIT_FAILURE);
    }

    return epollfd;
}
int createEventfd()
{
	int fd=::eventfd(0,0);
	if(fd == -1)
	{
		perror("create eventfd error!");
	}
	return fd;
}
void addEpollReadFd(int epollfd, int fd)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN;
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) == -1)
    {
         perror("add epoll fd error");
        exit(EXIT_FAILURE);
    }
}

void delEpollReadFd(int epollfd, int fd)
{
    s truct epoll_event ev;
    ev.data.fd = fd;
    //ev.events = EPOLLIN;
    if(epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &ev) == -1)
    {
        perror("del epoll fd error");
        exit(EXIT_FAILURE);
    }
}

int acceptConnFd(int listenfd)
{
     int peerfd = ::accept(listenfd, NULL, NULL);
    if(peerfd == -1)
    {
         perror("accept conn fd");
        exit(EXIT_FAILURE);
    }
    return peerfd;
}

//预览数据
ssize_t recvPeek(int sockfd, void *buf, size_t len)
{
     int nread;
    do
    {
        nread = ::recv(sockfd, buf, len, MSG_PEEK);
    }
    while(nread == -1 && errno == EINTR);

    return nread;
}

//通过预览数据 判断conn是否关闭
bool isConnectionClosed(int sockfd)
{
     char buf[1024];
    ssize_t nread = recvPeek(sockfd, buf, sizeof buf);
    if(nread == -1)
    {
         perror("recvPeek");
        exit(EXIT_FAILURE);
    }

    return (nread == 0);
}
}//end anonymous namespace

namespace wd
{
EpollPoller::EpollPoller(int listenfd)
: epollfd_(createEpollFd()),
  listenfd_(listenfd),
	eventfd_(createEventfd()),
  isLooping_(false),
  events_(1024)
{
    addEpollReadFd(epollfd_, listenfd);
	addEpollReadFd(epollfd_,eventfd_);
}

EpollPoller::~EpollPoller()
{
    ::close(epollfd_);
}


void EpollPoller::waitEpollFd()
{
     int nready;
    do
    {
         nready = ::epoll_wait(epollfd_, 
                               &*events_.begin(), 
                              static_cast<int>(events_.size()), 
                              5000);
    }while(nready == -1 && errno == EINTR);
    
    if(nready == -1)
    {
         perror("epoll wait error");
        exit(EXIT_FAILURE);
    }
    else if(nready == 0)
    {
        printf("> epoll timeout.\n");
    }
    else
    {
        //当vector满时，扩充内存
        if(nready == static_cast<int>(events_.size()))
        {
            events_.resize(events_.size() * 2);
        }


        for(int ix = 0; ix != nready; ++ix)
        {
            if(events_[ix].data.fd == listenfd_)
            {
                 if(events_[ix].events & EPOLLIN)
                    handleConnection();
            }
            else if(events_[ix].data.fd==eventfd_)
            {
				//真正去发送数据
				handleRead();
				doPendingFunctors();
			}else
			{
                 if(events_[ix].events & EPOLLIN)
                    handleMessage(events_[ix].data.fd);
            }
        }
    }

}

void EpollPoller::handleRead()
{
	uint64_t buff=0;
	int ret =::read(eventfd_,&buff,sizeof(buff));
	if(ret!=sizeof(buff))
	{
		perror("read eventfd error");
	}
}

void EpollPoller::runInLoop(Function cb)
{
	{
		MutexLockGuard guard(mutex_);
		pendingFunctors_.push_back(cb);
	}
	wakeup();
}

void EpollPoller ::wakeup()
{
	uint64_t one =1;
	int ret =::write(eventfd_,&one,sizeof(one));
	if(ret!=sizeof(one))
	{
		perror("read eventfd error");
	}
}
void EpollPoller::doPendingFunctors()
{
	printf("\n> doPendingFunctors() \n");
	std::vector<Function>tmp;
	{
		MutexLockGuard guard(mutex_);
		tmp.swap(pendingFunctors_);
	}

	for(auto&func:tmp)//auto自动识别类型 
	{
		if(func)
			func();
	}
}
void EpollPoller::handleConnection()
{
    int peerfd = acceptConnFd(listenfd_);
    addEpollReadFd(epollfd_, peerfd);

    std::pair<ConnectionList::iterator, bool> ret;

    TcpConnectionPtr conn(new TcpConnection(peerfd,this));
    conn->setConnectCallback(onConnectCallback_);
    conn->setMessageCallback(onMessageCallback_);
    conn->setCloseCallback(onCloseCallback_);

    ret = lists_.insert(std::make_pair(peerfd, conn));
    assert(ret.second == true); //断言插入成功
    (void)ret; //消除ret 未使用的warning

    conn->handleConnectCallback();
}

void EpollPoller::handleMessage(int peerfd)
{
     bool isClosed = isConnectionClosed(peerfd);
    ConnectionList::iterator it = lists_.find(peerfd);
    assert(it != lists_.end());

    if(isClosed)
    {
         //调用conn的close事件handleCloseCalback
        it->second->handleCloseCallback();
        delEpollReadFd(epollfd_, peerfd);
        lists_.erase(it);
    }
    else
    {
        it->second->handleMessageCallback();
    }
}

void EpollPoller::loop()
{
     isLooping_ = true;

    while(isLooping_)
    {
        waitEpollFd();
    }

    printf("Loop quit safely\n");
}

void EpollPoller::unloop()
{
    isLooping_ = false;

}

}
