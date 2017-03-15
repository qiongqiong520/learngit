 ///
 /// @file    set.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 16:12:18
 ///
 //set容器使用：关键字不允许重复，按照关键字排序
#include <iostream>
#include<set>
using std::cout;
using std::endl;
using std::set;
int main(void)
{
	//set不支持下标式随机访问，必须通过迭代器访问元素
	int sz[9]={2,1,3,5,4,6,3,5,6};//定义int型数组，数组名相当于指针(迭代器)
	set<int>A(sz,sz+9);//将迭代器区间作为参数创建容器对象A
	cout<<A.size()<<endl;//a输出A中元素个数

	set<int>::iterator it =A.begin();//创建set<int>::iterator迭代器,zh
	//指向A头部，输出全部元素
	while(it!=A.end())
	{
		cout<<*it<<" ";
		it++;//指向下一个元素
	}
	cout<<endl;

	return 0;
}

