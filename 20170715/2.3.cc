 ///
 /// @file    2.3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-15 20:36:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//解法二：采用尾插法建立单链表.用p指针扫描所有L的节点指针,当其值部位x时将其链接到L之后，否则将其释放
void Del_x_2(LinkList &L,ElemType x){
	//L为带头节点的单链表，本算法删除L中所有值为x的节点
	LNode *p=L->next,*r=L,*q;//r指向尾结点，其处置为头节点
	while(p!=NULL){
		if(p->data!=x){//*p结点值不为x时将其链接到L尾部
			r->next=p;
			r=p;
			p=p->next;//继续扫描
		}
		else{
			q=p;//*p结点值为x时将其释放
			p=p->next;//继续扫描
			free(q);//释放空间
		}
	}
	r->next=NULL;//插入结束后置尾结点指针为 NULL}
	}

//3.勇战思想解决,很自然联想递归实现，每当访问一个结点时，先递归输出后面的节点，在输出该节点自身，实现链表反向输出
void R_Print(LinkList L){
	//从尾到头输出单链表l中的每个节点的值
	if(L->next!=NULL)
	{
		R_Print(L->next);//递归
	}
	print(L->data);//输出函数
}

//4.算法思想:用p从头到尾扫描单链表，pre指向*p结点的前驱，用minp保存至最小的节点指针
//,minpre指向*minp节点的前驱，一边扫描，一边比较，若p->data小于minp->data
//则将p,pre分别赋值给minp,minpre。当p扫描完毕
//minp指向最小值，minpre指向最新奥节点的前驱节点，再将minp所指节点删除即可
LinkList Delete_Min(LinkList v&L){
	//L带头结点的单链表，本算法删除最小值节点
	LNode *pre=L,*p=pre->next;//p为工作指针，pre指向其前驱
	LNode *minpre=pre,*minp=p;//保存值最小结点及其前驱
	while(p!=NULL){
		if(p->data<minp->data){
			minp=p;//找到比之前找到的最小值节点更小的节点
			minp=p;
			minpre=pre;
		}
		pre=p;
		p=p->next;
	}
	minpre->next=minp->next;//删除最小值结点
	free(minp);
	return L;
}

//5.解法一：将头结点摘下，然后实现第一节点开始，一次前插刀头结点的后面（头插法建立单恋比啊）直到最后一个结点
//则实现了链表逆置
LinkList Reverse_l(LinkList L){
	//L是带头结点的单链表，本算法将L就地逆置
	LNode *p,*r;//p为工作指针，r为p的后继，以防止锻炼
	p=L->next;//从第一个元素结点开始
	L->next=NULL;//先将头结点Ldnext域置为NULL
	while(p!=NULL){//一次将结点元素摘下
		r=p->next;
		p->next=L->next;//将p结点插入到头结点之后
		p=r;
	}
	return L;
}

//解法二:一是处理第一个结点时，应将其next域置为NULL，而不是指向头节点
//二是处理完最后一个结点后，需要将头结点的指针指向他
LinkList Reverse_2(LinkList L){
	//依次遍历线性表L，并将结点执着反转
	LNode *pre,*p=L->next,*r=p->next;//处理第一个结点
	p->next=NULL;
	while(r!=NULL){//r为空，则说明p为最后一个结点
		pre=p;
		//依次继续遍历
		p=r;
		r=r->next;
		p-<next=pre;
	}
	L->next=p;//处理最后一个结点
	return L;
}

//6.算法思想：采用直接插入排序,先构成一个数据结点的有序单链表，然后一次扫描单链表中的剩下结点*p，在有序表中通过比较查找插入*p的前驱节点*[热，然后将*p插入到*pre之后
void Sort(LinkList &L){
	//本算法实现奖单链表Ld节点重排，使其递增有序
	LNode *p=L->next,*pre;
	LNode *r=p->next;//r保持*p后继节点指针
	p-<next=NULL；
		骗人；
		while（p！=NULL）{
		r=p->
