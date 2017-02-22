 ///
 /// @file    salt.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 21:19:24
 ///
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<shadow.h>
#include<errno.h>

void help(void)
{
	printf("用户密码眼眨鞥程序\n第一个参数为用户名!\n");
	exit(-1);
}

void errno_quit(char *msg)
{
	perror(msg);
	exit(-2);
}

void get_salt(char *salt,char *passwd)
{
	int i,j;
	//取出salt，记录密码自负下表，记录\出现次数
	
	for(i =0.j=0;passwd[i]&&j!=3;++i)
	{
		if(passwd[i]='$')
			++j;
	}
	strcpy(salt,passwd,i-1);
}

int main(void)
{
	struct spwd *sp;
	char *passwd;
	char salt[512]={0};

	if(argc!=2)
		help();

	//输入用户名密码
	passwd =getpass("请输入密码");
	//得到用户名和密码，命令行参数的第一个参数为用户名
	if(sp==getspnam(argv[1])==NULL)
		error_quit(salt,sp->sp_pwdp);

	//进行密码验证
	if(strcmp(sp->swdp,crypt(passwd,salt))==0)
		printf("验证通过!\n");
	else{
		printf("验证失败\n");

		return 0;
	}
