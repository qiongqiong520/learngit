#ifdef _WORK_QUE_H_
#define _WORK_QUE_H_
#include "normal.h"

//队列节点
typedef struct list{
int new_fd;
struct list *pnext;
}Node,*pNode;

//队列结构体
typedef struct work_que{
pNode_init(pque);
void que_add(pque ,int);
void que_get(pque,pNode* p_new_fd);

#endif


