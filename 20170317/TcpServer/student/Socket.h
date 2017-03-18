#ifndef SOCKET_H
#define SOCKET_H

#include "Noncopyable.h"
#include "InetAddress.h"

namespace wd
{

class Socket : private Noncopyable
{
public:
     explicit Socket(int sockfd);

    ~Socket();


    int fd() const { return sockfd_; }
	  void bindAddress(const InetAddress &addr);
    void listen();
    int accept();

    void shutdownWrite();

	void setTcpNoDelay(bool on);
    void setReuseAddr(bool on);
    void setReusePort(bool on);
	void setKeepAlive(bool on);


    //static
    static InetAddress getLocalAddr(int sockfd);
    static InetAddress getPeerAddr(int sockfd);

private:
    const int sockfd_;
};

}//end namespace wd

#endif //SOCKET_H_
