 ///
 /// @file    tcpclient.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-22 14:10:24
 ///
#include<stdio.h>
#include"etcp.h"
#include <iostream>
using std::cout;
using std::endl;
int readn(SOCKET s,char *buf,size_t len);
int readvrec(SOCKET fd,char *bp,size_t len);
int main(int argc,char **argv)
{	struct sockaddr_in peer;
	SOCKET s;
	INIT ();
	set_address(argv[1],argv[2],&peer,"tcp");
	s= socket(AF_INET,SOCK_STREAM,0);
	if(!isvalidsock(s))
		error(1,errno,"socket call failed");
	if(connect(s,(struct sockaddr *)&peer,
				sizeof(peer)))
		error(1,errno,"connect failed");
	client(s,&peer);
	EXIT(0);
}
