 ///
 /// @file    7-16左单旋转算法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-30 21:14:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class E,class K>
void AVLTree<E,K>::RotateL(AVLNode<E,K>*&ptr){
	//右子树比左子树高：对以ptr为根的AVL树做左单旋转，旋转后新根在ptr
	AVLNode<e.K> * subL=ptr;//要做旋转的结点
	subL->right=ptr->left;//ptr成为新根潛携带哦左边负载
	ptr->left=subL;//左单旋转，ptr稳日新根
	ptr->bf=subL->bf=0;
};

template<class E,class K>
void AVLTree<E,K>::RotateL(AVLNode<E,K>* &ptr){
	//右子树比左子树高，对以ptr为根的avl树左左单旋转，旋转后新根在ptr
	ptr=subL->right=ptr->left;//ptr成为新根钱携带哦左边负载
	ptr->left=subL;
	ptr->bf=subL->bf=0;//左单旋转，ptr为新根

};

template<class E,class K>
void AVLTree<E,K>::RotateL(AVLNode<E,K>*&ptr){
	//右子树比左子树高：对以ptr为根的AVL树作为左单旋转，旋转后在新根ptr
	AVLNode<E,K>*subL=ptr;//要左单旋转的结点
	ptr=subL->right;//要原根的右子女
	subL->right=ptr->left;//ptr成为行根钱卸掉左边负载
	ptr->left=subL;//左单旋转，ptr为新根
	ptr->bf=subL->bf=0;
};
