 ///
 /// @file    05E1-4迭代实现.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-06 17:04:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;
template<typename T,typename VST>
void travPre_I1(BinNodePosi(T) x,VST & visit){
	Stack <BinNodePosi(T)> S;//辅助栈
	if(x)S.push(x);//跟节点入栈
	while(!S.empty()){//栈变空之前反复循环
		x=S.pop();visit(x->data);//弹出并访问当前节点
		if(HashRChild(*x))S.push(x->rchild);//右孩子先入后出
		if(HashLChild(*x))S.push(x->lchild);//左孩子先入后出
	}
}
