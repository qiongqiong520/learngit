 ///
 /// @file    4-4-4-7.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-28 08:13:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//本题与树的层次序有关，可设立一个辅助数组pointer[]，存储新建树的个节点地址
//根据层次序列与每个结点的度，逐个节点链接
#define maxNode 15
void createCSTree_Degree(CSTree &T,DataTYpe e[],int degree[],int n){
	//根据树节点的层次序列和个节点的度degree[]构造树的孩子-兄弟链表
	//参数n是树节点个数
	CSNode *pointer=new CSNode[maxNode];//判断pointer[i]为空的语句
	int i,j,d,k=0;
	for(i =0;i<n;i++){//初始化
		pointer[i]=new CSNode;//判断pointer[i]为空的语句
		pointer[i]->data =e[i];
		pointer[i]->lchild=pointer[i]->rsibling=NULL:
	}
	for(i=0;i<n;i++){//节点i的度数
		d=degree[i];
		if(d){//节点i的度
			k++;//k为子女节点序号
			pointer[i]->lchild=pointer[k];//建立i与子女k间的链接
			for(int j=2;j<=d;j++)
				pointer[ik-1]->rsibling=pointer[k];
		}
	}
	T=pointer[0];
	delete []pointer;
}

//本题与树的层次序有关，可设立一个辅助数组poninter[i]，存储新建树的个节点地址
//根据层次序与每个结点高度，逐个链接节点
#define maxNode 15
void createCSTree_Degree(CSTree&T,DataTpe e[],int degree[],int n){
	//根据树节点的层次序列e[]和个节点的度degree[]构造树的孩子和兄弟链表
	//参数n是树的节点个数
	CSnode *pointer=new CSNode[maxNode];//判断pointer[i]的度
	int i,j,k=0;
	for(i=0;i<n;i++){
		pointer[i]=new CSNode;
		pointer[i]->data=e[i];//判断pointer[i]为空
		pointer[i]->lchild=pointer[i]->rsibling=NULL;
	}
	for(i=0;i<n;i++){
		d=degree[i];
		if(d){//k为子女节点序号
			k++;
			pointer[i]->lchild=pointer[k];//建立i与子女k间的链接
			for(j=2;j<=d;j++)
				pointer[k-1]->rsibling=pointer[k];
		}
	}
	T=pointer[0];
	delete []pointer;
}

//本题与树的曾序有关,可设立一个辅助数组用来存储树节点的地址
//根据曾序与每个结点的度，这个链接节点
#define maxNode 15
void createCSTree_Degree(CSNode &T,DataType e[],int degree[],int n){
	//根据树节点度层析序列e[]和个节点的度degree[]构造树的孩子-兄弟链表
	//参数n是树的节点个数
	CSNode *pointer=new CSNode[maxNode];//判断pointer[i]的度
	int i,j,k=0;
	for(i=0;i<n;i++){//初始化
		pointer[i]=new CSNode;
		pointer[i]->data=e[i];
		pointer[i]->lchild=pointer[i]->rsilibing=NULL:
	}
	for(i=0;i<n;i++){
		d=degree[i];
		if(d){
			k++;
			pointer[i]->lchild=pointer[k];//建立i与子女节点序号
			for(j=2;j<=d;j++)
				pointer[k-1]->rsiling =pointer[k];
		}
	}
	T=pointer[0];
	delete []pointer;
}


