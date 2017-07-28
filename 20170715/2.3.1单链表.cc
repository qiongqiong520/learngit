 ///
 /// @file    2.3.1单链表.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-15 17:11:15
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//单链表类型描述

typedef struct LNode{
	ElemType data;//数据域
	struct LNode *next;//指针域
}
LNode,*LinkList;
//头插法建立单链表
//
LinkList CreateList1(LinkList &L){
	//从表尾到表头建立单链表L，每次均在头节点之后插入元素
	LNode *s;int x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;//初始为空表
	scanf("%d",&x);//输入节点的值
	while(x!=9999){//输入9999表示结束
		s=(LNode*)malloc(sizeof(LNode));//创建新结点
		s->data=x;
		s->next=L->next;
		L->next=s;//奖新节点插入表中，L为头指针
		scanf("%d",&x);
	}
	return L;//while结束
}
//每个节点插入时间复杂度为O(1),总时间复杂度为O(n)
//
//2.采用尾插法建立单链表
LinkList CreatList2(LinkList &L){
	//从表头都表尾正向建立单链表L，每次均在表尾插入元素
	int x;//设元素类型为整数
	L=(LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;//r为表尾指针
	scanf("%d",&x);//输入节点的值
	while(x!=9999){//输入99999表示结束
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;//r指向新的表尾结点
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;//尾结点指针置空
	return L;
}

//按序号查找节点的值
LNode *GetElem(LinkList L,int i){
	//本算法取出单链表L（带头节点）中第一个位置的节点指针
	int j=1;//计数，初始为1
	LNode *p=L->next;//头节点指针付给p
	if(i==0)
		return L;//若i等于0，则返回头节点
	if(i<l)
		return NULL;//若i无效，则返回NULL
	while(p&&j<i){//从第1个节点开始查找，查找第i个节点
		p=p->next;
		j++;
	}
	return p;//返回第i个节点的指针，如果i大于表长，p=NULL，直接返回p即可
}

//4.按值查找
LNode *LocateElem(LinkList L,ElemType e){//本算法查找单链表l带头节点中数据域值等于e的节点指针，否则返回NULL
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e)//从第i个节点开始查找打他域为e的节点
		p=p->next;
	return p;//找到后返回该节点指针，否则返回null
}

//5.插入节点查找

p=GetElem(L,i-1);//查找插入位置的前驱节点
s->next=p->next;
p->next=s;


//候查操作
//奖s节点插入到*p之前的主要代码段
s->next=p->next;//修改指针域，不能颠倒
p->next=s;
temp=p->data;//交换数据域部分
p->data=s->data;
s->data=temp;




//6.删除节点操作
p=GetElem(L,i-1);//查找删除位置的前驱节点
q=p->next;//令q指向被删除节点
p->next=q->next;//将*q节点从链中断开
free(q);//释放节点的存储空间

q=p->next;//令q指向*p的后继节点
p->data=p->next->data;//和后继节点交换数据域
p->next=q->next;//将*p节点从链中断开
free(q);

//7.求表长
计算单链表数据节点个数,需要从第一个节点开始顺序访问其后每一个节点指针,直到访问到空节点位置
//2.3.3双链表
//
typedef struct DNode{//定义双链表节点类型
	ElemType data;//数据域
	struct DNode *prior,*next;//前驱和后继指针
}DNode,*DLinkList;

//双链表插入操作
s->next=p->next;//将节点*s插入到节点*p之后
p->next->prior=s;
s->prior=p;
p->next=s;

//双链表删除操作

