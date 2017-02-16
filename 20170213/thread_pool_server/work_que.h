#ifndef _WORK_QUE_H_
#define _WORK_QUE_H_
#include "normal.h"

//队列节点
typedef struct list{
	int new_fd;
	struct list *pnext;
}Node,*pNOde;

//u 队列结构体
typdef struct work_que{
	pNode phead,ptail;
	pthread_mutex_t mutex;
int size;//标示队列实时长度
}que_t,*pque;

void que_init(pque);
void que_add(pque,int);
vod que_get(pque,pNode*,p_new_fd);
#endif
