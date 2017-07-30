 ///
 /// @file    4-3-11.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 14:07:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//删除一元素x为根的子树，只要能删除其左右子树，就可以释放其值为x的跟节点，因此采用及后序遍历算法。算法思想：删除其值为x的节点，意味着应将其敷节点的左右子女指针置空
//用层次遍历抑郁找到某节点的父结点。本体要求删除树中每一个元素值为x的节点的子树，因此要遍历完整棵二叉树
void DeleteXTree(BiTree bt){//删除以bt为根的子树
	if(bt){
		DeleteXTree(bt->lchild);
		DeleteXTree(bt->rchild);
		free(bt);//删除bt的左子树，右子树
		//释放被删节点所占的存储空间
	}
}
//在二叉树上查找所有以x为元素值的节点，并删除以其为根的子树
void Search(BiTree bt,EleType x){
	BiTree Q[];//Q是存放二叉树节点指针的队列，容量足够大
	if(bt){
		if(bt->data==x){
			//若跟节点值为x，则删除郑棵树
			DeleteXTree(bt);
			exit(0);
		}
		InitQueue(Q);
		EnQueue(Q,bt);
		while(!IsEmpty(Q)){
			DeQueue(Q,p);
			if(p->lchild)
				if(p->lchild->data==x){//左子树复合则删除左子树
					DeleteXTree(p->lchild);
					p->lchild=NULL;
				}
				else
					EnQueue(Q,p->lchild);//左子树如队列
			if(p>rchild)//若右子女非空
				if(p->rchild->Data==x){/右子女复合则删除右子树
					DeleteXTree(p->p->rchild);
					p->rchild=NULL;
				}
				else
					EnQueue(Q,p->rchild);//右子女如队列
		}
	}
}
