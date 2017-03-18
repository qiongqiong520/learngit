 ///
 /// @file    TcpServer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-18 21:02:31
 ///
 
#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include"Noncopyable.h"
#include"EpollPoller.h"
#include"Socket.h"
#include"InetAddress.h"

using std::string;
namespace wd
{
	class TcpServer:Noncopyable
	{
		public:
		typedef EpollPoller::EpollCallback TcpServerCallback;

		TcpServer(const string &ip,unsigned int port);

		void start()
		{poller_.loop();}

		void setConnetCallback(TcpServerCallback cb)
		{
			poller_.setConnetCallback(std::move());
		}
		void setMessageCallback(TcpServerCallback cb)
		{
			poller_.setMessageCallback(std::move());
		}
		void setCloseCallbcak(TcpServerCallback cb)
		{
			poller_.setCloseCallbcak(std::move());
		}



		private:
		InetAddress _addr;
		Socket sockfd_;
		EpollPoller poller_;

	};
}
#endif //TCP_SERVER_H
