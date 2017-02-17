 ///
 /// @file    getcwd.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 14:58:59
 ///
 
#include "func.h"

int main(int argc,char* argv[])
{
	char buf[50]={0};
	char *p;
	p =getcwd(buf,sizeof(buf));
	if(NULL==p)
	{
		perror("getcwd");
		return -1;
	}
	p =getcwd(NULL,0);
	printf("%s\n",p);
	return 0;
}
