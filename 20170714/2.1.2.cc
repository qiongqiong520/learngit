 ///
 /// @file    2.1.2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 18:19:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//设计一个高效算法，将顺序表所有元素逆置
//算法思想：扫描顺序表L的前半部分元素，对于元素L.data[i](0<L.length/2),将其与半部分对应元素l.data[length-i-1];//交换l.data[i]与L.data[L.length-i-1]
void Reverse(SqList &L){
	ElemType temp;//辅助变量
	for(i=0;i<L.length/2;i++){
		temp=L.data[i];//交换L.data【i]与l.data[l.length-i-1]
		L.data[i]=L.data[L.length-i-1];
		L.data[L.length-i-1]=temp;
	}
}


