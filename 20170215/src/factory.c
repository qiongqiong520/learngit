 ///
 /// @file    factory.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-18 14:47:31
 ///
 

#include"factory.h"
void factory_init(pfac p,fthfunc entry)
{
	p->pth = (pthread_t*)calloc(p->tnum,sizeof(pthread_t));
	p->entry = entry;//线程入口函数初始化
	pthread_cond_init(&p->cond,NULL);
	que_init(&p->que);
	p->start = 0;
}

void factory_start(pfac p)
{
	int i;
	if(0==p->start)
	{
		for(i=0;i<p->tnum;i++)
		{
			pthread_create(&p->pth[i],NULL,p->entry,p);
		}
		p->start =1;
	}else{
		printf("factroy has startrd\n");
	}
}
