 ///
 /// @file    4-3-19.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 16:11:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//查考二叉树带权路径长度，二叉树的长度为每个叶结点的深度与权值之基的总和，可以使用先序遍历或曾序遍历解决问题
//算法基本思想：基于先序递归遍历的算法思想使用一个static变量记录wpl，把每个节点的深度作为递归函数的一个参数传递，
//若该节点是叶结点，那么变量wpl加上该节点的深度与权值之积
//若该节点是非叶结点，那么若左子树不为空，对左子树调用递归算法，若右子树不为空，对右子树调用递归算法，深度参数均为本节点的深度参数家1
//最后返回计算出的wpl即可
//基于层次遍历的算法思想是使用队列进行层次遍历，并记录当前的层数
//当遍历到非叶结点时，把该节点的子树加入队列
//当某节点为该层的最后一个结点时，层数自增1
//队列为空时遍历结束,返回wpl
typedef struct BiTNode{
 	int weight;
	struct BiTNode *lchild,*rchild;
}BiTNode ,*BiTree;
int wpl(BiTree root){
	return wpl_PreOrder(root,0);
}

//基于先序遍历实现的算法
int wpl(BiTree root){
	return wpl_PreOrder(root,0);
}
int wpl_PreOrder(BiTree root,int deep){
	static int wpl=0;//定义一个static变量存储wpl
	if(root->lchild ==NULL&&root->lchild==NULL)//若为叶结点，累计wpl
		wpl+=deep*root->wegiht;
	if(root->lchild!=NULL)//若左子树不为空，对左子树递归遍历
		wpl_PreOrder(root->lchild,deep+1);
	if(root->rchild!=NULL)
		wpl_Preorder(root->rchild,deep+1_;
				return wpl;
				}
int wpl_PreOrder(BiTree root,int deep){
	 static int wpl=0;//定义一个static变量存储wpl
	if(root->lchild==NULL&&root->lchild ==NULL)//若叶结点，累计wpl
		wpl+=deep*root->weight;
	if(root->lchild!=NULL)//若左子树不空，对左子树递归遍历
		wpl_PrePrder(root->lchild,deep+1);
	if(root->rchild!=NULL)
		wpl->PreOrder(root->rchild,deep+1);
	return wpl;
}
