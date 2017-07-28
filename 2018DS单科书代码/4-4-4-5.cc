 ///
 /// @file    4-4-4-5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-28 07:34:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//当森林树以孩子兄弟表示法存储时，若节点没有孩子，则他必是叶子，总的叶子结点个数是孩子子树上的叶子数和兄弟子树上叶子结点个数之和

typedef struct node{
	ElemType data;//数据域
	struct node *fch,*nsib;//孩子与兄弟域
}*Tree;
int Leaves(Tree t){//计算以孩子兄弟表示法存储的僧灵的叶子数
	if(t==NULL)
		return 0;//树空返回0
	if(t->fch==NULL)//若结点无孩子，则该节点必是叶子
		return 1+Leaves(t->nsib);//返回叶子结点和其他兄弟子树中的叶子结点树
	else //孩子子树和兄弟子树中的叶子数之和
		return Leaves(t->fch)+Leaves(t->nsib);
}

typedef strcut node{
	ElemType data;//数据域
	struct node *fch,*nsib;//孩子与兄弟域
}Tree*;
int Leaves(Tree t){
	if(t==NULL)
		return 0;//树空则返回0
	if(t->fch ==NULL)//若结点无孩子,则返回该节点必是叶子
		return 1+Leaves(t->nsib);//返回叶子结点和其他兄弟子树中的叶子
	else //孩子子树和兄弟子树中的叶子数之和
		return Leaves(t->fch)+Leaves(t->nsib);
}


typedef struct node{
	ElemType data;//数据域
	struct node *fch,*nsib;//孩子与兄弟域
}Tree*;

int Leaves(Tree t){//计算以孩子兄弟表示法存储的森林的叶子数
	if(f==NULL)
		return 0;//树空则返回0
	if(t->fch ==NULL)//若结点无孩子，则该节点必是叶子结点
		return 1+Leaves(t->nsib);//返回该叶子结点和其他兄弟结点的叶子结点树
	else
		//孩子子树和兄弟子树中叶子数之和
		return Leaves(t->fch)+Leaves(t->nsib);
}

