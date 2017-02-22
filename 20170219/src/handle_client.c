 ///
 /// @file    handle_client.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 17:12:35
 ///
#include"func.h"

static void* hanfle_client(void* arg)
{
	int sock = (int)arg;
	char buff[1024];
	int len;
	printf("begin send\n");
	FILE* file = fopen(fiename,"r");
	if(file ==NULL)
	{
		close(sock);
		exit(-1);
	}
	//发文件名
	//
	if(send(sock,filename,FILEN_MAX_LEN,0)==-1)
	{
		perror("send file name\n");
		goto EXIT_THREAD;
	}
	printf("begin send file%s\n",filename);
	//发文件内容
	while(!feof(file))
	{
		len =fread(buff,1,sizeof(buff),file);
		printf("server read %s,len%d\n",filename,len);
		if(send
