 ///
 /// @file    7-14求解最优二叉树搜索算法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-30 20:40:46
 ///
#include<iostream>

template<class E,class K>
BST<E,K>::OpticBST(int p[],int q[],E a[],int n){
	//给定n个不同的数据以及他们的权值
	//另外落在他们之间外部节点的权值分别为qi],本算法计算的最优二叉树搜索树
	//的根、代价和权
	int R[n+1][n+1],C[n+1][n+1],W[n+1][n+1];
	int l,j,k,m,min,u;
	for(i=0;i<n;i++){
		W[i][i]=q[i];
		C[i][i]=R[i][i]=0;//初始化
		W[i][i+1]=W[i][i]+p[i+1]+q[i+1];//构造只有一个内部节点，两个外部结点的最优二叉树
		R[i][i+1]=i+1;//这些树的根在i+1
		c[i][i+1]=w[i][i+1];//这些树的总代权路径长度
	}
	W[n][n]=q[n];
	R[n][n]=C[n][n]=0;//构造具有m个内部节点的最优二叉树
	for(m=2;m<=n;m++)
		for(i=0;i<=n-m;i++){
			j=i+m;//在前一刻树基础上加一内部节点和一外部结点
			W[i][j]=W[i][j-1]+p[j]+q[j];
			min=C[i+1][j];u=i+1;//假定i+1为根，计算代价
			for(k=i+2;k<=j;k++)
				if(C[i][k-1]+C[k][j]<min)
				{min=C[i][k-1]+C[k][j];u=k;}
			//轮流以i+2，j为根，选代价最下的送min，其根为u
			C[i][j]=W[i][j]+min;R[i][j]=u;
		}
};


template<class E,class K>
BST<E,K>::OpticBST(int p[],int q[],E a[],int n){
	//给定n个不同的数据，以及他们的权值，；ing外落在他们之间外部结点的权值分别为q[i],本算法计算的最优二叉搜索树的代价的根和权值
	int R[n+1][n+1],C[n+1][n+1],W[n+1][n+1];
	int l,j,k,m,min,u;
	for(i=0;i<n;i++){
		W[i][i]=q[i];
		C[i][i]=R[i][i]=0;//初始化
		W[i][i+1]=W[i][i]+p[i+1]+q[i+1];//构造内部节点，另外两个外部结点的最优二叉树为
		R[i][i+1]=i+1;//这些树的根在i+1
		C[i][i+1]=W[i][i+1];//这些树的总代权路径长度代价
	}
	W[n][n]=q[n];
	R[n][n]=C[n][n]=0;
	for(m=2;m<=n;m++){//构造具有m个内部节点的最优二叉搜索树
		for(i=0;i<=n-m;i++){
			j=i+m;//在前一棵树基础上加一内部节点和一外部结点
			W[i][j]=W[i][j-1]+p[j]+q[j];
			min=C[i+1][j];u=i+1;//假定i+1为根，计算代价
			for(k=i+2;k<=j;k++)
				if(C[i][k-1]+C[k][j]<min)
				{min=C[i][k-1]+C[k][j];u=k;}
			//轮流以i+2，j为根，选代价最小的送min，七根为u
			C[i][j]=W[i][j]+min;R[i][j]=u;
		}
	};


