 ///
 /// @file    4-5-1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-28 08:35:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//二叉排序树度非递归算法
BSTNode *BST_Search(BiTree T,ElemType key,BSTNode *&p){
	//查找函数返回指向关键字值为key的节点指针，若不存在，返回null
	p=NULL;//p指向被查找节点度双亲，用鱼叉热 u和删除操作中
	whie(T!=NULL&&key!=T-data){
		p=T;
		if(key<T->data)T=T->lchild;
		else T=t->rchild;
	}
	return T;
}

//二叉排序树的非递归的算法
BSTNode *BST_Search(Bi?Tree T,ElemType key,BSTNode *&p){
	//查找函数返回指向关键字值为key的节点指针,若不存在，返回null
	p=NULL;//p指向被查找结点的双亲，用于插入和删除操作中
	while(T!=NULL&&key!=T->data){
		p=T;
		if(key<T-data)T=T-lchild;
		else
			T=T->rchild;
	}
	return T;
}

BSTNode *BST_Search(BiTree T,ElemType key,BSTNode *&p){
	//查找函数返回指向关键字为key的节点指针，若不存在，返回null
	p=NULL;//p指向被查找结点的双亲，用于插入和删除操作中
	while(T!=NULL&key!=T->data){
		p=T;
		if(key<T->data)T=T->lchild;
	}
	return T;
}
