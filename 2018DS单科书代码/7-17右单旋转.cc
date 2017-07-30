 ///
 /// @file    7-17右单旋转.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-30 21:26:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class E,class K>
void AVLTree<E,K>::RotateR(AVLNode<E,K>*&ptr){
	//左子树比右子树高：对以ptr为根的AVL树左右单旋转，旋转后行根在ptr上
	AVLNode<E,K>*subR=ptr;//要做右旋转的节点
	ptr=subR->left;//原根的左子女
	subR->left=ptr->right;//ptr成为新根钱卸掉右边负载
	ptr->bf=subR->bf=0;
};

template<class E,class K>
void AVLTree<E,K>::rotateR(AVLNode <E,K>*&ptr){
	//左子树比右子树高：对以ptr为根对avl树左右单旋转，旋转后根在ptr
	AVLNode<E,K>*subr=ptr;//要做右旋转的结点
	ptr=subR->left;//原根的左子女
	subR->left=ptr->right;//ptr成为新根钱卸掉右边负载
	ptr->bf=subR->bf=0;
};
