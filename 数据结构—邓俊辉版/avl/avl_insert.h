 ///
 /// @file    avl_insert.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-15 16:56:07
 ///

template<typename T>BinNodePosi(T) AVL<T>::insert(const T& e){//将关键码e插入AVL树中
	BinNodePosi(T) & x=search(e);if(x)return x;//确认目标节点存在
	BinNodePosi(T)xx=x=new BinNode<T>(e,_hot);size++;//创建新节点x
	//此时，x的父亲节点若增高，则祖父节点可能失衡
	for(BinNodePosi(T) g=_hot;g;g=g->parent){//从x之父出发向上，逐层检查各代祖先g
		if(!Avlbalanced(*g)){//一旦发现g失衡，则采用3+4算法，使之失衡，并将子树重新介入原树
			FromParentTo(*g)=rotateAt(tallerChild(g));
			break;//g复衡后，局部子树高度必然复原
		}else//否则g依然平衡，只需简单地
			updateHeight(g);//更新其高度
	}//至多只需一次调整：若果真做过调整，则全树高度必然失衡
	return xx;//返回新节点位置
}//无论e是否存在原树中，总有AVL::insert(e)->data=e


