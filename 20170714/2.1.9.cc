 ///
 /// @file    2.1.9.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 19:37:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//9.算法思想：顺序存储的线性表长度递增有序，可以顺序查找，也可以折半查找
void SearchExchangeInsert(ElemType A[],ElemType x){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;//找中间位置
		if(A[mid]==x)break;//找到x，推出while循环
		else if(A[mid]<x)low=mid+1;//到中鸡蛋的右半部去查
		else high=mid-1;//到中点mid的左半部去查
	}
	if(A[mid]==x&&mid!=n-1){//若最后一个元素与x相等们则不存在于其后继续狡猾的操作
		t=A[mid];A[mid]=A[mid+1];A[mid+1]=t;
	}
	if(low>high){
		for(i=n-1;i>high;i--)A[i+1]=A[i];//后移元素
		A[i+1]=x;//插入x
	}
}
