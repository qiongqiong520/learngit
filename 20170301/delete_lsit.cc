 ///
 /// @file    delete_lsit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 15:18:52
 ///
 //删除容器中的元素
#include <iostream>
#include<list>
using std::list;
using std::cout;
using std::endl;

void disp(list<int>& x )
{
	list<int>::iterator it =x.begin();
	for(;it!=x.end();it++)
	{
		cout<<*it<<endl;
	}
}

int main()
{
	//创建容器
	int sz[9]={1,2,3,4,5,6,7,8,9};
	list<int> obL(sz,sz+9);//使用两个迭代器指针创建list对象
	disp(obL);
	cout<<endl;

	//2.erease重载版本
	list<int>::iterator iter =obL.begin();//创建迭代器ietr，指向最前端元素
	iter++;//指向第二个元素
	iter=obL.erase(iter);//将第二个元素删除，指向第三个元素的迭代器为iter赋值
	disp(obL);
	cout<<endl;

	//erase重载版本
	obL.erase(iter,obL.end());
	disp(obL);
	cout<<endl;

	//4.clear
	obL.clear();
	cout<<"clear后容器的元素个数减少"<<endl;

	return 0;
}
	//
