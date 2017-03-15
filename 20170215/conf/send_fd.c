///
/// @file    send_fd.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-26 18:24:19
///

#include "func.h"

void send_fd(int fdw,int fd)
{
	s truct msghdr msg;
	memset(&msg,0,sizeof(msg));
	char buf[10]="hello";
	char buf1[10]=" world";
	struct iovec iov[2];
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=6;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr *)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	*(int*)CMSG_DATA(cmsg)=fd;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=sendmsg(fdw,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return;
	}
}		

void recv_fd(int fdr,int* fd)
{
	struct msghdr msg;
	memset(&msg,0,sizeof(msg));
	char buf[10]="hello";
	char buf1[10]=" world";
	struct iovec iov[2];
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=6;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr *)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=recvmsg(fdr,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return;
	}
	*fd=*(int*)CMSG_DATA(cmsg);
}		

void unlink(inf new_fd)
{
	if(-1==unlink(new_fd))
	{
		perror("unlink");
		return -1;
	}
	return new_fd;
}

 void  cd_d(char** path,char* new_fd)
{
	char buf[50]={0};
	char *p;
	if(-1==chdir(new_fd))
	{
		perror("chdir");
		return -1;
	}
	printf("path = %s\n",getcwd(NULL,0));
	return new_fd;
}

void ls_d(int new_fd)
{
	DIR *dir;
	dir = opendir(new_fd);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *p;
	off_t pos;
	while((p=readdir(dir))!=NULL)
	{
		if(!strcmp(p->d_name,"opendir"))
		{
			pos = telldir(dir);//读到a.out文件后，记录当时的位置
			if(-1==pos)
			{
				perror("telldir");
				return -1;
			}
			printf("inode = %ld,len=%d,type=%d,%s\n",p->d_ino,p->d_reclen,p->type,p->d_name);
		}
	}
		//rewinddir(dir);//回到目录开头
		//p =readdir(dir);
			//printf("inode = %ld,len=%d,type=%d,%s\n",p->d_ino,p->d_reclen,p->type,p->d_name);
		seekdir(dir,pos);
		p =readdir(dir);
closefd(dir);
return 0;
}
