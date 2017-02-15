#include"factory.h"

typedef struct factory{
	pthread_t *pth;
	int num;
	void* (*pthread) (void*);
	pthread_cond_t cond;
	int capibility;//能力
	int start;

};

void factory_init(pfac p,pthfunc entry )
{
	p->pth= (pthread_t*)calloc(p->tnum,sizeof(pthread_t));
	p->entry = entry;//线程函数入口初始化
	pthread_cond_init(&p->cond,NULL);
	que_init(&p->que);
	p->start = 0;
}
void factory_start(pfac p)
{
	int i;
	if(0==p->start )
	{
		for(i =0;i<p->tnum;i++)
		{
			pthread_ctreat(&p->pth[i],NULL,p->entry,p);
		}
	p->start =1;
}else{
printf("factory 

	}
