 ///
 /// @file    2-2-1SqList.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-08 23:28:16
 ///
 
#define MaxSize 50//定义线性表的最大长度值
typedef struct{
	ElemType data[MaxSize];//顺序表的元素
	int length;//顺序比啊的当前长度
}SqList;//顺序表的类型定义

bool ListInsert(SqList &L,int i,ElemType e){
	//本算法实现将元素e插入到顺序表中的dii个位置
	if(i<1||i>L.length+1)//判断i的范围是否有效
		return false;
	if(L.length>=MaxSize)//当前存储空间元素已满，不能插入
		L.data[j]=L.data[j-1];//
	L.data[i-1]=e;//在位置i处放入e
	L.length++;//线性表长度加1
		return true;
}
