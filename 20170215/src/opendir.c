///
/// @file    opendir.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-19 09:48:09
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	DIR *dir;
	dir=opendir(argv[1]);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *p;
	off_t pos;
	while((p=readdir(dir))!=NULL)
	{
		if(!strcmp(p->d_name,"opendir1.c"))
		{
			pos=telldir(dir);//读到a.out文件后，记录当时的位置
			if(-1==pos)
			{
				perror("dir");
				return -1;
			}
		}
		printf("%10s\n",p->d_name);	
	}
	rewinddir(dir);//回到目录开头
	p=readdir(dir);
	printf("%10s\n",p->d_name);//实现ls功能打印目录
	seekdir(dir,pos);
	p=readdir(dir);
	printf("%10s\n",p->d_name);
	closedir(dir);
	return 0;
}

