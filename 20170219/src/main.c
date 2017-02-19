 ///
 /// @file    main.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-18 15:35:38
 ///
#include"factory.h"
void* threadfunc(void* p)
{
	pfac pf=(pfac)p;
	pque pq=&pf->que;
	pNode pn;//指向new——fd所存储的节点
	while(1)
	{
		pthread_mutex_lock(&pq->mutex);
		if(0==pq->size)
		{
			pthread_cond_wait(&pf->cond,&pq->mutex);//一旦队列为空，就睡觉
		}
		que_get(pq,&pn);
		pthread_mutex_unlock(&pq->mutex);
		send_file(pn->new_fd);
		free(pn);//不要把free放在锁之间，malloc 和free函数耗时太久
	}
}



int main(int argc,char* argv[])
{
	if(argc!=5)
	{
		printf("error args\n");
		return -1;
	}
	fac f;
	memset(&f,0,sizeof(f));//开始工厂数据初始化
	f.tnum = atoi(argv[3]);
	f.capibility = atoi(argv[4]);
	factory_init(&f,threadfunc);//数据初始化
	factory_start(&f);
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	set_init(sfd,argv[1],argv[2]);//bindIP地址及端口号
	listen(sfd,f.capibility);
	int new_fd;
	while(1)
	{
		new_fd =accept(sfd,NULL,NULL);
		que_add(&f.que,new_fd);
		ptread_cond_signal(&f.cond);
	}
	return 0;
}
