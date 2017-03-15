 ///
 /// @file    atoi.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-26 17:39:12
 ///
 //将百度的www.baidu.com转换成ip地址
 //
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#include<stdio.h>

int main(int argc,char* argv[])
{
	char *ptr,**pptr;
	struct hostent *hptr;
	char str[32]={'\0'};
	//*取得命令后的第一个参数，既要解析的域名和主机名
	ptr = argv[1];
	//调用gethostbyname（）,结果存在hptr中
	if((hptr =gethostbyname(ptr))==NULL)
	{
		printf("gethostbyname error for host :%s\n",ptr);
		return 0;
	}
	//将主机的规范名打出来
	printf("offical hostname :%s\n",hptr->h_name);
	//主机可能由多个别名，分别将别名都打出来
	for(pptr =hptr->h_aliases;*pptr!=NULL;pptr++)
	{
		printf("alias:%s\n",*pptr);
		//根据地址类型将地址打出来
		switch(hptr->h_addrtype){
			case AF_INET:
				case AF_INET6:
				pptr=hptr->h_addr_list;
				//将刚才得到的地址都打印出来，调用inet——ntop函数
				for(;*pptr!=NULL;pptr++)
					printf("address :%s\n",inet_ntop(hptr->h_addrtype,*pptr,str,sizeof(str)));
				printf("first address :%s\n",inet_ntop(hptr->h_addrtype,hptr->h_addr,str,sizeof(str)));
				break;
				default:
				printf("unknown address type\n");
				break;
		}
		return 0;
	}
}
