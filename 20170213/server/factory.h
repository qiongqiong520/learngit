#ifndef _FACTORY_H_
#define _FACTORY_H_
#include "work_que.h"
#includ "normal.h"

typedef struct factory{
pthread_t *pth;
int tnum;//创建线程数目
pthfunc entry;//线程入口函数
pthread_cond_t cond;
int capibility ;//能力
que_t que;
int start;
}fac,*pfac;

void set_init(int ,char*,char*);
void send_file(int);
void factory_init(pfac,pthfunc);
void factory_start(pfac);
#endif
