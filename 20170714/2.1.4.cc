 ///
 /// @file    2.1.4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 18:33:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//算法思想：现寻找值大雨等于s的第一个元素（第一个删除的元素），然后寻找值>t的第一个元素，最后一个删除的元素的下一个元素，要将这段元素删除，则只需要直接将后面的元素前移即可
//
bool Del_s_t2(sqList &L,ElemType s,ElemType t){
	//删除有序顺序表L中值在给定值s与t之间的所有元素
	int i,j;
	if((s>=t)||L.length==0)
		return false;
	for(i=0;i<L.length&&L.data[i]<s;i++);//寻找值》=s的第一个元素
	if(i>=L.length)
		return false;//所有元素值均小于s，则返回
	for(j=i;j<L.length&& L.data[j]<=t;j++);//寻找值》t的第一个元素
	for(;j<L.length;i++,j++)
		L.data[i]=L.data[j];//前移，填补被删除元素位置
	L.length=i;
	return true;
}
