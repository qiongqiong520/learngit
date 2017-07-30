 ///
 /// @file    4-3-4-3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 13:23:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//算法思想：因为后序非递归遍历二叉树的顺序是先访问左子树，在访问右子树，最后访问跟节点。当用对战来存储结点时，必须分清返回根节点时，是从左子树中返回的还是从右子树总返回的。
//使用辅助指针r，其指向最近访问过的节点，也可以在节点中增加一个标志与是否被访问过
void PostOrder(BiTree T){
	InitStack(S);
	p=T;
	r=NULL;
	while(p||!IsEmpty(S)){
		if(p){
			Push(s,p);
			p=p->lchild;
		}
		else{
			GetTop(s,p);//去栈顶节点
			if(p->rchild&&p->rchild!=r){//如果右子树存在，且未被访问过
				p=p->rchild;//转向右
				push(S,p);//压入栈
				p=p->lchild;//在走道最左
			}
			else{
				//否则弹出节点并访问，
				pop(S,p);//将节点弹出
				visit(p->data);//访问该节点
				r=p;//记录最近访问过的结点
				p=NULL;//记录最佳放翁的结点
			}
		}
	}

}

//因为后续非递归排序的顺序是先访问左子树,再访问右子树,最后访问跟节点，当用堆栈来存储节点，必须分清返回根节点时，是从左子树返回，还是从右子树返回的，所以，使用辅助指针r，其指向
//使用辅助指针r，其指向最近访问过的节点，也可以在节点中增加一个标志域，记录是否被访问过
void PostOrder(BiTree T){
	InitStack(S);
	r=NULL;
	while(p||!IsEmpty(S)){
		if(p){//走到最左边
			push(S,p);
			p=p->lchild;
		}
		else{
			GetTop(S,p);//向右
			if(p->rchild&&p->rchild!=r){//如果右子树存在，且未被访问
				p=p->rchild;//转向右
				push(S,p);//压入栈
				p=p->lchild;//再走到最左
			}
			else{
				pop(S,p);//将节点弹出
				visit(p->data);//访问该节点
				r=p;//记录最近反问过的节点
				p=NULL;//接单访问完后，重置p指针
			}
		}
	}
}

//算法思想：因为后序非递归遍历二叉树的顺序时先访问左子树，在访问右子树，最后访问跟节点，当用对战来存储节点时，必须分清返回根节点时，是从左子树返回的
//还是从右子树返回的。使用辅助指针r，指向最近访问过的节点，也可以在节点中增加一个标志域，记录是否被访问过
void PostOrder(BiTree T){
	InitStack(S);
	p=T;
	r=NULL;
	while(p||!IsEmpty(S)){
		if(p){
			//走到最左边
			push(S,p);
			p=p->lchild;
		}
		else{
			GetTop(S,p);//向右
			if(p->rchild&&p->rchild!=r){//如果右子树存在，且未被访问过
				p=p->rchild;//转向右
				push(S,p);//压入栈
				p=p->lchild;//再走到最左
			}
			else{//否则，弹出节点并访问
				pop(S,p);//将节点弹出
				visit(p->data);//将节点弹出
				r=p;//记录最近访问过的节点
				p=NULL;//节点访问完后，重置p指针
			}
		}
	}
}


		

