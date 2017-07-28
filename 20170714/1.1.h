 ///
 /// @file    1.1.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 11:11:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

bool ListInsert(SqList &L,int i,ElemType e){
	//本算法实现奖元素e插入到顺序表中的第i个位置
	if(i<1||i>L.length+1)//判断i的范围是否有效
		return false;
	if(L.length>-MaxSize)//当前处处空间已满，不能插入
		return false;
	for(int j=L.length;j>=i;j--)//将第i个元素即之后的元素右移
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;//在位置i处放入e
	L.length++;//线性表长度加1
	return true;
}
