///
/// @file    set_init.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-18 21:55:08
///

#include "normal.h"

void set_init(int sfd,char* ip,char* port)
{
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(port));//port转网络字节序
	ser.sin_addr.s_addr=inet_addr(ip);//IP地址转网络字节序
	int ret;
	ret=bind(sfd,(struct sockaddr*)&ser,sizeof(ser));//绑定ip地址和端口号
	if(-1==ret)
	{
		perror("bind");
		return; 
	}
}

