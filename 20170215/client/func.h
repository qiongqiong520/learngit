 ///
 /// @file    func.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-26 15:46:11
 ///
 
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/uio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

//进程池的数据结构
//
#define FILENAME "file"
typedef struct childdata{
	pid_t pid;
	int fdw;
	short busy;//标示子进程是否忙碌
}cdata,*pcdata;

typedef struct tdata{
	int len;//代表后面的真是数据长度
	char buf[1000];//火车车厢
}td,*ptd;

void make_child(pcdata,int);
void set_init(int,char*,char*);
void send_file(int);
void recv_n(int,char*,int);


