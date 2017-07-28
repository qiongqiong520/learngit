 ///
 /// @file    2.10.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-17 22:28:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//算法思想：设置一个访问序号变量，初值为0，每访问一个结点序号自动加一，谈后序号等奇偶性将结点擦乳刀A表或B表中，重复上述操作指导结束

LinkList DisCreate_l(LinkList &A){
	//将表中节点按序号的奇偶性分解到表A或表B中
	i=0;//i记录表A中节点等序号
	B=(LinkList)malloc(sizeof(LNode));//创建bbiao表头
	B->next=NULL;//ra和rb将分别指向将创建的表he表表尾结点
	LNode *ra=A,*rb=B;//ra和rb将分别指向将创建da表和b表尾结点
	p=A-<next;//置空新的a表
	while(p!=NULL){
		i++;//序号加1
		if(i%2==0){//处理序号为偶数的表尾结点
			rb->next=p;//在b表尾处插入新结点
			rb=p;
		}
		else{
			ra->next=p;//在a表尾插入新结点
			ra=p;
		}
		p=p->next;
		//奖p恢复为指向新结点的待处理结点
		//while结束
	}
	ra->next=NULL;
	rb->next=NULL:
		return B;
}
