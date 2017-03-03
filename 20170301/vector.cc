 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 14:58:25
 ///
 //容器重载对三种形式的插入操作
#include <iostream>
#include<vector>
#include<list>
#include<deque>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

//将元素t插入到p之前，返回的迭代器指向被插入的元素
//
//在p之前插入n个t，无返回值
//
//在p之前插入first，last之间的所有元素


void disp(vector<int> &x)
{
 	//定义disp函数用一输出容器对象所有元素
	vector<int>::iterator it =x.begin();
	while(it!=x.end())
	{
		cout<<*it<<" ";
		it++;
	}
}

int main(void)
{
	//创建一个vector容器对象
	vector<int> obD(5,0);
	vector<int>::iterator pD = obD.end();//创建迭代器
	pD=obD.insert(pD,1);//在尾部插入元素，并使迭代器指向
	disp(obD);
	cout<<endl;

	//insesrt()的重载形式
	obD.insert(pD,2,3);//在新插入的元素之前插入两个元素
	disp(obD);
	cout<<endl;

	//insert()的是重载形式
	pD = obD.begin();//插入后迭代器可能失效
	int sz[3]={7,8,9};
	obD.insert(pD,sz,sz+3);//将两个指针相当于迭代器插入
	disp(obD);
	cout<<endl;

	//上述插入操作对list，vector，deue三种容器都适合可自行测试
	
	return 0;
}
