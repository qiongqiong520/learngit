 ///
 /// @file    avl_remove.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-15 17:09:36
 ///
 template<typename T>bool AVL<T>::remove(const T& e){//从AVl树中删除关键码e
	 BinNodePosi(T) & x=search(e);if(!x)return false;//确认目标存在
	 removeAt(x,_hot);_size--;//先按BST规则删除之，此后，愿节点之父_hot及其祖先均可能失衡
	 if(!AvlBalanced(*g))//一旦发现失衡，则采用3+4算法，使之复衡并将该子树联至
		 g=FromparentTo(*g)=rotateAt(tallerChild(tallerChild(g)));//原父亲
	 updateHeight(g);//并更新高度，即便g未失衡，高度亦可能降低
 }//kennel需要做omega(logn)次调整，无论是否做过调整，全书高度均可能降低
return true;//删除成功
}//若目标节点存在且被删除,返回true，否则返回false

