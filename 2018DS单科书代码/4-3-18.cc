 ///
 /// @file    4-3-18.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 15:49:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//算法思想：在后续序列中，若结点子女有右子女，则右子女时其前驱，若无右子女而有左子女，则左子女时其前驱
//若结点p左右子女均无，设其中序做线索指向某祖先节点f（p时f右子树中安中序遍历的第一个节点），若f有左子女时节点p的后序下的前驱，若f鹜左子女，则顺其前驱找双亲的双亲，一直找到双亲有左子女（这是左子女是p的前驱
//还有一种情况，若p是中序遍历的第一个节点，节点p的中序和后序下军务前驱
BiThrTree InPostPre(BiThrTree t,BiThrTree p){
	//在中序线索二叉树中，求指定结点p在后序下的前驱节点p
	BiThrTree q;
	if(p->rtag==0)//若p有右子女，则右子女是其后序前驱
		q=p->lchild;/
	else if(p->ltag==0)
		q=p->rchild;
	else if(p->lchild ==NULL)
		q=NULL;//p是中序序列第一个节点，无后序前驱
	else if(p->lchild ==NULL)
		q=NULL;//p是中序序列第一个节点，无后序前驱
	else{
		//顺左线索向上找p的祖先，若存在，再找祖先的左子女
		while(p>ltag==1&&p->lchild!=NULL)
			p=p->lchild;
		if(p->ltag==0)
			q=p->lchild;//p节点的祖先的左子女是其后序前驱
		else
			q=NULL;//仅有单指数p是叶子，一大根节点，无后序前驱
	}
	return q;
}

//算法思想：在后续序列中，若结点p有右子女，则右子女时其前驱，若无右子女而有左子女，则左子女是其前驱。若结点p左，右子女均无，舍弃中序左线索指向某祖先节点f（p是f右子树中按中序遍历的第一个节点）若f有左子女，则其左子女是节点p在后序下的前驱，若f无左子女，则顺其前驱赵大双亲的双亲，一直找到双亲右子女（这时左子女是p的前驱）若p是中序遍历的第一个节点，节点p在中序和后序下均无前驱
BiThrTree InPostPre(BiThrTree t,BiThrTree p){
	//在中序线索二叉树中，求指定节点p在后续下的前驱节点p
	BiThrTree q;
	if(p->rtag==0)//若p有右子女，则右子女是其后序前驱
		q=p->rchild;
	else if(p->ltag==0)//若p只有左子女，左子女是其后序前驱
		q=p->lchild;
	else if(p->lchild ==NULL)
		q=NULL;//p是中序序列第一节点，无后序前驱
	else{//顺左线索向上找p祖先，若存在，在找祖先的左子女
		while(p->ltag==1&&p->lchild!=NULLL)
			p=p->lchild;
		if(p>ltag==0)
			q=p->lchild;//p节点的祖先的左子女是其后序前驱
		else
			q=NULL;//仅有单支树p是叶子，已到根节点，p无后序前驱
	}
	return q;
}
