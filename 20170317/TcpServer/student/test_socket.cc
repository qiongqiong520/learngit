
#include "TcpServer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void onConnection(const wd::TcpConnectionPtr &conn)
{
	printf("%s\n",conn->toString().c_str());
	conn->send("hello,welcome to chat Server.\r\n");
}

void onMessage(const wd::TcpConnectionPtr &conn)
{
	std::string s(conn->receive());
	conn->send(s);
}

void onClose(const wd::TcpConnectionPtr &conn)
{
	printf("%s close\n",conn->toString().c_str());
}

int main(int argc, char const *argv[])
{

	 wd::TcpServer server("192.168.137.128",9999);

	server.setConnectCallback(&onConnection);
	server.setMessageCallback(&onMessage);
	server.setCloseCallback(&onClose);

	server.start();

	return 0;
}
    
