 ///
 /// @file    ntohs.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 10:26:09
 ///
 

#include "func.h"
//端口号主机字节序转网络字节序，网络字节序转主机字节序

int main(int argc,char* argv[])
{
	int port=0x1234;
	int nport;
	nport =htons(port);
	printf("nport =%x\n",nport);
	int hport;
	hport = ntohs(nport);
	printf("hport = %x\n",hport);
	return 0;
}
