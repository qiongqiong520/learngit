 ///
 /// @file    opendir.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 16:22:50
 ///
 

#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	DIR *dir;
	dir = opendir(argv[1]);
	if((DIR*)NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *p;
	off_t pos;
	while((p=readdir(dir))!=NULL)
	{
		if(!strcmp(p->d_name,"opendir.c")
		{
		pos=telldir(dir);//读到a.out文件后，记录当前位置
		if(-1==pos)
		{
		perror("telldir");
		return -1;
		}
		}
		printf("indoe = %ld len =%d type = %s\n",p->d_ino,p->reclen,p->d_type,

