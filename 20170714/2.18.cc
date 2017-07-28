 ///
 /// @file    2.18.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 19:29:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//8.算法思想：首先将数组A[m+n]中的元素原地逆置，再对前n个元素和后m个元素分别使用逆置算法，就可以的到最后结果，从而实现顺序表的位置互换.
typedef int DataType;
void Reverse(DataType A[],int left,int right,int arraySize){
	//逆转（aleft,aleft+1,aleft+2,aright)为
	if(left>=right||right>=arraySize)
		return ;
	int mid=(left+right)/2;
	for(int i=0;i<mid-left;i++){
		DataType temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
}
void Exchange(DataType A[],int m,int n,int arraySize){
	Reverse(A,0,m+n-1;arraySize);
	Reverse(A,0,n-1,arraySize);
	Reverse(A,n,m+n-1,arraySize);
}
