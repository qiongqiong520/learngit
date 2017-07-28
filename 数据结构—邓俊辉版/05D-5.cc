 ///
 /// @file    05D-5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-06 16:31:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//节点插入
template<typename T> BinNodePosi(T)
	BinTree<T>::insertAsRc(BinNodePosi(T) x,T const & e){//insertAsLC()对称
		_size++;
		x->insertAsRc(e);//x祖先的高度增加，其余节点必然不变
		updateHeightAbove(x);
		return x->rChild;
	}
