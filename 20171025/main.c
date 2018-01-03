 ///
 /// @file    main.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-10-25 13:41:48
 ///
#include<signal.h>
#include<unistd.h>
#include<stdio.h>

#define BUFFER_SIZE 50
char buffer[BUFFER_SIZE];

/*信号处理函数*/
void handle_SIGINT()
{
	write(STDOUT_FILENO,buffer,strlen(buffer));
	exit(0);
}
int main(int argc,char *argv[])
{
	//创建喜好处理器
	struct sigaction handler;
	handler.sa_handler = handle_SIGINT;
	sigaction(SIGINT,&handler,NULL);
	//生成输出消息
	strcpy(buffer,"Caught Control C\n");
	//循环运行，直至接收到
	while(1)
		;
	return 0;
}
