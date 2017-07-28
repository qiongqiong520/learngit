 ///
 /// @file    2.1.5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 18:40:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//算法思想：从前向后扫描顺序表l.用k记录下元素值在s到t之间元素的个数,对于当前扫描的元素，若其值不在s到t之间，则前移开个位置；否则执行k++。由于这样每个不在s到t之间的元素仅移动一次
//
bool Del_s_t(sqList &L,ElemType s,ElemTpye t){
	//删除顺序表L中值在给定值s与t之间的所有元素
	int i,k=0;
	if(L.length==0||s>=t)
		return false;//线性表为空或s，t不合法，返回
	for(i =0;i<L.length;i++){
		if(L.data[i]>=S&&L.data[i]<=t)
			k++;
		else
			L.data[i-k]=L.data[i];//当前元素前移k个位置
	}
	L.length-=k;//长度减小
	return true;
}

