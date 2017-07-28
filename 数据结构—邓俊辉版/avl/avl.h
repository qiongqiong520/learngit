 ///
 /// @file    avl.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-15 16:48:28
 ///
#include"BST/BST.h"//基于BST实现AVL树
template<typename T>class AVL:public BST<T>{//由BST派生AVl树模板类
	public:
		BinNodePosi(T)insert(const T& e);//插入重写
		bool remove(constT& e);//删除重写
		//BST：：search等其余接口可直接沿用
		};

