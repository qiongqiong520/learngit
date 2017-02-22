 ///
 /// @file    stat.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 09:33:15
 ///
 
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>

void stat(char* dirname)
{
	struct stat buf;
	DIR *dir;
	dir = opendir(dirname);
	if(NULL=dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *p;
	off_t pos;
	while((p=readdir(dir))!=NULL)
	{
		memset(&buf,0,sizeof(buf));
		int ret;
		ret= stat(p->d_name,&buf);
		if(-1==ret)
		{
			perror("stat");
			return -1;
		}
		printf("%10s\n",p->d_name);
	}
	return 0;
}
