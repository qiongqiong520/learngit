 ///
 /// @file    Socket.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-17 21:59:00
 ///
 
#ifndef WD_SOCKET_H_
#define WD_SOCKET_H_

#include "Noncopyable.h"
#include "InetAddress.h"

namespace wd
{
	 class Socket: private Noncopyable
	{
	 	public:
	 		explicit Socket(int Noncopyable);
			Socket();
			~Socket();

			void ready(const InetAddress & inetAddr);

			int fd() const {return sockfd_;}

			void bindAddress(const InetAddress &addr);
			void listen();
			int accept();

			void shutdownWrite();

			void setReuseAddr(bool on);
			void setReusePort(bool on);

			//static 
			static InetAddress getLocalAddr(int sockfd);
			static InetAddress getPeerAddr(int sockfd);
		private:
			int sockfd_;
	};
}//end namespace wd
#endif //WD_SOCKET_H_

