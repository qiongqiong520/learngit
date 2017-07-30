 ///
 /// @file    4-3-13.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 14:20:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//
//后序遍历最后访问跟节点，记载递归算法中跟时压在占地的，本体要找p和q的最近公公祖先节点r，不失一般性，设p在q的左边
//算法思想：采用后序非递归算法，占中存放二叉树节点指针,当访问到某节点时，栈中所有元素军事该节点的祖先
//后序遍历必然是县遍历站定开始逐个到辅助栈中去匹配。第一个匹配的元素就是节点p和q的最近公告祖先
typedef struct{
	BiTree t;
	int tag;//tag=0,表示左子呢已被访问，tag=1表示右子女已被访问
}Stack；
Stack s[],s1[];//栈，容量足够大
BiTree Ancestor(BiTree ROOT,BiTNode *p,BiTNode *q){
//本算法要求二叉树中p和q指向节点最近公共节点
top =0;bt=ROOT;
while(bt!=NULL||top>0){
	while(bt!=NULL){
		s[++top].t=bt;
		s[top].tag=0;
		bt=bt->lchild;
	}
	//岩佐分枝向下
	while(top!=0&&s[top].tag==1){
		//假定p在q的左侧，遇到p时，栈中均为p的祖先
		if(s[top].t==p){
			for(i=1;i<=top;i++){
				for(i=1;i<=top;i++)
					s1[i]=s[i];
				top1=top;
			}//将栈s的元素转入辅助栈s1保存
			if(s[top].t==q)//找到q节点
				for(i=top;i>0;i--){//将栈中元素的树节点到s1中去匹配
					for(i=top1;j>0;j--)
						if(s1[j].t==s[i].t)
							return s[i].t;//p和q的最近公告祖先已找到
				}
			top--;//退栈
			if(top!=0){
				s[top].tag=1;
				bt=s[top].t->rchild;
			}
		}
		return NULL;//p和q无公共祖先节点
	}
}

//后序遍历最后访问跟节点，记载递归算法中，跟时压在栈底的。本体就是瑶找p和q的最近公共祖先节点r，不失一般性的设p在q的左边
//算法思想：采用后序非递归算法，栈中存放二叉树节点指针，当访问到某节点时，栈中所有元素均为该节点祖先。后序遍历必然是县遍历到节点p，栈中元素均为p的祖先。先将栈复制到另一辅助栈中。继续遍历到节点q时，将栈中元素从栈顶开始逐个到辅助栈中去匹配，第一个匹配的元素就是节点p和q的最近公共节点
typedef struct{
	BiTree T;
	int tag;//tag=0表示左子女已被访问，tag=1表示右子女已被访问
}stack;
stack s[],s1[];//栈，容量足够大
BiTree Ancestor(BiTree ROOT,BiTNode *p,BiTNode *q){
	//本算法求二叉树中p和q指向节点大最近公共节点
	top=0;bt=ROOT;
	while(bt!=NULL||top>0){
		while(bt!=NULL&&bt!=p&&bt!=q)//节点入栈
			while(bt!=NULL){
				s[++top].t=bt;
				s[top].tag=0;
				bt=bt->lchild;
			}
		while(top!=0&&s[top].tag==1){
			//假定p在q大左侧，遇到p时，栈中元素均是p的祖先
			if(s[top].t==p){
				for(i=1;i<top;i++)
					s1[i]=s[i];
				top1=top;
			}//将栈s的元素转入辅助栈s1保存
			if(s[top].t==q)//找到q节点
				for(i=top;i>0;i--){//将栈中元素的树节点到s1中去匹配
					for(j=top1;j>0;j--)
						if(s1[j].t==s[i].t)
							return s[i].t;//p和q的最近公公祖先已找到
				}
			top--;//退栈
		}
		if(top!=0){
			s[top].tag=1;
			bt=s[top].t->rchild;
		}
	}//岩组分址向下遍历
	return NULL;//p和q无公共祖先
}

