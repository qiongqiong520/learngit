 ///
 /// @file    tcp_Server.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-22 11:44:30
 ///
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdarg.h>
#include<string.h>
#include<errno.h>
#include<netdb.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include"etcp.h"
#include"skel.h"

void set_address(char *host,char *port,
		struct sockaddr_in *sap,char * protocl);
void  error(int status,int err,char *format)
{
	va_list ap;
	va_start(ap,fmt);
	fprintf(stderr,"%s:",program_name);
	vfprintf(stderr,fmt,ap);
	va_end(ap);
	if(err)
	fprintf(stderr,":%s(%d)\n",strerror(err),err);
	if(status)
		EXIT(status);
	
}

char *pragram_name;

int main(int argc,char **argv)
{
	struct sockaddr_in local;
	struct sockaddr_in peer;
	char *hname;
	char *sname;
	int peerlen;
	SOCKET s1;
	SOCKEt s;
	const int on=1;
	INIT();

	if(argc==2)
	{
		hname =NULL;
			sname =argv[1];
	}
	else
	{
		hname =argv[1];
		sname =argv[2];
	}
	set_address(hname,sname,&local,"tcp");
	s =socket(AF_INET,SOCK_STREAM,0);
	if(!isvalidsock(s))
		error(1,errno,"socket call failed");
	if(setsocketop(s,SOL_SOCKET,SO_REUSEADDR,&on
		,	sizeof(on)))
		error(1,errno,"setsocketop failed");
	if(bind(s,(struct socketaddr*)&local,
				sizeof(local)))
		error(1errno,"bind failed");
	if(listen(s,NLISTEN))
		error(1,errno,"lissten failed");
	do{
		peerlen =sizeof(peer);
		s1=accept(s,(struct sockaddr*)&peer,&peerlen);
		if(!isvalidsock(s1))
			error(1,errno,"accept failed");
		server(s1,&peer);
		CLOSE(s1);
	}while(1);
	EXIT(0);
}
