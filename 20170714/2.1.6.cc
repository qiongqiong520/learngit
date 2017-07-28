 ///
 /// @file    2.1.6.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 18:46:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//算法思想：有序顺序表，值相同的元素一定在连续的位置上，用类似于直接插入排序的思想
//初始时将第一个元素看作非重复的有序表。之后一次判断后面的元素是否愿前面的元素重复，如果想同泽继续向后判断，如果不同则插入到前面非重复有序表带最后，知道判断到表尾为止
bool Delete_Same((SeqList &L){
		if(L.length==0)
		return false;//ic存储第一个不相同的元素，j工作指针
		for(i=0,j=1;j<L.length;j++)
		if(L.data[i]!=L.data[j])//查找下一个与上个元素值不同的元素
		L.data[++i]=L.data[j];//找到后，则将元素前移
		L.length=i+1;
		}
