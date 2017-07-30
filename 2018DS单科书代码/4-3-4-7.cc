 ///
 /// @file    4-3-4-7.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 13:54:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//根据完全二叉树，具有n个节点的完全二叉树域满二叉树中编号从1～n的节点一一对应。
//算法思想：采用遍历算法，将所有节点加入队列（包括空节点）。当遇到空节点时，查看气候是否有非空节点
//若有，则二叉树不是完全二叉树
bool IsComplete(BiTree T){
	//本算法判断给定二叉树是否为完全二叉树
	InitQueue(Q);
	if(!T)
		return 1;//空树为满二叉树
	EnQueue(Q,T);
	while(!IsEmpty(Q)){
		DeQueue(q,p);
		if(p){//节点非空，将其左右子树如队列
			EnQueue(Q,p->lchild);
			EnQueue(Q,p->rchild);
		}
		else
			while(!IsEmpty(Q)){
				DeQueue(q,p);
				if(p)//节点非空，则二叉树为非完全二叉树
					return 0;
			}
		}
		return 1;
	}

//7..根据完全二叉树，具有n个节点的完全二叉树和满二叉树中编号从1～n的节点一一对应。算法思想：采用层次遍历的算法，将所有节点加入队列包括空节点。
//当遇到空节点时，查看气候是否有非空节点，若有，则二叉树不是完全二叉树
bool IsComplete(BiTree T){
	//本算法判断给定二叉树是否为完全二叉树
	InitQueue(Q);
	if(!T)
		return 1;//空树为满二叉树
	EnQueue(Q,T);
	while(!IsEmpty(Q)){
		DeQueue(Q,p);
		if(p){//节点非空，将其左右子树队列如空
			EnQueue(Q,p->lchild);
			EnQueue(Q,p->rchild);
		}
		else
			while(!IsEmpty(Q)){
				DeQueue(Q,p);
				if(p)//节点非空，则二叉树为非空二叉树
					return 0;
			}
	}
	return 1;
}
