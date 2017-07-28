 ///
 /// @file    2.1.7.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 19:05:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//算法思想：首先，按顺序不断取下两个顺序表表头较小的节点存入新的顺序表中。然后，看那个表还有剩余，将剩下的部分驾到新的顺序表后面
bool Merge(SeqList A,SeqList B,SeqList &C){

//合并有序顺序表中a与b成为一个新的顺序表有序顺序表c
	if(A.length+B.length>C.maxSize)//顺序表的最大长度
		int i=0,j=0,k=0;
	while(i<A.length&&j<B.length){//循环，两两比较，小者存入结果表中
		if(A.data[i]<=B.data[j])
			C.data[k++]=A.data[i++];
		else
			C.data[k++]=B.data[j++];
	}
	while(i<A.length)//还剩下一个没有比较万的顺序表
		C.data[k++]=A.data[i++];
	while(j<B.length)
		C.data[k++]=B.data[j++];
	C.length=k;
	return true;
}
