///
/// @file    factory.h
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-18 14:54:5 
//

#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "work_que.h"
#include "normal.h"

typedef void* (*pthfunc)(void*);

typedef struct  factory{
	pthread_t *pth;
	int tnum;//创建的线程数目
	pthfunc entry;//线程入口函数
	pthread_cond_t cond;
	int capibility;//能力
	struct que_t que;
	int start;
}fac,*pfac;

void set_init(int,char*,char*);
void send_file(int);
void factory_init(pfac,pthfunc);
void factroy_start(pfac);
#endif

