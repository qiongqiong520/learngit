 ///
 /// @file    pool_n.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-18 15:14:29
 ///
 

#include"func.h"

void send_n(int fd,char* buf,int len)
{
	int total =0;
	int pos;
	while(total<len)
	{
		pos = send(fd,buf+total,len-total,0);
		total =total+pos;
	}
}
void recv_n(int fd,char* buf,int len)
{
	int total =0;
	int pos ; 
	while(total<len)
	{
		pos= recv(fd,buf+total,len-total,0);
		total = total +pos;
	}
}
