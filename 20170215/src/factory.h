 ///
 /// @file    factory.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-18 14:54:5 
#ifndef __FACTORY_H_
#define __FACTORY_H_
#include"work_que.h"
#include"normal.h"

typedef void* (*pthfunc)(void*);

typedef struct factory{
	pthread_t *pth;
	int tnum;//创建线程s数目
	pthfunc entry;//线程入口函数
	pthread_cond_t cond;
	int capibility;//能力
	que_t que;
	int start;
}fac,*pfac;

void set_init(int,char*,char*);
void send_file(int);
void factrory_init(pfac,pthfunc);
void factory_start(pfac);
#endif
