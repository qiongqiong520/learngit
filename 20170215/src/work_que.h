 ///
 /// @file    work_que.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-18 10:23:54
 ///
 

#ifndef __WORK_QUE__
#define __WORK_QUE__
#include "normal.h"

//队列节点
typedef struct list{
	int new_fd;
	struct list *pnext;
}Node,*pNode;

//队列结构
typedef struct work_que{
	pNode phead,ptail;
	pthread_mutex_t mutex;
	int size;//标示队列实时长度
}que_t,*pque;

void que_init(pque );
void que_add(pque,int);
void que_get(pque,pNode* p_new_fd);
#endif
