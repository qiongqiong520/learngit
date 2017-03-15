 ///
 /// @file    multiset.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 16:19:48
 ///
 
#include <iostream>
#include<set>
using std::cout;
using std::endl;
using std::set;
using std::multiset;
//multiset容器的使用：关键字允许重复，按照关键字排序
//
int main(void)
{
	int sz[9]={2,1,3,4,5,6,5,3,5};
	multiset<int> A(sz,sz+9);
	cout<<A.size()<<endl;

	multiset<int>::iterator it =A.begin();//创建set<int>::iterator迭代器it
	//指向A头部
	while(it!=A.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	return 0;
}
