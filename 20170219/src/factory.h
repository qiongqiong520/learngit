///
/// @file    factory.h
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-18 14:54:5 
//

#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "normal.h"

typedef void* (*pthfunc)(void*);
//定义队列结构体
typedef struct list{
	int new_fd;
	struct list *pnext;
}Node,*pNode;
//定义结构体
typedef struct work_que{
	pNode phead,ptail;
	pthread_mutex_t mutex;
	int size;//标示队列实时长度
}que_t,*pque;


typedef struct  factory{
	pthread_t *pth;
	int tnum;//创建的线程数目
	pthfunc entry;//线程入口函数
	pthread_cond_t cond;
	int capibility;//能力
	que_t que;
	int start;
}fac,*pfac;
void que_init(pque);
void que_add(pque,int);
void que_get(pque,pNode* p_new_fd);

void set_init(int,char*,char*);
void send_file(int);
void factory_init(pfac,pthfunc);
void factroy_start(pfac);
#endif

