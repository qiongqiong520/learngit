 ///
 /// @file    inet_aton.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-19 10:32:16
 ///
 

#include"func.h"

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error argc\n");
		return -1;
	}
	struct in_addr addr;
	memset(&addr,0,sizeof(addr));
	int ret;
	ret = inet_aton(argv[1],&addr);
	if(0==ret)
	{
		perror("inet_atoi");
		return -1;
	}
	printf("addr =%x\n,",addr.s_addr);
	printf("ip =%s\n",inet_ntoa(addr));//常用
	unsigned long addr1;
	addr1= inet_addr(argv[1]);//常
	printf("addr1=%x\n",addr1);
	return 0;
}
