 ///
 /// @file    2.38.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-15 18:43:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//1.设f(L,x)的功能是删除以L为首节点指针的单链表中所有值等于x的节点的
void Del_X_3(LinkList &L,ElemType x){
	//递归实现在单链表l中删除值为x的节点
	LNode *p;//p指向带删除节点
	if(L==NULL)///递归出口
		return ;
	if(L->data==x){//若L所指节点的值为x
		p=L;//删除*L，并让L指向下一节点
		L=L->next;/
		free(p);
		Del_X_3(L,x);//递归调用
	}
	else Del_X_3(L->next,x);//递归调用
}

//2.用p从头到尾扫描单链表，pre指向*p节点的前驱，若p所指节点的值为x，则删除，并让p移向下一个节点，否则让pre，p指针同步向后移动一个节点
void Del_X_l(LinkList &L,ElemType x){
	//L带头节点的单链表，本算法删除L中所有值为x的节点
	LNode *p=L->next,*pre=L,*p;//置p和pre的初始值
	while(p!=NULL){
		if(p->data==x){
			q=p;//q指向该节点
			p=p->next;
			pre->next=p;//删除*q节点
			free(q);//释放*q节点空间
		}
		else{
			／／否则，pre和p同步后移
				pre=p;
			p=p->next；
				}
	}
}

//解法二:采用尾插法建立单链表，用p指针扫描L的所有节点，当其值不为x时将其链接到l之后，否则奖其释放
void Del_X_2(Linklist &L,ElemType x){
	//L为带头节点的单链表，本算法将删除L中所有值为x的节点
	LNode *p=L->next,*r=L,*q;//r指向尾结点，其处置为头节点
	while(p!=NULL){
		if(p->data!=x){//*p节点值不为x时将其链接到L尾部
			r->next=p;
			r=p;
			p=p->next;//继续扫描
		}
		else{
			//*p节点值为x时将其释放
			q=p;
			p=p->next;//继续扫描
			free(q);//释放空间
		}
	}//while
	r->next=NULL;//插入结束后置尾结点指针为NULL
}

