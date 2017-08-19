 ///
 /// @file    5-31.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-01 20:52:23
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//树的递归的想跟遍历和后跟次序遍历
#include"tree.h"
#include<iostream>
template(ostream& out,TreeNode<T> *p){
	//先根次序遍历并输出以*p为根的树
	if(p!=NULL){
		out<<p->data;//当树为空是，输出跟节点数据
		for(p=p->firstchild;p!=NULL;p=p->nextSibling)
			PreOrder(out,p);
	}
};
template<class T>
void PostOrder(ostream& out,TreeNode<T> *p){
	//以指针p为根，按后跟次序遍历树
	if(p!=NULL){
		TreeNode>t> *q;
		for(q=p->firstChild;q!=NULL;q=q->nextSibling)
			PostOrder(out,q);//最后访问根结点
		out<<p->data;
	}
};





#include<iostream>
#include"tree.h"
template<class T>
void PreOrder(ostream& out,TreeNode<T> *p){
	//先根次序遍历并输出以*p为根的树
	if(p!=NULL){
		out<<p->data;
		for(p=p->firstChild;p!=NULL;p=p->nextSibling)
			PreOrder(out,p);
	}
};

template<class T>
void PostOrder(ostream&  out,TreeNode<T> *p){
	//一指针p为根，按后跟次序遍历树
	if(p!=NULL){
		TreeNode<T> *q;
		for(q=p->firstChild;q!=NULL;q=q->nextSibling)
			PostOrder(out,q);
		out<<p->data;//最后访问跟节点
	}
};

#include<iostream>
#include"tree.h"
template(ostream& out,TreeNode<T> *p){
	//先根次序遍历并输出以*p为根的树
	if(p!=NULL){
		out<<p->data;
		for(p=p->firstChild;p!=NULL;p=p->nextSibling)
			PreOrder(out,p);
	}
};
template<class T>
void PostOrder(ostream& out,TreeNode<T> *P){
	//以指针p为根，按后序遍历树
	if(p!=NULL){
		TreeNode<T> *q;
		for(q=p->firstchild;q!=NULL;q=q->nextSibling)
			PostOrder(out,q);//最后访问跟节点
		out<<p->data;
	}
};
