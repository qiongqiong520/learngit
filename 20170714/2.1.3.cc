 ///
 /// @file    2.1.3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-14 18:24:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//3.长度为n的顺序表L，编写一个时间复杂度为 O(n),空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素
//解法一：用k纪录顺序表L中不等于x的元素个数（急需要保存的元素个数),便扫描变统计k，并将不等于k的元素向前放置在k位置上，最后修改L的长度
void del_x_l(SqList &L,ElemType x){
	//本算法实现删除顺序表l中所有值为x的数据元素
	int k=0;//记录值不等于x的元素个数
	for(i=0;i<L.length;i++)
		if(L.data[i]!=x){
			L.data[k]=L.data[i];
			k++;//不等于x的元素增1
		}
	L.length=k;//顺序表Ld长度等于k
}

//接发二：用k记录顺序表中等于x的元素个数，便扫描L边统计k，并将不等于x的元素前移k个位置，最后修改l的长度
void del_x_2(SqList &L,ElemType x){
	int k=0,i=0;//k记录值等于x的元素个数
	while(i<L.length){
		if(L.data[i]==x)
			k++;
		else
			L.data[i-k]=L.data[i];//当前元素前移k个位置
		i++;
	}
	L.length=L.length-k;//顺序表Ld长度递减
}

