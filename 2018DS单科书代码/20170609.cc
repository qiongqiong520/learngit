 ///
 /// @file    20170609.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-09 16:46:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#define MaxSize 50//定义线性表的最大长度
typedef struct{
	ElemType data[MaxSize];//顺序表的元素
	int length;//顺序表的当前长度
}sqList;//顺序表的类型定义

#define InitSize 100//表长度初始定义
typedef struct{
	Elemtype *data;//指示动态分配数据长度
	int MaxSize,length;//数组的最大容量的当前个数
}SeqList;//动态分配数组线性表长度


//算法思想：搜索整个顺序表，查找最小值元素并记录其位置,搜索结束后用最后一个元素填补空白的原罪小元素位置
bool Del_Min(sqList &L,ElemType &value){
	//删除顺序表L中最小值元素的节点，并通过引用型参数value返回其值
	//如果删除成功，返回true，否则，返回false
	if(L.length==0)//表空，终止操作返回
		return false;
	value=L.data[0];//假定0号元素的值最小
	int pos=0;//循环，寻找最小值
	for(int i=1;i<L.length;i++)
		if(L.data[i]<value){
			value=L.data[i];
			pos=i;
		}
	L.data[pos]=L.data[L.length-1];//空出的位置由最后一个元素填补
	L.length--;
	return true;
}
//2.扫描顺序表Ld前半部分元素,对于元素L.data
